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

#ifndef DC_MIDI_IN_H_INCLUDED
#define DC_MIDI_IN_H_INCLUDED

#include <pattern/singleton.hpp>
#include <cast/lexical_cast.hpp>

#include <string>
#include <vector>

#include <rtmidi-2.0.1/RtMidi.h>    /// version 2.0.1

#include <dc_log_informations.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

namespace dc_midi{

    using namespace dc_objects;

    class MidiIn final :
        public SelecteddetailProjectObserver_V2
    {
    SINGLETON_foo(MidiIn)

        MidiIn() noexcept = default;
        ~MidiIn() noexcept;

        typedef SelecteddetailProjectObserver_V2    this_dtlPROJECT_OBSERVER;

        std::string const CYTHAR_MIDIINPORT_NAME = "CYTHAR IN";
        std::string const CYTHAR_CONNECTION_NAME = " @ CYTHAR";

        RtMidiIn* rtMidiInScanner;

        RtMidiIn* rtMidiIn{nullptr};        // Lesegerrät
        RtMidi::Api _rtmidi_api;

        //! Master oder Nicht? -> start oder stop reciving
        virtual void property_changed(AT_(Project,IS_MASTER)) noexcept;
        void set_master() noexcept;

        void midi_in_reciver() noexcept;

        //! Setzt Callback und öffnet Port
        void start_reciving() noexcept;
        //! Startet ThreadLoop für MidiIn
        unsigned int _last_port{0}; // Cache
        void start_reciver_thread_at_port(unsigned int port_id__ = 0) noexcept;

        //! Schliest Port und entfernt Callback
        void stop_reciving() noexcept;


        //! Schlies Leseport
        void close_in_port() noexcept;

    public:
        void init() noexcept;

        //! Liste aller lesbaren Geräte
        std::vector<std::string> get_port_list() noexcept;

        //! Setzt die Id des zu öffnenden Ports
        void change_port_id(unsigned int) noexcept;
        unsigned int port_id() const noexcept;
    };
}

#endif // DC_MIDI_IN_H_INCLUDED
