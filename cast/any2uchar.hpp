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

#ifndef ANY2UCHAR_HPP_INCLUDED
#define ANY2UCHAR_HPP_INCLUDED


template<typename TYPE_FROM>
inline unsigned char int2uchar(TYPE_FROM cast_from__) noexcept
{
    if(cast_from__ > -1 && cast_from__ < 256)
        return cast_from__;
    else
    {
    #ifdef DEBUG
        std::cout << "BUG - bad unsigned char cast from: " << cast_from__ << std::endl;
    #endif // DEBUG
        return 0;
    }
}

template<typename TYPE_FROM>
inline unsigned char int2uchar127(TYPE_FROM cast_from__) noexcept
{
    if(cast_from__ > -1 && cast_from__ < 128)
        return cast_from__;
    else
    {
    #ifdef DEBUG
        std::cout << "BUG - bad unsigned char 127 cast from: " << cast_from__ << std::endl;
    #endif // DEBUG
        return 0;
    }
}

#endif // ANY2UCHAR_HPP_INCLUDED
