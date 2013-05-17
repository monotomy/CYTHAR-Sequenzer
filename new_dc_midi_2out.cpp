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

#include <dc_midi_2out.h>

#include <dc_midi_message.h>

#include <vector>
#include <string>

#include <dc_log_informations.h>

namespace dc_midi{

//!\class MidiOut
    MidiOut
    ::MidiOut() noexcept
    {
    }

    static const std::vector<std::string> rtmidi_api_names
    {
        "UNSPECIFIED",
        "MACOSX_CORE",
        "LINUX_ALSA",
        "UNIX_JACK",
        "WINDOWS_MM",
        "WINDOWS_KS",
        "RTMIDI_DUMMY"
    };

    void MidiOut
    ::init() noexcept
    {
        try
        {
            std::vector<RtMidi::Api> Api;
            RtMidi::getCompiledApi(Api);

            // Erstelle einen outScanner je compiled API
            std::cout << "apis size" << Api.size() << std::endl;
            for(auto api : Api)
            {
                std::cout << rtmidi_api_names[api] << std::endl;
                _rtMidiOutScanners[api] = new RtMidiOut(api, CYTHAR_MIDIOUTPORT_NAME + rtmidi_api_names[api]);
                _rtMidiOutScanners[api]->openVirtualPort("virtual midi output");
            }
        }
        catch (RtError &error)
        {
            develINFO_(_3ERR, error.getMessage());
        }
    }

    MidiOut
    ::~MidiOut() noexcept
    {
        DCTOR_LOGFILE_DEBUG_(MidiOut);
        send_stop();
        send_panic();

        clear_plugged_devices();

        for(auto rtmidiout : _rtMidiOutScanners)
        {
            try
            {
                rtmidiout.second->closePort();
                delete rtmidiout.second;
            }
            catch (RtError &error)
            {
                develINFO_(_3ERR, error.getMessage());
            }
        }

    }

    void MidiOut
    ::clear_plugged_devices() noexcept
    {
        for(auto plugged_device : _plugged_devices)
        {
            try
            {
                plugged_device.second->closePort();
                delete plugged_device.second;
            }
            catch (RtError &error)
            {
                develINFO_(_3ERR, error.getMessage());
            }
        }

        _plugged_devices.clear();
    }

    void MidiOut
    ::refresh() noexcept
    {
        refresh_all();
    }

    void MidiOut
    ::refresh_all() noexcept
    {
        auto midi_device_database(selOBS_(this_selMIDI_DEVICEDATABASE_OBSERVER));
        try
        {
            // Do for Compiled apis
            std::vector<std::string> yet_plugged_devicenames{};
            for(auto rt_midi_out_scanner_to_api : _rtMidiOutScanners)
            {
                auto api(rt_midi_out_scanner_to_api.first);
                auto rtmidi_out_scanner(rt_midi_out_scanner_to_api.second);

                // Setup plugged
                for(decltype(rtmidi_out_scanner->getPortCount()) port{0};
                    port < rtmidi_out_scanner->getPortCount();
                    ++port)
                {
                    std::string out_port_name{rtmidi_out_scanner->getPortName(port)};
                    if(out_port_name.find("CYTHAR") != std::string::npos)   // Dont add cythar ports
                        continue;

                    yet_plugged_devicenames.push_back(out_port_name);
                    // Scannt angeschlossene Geräte
                    if( _plugged_devices.find(port) == _plugged_devices.end() )
                    {
                        RtMidiOut* rtMidiOut{new RtMidiOut{api, CYTHAR_MIDIOUTPORT_NAME}};
                        auto device(get_open_port(port, rtMidiOut));
                        if( device != nullptr )
                        {
                            _plugged_devices[port] = device;

                            std::string device_name(device->getPortName(port));
                            auto stored_device_to_name(midi_device_database->find_child_with<MIDI_DevicePropertiesIndex::DEVICE_NAME>(device_name));
                            if(stored_device_to_name != nullptr)
                            {
                                // Config known plugged
                                stored_device_to_name->set_property<MIDI_DevicePropertiesIndex::LAST_PORT>(port);
                                stored_device_to_name->set_property<MIDI_DevicePropertiesIndex::IS_PLUGGED_YET>(true);
                            }
                            else
                            {
                                // Add plugged
                                auto new_device_in_db(midi_device_database->make_back_get());
                                new_device_in_db->set_property<MIDI_DevicePropertiesIndex::DEVICE_NAME>(device_name);
                                new_device_in_db->set_property<MIDI_DevicePropertiesIndex::LAST_PORT>(port);
                                new_device_in_db->set_property<MIDI_DevicePropertiesIndex::IS_PLUGGED_YET>(true);
                            }
                        }
                        else
                        {
                            // Entfernen
                            if( _plugged_devices.find(port) != _plugged_devices.end() )
                                _plugged_devices.erase(_plugged_devices.find(port));

                            auto stored_device_to_name(midi_device_database->find_child_with<MIDI_DevicePropertiesIndex::LAST_PORT>(port));
                            if(stored_device_to_name != nullptr)
                                stored_device_to_name->set_property<MIDI_DevicePropertiesIndex::IS_PLUGGED_YET>(false);
                        }
                    }
                }
            }

            // Remove unplugged
            for(auto devicepair_in_database : *midi_device_database)
            {
                auto device_in_database(devicepair_in_database._DEVICE);
                auto device_name(device_in_database->get_property<MIDI_DevicePropertiesIndex::DEVICE_NAME>());
                size_t hit{false};
                for(auto yet_plugged_name : yet_plugged_devicenames)
                    if(yet_plugged_name == device_name)
                        ++hit;

                if(hit == false)
                    device_in_database->set_property<MIDI_DevicePropertiesIndex::IS_PLUGGED_YET>(false);
                #ifdef DEBUG
                else if(hit > 1)
                        std::cout << "BUG: More than one Device with the same name in Database" << std::endl;
                #endif // DEBUG
            }
        }
        catch (RtError &error)
        {
            develINFO_(_3ERR, error.getMessage());
        }
    }

    RtMidiOut* MidiOut
    ::get_open_port(unsigned int port_number__, RtMidiOut* rtMidiOut__) noexcept
    {
        try
        {
            std::string temp_port_name = rtMidiOut__->getPortName(port_number__);
            std::string connection_name{any2string(port_number__)
                                        + CYTHAR_CONNECTION_NAME
                                        + temp_port_name};

            rtMidiOut__->openPort(port_number__, connection_name);

            return rtMidiOut__;
        }
        catch (RtError &error)
        {
            develINFO_(_3ERR, error.getMessage());
            return nullptr;
        }
    }

    void MidiOut
    ::send_continue() noexcept
    {
        send_message_to_all(&CONTINUE_MESSAGE);
        develINFO_(SEND, "continue")
    }

    void MidiOut
    ::send_start() noexcept
    {
        send_message_to_all(&START_MESSAGE);
        develINFO_(SEND, "start")
    }

    void MidiOut
    ::send_stop() noexcept
    {
        send_message_to_all(&STOP_MESSAGE);
        develINFO_(SEND, "stop")
    }

    void MidiOut
    ::send_reset() noexcept
    {
        send_message_to_all(&RESET_MESSAGE);
        develINFO_(SEND, "reset")
    }

    void MidiOut
    ::send_panic() noexcept
    {
        for(unsigned int channel{0} ; channel != 16 ; ++channel )
        {
            TYPE_pure_midi_message panic_message_per_channel{PANIC_MESSAGE};
            panic_message_per_channel[0] += channel;
            send_message_to_all(&panic_message_per_channel);
        }

        develINFO_(SEND, "panic")
    }
}   /// EO namespace dc_midi
