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

#ifndef INVERT_HPP_INCLUDED
#define INVERT_HPP_INCLUDED

#ifdef DEBUG
    #include <iostream>
#endif // DEBUG

namespace functions{

    template<typename TYPE_numeric>
    inline TYPE_numeric invert_numeric(TYPE_numeric value_to_invert) noexcept
    {
        return value_to_invert *-1;
    }

    template<>
    inline bool invert_numeric<bool>(bool bool_to_invert) noexcept
    {
        switch(bool_to_invert) {
            case true:
            return false;

            case false:
            return true;
            break;

            default:
            break;
        }

        // Unimpossible
        #ifdef DEBUG
            std::cout << "DEBUG: invert_numeric<bool> isn't true or false?" << std::endl;
        #endif // DEBUG
        return false;
    }
}

using namespace functions;

#endif // INVERT_HPP_INCLUDED
