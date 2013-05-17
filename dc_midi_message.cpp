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

#include <dc_midi_message.h>

#include <midi_ports.h>
#include <cast/any2uchar.hpp>

namespace dc_midi{

//!\class NoteMessage

    NoteMessage
    ::NoteMessage(TYPE_note note__,
                TYPE_velocity velocity__,
                TYPE_lengthy length__,
                bool is_endless__,
                std::string const& port_name_,
                TYPE_midi_channel channel__,
                TYPE_lengthy delay__,
                uint8_t start_byte__,
                uint8_t end_byte__) noexcept :
        _port_name{port_name_},

        _start_message{{int2uchar(start_byte__+channel__),
                        note__,
                        velocity__}},

        _end_message{{int2uchar(end_byte__+channel__),
                        note__,
                        velocity__}},

        _aktive_message{&_start_message},
        _livetime{length__},
        _is_endless{is_endless__},
        _delay{delay__}
    {
        MessageStack<UNIQUE_DELAY_STACK>::singleton()->attach_message(this);
    }

    void NoteMessage
    ::push_to_ready_stack() noexcept
    {
        MessageStack<UNIQUE_DELAY_STACK>::singleton()->detach_message(this);
        MessageStack<UNIQUE_READY_STACK>::singleton()->attach_message(this);
    }

    void NoteMessage
    ::precalculate_you(Loki::Type2Type<UNIQUE_DELAY_STACK>) noexcept
    {
        // COUNT DELAY
        if(_delay > 0)
            --_delay;
        else
            push_to_ready_stack();
    }

    void NoteMessage
    ::precalculate_you(Loki::Type2Type<UNIQUE_READY_STACK>) noexcept
    {
        switch_to_running_stack();
    }

    void NoteMessage
    ::precalculate_you(Loki::Type2Type<UNIQUE_RUNNING_STACK>) noexcept
    {
        if(_is_endless != true)
        {
            // Fertig zum Sterben?
            if(_livetime > 0)
                // Lebt weiter...
                --_livetime;
            else
            {
                change_active_message_to(&_end_message);
                switch_to_over_stack();
            }
        }
    }

    void NoteMessage
    ::precalculate_you(Loki::Type2Type<UNIQUE_OVER_STACK>) noexcept
    {
        MessageStack<UNIQUE_OVER_STACK>::singleton()->detach_message(this);
        delete this;
    }

    void NoteMessage
    ::switch_to_running_stack() noexcept
    {
        MessageStack<UNIQUE_READY_STACK>::singleton()->detach_message(this);
        MessageStack<UNIQUE_RUNNING_STACK>::singleton()->attach_message(this);
    }

    void NoteMessage
    ::change_active_message_to(TYPE_pure_midi_message_data *const message__) noexcept
    {
        _aktive_message = message__;
    }

    void NoteMessage
    ::switch_to_over_stack() noexcept
    {
        MessageStack<UNIQUE_RUNNING_STACK>::singleton()->detach_message(this);
        MessageStack<UNIQUE_OVER_STACK>::singleton()->attach_message(this);
    }


}
