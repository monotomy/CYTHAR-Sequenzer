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

#ifndef DC_ALG_LENGTHMATRIX_HPP_INCLUDED
#define DC_ALG_LENGTHMATRIX_HPP_INCLUDED

namespace dc_alg{

    template<unsigned int LENGTH_CONSTANTS__>
    bool LengthMatrix
    ::is_dot(unsigned int rest_length__) noexcept
    {
        if(rest_length__ >= LENGTH_CONSTANTS__)
            return true;

        return false;
    }
}       // namespace dc_alg

#endif // DC_ALG_LENGTHMATRIX_HPP_INCLUDED
