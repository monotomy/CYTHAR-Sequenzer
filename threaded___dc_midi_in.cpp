////////////////////////////////////////////////////////////////////////////////
// Author: Thomas Arndt info@monotomy.de.
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

#include <dc_midi_in.h>

#include <signal.h>

#include <crossplatt_threading.hpp>

#include <gm_midistandard.h>

#include <dc_ticker_generator.h>

#include <pattern/singleton.hpp>
#include <condition_variable>

namespace dc_midi{

    static bool IS_MASTER{false};
    void rtmidi_callback(double, std::vector<uint8_t>* message, void*) noexcept;

    // Own Thread
    void interpret_midiin(uint8_t first_byte__) noexcept;
    void play_clicked() noexcept;
    void pause_clicked() noexcept;
    void stop_clicked() noexcept;
    void panic_clicked() noexcept;
    void reset_clicked() noexcept;

    cross_mutex callback_mutex;
    std::condition_variable wait_for_callback_condition;
    uint8_t first_byte_flag{0};
    void rtmidi_callback(double, std::vector<uint8_t>* message__, void*) noexcept
    {
        if( message__->size() > 0 and IS_MASTER == false )
        {
            first_byte_flag = (*message__)[0];
            callback_mutex.unlock();
        }
    }

    void MidiIn
    ::midi_in_reciver() noexcept  //
    {
        // One Thread guard
        static bool is_running{false};
        if(is_running == false)
            is_running = true;
        else
            return;

        // Open Port
        using namespace gm_standard;
        try
        {
            std::string in_port_name{rtMidiInScanner->getPortName(_last_port)};
            in_port_name += CYTHAR_CONNECTION_NAME;

            rtMidiIn = new RtMidiIn(_rtmidi_api, in_port_name);
            rtMidiIn->ignoreTypes( false, false, false );
            rtMidiIn->setCallback( &rtmidi_callback );
            rtMidiIn->openPort(_last_port, in_port_name);
        }
        catch (RtError &error)
        {
            develINFO_(_3ERR, error.getMessage());
            return;
        }

        //! Reciver
        callback_mutex.lock();
        while(IS_MASTER == false)
        {
            callback_mutex.lock();

                switch(first_byte_flag)
                {
                case TIMING_CLOCK:
                    dc_ticker::Ticker::singleton()->extern_clock();
                    break;
                case START:
                    play_clicked();
                    break;
                case STOP:
                    stop_clicked();
                    break;
                case CONTINUE:
                    pause_clicked();
                    break;
                case RESET:
                    reset_clicked();
                    break;
                case 0:
                    // IGNORE
                    break;
                default:
                    break;
                }

                first_byte_flag = 0;
        }

        close_in_port();

        is_running = false;
    }

    MidiIn
    ::~MidiIn() noexcept
    {
        DCTOR_LOGFILE_DEBUG_(MidiIn);
        stop_reciving();
        delete rtMidiInScanner;
    }

    void MidiIn
    ::property_changed(AT_(Project,IS_MASTER)) noexcept
    {
        set_master();
    }

    void MidiIn
    ::set_master() noexcept
    {
        IS_MASTER = selGET_(this_dtlPROJECT_OBSERVER,IS_MASTER);

        if(IS_MASTER == false)
            start_reciving();
        else
        {
            stop_reciving();
        }
    }

    void MidiIn
    ::start_reciving() noexcept
    {
        start_reciver_thread_at_port(_last_port);
    }

    void MidiIn
    ::start_reciver_thread_at_port(unsigned int port_id__) noexcept
    {
        _last_port = port_id__;

        cross_thread reciver_thread(&MidiIn::midi_in_reciver, this);
        reciver_thread.detach();
    }

    void MidiIn
    ::stop_reciving() noexcept
    {
        wait_for_callback_condition.notify_one();
        close_in_port();
    }

    void MidiIn
    ::init() noexcept
    {
        try
        {
            std::vector<RtMidi::Api> Api;
            RtMidi::getCompiledApi(Api);
            _rtmidi_api = Api[0];
            rtMidiInScanner = new RtMidiIn(_rtmidi_api, CYTHAR_MIDIINPORT_NAME);
        }
        catch (RtError &error)
        {
            develINFO_(_3ERR, error.getMessage());
        }

        set_master();
    }



    void MidiIn
    ::close_in_port() noexcept
    {
        try
        {
            if(rtMidiIn != nullptr)
            {
                rtMidiIn->closePort();
                rtMidiIn->cancelCallback();
                delete rtMidiIn;
                rtMidiIn = nullptr;
            }
        }
        catch (RtError &error)
        {
            develINFO_(_3ERR, error.getMessage());
        }
    }

    std::vector<std::string> MidiIn
    ::get_port_list() noexcept
    {
        std::vector<std::string> plugged_in_ports{};
        try
        {
            for(unsigned int port_id_{0} ; port_id_!=rtMidiInScanner->getPortCount() ; ++port_id_ )
                plugged_in_ports.push_back(rtMidiInScanner->getPortName(port_id_));
        }
        catch (RtError &error)
        {
            develINFO_(_3ERR, error.getMessage());
        }

        return plugged_in_ports;
    }

    void MidiIn
    ::change_port_id(unsigned int port_id__) noexcept
    {
        _last_port = port_id__;

        if(IS_MASTER == false)
        {
            stop_reciving();
            start_reciving();
        }
    }

    unsigned int MidiIn
    ::port_id() const noexcept
    {
        return _last_port;
    }

    void play_clicked() noexcept
    {
        if(tmpGET_(IS_PAUSE) == true)
        {
            dc_midi::Sequencer::singleton()->reset();
            tmpSET_(IS_PAUSE, false);
        }


        tmpSET_(IS_NOTFYING, true);
    }

    void pause_clicked() noexcept
    {
        if(tmpGET_(IS_PAUSE) == true)
        {
            tmpSET_(IS_PAUSE, false);
            tmpSET_(IS_NOTFYING, true);
        }
        else
        {
            tmpSET_(IS_PAUSE, true);
            tmpSET_(IS_NOTFYING, false);
        }
    }

    void stop_clicked() noexcept
    {
        tmpSET_(IS_NOTFYING, false);
        tmpSET_(IS_PAUSE, true);
        dc_midi::MidiOut::singleton()->send_panic();
    }

    void reset_clicked() noexcept
    {
        dc_midi::Sequencer::singleton()->reset();
    }

    void panic_clicked() noexcept
    {
        dc_midi::MidiOut::singleton()->send_panic();
    }
}
