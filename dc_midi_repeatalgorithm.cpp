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

#include <dc_midi_repeatalgorithm.h>


namespace dc_midi
{

//! \class RepeatAlgorithm
    int RepeatAlgorithm
    ::manipulate(int, size_t, int) noexcept
    {
        /*
        switch (Manipulator)
        {
        case calcNOT:   return l_value__;
            break;

        case calcPLUS:  return l_value__+r_value__;
            break;

        case calcMINUS: return l_value__-r_value__;
            break;

        case calcMULTI: return l_value__*r_value__;
            break;

        case calcDIV:
            if( r_value__ !=0 )
                return l_value__/r_value__;
            else
                return 0;
            break;

        case calcMODULA:
            if( r_value__>0 && l_value__ >0 )
                return l_value__%r_value__;
            else
                return 0;
            break;

        default:        return 0;
            break;
        }
        */
        return 0;
    }
}   /// EO namespace dc_midi


