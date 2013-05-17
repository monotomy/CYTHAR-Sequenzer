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

#ifndef DC_MIDI_MESSAGEHANDELS_H_INCLUDED
#define DC_MIDI_MESSAGEHANDELS_H_INCLUDED

#include <gm_midistandard.h>

#include <stdint.h>

#include <class/properties.hpp>
#include <pattern/singleton.hpp>

#include <vector>
#include <set>

#include <loki/TypeManip.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

namespace dc_midi{

    using namespace dc_objects;

    /***********************************************************************/
    /*! \class  NoteMessage
        \brief
    */
    /***********************************************************************/
    class UNIQUE_DELAY_STACK{};
    class UNIQUE_READY_STACK{};
    class UNIQUE_RUNNING_STACK{};
    class UNIQUE_OVER_STACK{};

    typedef std::vector<uint8_t> TYPE_pure_midi_message_data;
    class NoteMessage
    {
    NO_COPY_NO_MOVE(NoteMessage)

        std::string _port_name;

        TYPE_pure_midi_message_data _start_message;
        TYPE_pure_midi_message_data _end_message;

        //! Ist entweder die _start_message oder _end_message
        TYPE_pure_midi_message_data* _aktive_message;

        TYPE_lengthy _livetime;
        bool const _is_endless;
        TYPE_lengthy _delay;

    public:
        //! Berechnung der Start und Endnachricht, selbstablage auf dem Ready Stack
        NoteMessage(TYPE_note note__,
                    TYPE_velocity velocity__,
                    TYPE_lengthy length__,
                    bool is_endless__,
                    std::string  const& _port_name,
                    TYPE_midi_channel channel__,
                    TYPE_lengthy delay__ = 0,
                    uint8_t start_byte__ = gm_standard::GM_1st::NOTE_ON,
                    uint8_t end_byte__ = gm_standard::GM_1st::NOTE_OFF) noexcept;

        ~NoteMessage() noexcept = default;

    private:
        //! Setzt sich auf den Ready stack
        void push_to_ready_stack() noexcept;
    public:
        //! Stackorganisation
        void precalculate_you(Loki::Type2Type<UNIQUE_DELAY_STACK>) noexcept;
        void precalculate_you(Loki::Type2Type<UNIQUE_READY_STACK>) noexcept;
        void precalculate_you(Loki::Type2Type<UNIQUE_RUNNING_STACK>) noexcept;
        void precalculate_you(Loki::Type2Type<UNIQUE_OVER_STACK>) noexcept;
        void clean_up() noexcept;
    private:
        //! Verschiebt sich auf den Running stack
        void switch_to_running_stack() noexcept;
        //! Ändert die aktive Nachricht
        void change_active_message_to(TYPE_pure_midi_message_data*const) noexcept;
        //! Verschiebt sich auf den Over stack
        void switch_to_over_stack() noexcept;
    public:
        //! Sendet die Start oder EndMessage je nach bedarf
        inline void send_your_message() noexcept;

        inline void send_your_STOP_message() noexcept;
    };

    /***********************************************************************/
    /*! \class  MessageStack
        \brief
    */
    /***********************************************************************/
    class StaticAccess{};
    template<class UNIQUE_STACK_TYPE>
    class MessageStack
    {
    SINGLETON(MessageStack)

        friend class MessageStack<StaticAccess>;
        std::set<NoteMessage*> _message_stack{};

    public:
        //! Informiert alle Messages auf dem Stack
        void precalculate_stack() noexcept;
        inline void critical_send_stack() noexcept;
        static void clean_all() noexcept;

    private:
        friend class NoteMessage;
        void attach_message(NoteMessage*const message__) noexcept;
        void detach_message(NoteMessage*const message__) noexcept;
    };
}

#include <dc_midi_message.hpp>

#endif // DC_MIDI_MESSAGEHANDELS_H_INCLUDED
