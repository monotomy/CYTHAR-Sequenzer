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

#include <dc_alg_lengthmatrix.h>

#include <iostream>

namespace dc_alg{

    auto LengthMatrix
    ::get_enabled_dots(unsigned int length__) noexcept
    -> MatrixDotArray_Type
    {
        MatrixDotArray_Type tmp_array{{false,false,false,false,false,false,false,false,false}};

        tmp_array[DOT_FULL] = is_dot<LENGTH_FULL>(length__);
        if( tmp_array[DOT_FULL] )
        {
            return tmp_array; //  Matrixauflösung erreicht.
        }
        unsigned int rest_length{length__};
        if(is_dot<LENGTH_3_4>(rest_length))
        {
            tmp_array[DOT_3_4] = true;
            tmp_array[DOT_2_4] = true;
            tmp_array[DOT_1_4] = true;

            rest_length -= LENGTH_3_4;
        }
        else if(is_dot<LENGTH_2_4>(rest_length))
        {
            tmp_array[DOT_2_4] = true;
            tmp_array[DOT_1_4] = true;

            rest_length -= LENGTH_2_4;
        }
        else if(is_dot<LENGTH_1_4>(rest_length))
        {
            tmp_array[DOT_1_4] = true;

            rest_length -= LENGTH_1_4;
        }

        if(is_dot<LENGTH_1_8>(rest_length))
        {
            tmp_array[DOT_1_8] = true;

            rest_length -= LENGTH_1_8;
        }

        if(is_dot<LENGTH_1_16>(rest_length))
        {
            tmp_array[DOT_1_16] = true;

            rest_length -= LENGTH_1_16;
        }

        if(is_dot<LENGTH_1_32>(rest_length))
        {
            tmp_array[DOT_1_32] = true;

            rest_length -= LENGTH_1_32;
        }

        if(is_dot<LENGTH_2_96>(rest_length))
        {
            tmp_array[DOT_2_96] = true;
            tmp_array[DOT_1_96] = true;

            rest_length -= LENGTH_2_96;
        }
        else if(is_dot<LENGTH_1_96>(rest_length))
        {
            tmp_array[DOT_1_96] = true;

            rest_length -= LENGTH_1_96;
        }

        return std::move(tmp_array);
    }

    unsigned int LengthMatrix
    ::get_length_fromDotMatrix(MatrixDotArray_Type const& matrixDotArray__) noexcept
    {
        unsigned int length{0};
        if(matrixDotArray__[DOT_FULL]) length += LENGTH_1_4;
        if(matrixDotArray__[DOT_1_4]) length += LENGTH_1_4;
        if(matrixDotArray__[DOT_2_4]) length += LENGTH_1_4;
        if(matrixDotArray__[DOT_3_4]) length += LENGTH_1_4;

        if(matrixDotArray__[DOT_1_8]) length += LENGTH_1_8;
        if(matrixDotArray__[DOT_1_16]) length += LENGTH_1_16;
        if(matrixDotArray__[DOT_1_32]) length += LENGTH_1_32;

        if(matrixDotArray__[DOT_1_96]) length += LENGTH_1_96;
        if(matrixDotArray__[DOT_2_96]) length += LENGTH_1_96;

        return length;
    }
}   //  namespace dc_alg
