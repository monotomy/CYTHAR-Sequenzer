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

#include "midi_ports.h"

namespace dc_midi{

//!\class MidiOutPort
    MidiOutPort
    ::MidiOutPort(RtMidiOut*const out_port_,
                  RtMidi::Api api_,
                  unsigned int port_id_) noexcept :
        _out_port{out_port_},
        _api{api_}
    {
        _port_name = try_get_port_name(port_id_);
        _connection_name = str_CYTHAR_OUT_AT_ + _port_name;
        _is_open = try_open_port(port_id_);
    }

    MidiOutPort
    ::MidiOutPort(RtMidiOut*const out_port_,
                  RtMidi::Api api_,
                  std::string connection_string_at_api_) noexcept :
        _out_port{out_port_},
        _api{api_},
        _port_name{connection_string_at_api_},
        _connection_name{connection_string_at_api_}
    {
        _is_open = try_open_virtual_port();
    }

    MidiOutPort
    ::~MidiOutPort() noexcept
    {
        if(_out_port != nullptr)
            if(_is_open == true)
            {
                try
                {
                    _out_port->closePort();
                }
                catch(...)
                {
                    develINFO_(_MIDI, "Error: close out port: " + _port_name);
                }
            }

        if(_out_port != nullptr)
        {
            try
            {
                delete _out_port;
            }
            catch(...)
            {
                develINFO_(_MIDI, "Error: clean out port: " + _port_name);
            }
        }
    }


    std::string MidiOutPort
    ::try_get_port_name(unsigned int port_id_) noexcept
    {
        if(_out_port == nullptr)
        {
            _status = IS_DUMMY;
            return {"dummy port"};
        }

        try
        {
            return _out_port->getPortName(port_id_);
            _status = IS_OK;
        }
        catch (RtError &error)
        {
            _status = error.getType();
            develINFO_(_MIDI, "Error: " + error.getMessage());
            return {"unknown portname"};
        }
    }

    bool MidiOutPort
    ::try_open_port(unsigned int port_id_) noexcept
    {
        if(_out_port == nullptr)
        {
            _status = IS_DUMMY;
            return false;
        }


        try
        {
            _out_port->openPort(port_id_,_connection_name);
            _status = IS_OK;
            _was_one_time_open = true;
            return true;
        }
        catch (RtError &error)
        {
            _status = error.getType();
            develINFO_(_MIDI, "Error: " + error.getMessage());
            return false;
        }
    }

    bool MidiOutPort
    ::try_open_virtual_port() noexcept
    {
        if(_out_port == nullptr)
        {
            _status = IS_DUMMY;
            return false;
        }


        try
        {
            _out_port->openVirtualPort(_connection_name);
            _status = IS_OK;
            _was_one_time_open = true;
            return true;
        }
        catch (RtError &error)
        {
            _status = error.getType();
            develINFO_(_MIDI, "Error: " + error.getMessage());
            return false;
        }
    }

    void MidiOutPort
    ::try_close_port() noexcept
    {
        try
        {
            if(_out_port != nullptr)
                _out_port->closePort();

            _is_open = false;

            if(_was_one_time_open)
                _status = IS_NOT_PLUGGED;
            else
                _status = IS_NOT_OPEN;
        }
        catch (RtError &error)
        {
            develINFO_(_MIDI, "Error: " + error.getMessage());
            _status = error.getType();
        }
    }

    void MidiOutPort
    ::try_reopen_port(unsigned int new_port_id_) noexcept
    {
        _is_open = try_open_port(new_port_id_);
    }

    std::string MidiOutPort
    ::port_name() const noexcept
    {
        return _port_name;
    }

    std::string MidiOutPort
    ::status_port_name() const noexcept
    {
        std::string str_current_status;
        switch (_status)
        {
        case RtError::WARNING :
            str_current_status = str_WARNING;
            break;
        case RtError::DEBUG_WARNING :
            str_current_status = str_DEBUG_WARNING;
            break;
        case RtError::UNSPECIFIED :
            str_current_status = str_UNSPECIFIED;
            break;
        case RtError::NO_DEVICES_FOUND :
            str_current_status = str_NO_DEVICES_FOUND;
            break;
        case RtError::INVALID_DEVICE :
            str_current_status = str_INVALID_DEVICE;
            break;
        case RtError::MEMORY_ERROR :
            str_current_status = str_MEMORY_ERROR;
            break;
        case RtError::INVALID_PARAMETER :
            str_current_status = str_INVALID_PARAMETER;
            break;
        case RtError::INVALID_USE :
            str_current_status = str_INVALID_USE;
            break;
        case RtError::DRIVER_ERROR :
            str_current_status = str_DRIVER_ERROR;
            break;
        case RtError::SYSTEM_ERROR :
            str_current_status = str_SYSTEM_ERROR;
            break;
        case RtError::THREAD_ERROR :
            str_current_status = str_THREAD_ERROR;
            break;
        case IS_OK :
            str_current_status = str_IS_OK;
            break;
        case IS_NOT_PLUGGED :
            str_current_status = str_IS_NOT_PLUGGED;
            break;
        case IS_DUMMY :
            str_current_status = str_IS_DUMMY;
            break;
        case IS_NOT_OPEN :
            str_current_status = str_IS_NOT_OPEN;
            break;
        default:
            str_current_status = "UKnow";
            break;
        }

        return {str_current_status + ":" + _port_name};
    }

    bool MidiOutPort
    ::is_open() const noexcept
    {
        return _is_open;
    }

//!\class MidiOutPortsPerApi
    std::vector<RtMidi::Api> const MidiOutPortsPerApi::compiled_apis{get_compiled_apis()};
    std::map<RtMidi::Api, RtMidiOut*> MidiOutPortsPerApi::master_ports{};

    void MidiOutPortsPerApi
    ::attach_gui(MidiOutPortsPerApiGUIInterface* gui_) noexcept
    {
        _gui = gui_;
    }

    void MidiOutPortsPerApi
    ::detach_gui(MidiOutPortsPerApiGUIInterface* gui_) noexcept
    {
        _gui = nullptr;
    }

    std::vector<RtMidi::Api> MidiOutPortsPerApi
    ::get_compiled_apis() noexcept
    {
        std::vector<RtMidi::Api> compiled_apis;
        RtMidi::getCompiledApi(compiled_apis);
        return compiled_apis;
    }

    std::map<RtMidi::Api, RtMidiOut*> MidiOutPortsPerApi
    ::get_master_ports_per_api(std::vector<RtMidi::Api> const& compiled_apis_) noexcept
    {
        std::map<RtMidi::Api, RtMidiOut*> master_ports{};
        for(RtMidi::Api api : compiled_apis_)
        {
            try // Open the MasterPort
            {
                master_ports.insert({api,new RtMidiOut{api, str_CYTHAR_OUT_}});
            }
            catch (RtError &error)
            {
                develINFO_(_MIDI, "Error: " + lexical_cast<std::string>(error.getType()) + " :: make cythar out :: " + error.getMessage());
            }
        }
        return master_ports;
    }

#ifndef __WIN__
    void MidiOutPortsPerApi
    ::make_virtual_ports() noexcept
    {
        for(RtMidi::Api api : compiled_apis)
        {
            try // Make Ports to this Api
            {
                std::string virtual_connection_name{str_CYTHAR_VIRTUAL_CONNECTION_NAME + API_NAMES[api]};
                if(_midi_ports.find(virtual_connection_name) == _midi_ports.end())
                {
                    MidiOutPort* new_midi_out_port{new MidiOutPort{new RtMidiOut{api,
                                                                                 virtual_connection_name},
                                                                   api,
                                                                   virtual_connection_name}};

                    _midi_ports.insert({virtual_connection_name,
                                        new_midi_out_port});
                }
            }
            catch (RtError &error)
            {
                develINFO_(_MIDI, "Error: " + lexical_cast<std::string>(error.getType()) + " :: make virtual port :: " + error.getMessage());
            }
        }
    }
#endif // __WIN__

    void MidiOutPortsPerApi
    ::refresh_ports() noexcept
    {
        for(RtMidi::Api api : compiled_apis)
        {
            // Ermittelt alle derzeitig angeschlossenen Geräte dieser Api
            develINFO_(_MIDI, " ");
            develINFO_(_MIDI, "Plugged MIDI OUT Ports @ " + API_NAMES[api] + ":");
            develINFO_(_MIDI, "-------------------------------------");
            #define _PORT_ID_ second
            std::map<std::string,unsigned int> plugged_port_names{};
            for(unsigned int port_id{0} ; port_id < master_ports[api]->getPortCount() ; ++port_id)
            {
                try // Get Portname
                {
                    std::string plugged_port_name{master_ports[api]->getPortName(port_id)};
                    plugged_port_names.insert({plugged_port_name,port_id});
                    develINFO_(_MIDI, plugged_port_name);
                }
                catch (RtError &error)
                {
                    develINFO_(_MIDI, "Error: " + lexical_cast<std::string>(error.getType()) + " :: get port name :: " + error.getMessage());
                }
            }

            // Prüft ob bekannter Port noch immer angeschlossen
            develINFO_(_MIDI, " ");
            develINFO_(_MIDI, "check known ports...");
            std::string virtual_connection_name{str_CYTHAR_VIRTUAL_CONNECTION_NAME + API_NAMES[api]};
            for(auto known_midi_port_pair : _midi_ports)
            {

                // Virtual Port check
                if(virtual_connection_name == known_midi_port_pair.first)
                {
                    develINFO_(_MIDI, virtual_connection_name + " : virtual is still OK");
                }
                else
                {
                    // Plugged Port check
                    auto midi_port_that_is_still_plugged(plugged_port_names.find(known_midi_port_pair.first));
                    if(midi_port_that_is_still_plugged != plugged_port_names.end())
                    {
                        if(known_midi_port_pair.PORT->_api == api) //! Ignor other Api
                        {
                            if(known_midi_port_pair.PORT->is_open() == false)
                            {
                                known_midi_port_pair.PORT->try_reopen_port(midi_port_that_is_still_plugged->_PORT_ID_);
                                develINFO_(_MIDI, known_midi_port_pair.first + " : reopen - now OK");
                            }
                            else
                                develINFO_(_MIDI, known_midi_port_pair.first + " : is still OK");
                        }
                    }
                    // Known But not connected
                    else
                    {
                        if(known_midi_port_pair.PORT->_api == api) //! Ignor other Api
                        {

                            if(known_midi_port_pair.PORT->is_open() == true)
                            {
                                known_midi_port_pair.PORT->try_close_port();
                                develINFO_(_MIDI, known_midi_port_pair.first + " : closed - removed?");
                            }
                            else
                                develINFO_(_MIDI, known_midi_port_pair.first + " : is still removed?");
                        }
                    }
                }
            }

            develINFO_(_MIDI, " ");
            develINFO_(_MIDI, "add new ports...");
            // Scant RtMidi nach Port und vergleich ob diese breits bekannt sind, anderen Falls neu erstellen
            for(auto plugged_port_name : plugged_port_names)
            {
                try // Make Ports to this Api
                {
                    if(_midi_ports.find(plugged_port_name.first) == _midi_ports.end())
                    {
                        MidiOutPort* new_midi_out_port{new MidiOutPort{new RtMidiOut{api, str_CYTHAR_OUT_},
                                                                       api,
                                                                       plugged_port_name._PORT_ID_}};
                        _midi_ports.insert({plugged_port_name.first,
                                            new_midi_out_port});

                        develINFO_(_MIDI, plugged_port_name.first + " : added ");
                    }
                }
                catch (RtError &error)
                {
                    develINFO_(_MIDI, "Error: " + lexical_cast<std::string>(error.getType()) + " :: add port :: " + error.getMessage());
                }

            }
        }
        develINFO_(_MIDI, " ");
        develINFO_(_MIDI, "finish refresh MIDI OUT ports...");
        develINFO_(_MIDI, " ");

        #undef _PORT_ID_
    }

    auto MidiOutPortsPerApi
    ::begin() noexcept
        -> decltype(_midi_ports.begin())
    {
        return _midi_ports.begin();
    }

    auto MidiOutPortsPerApi
    ::end() noexcept
        -> decltype(_midi_ports.end())
    {
        return _midi_ports.end();
    }

    MidiOutPort* MidiOutPortsPerApi
    ::midi_out_port(std::string const& port_name_) const noexcept
    {
        auto port_pair(_midi_ports.find(port_name_));
        if(port_pair != _midi_ports.end())
            return port_pair->PORT;

        return _dummy_out_port;
    }

    MidiOutPort* MidiOutPortsPerApi
    ::midi_out_port(size_t index_) const noexcept
    {
        for(auto port_pair : _midi_ports)
        {
            if(index_ == 0)
                return port_pair.PORT;
            else
                --index_;

        }

        return _dummy_out_port;
    }

    bool MidiOutPortsPerApi
    ::is_port(std::string const& port_name_) const noexcept
    {
        auto port_pair(_midi_ports.find(port_name_));
        if(port_pair != _midi_ports.end())
            return true;

        return false;
    }

    void MidiOutPortsPerApi::try_send_continue() noexcept {try_send_to_all_open(&CONTINUE_MESSAGE);}
    void MidiOutPortsPerApi::try_send_start() noexcept {try_send_to_all_open(&START_MESSAGE);}
    void MidiOutPortsPerApi::try_send_stop() noexcept {try_send_to_all_open(&STOP_MESSAGE);}
    void MidiOutPortsPerApi::try_send_reset() noexcept {try_send_to_all_open(&RESET_MESSAGE);}
    void MidiOutPortsPerApi::try_send_panic() noexcept {try_send_to_all_open(&PANIC_MESSAGE);}
}
