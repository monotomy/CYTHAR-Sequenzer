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

#ifndef DC_TYPES_H_INCLUDED
#define DC_TYPES_H_INCLUDED

#include <stdint.h>

    //!\Typedef für nicht spezielle Eigenschaften
    typedef int8_t      TYPE_offset;
    typedef uint8_t     TYPE_velocity;
    typedef uint16_t    TYPE_lengthy;
    typedef uint8_t     TYPE_interval;
    typedef uint8_t     TYPE_note;

    typedef uint8_t TYPE_clockstep;
    typedef uint8_t TYPE_mute_time_inTakt;
    typedef uint8_t TYPE_delay_inClocks;
    typedef uint8_t TYPE_repeat_times;

    typedef bool TYPE_is_mute;
    typedef bool TYPE_is_init;

    typedef uint8_t TYPE_index_child;

    typedef uint8_t TYPE_midichannel;

    typedef uint8_t TYPE_operator;
    typedef int8_t  TYPE_operand;

#endif // DC_TYPES_H_INCLUDED
