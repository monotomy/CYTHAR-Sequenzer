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

#ifndef DC_ALG_LENGTHMATRIX_H_INCLUDED
#define DC_ALG_LENGTHMATRIX_H_INCLUDED

#include <class/properties.hpp>

#include <array>

namespace dc_alg{

    unsigned int constexpr MATRIX_SUM_DOTS = 9;   //  4x Felder für 4tel; 1x 8tel; 1x 16tel; 1x 32tel; 2x 96tel
    enum LENGTH_CONSTANTS : unsigned int
    {
        LENGTH_FULL  = 96,

        LENGTH_3_4   = 72,    //  Example: LENGTH_3_4 = 3/4 Note
        LENGTH_2_4   = 48,
        LENGTH_1_4   = 24,
        LENGTH_1_8   = 12,
        LENGTH_1_16  = 6,
        LENGTH_1_32  = 3,
        LENGTH_2_96  = 2,
        LENGTH_1_96  = 1,

        LENGTH_NULL  = 0
    };

    enum DOT_ARRAY_INDEX : unsigned int
    {
        DOT_FULL  = 0,
        DOT_3_4,
        DOT_2_4,
        DOT_1_4,
        DOT_1_8,
        DOT_1_16,
        DOT_1_32,
        DOT_2_96,
        DOT_1_96
    };

    class LengthMatrix
    {
    NOT_INSTANCEABLE(LengthMatrix)

        template<unsigned int LENGTH_CONSTANTS__>
        static bool is_dot(unsigned int rest_length__) noexcept;

    public:
        typedef std::array<bool, MATRIX_SUM_DOTS> MatrixDotArray_Type;
        static auto get_enabled_dots(unsigned int length__) noexcept
        -> MatrixDotArray_Type;

        static unsigned int get_length_fromDotMatrix(MatrixDotArray_Type const&) noexcept;
    };

}       // namespace dc_alg

#include <dc_alg_lengthmatrix.hpp>  //  Templateimpl

#endif // DC_ALG_LENGTHMATRIX_H_INCLUDED
