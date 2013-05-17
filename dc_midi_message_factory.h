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

#ifndef CYTHAR_SEQUENCER_MIDIOUT_FACTORY_H_INCLUDED
#define CYTHAR_SEQUENCER_MIDIOUT_FACTORY_H_INCLUDED

#include <pattern/singleton.hpp>

#include <dc_midi_message.h>
#include <dc_midi_sequencer_timer.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

namespace dc_midi{

    /**********************************************************************/
    /*! \class MIDI_MessageFactory
        \brief
    */
    /**********************************************************************/
    class MessageFactory :
        public SelecteddetailSequencerObserver_V2,
        public SelectedProjectObserver_V2
    {
    SINGLETON(MessageFactory)

    public:
        void init() noexcept {}
    private:

        typedef SelecteddetailSequencerObserver_V2  this_dtlSEQUENCER_OBSERVER;
        typedef SelectedProjectObserver_V2          this_selPROJECT_OBSERVER;


    public:
        //! Erstellt neue Messages bei neuen Steps
        inline void make_messages_to_sequencer_positions() const;
    };
}

#include <dc_midi_message_factory.hpp>

#endif  /// CYTHAR_SEQUENCER_MIDIOUT_FACTORY_H_INCLUDED
