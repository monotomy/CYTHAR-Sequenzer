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

#ifndef DC_MIDI_MESSAGEHANDELS_HPP_INCLUDED
#define DC_MIDI_MESSAGEHANDELS_HPP_INCLUDED

#include <midi_ports.h>

#include <iostream>

namespace dc_midi{

    using namespace dc_objects;

//!\class NoteMessage
    inline void NoteMessage
    ::send_your_message() noexcept
    {
        dc_midi::MidiOutPortsPerApi::singleton()->try_send_message(_aktive_message, _port_name);
    }

    inline void NoteMessage
    ::send_your_STOP_message() noexcept
    {
        dc_midi::MidiOutPortsPerApi::singleton()->try_send_message(&_end_message, _port_name);
    }

//!\MessageStack
    template<class UNIQUE_STACK_TYPE>
    void MessageStack<UNIQUE_STACK_TYPE>
    ::precalculate_stack() noexcept
    {
        std::set<NoteMessage*> copy_of_message_stack{_message_stack};

        for(auto message : copy_of_message_stack)
            message->precalculate_you(Loki::Type2Type<UNIQUE_STACK_TYPE>());
    }

    template<class UNIQUE_STACK_TYPE>
    inline void MessageStack<UNIQUE_STACK_TYPE>
    ::critical_send_stack() noexcept
    {
        for(auto message : _message_stack)
            message->send_your_message();
    }

    template<class UNIQUE_STACK_TYPE>
    void MessageStack<UNIQUE_STACK_TYPE>
    ::attach_message(NoteMessage*const message__) noexcept
    {
        _message_stack.insert(message__);
    }

    template<class UNIQUE_STACK_TYPE>
    void MessageStack<UNIQUE_STACK_TYPE>
    ::detach_message(NoteMessage*const message__) noexcept
    {
        _message_stack.erase(message__);
    }

    template<class UNIQUE_STACK_TYPE>
    void MessageStack<UNIQUE_STACK_TYPE>
    ::clean_all() noexcept
    {
        // Laufende stoppen
        for(auto running_message : MessageStack<UNIQUE_RUNNING_STACK>::singleton()->_message_stack)
            running_message->send_your_STOP_message();

        // Alles Weitere Killen
        for(auto running_message : MessageStack<UNIQUE_DELAY_STACK>::singleton()->_message_stack)
            delete running_message;
        for(auto ready_message : MessageStack<UNIQUE_READY_STACK>::singleton()->_message_stack)
            delete ready_message;
        for(auto over_message : MessageStack<UNIQUE_OVER_STACK>::singleton()->_message_stack)
            delete over_message;
        for(auto running_message : MessageStack<UNIQUE_RUNNING_STACK>::singleton()->_message_stack)
            delete running_message;

        MessageStack<UNIQUE_DELAY_STACK>::singleton()->_message_stack.clear();
        MessageStack<UNIQUE_READY_STACK>::singleton()->_message_stack.clear();
        MessageStack<UNIQUE_OVER_STACK>::singleton()->_message_stack.clear();
        MessageStack<UNIQUE_RUNNING_STACK>::singleton()->_message_stack.clear();
    }
}

#endif // DC_MIDI_MESSAGEHANDELS_HPP_INCLUDED
