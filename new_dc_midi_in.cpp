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

namespace dc_midi{

    static bool IS_MASTER{false};

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

    void rtmidi_callback(double, std::vector<unsigned char>* message, void*) noexcept;

    // Own Thread
    void interpret_midiin(unsigned char first_byte__) noexcept;
    void play_clicked() noexcept;
    void pause_clicked() noexcept;
    void stop_clicked() noexcept;
    void panic_clicked() noexcept;
    void reset_clicked() noexcept;

    void rtmidi_callback(double, std::vector<unsigned char>* message__, void*) noexcept
    {
        if( message__->size() > 0 and IS_MASTER == true )
        {
            cross_thread interpreter(interpret_midiin,(*message__)[0]);
            interpreter.join();
        }
    }

    void interpret_midiin(unsigned char first_byte__) noexcept
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

        for(auto rt_midi_in : _rtMidiInScanners)
        {
            try
            {
                rt_midi_in.second->cancelCallback();
                rt_midi_in.second->closePort();
                delete rt_midi_in.second;
            }
            catch (RtError &error)
            {
                develINFO_(_3ERR, error.getMessage());
            }
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
    }

    void MidiIn
    ::init() noexcept
    {
        set_master();

        try
        {
            std::vector<RtMidi::Api> Api;
            RtMidi::getCompiledApi(Api);

            // Erstelle einen outScanner je compiled API
            std::cout << "apis size" << Api.size() << std::endl;
            for(auto api : Api)
            {
                std::cout << rtmidi_api_names[api] << std::endl;
                _rtMidiInScanners[api] = new RtMidiIn(api, CYTHAR_MIDIINPORT_NAME + rtmidi_api_names[api]);
#ifdef __WIN__
                _fakeVirtualPort[api] = new RtMidiIn(api, CYTHAR_MIDIINPORT_NAME + rtmidi_api_names[api]);

                _rtMidiInScanners[api]->openVirtualPort("virtual midi input");
#elif
                _rtMidiInScanners[api]->openVirtualPort("virtual midi input");
#endif // __WIN__
                _rtMidiInScanners[api]->ignoreTypes( false, false, false );
                _rtMidiInScanners[api]->setCallback( &rtmidi_callback );
            }
        }
        catch (RtError &error)
        {
            develINFO_(_3ERR, error.getMessage());
        }
    }

    void play_clicked() noexcept
    {
        if(tmpGET_(IS_PAUSE) == true)
            tmpSET_(IS_PAUSE, false);

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
