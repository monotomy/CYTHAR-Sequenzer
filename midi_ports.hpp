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

#ifndef MIDI_PORTS_HPP_INCLUDED
#define MIDI_PORTS_HPP_INCLUDED

#include <crossplatt_threading.hpp>

namespace dc_midi{

    static cross_mutex mutex_only_one_thread_send{};

//!\class MidiOutPort
    inline TYPE_RtError MidiOutPort
    ::try_send_message(TYPE_midi_message* message_) noexcept
    {
        if(_out_port != nullptr)
        {
            if(_is_open)
                try
                {
                    mutex_only_one_thread_send.lock();
                    _out_port->sendMessage(message_);
                    mutex_only_one_thread_send.unlock();
                    return IS_OK;
                }
                catch (RtError &error)
                {
                    develINFO_(_MIDI, "Error: " + error.getMessage());
                    mutex_only_one_thread_send.unlock();
                    _status = error.getType();
                    return error.getType();
                }
            else
            {
                _status = IS_NOT_OPEN;
                return IS_NOT_OPEN;
            }
        }
        else
        {
            _status = IS_DUMMY;
            return IS_DUMMY;
        }
    }

//!\class MidiOutPortsPerApi
    inline void MidiOutPortsPerApi
    ::try_send_message(TYPE_midi_message* message_,
                       std::string const& port_name_) noexcept
    {
        auto port_pair(_midi_ports.find(port_name_));
        if(port_pair != _midi_ports.end())
        {
            if(port_pair->PORT->_is_open == true)
                if(port_pair->PORT->_status == RtError_extended::IS_OK)
                {
                    auto send_status(port_pair->PORT->try_send_message(message_));
                    send_status_handler(send_status, port_pair->first);
                }
        }
    }

    inline void MidiOutPortsPerApi
    ::try_send_clock() noexcept
    {
        try_send_to_all_open(&CLOCK_MESSAGE);
    }

    inline void MidiOutPortsPerApi
    ::try_send_to_all_open(TYPE_midi_message* message_) noexcept
    {
        for(auto midi_port_pair : _midi_ports)
            if(midi_port_pair.PORT->_is_open == true)
                if(midi_port_pair.PORT->_status == RtError_extended::IS_OK)
                    try_send_message(message_, midi_port_pair.first);
    }

    void inline MidiOutPortsPerApi
    ::send_status_handler(TYPE_RtError error_, std::string const& port_) noexcept
    {
        // Alles I.O.
        if(error_ == RtError_extended::IS_OK)
            return;

        /*
            WARNING,           !< A non-critical error.
            DEBUG_WARNING,     !< A non-critical error which might be useful for debugging.
            UNSPECIFIED,       !< The default, unspecified error type.
            NO_DEVICES_FOUND,  !< No devices found on system.
            INVALID_DEVICE,    !< An invalid device ID was specified.
            MEMORY_ERROR,      !< An error occured during memory allocation.
            INVALID_PARAMETER, !< An invalid parameter was specified to a function.
            INVALID_USE,       !< The function was called incorrectly.
            DRIVER_ERROR,      !< A system driver error occured.
            SYSTEM_ERROR,      !< A system error occured.
            THREAD_ERROR       !< A thread error occured.
        */

        switch (error_)
        {
        case RtError::WARNING :
            develINFO_(_MIDI, "Error: WARNING @ " + port_);
            break;
        case RtError::DEBUG_WARNING :
            develINFO_(_MIDI, "Error: DEBUG_WARNING @ " + port_);
            break;
        case RtError::UNSPECIFIED :
            develINFO_(_MIDI, "Error: UNSPECIFIED @ " + port_);
            break;
        case RtError::NO_DEVICES_FOUND :
            develINFO_(_MIDI, "Error: NO_DEVICES_FOUND @ " + port_);
            break;
        case RtError::INVALID_DEVICE :
            develINFO_(_MIDI, "Error: INVALID_DEVICE @ " + port_);
            break;
        case RtError::MEMORY_ERROR :
            develINFO_(_MIDI, "Error: MEMORY_ERROR @ " + port_);
            break;
        case RtError::INVALID_PARAMETER :
            develINFO_(_MIDI, "Error: INVALID_PARAMETER @ " + port_);
            break;
        case RtError::INVALID_USE :
            develINFO_(_MIDI, "Error: INVALID_USE @ " + port_);
            break;
        case RtError::DRIVER_ERROR :
            develINFO_(_MIDI, "Error: DRIVER_ERROR @ " + port_);
            break;
        case RtError::SYSTEM_ERROR :
            develINFO_(_MIDI, "Error: SYSTEM_ERROR @ " + port_);
            break;
        case RtError::THREAD_ERROR :
            develINFO_(_MIDI, "Error: THREAD_ERROR @ " + port_);
            break;
        case IS_NOT_PLUGGED :
            develINFO_(_MIDI, "Error: send to unplugged @ " + port_);
            break;
        case IS_DUMMY :
            develINFO_(_MIDI, "Error: send to dummy port @ " + port_);
            break;
        case IS_NOT_OPEN :
            develINFO_(_MIDI, "Error: send to closed @ " + port_);
            break;
        default:
            develINFO_(_MIDI, "Error: send : unknown error @ " + port_);
            break;
        }

        develINFO_(_MIDI, "Refresh ports...");
        refresh_ports();
        if(_gui != nullptr) _gui->notify_refreshed_ports();
    }

}

#endif // MIDI_PORTS_HPP_INCLUDED
