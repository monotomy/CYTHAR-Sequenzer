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

#include <dc_midi_sequencer.h>

namespace dc_midi{

    unsigned char Sequencer::count_pos_clock{0};

//!\class Sequencer
    Sequencer
    ::Sequencer() noexcept
    {}

    void Sequencer
    ::reset() noexcept
    {
        selSET_(this_selSEQUENCER_OBSERVER, CLOCK_POS, 0);
        selSET_(this_selSEQUENCER_OBSERVER, STEP_POS, 0);
        selSET_(this_selSEQUENCER_OBSERVER, TAKT_POS, 0);
        count_pos_clock = 0;
    }
}
