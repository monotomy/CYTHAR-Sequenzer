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

#ifndef DC_APPXMIDI_RECTOR_H_INCLUDED__
#define DC_APPXMIDI_RECTOR_H_INCLUDED__

#include <pattern/singleton.hpp>
#include <cast/any2string.hpp>


#include <rtmidi-2.0.1/RtMidi.h>    /// version 2.0.1

#include <map>
#include <vector>
#include <string>

#include <gm_midistandard.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

#include <crossplatt_threading.hpp>

namespace dc_midi{

    using namespace dc_objects;

    typedef std::vector<unsigned char> TYPE_pure_midi_message;

    std::string const CYTHAR_MIDIOUTPORT_NAME       = "CYTHAR ";
    std::string const CYTHAR_CONNECTION_NAME        = " CYTHAR @ ";

    static TYPE_pure_midi_message CLOCK_MESSAGE{TYPE_pure_midi_message{gm_standard::TIMING_CLOCK}};
    static TYPE_pure_midi_message CONTINUE_MESSAGE{TYPE_pure_midi_message{gm_standard::CONTINUE}};
    static TYPE_pure_midi_message START_MESSAGE{TYPE_pure_midi_message{gm_standard::START}};
    static TYPE_pure_midi_message STOP_MESSAGE{TYPE_pure_midi_message{gm_standard::STOP}};
    static TYPE_pure_midi_message RESET_MESSAGE{TYPE_pure_midi_message{gm_standard::RESET}};
    static TYPE_pure_midi_message PANIC_MESSAGE{TYPE_pure_midi_message{{gm_standard::CONTROL_CHANGE},{gm_standard::ALL_NOTES_OFF},{0}}};

    class MidiClock;    //! CLOCK-BAD-HACK - Remove from this class!
    class MidiOut final:
        public SelectedMIDI_DeviceDatabaseObserver_V2
    {
    SINGLETON_foo(MidiOut)

        cross_mutex mutex_only_one_thread_send{};

        typedef SelectedMIDI_DeviceDatabaseObserver_V2 this_selMIDI_DEVICEDATABASE_OBSERVER;

        RtMidiOut* rtMidiOutScanner;
        std::map<RtMidi::Api,RtMidiOut*> _rtMidiOutScanners;
        std::map<RtMidi::Api,RtMidiOut*> _rtMidiOutVirtualPorts;

        RtMidiOut* rtMidiOutVirtual;

        RtMidi::Api _rtmidi_api;
        std::map<size_t,RtMidiOut*> _plugged_devices{};

        MidiOut() noexcept;
    public:
        void init() noexcept;
    private:
        ~MidiOut() noexcept;

        void clear_plugged_devices() noexcept;
        void refresh_all() noexcept;
        RtMidiOut* get_open_port(unsigned int port_number__, RtMidiOut*) noexcept;

    public:
        void refresh() noexcept;

        inline void send_clock() noexcept;
        void send_continue() noexcept;
        void send_start() noexcept;
        void send_stop() noexcept;
        void send_reset() noexcept;
        void send_panic() noexcept;

        inline void send_message_to_all(TYPE_pure_midi_message*message__) noexcept;
        inline void send_message(TYPE_pure_midi_message*message__, TYPE_midi_port port_number__) noexcept;
    };
}

#include <dc_midi_2out.hpp>

#endif // DC_APPXMIDI_RECTOR_H_INCLUDED
