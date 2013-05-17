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

#ifndef CYTHAR_SEQUENCER_SEQUENCER_H_INCLUDED
#define CYTHAR_SEQUENCER_SEQUENCER_H_INCLUDED

#include <pattern/singleton.hpp>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

namespace dc_midi{

    using namespace dc_objects;

    /**********************************************************************/
    /*! \class Sequencer
        \brief Positionszähler & Mutetimer Inhaber
    */
    /**********************************************************************/
    class Sequencer final :
        public SelectedSequencerObserver_V2
    {
    SINGLETON_ownCTOR(Sequencer)

        typedef SelectedSequencerObserver_V2 this_selSEQUENCER_OBSERVER;

        Sequencer() noexcept;

        //! Berechnet die Masterpositionen und informiert Timers
        inline void calc_positions() noexcept;
        static uint8_t count_pos_clock;

    public:
        //! Call für den Ticker um berechnung auszulösen.
        inline void precalculate_next_positions() noexcept;

        //! Nullung der Maserpositionen
        void reset() noexcept;
    };
}

#include <dc_midi_sequencer.hpp>

#endif // CYTHAR_SEQUENCER_SEQUENCER_H_INCLUDED
