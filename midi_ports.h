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

#ifndef MIDI_PORTS_H_INCLUDED
#define MIDI_PORTS_H_INCLUDED

#include <string>
#include <map>
#include <array>

#include <cast/lexical_cast.hpp>

#include <rtmidi-2.0.1/RtMidi.h>

#include <pattern/singleton.hpp>

#include <dc_log_informations.h>

#include <gm_midistandard.h>


namespace dc_midi{

    typedef std::vector<uint8_t> TYPE_midi_message;

    std::string const str_CYTHAR_OUT_ = "CYTHAR OUT";
    std::string const str_CYTHAR_OUT_AT_ = "CYTHAR OUT @ ";
    std::string const str_CYTHAR_VIRTUAL_CONNECTION_NAME = "CYTHAR Virtual OUT @ ";

    std::string const str_WARNING{"errWARN"};
    std::string const str_DEBUG_WARNING{"errDb-Ok"};
    std::string const str_UNSPECIFIED{"errUknw"};
    std::string const str_NO_DEVICES_FOUND{"errNDFo"};
    std::string const str_INVALID_DEVICE{"errInvD"};
    std::string const str_MEMORY_ERROR{"errMem"};
    std::string const str_INVALID_PARAMETER{"errPara"};
    std::string const str_INVALID_USE{"errIUse"};
    std::string const str_DRIVER_ERROR{"errDriv"};
    std::string const str_SYSTEM_ERROR{"errSys"};
    std::string const str_THREAD_ERROR{"errThre"};
    std::string const str_IS_OK{"OK"};
    std::string const str_REMOVED_ERROR{"errRemv"};
    std::string const str_IS_NOT_OPEN{"errClos"};
    std::string const str_IS_NOT_PLUGGED{"errUnpl"};
    std::string const str_IS_DUMMY{"Dummy"};
    /*!
    enum Api {
        UNSPECIFIED,    !< Search for a working compiled API.
        MACOSX_CORE,    !< Macintosh OS-X Core Midi API.
        LINUX_ALSA,     !< The Advanced Linux Sound Architecture API.
        UNIX_JACK,      !< The Jack Low-Latency MIDI Server API.
        WINDOWS_MM,     !< The Microsoft Multimedia MIDI API.
        WINDOWS_KS,     !< The Microsoft Kernel Streaming MIDI API.
        RTMIDI_DUMMY    !< A compilable but non-functional API.
    };
    */

    static const std::array<std::string, 7> API_NAMES{{
                                                       {"UNSPECIFIED"},
                                                       {"MACOSX_CORE"},
                                                       {"LINUX_ALSA"},
                                                       {"UNIX_JACK"},
                                                       {"WINDOWS_MM"},
                                                       {"WINDOWS_KS"},
                                                       {"RTMIDI_DUMMY"}
                                                      }};

    /***********************************************************************/
    /*! \class  MidiOutPort

        Wrapper für Midi Out Ports
    */
    /***********************************************************************/
    typedef int TYPE_RtError;
    enum RtError_extended : TYPE_RtError
    {
        /*! RtErrors in 2.0.1
            enum Type
            {
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
            };
        */

        IS_OK = 31, // Place for 20 new RtErrors
        IS_DUMMY,
        IS_NOT_PLUGGED,
        IS_NOT_OPEN,
        IS_REMOVED
    };

    class MidiOutPortsPerApi;
    class MidiOutPort final
    {
        RtMidiOut*const _out_port{nullptr};
        bool _is_send_clock{false};

        RtMidi::Api const _api;

        std::string _port_name{};
        std::string _connection_name{};

        bool _is_open{false};
        bool _was_one_time_open{false};

        TYPE_RtError _status{RtError::UNSPECIFIED};

        //! Standard Initialisierung
        friend class MidiOutPortsPerApi;
        MidiOutPort(RtMidiOut*const out_port_,
                    RtMidi::Api api_,
                    unsigned int port_id_) noexcept;

        //! Initialisierung für Id-lose virtuellen Ports
        MidiOutPort(RtMidiOut*const out_port_,
                    RtMidi::Api api_,
                    std::string connection_string_at_api_) noexcept;
        MidiOutPort() = delete;

        //! Liest den Portnamen aus
        std::string try_get_port_name(unsigned int port_id_) noexcept;
        //! Versucht den Port zu öffnen
        bool try_open_port(unsigned int port_id_) noexcept;
        //! Versucht einen virtuellen Port zu öffnen
        bool try_open_virtual_port() noexcept;

        //! Versucht den Port zu schliessen
        void try_close_port() noexcept;
        //! Öffnet den Port erneut
        void try_reopen_port(unsigned int new_port_id_) noexcept;

        ~MidiOutPort() noexcept;
    public:
        //! Name des Ports
        std::string port_name() const noexcept;
        //! Status und Name des Ports
        std::string status_port_name() const noexcept;
        //! Ist der Port derzeit geöffnet?
        bool is_open() const noexcept;
        TYPE_RtError status() const noexcept {return _status;}

    private:
        //! Sendet eine Nachricht an den Port und gibt eine Statusmeldung zurück
        inline TYPE_RtError try_send_message(TYPE_midi_message* message_) noexcept;

        inline void send_clock() noexcept {}
        void send_continue() noexcept {}
        void send_start() noexcept {}
        void send_stop() noexcept {}
        void send_reset() noexcept {}
        void send_panic() noexcept {}
    };

    /***********************************************************************/
    /*! \class  MidiOutPortsPerApi

        Verwaltung der Ports, zugriff für Clienten.
    */
    /***********************************************************************/
    class MidiOutPortsPerApi;
    class MidiOutPortsPerApiGUIInterface
    {
    protected:
        MidiOutPortsPerApiGUIInterface() = default;
        ~MidiOutPortsPerApiGUIInterface() = default;
    private:
        friend class MidiOutPortsPerApi;
        virtual void notify_refreshed_ports() noexcept = 0;
    };
    class MidiOutPortsPerApi final
    {
    SINGLETON(MidiOutPortsPerApi)

        MidiOutPortsPerApiGUIInterface* _gui{nullptr};

    public:
        void attach_gui(MidiOutPortsPerApiGUIInterface* gui_) noexcept;
        void detach_gui(MidiOutPortsPerApiGUIInterface* gui_) noexcept;
/// TODO Cleanup, Error management
/// Refresh - Prüfen ob devices noch angeschlossen
/// -> ports still legen, evtl wiederbeleben.

        static std::vector<RtMidi::Api> const compiled_apis;
        static std::map<RtMidi::Api, RtMidiOut*> master_ports;

        std::map<std::string,MidiOutPort*> _midi_ports{};
        #define PORT second

        // Ignorierender Port
        MidiOutPort*const _dummy_out_port{new MidiOutPort{nullptr, RtMidi::Api::UNSPECIFIED, 0}};

        //! Ermittelt die kompilierten Api's
        static std::vector<RtMidi::Api> get_compiled_apis() noexcept;

        //! Erstellt je Api einen Master Port
        static std::map<RtMidi::Api, RtMidiOut*> get_master_ports_per_api(std::vector<RtMidi::Api> const& compiled_apis_) noexcept;

#ifndef __WIN__
        //! Erstellt virtuelle Ports je Api
        void make_virtual_ports() noexcept;
#endif // __WIN__

    public:
        //! Initalisiert virtuelle Ports und erstellt Ports
        void init() noexcept
        {
///RETURN_IF_ALLREADY_INIT

            master_ports = get_master_ports_per_api(compiled_apis);
#ifndef __WIN__
            make_virtual_ports();
#endif // __WIN__
            refresh_ports();
        }

        //! Erstellt zu jedem Gefundenen Gerät einen MidiOutPort
        //! und legt diese in _midi_ports ab.
        void refresh_ports() noexcept;

        //! Iteration der Ports
        auto begin() noexcept -> decltype(_midi_ports.begin());
        auto end() noexcept -> decltype(_midi_ports.end());
        size_t size() const noexcept { return _midi_ports.size();}

        //! Zugriff auf einen Port
        MidiOutPort* midi_out_port(std::string const& port_name_) const noexcept;
        MidiOutPort* midi_out_port(size_t index_) const noexcept;

        //! Rückgabe true, wenn das gerät angeschlossen ist
        bool is_port(std::string const& port_name_) const noexcept;

        //! Sendet eine MidiMessage zum Port
        inline void try_send_message(TYPE_midi_message* message_,
                                     std::string const& port_name_) noexcept;

    private:
        //! Standard Befehle
        TYPE_midi_message CLOCK_MESSAGE{TYPE_midi_message{gm_standard::TIMING_CLOCK}};
        TYPE_midi_message CONTINUE_MESSAGE{TYPE_midi_message{gm_standard::CONTINUE}};
        TYPE_midi_message START_MESSAGE{TYPE_midi_message{gm_standard::START}};
        TYPE_midi_message STOP_MESSAGE{TYPE_midi_message{gm_standard::STOP}};
        TYPE_midi_message RESET_MESSAGE{TYPE_midi_message{gm_standard::RESET}};
        TYPE_midi_message PANIC_MESSAGE{TYPE_midi_message{{gm_standard::CONTROL_CHANGE},{gm_standard::ALL_NOTES_OFF},{0}}};
    public:
        //! Kill die Ports
        void shut_down() noexcept
        {
            // Clean Ports
            for(auto port : _midi_ports)
            {
                try
                {
                    if(port.PORT != nullptr)
                        delete port.PORT;
                }
                catch(...)
                {
                    develINFO_(_MIDI, "Error: clean out port: " + port.first);
                }
            }

            // Clean Master Ports
            for(auto master_port : master_ports)
            {
                try
                {
                    if(master_port.PORT != nullptr)
                        delete master_port.PORT;
                }
                catch(...)
                {
                    develINFO_(_MIDI, "Error: clean master out port");
                }
            }
        }

        //! Senden von nachrichten an alle Ports, welche diese für diese option aktivert sind
        inline void try_send_clock() noexcept;
        void try_send_continue() noexcept;
        void try_send_start() noexcept;
        void try_send_stop() noexcept;
        void try_send_reset() noexcept;
        void try_send_panic() noexcept;
    private:
        //! Versucht eine Nachricht an alle Ports zu übermitteln
        inline void try_send_to_all_open(TYPE_midi_message* message_) noexcept;

    private:
        //! Interpretiert den Status und handelt entsprechend
        inline void send_status_handler(TYPE_RtError error_, std::string const& port_) noexcept;
    };
}

#include "midi_ports.hpp"

#endif // MIDI_PORTS_H_INCLUDED
