////////////////////////////////////////////////////////////////////////////////
// Author: Thomas Arndt monotomy@cythar.sequenzer.org
// This file is part of CYTHAR Sequenzer
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////////////

#ifndef DC_TICKER_GENERATOR_HPP_INCLUDED
#define DC_TICKER_GENERATOR_HPP_INCLUDED

#include <dc_midi_sequencer.h>
#include <midi_ports.h>
#include <dc_midi_message.h>
#include <dc_midi_message_factory.h>

#include <crossplatt_threading.hpp>

namespace dc_ticker{

    static inline int bpm_to_microsec(float bpm_) noexcept
    {
        static uint8_t clocks_per_beat{24};
        float clocks_per_min{bpm_*clocks_per_beat};
        float microsec_per_clock{(60*100*100*100)/clocks_per_min};

        return int{microsec_per_clock};
    }

    inline void Ticker
    ::tickLoop() noexcept
    {
        while( _is_running == true )
        {
            cross_thread _timer(&Usleep::exec,_microsec_per_clock);

            if( _is_master == true)
            {
                notify_subjects_clock();
                notify_subjects_event();
            }

            _timer.join();
        }
    }

    inline void Ticker
    ::extern_clock() noexcept
    {
        if( _is_master == false)
        {
            mutex_only_one_notify.lock();
            notify_subjects_event();
            if(_extern_clock_observer != nullptr)
                _extern_clock_observer->notify_extern_clock();
            mutex_only_one_notify.unlock();
        }

    }

    inline void Ticker
    ::notify_subjects_clock() noexcept
    {
        static auto const midi_out(dc_midi::MidiOutPortsPerApi::singleton());

        // TIME CRITICAL
        if( _is_master == true)
            midi_out->try_send_clock();
    }

    inline void Ticker
    ::notify_subjects_event() noexcept
    {
        static auto const sequencer(dc_midi::Sequencer::singleton());
        static auto const midi_message_fab(dc_midi::MessageFactory::singleton());
        static auto const message_stack_delay(dc_midi::MessageStack<dc_midi::UNIQUE_DELAY_STACK>::singleton());
        static auto const message_stack_ready(dc_midi::MessageStack<dc_midi::UNIQUE_READY_STACK>::singleton());
        static auto const message_stack_running(dc_midi::MessageStack<dc_midi::UNIQUE_RUNNING_STACK>::singleton());
        static auto const message_stack_over(dc_midi::MessageStack<dc_midi::UNIQUE_OVER_STACK>::singleton());

        if( _is_notifying == true )
        {
            // TIME CRITICAL
            message_stack_over->critical_send_stack();
            message_stack_ready->critical_send_stack();

            // CLEAN
            message_stack_over->precalculate_stack();

            // PRECALCULATE
            message_stack_ready->precalculate_stack();
            message_stack_running->precalculate_stack();

            sequencer->precalculate_next_positions();
            midi_message_fab->make_messages_to_sequencer_positions();

            message_stack_delay->precalculate_stack();
        }
    }

    inline void Ticker
    ::notify_subjects_event_at_start() noexcept
    {
        static auto const message_stack_delay(dc_midi::MessageStack<dc_midi::UNIQUE_DELAY_STACK>::singleton());
        static auto const midi_message_fab(dc_midi::MessageFactory::singleton());

        midi_message_fab->make_messages_to_sequencer_positions();

        message_stack_delay->precalculate_stack();
    }
}

#endif // DC_TICKER_GENERATOR_HPP_INCLUDED
