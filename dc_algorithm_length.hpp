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

#ifndef DC_ALGORITHM_LENGTH_HPP_INCLUDED
#define DC_ALGORITHM_LENGTH_HPP_INCLUDED

#include <dc_standard_types.h>
#include <dc_standard_values.h>

namespace dc_algorithm{

    //! Erstellt Triolen aus dem übergebenen Längenwert
    template<class TYPE_ofLength>
    inline constexpr TYPE_lengthy make_triplet(TYPE_ofLength length__) noexcept
    {
        return (length__*2) / 3;
    }

    //!Erstellt doppelt punktierte Noten aus dem übergebenen Wert
    template<class TYPE_ofLength>
    inline constexpr TYPE_lengthy make_double_pointet(TYPE_ofLength length__) noexcept
    {
        return length__ + length__/2 + length__/4;
    }

}

#endif // DC_ALGORITHM_LENGTH_HPP_INCLUDED
