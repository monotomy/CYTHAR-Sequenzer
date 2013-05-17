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

#ifndef DC_MIDI_SEQUENCER_HPP_INCLUDED
#define DC_MIDI_SEQUENCER_HPP_INCLUDED

#include <dc_midi_sequencer_timer.h>

namespace dc_midi{

//!\class Sequencer
    inline void Sequencer
    ::precalculate_next_positions() noexcept
    {
        calc_positions();
    }

    inline void Sequencer
    ::calc_positions() noexcept
    {
        static auto sequencer(selOBS_(this_selSEQUENCER_OBSERVER));
        if(count_pos_clock != GM_clock_per_takt-1)
        {
            ++count_pos_clock;
            if(count_pos_clock%GM_clock_per_step == 0)
            {
                auto pos_step(sequencer->get_property<SequencerPropertiesIndex::STEP_POS>());
                ++pos_step;
                sequencer->set_property<SequencerPropertiesIndex::STEP_POS>(pos_step);
            }
            sequencer->set_property<SequencerPropertiesIndex::CLOCK_POS>(count_pos_clock);
        }
        else
        {
            count_pos_clock = 0;

            auto pos_takt(sequencer->get_property<SequencerPropertiesIndex::TAKT_POS>());
            ++pos_takt;
            if(pos_takt == Takt_per_Pattern)
                pos_takt = 0;

            // Timers wird bevorzugt, da nachfolgende Observer auf der Timers Position
            // beruhen können
            Timers::notify_new_takt_pos(pos_takt);

            // Abhängige observer nach Timers
            sequencer->set_property<SequencerPropertiesIndex::CLOCK_POS>(count_pos_clock);
            sequencer->set_property<SequencerPropertiesIndex::STEP_POS>(0);
            sequencer->set_property<SequencerPropertiesIndex::TAKT_POS>(pos_takt);
        }
    }
}

#endif // DC_MIDI_SEQUENCER_HPP_INCLUDED
