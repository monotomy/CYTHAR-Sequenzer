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

#include <dc_midi_in.h>

#include <signal.h>

#include <crossplatt_threading.hpp>

#include <gm_midistandard.h>

#include <dc_ticker_generator.h>

#include <pattern/singleton.hpp>

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

    void rtmidi_callback(double, std::vector<uint8_t>* message__, void*) noexcept
    {
        if( message__->size() > 0 and IS_MASTER == false )
        {
            cross_thread interpreter(interpret_midiin,(*message__)[0]);
            interpreter.join();
        }
    }

    void interpret_midiin(uint8_t first_byte__) noexcept
    {
        using namespace gm_standard;

            switch(first_byte__)
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
            default:
                break;
            }
    }

    MidiIn
    ::~MidiIn() noexcept
    {
        DCTOR_LOGFILE_DEBUG_(MidiIn);
    }

    void MidiIn
    ::shut_down() noexcept
    {
        close_in_port();
        try
        {
            if(midi_in_master_port != nullptr)
                delete midi_in_master_port;
        }
        catch(...)
        {
            develINFO_(_MIDI, "Error: clean master in port");
        }
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
    }

    void MidiIn
    ::start_reciving() noexcept
    {
        open_in_port(_last_port);
    }

    void MidiIn
    ::stop_reciving() noexcept
    {
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
            midi_in_master_port = new RtMidiIn(_rtmidi_api, str_CYTHAR_IN_);
        }
        catch (RtError &error)
        {
            develINFO_(_3ERR, error.getMessage());
        }

        set_master();
    }

    void MidiIn
    ::open_in_port(unsigned int port_id__) noexcept
    {
        _last_port = port_id__;
        try
        {
                close_in_port();
                rtMidiIn = new RtMidiIn(_rtmidi_api, str_CYTHAR_IN_);


            std::string in_port_name{};
#ifndef __WIN__
                if(port_id__ == VIRTUAL_IN_PORT)
                {
                    rtMidiIn->ignoreTypes( false, false, false );
                    rtMidiIn->setCallback( &rtmidi_callback );
                    rtMidiIn->openVirtualPort(str_CYTHAR_VIRTUAL_IN_);
                    return;
                }
                else
#endif // __WIN__
                {
#ifndef __WIN__
                    port_id__ -= 1;
#endif // __WIN__
                    in_port_name = in_port_name = midi_in_master_port->getPortName(port_id__);
                    in_port_name += str_AT_CYTHAR_IN_;

                    rtMidiIn->ignoreTypes( false, false, false );
                    rtMidiIn->setCallback( &rtmidi_callback );
                    rtMidiIn->openPort(port_id__, in_port_name);
                }

        }
        catch (RtError &error)
        {
            develINFO_(_3ERR, error.getMessage());
        }
    }

    void MidiIn
    ::close_in_port() noexcept
    {
        try
        {
            if(rtMidiIn != nullptr)
            {
                rtMidiIn->cancelCallback();
                rtMidiIn->closePort();
#ifndef __UNIX_JACK__
                //! Jack stürzt ab bei Portlöschung
                delete rtMidiIn;
                rtMidiIn = nullptr;
#endif // __UNIX_JACK__
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
#ifndef __WIN__
        plugged_in_ports.push_back(str_CYTHAR_VIRTUAL_IN_);
#endif // __WIN__
        try
        {
            for(unsigned int port_id_{0} ; port_id_!=midi_in_master_port->getPortCount() ; ++port_id_ )
                plugged_in_ports.push_back(midi_in_master_port->getPortName(port_id_));
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
        open_in_port(port_id__);
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
        dc_midi::MidiOutPortsPerApi::singleton()->try_send_panic();
        dc_midi::MessageStack<dc_midi::StaticAccess>::clean_all();
        dc_midi::Timers::reset_all_taktchain();
    }

    void reset_clicked() noexcept
    {
        dc_midi::Sequencer::singleton()->reset();
    }

    void panic_clicked() noexcept
    {
        dc_midi::MidiOutPortsPerApi::singleton()->try_send_panic();
    }
}
