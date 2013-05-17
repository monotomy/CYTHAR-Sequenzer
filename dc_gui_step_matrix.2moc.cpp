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

#include <dc_gui_step_matrix.2moc.h>

#include <dc_alg_lengthmatrix.h>

namespace dc_gui
{
    StepMatrix
    ::StepMatrix()
        : QWidget { nullptr }
    {
        this->setupUi(this);
        this->setValue(0);    // unitalisation to 0
    }

    void StepMatrix
    ::setValue(int value__) noexcept
    {
        if(value__>FULL_NOTE)
        {
            frame_4_4_partLeft->setGeometry (__4_4_FULL_LEFT);
            frame_4_4_partRigth->setGeometry(__4_4_FULL_RIGTH);
            frame_1_8_set->setAutoFillBackground(true);
            frame_1_16_set->setAutoFillBackground(true);
            frame_1_32_set->setAutoFillBackground(true);
            frame_2_96_part->setGeometry(__2_96_FULL);

            return;
        }

        int rest{set4_4_getRest (value__) };
        rest =   set1_8_getRest (rest);
        rest =   set1_16_getRest(rest);
        rest =   set1_32_getRest(rest);
                 set2_96        (rest);
    }

    int StepMatrix
    ::set4_4_getRest  (int value__) noexcept
    {
        if( value__ >= FULL_NOTE )
        {
            frame_4_4_partLeft->setGeometry (__4_4_FULL_LEFT);
            frame_4_4_partRigth->setGeometry(__4_4_FULL_RIGTH);
            return 0;
        }
        if( value__ >= _3_4_NOTE )
        {
            frame_4_4_partLeft->setGeometry (__4_4_HALF_LEFT);
            frame_4_4_partRigth->setGeometry(__4_4_FULL_RIGTH);
            return value__ - _3_4_NOTE;
        }
        if( value__ >= _2_4_NOTE )
        {
            frame_4_4_partLeft->setGeometry (__4_4_ZERO_LEFT);
            frame_4_4_partRigth->setGeometry(__4_4_FULL_RIGTH);
            return value__ - _2_4_NOTE;
        }
        if( value__ >= _1_4_NOTE )
        {
            frame_4_4_partLeft->setGeometry (__4_4_ZERO_LEFT);
            frame_4_4_partRigth->setGeometry(__4_4_HALF_RIGTH);
            return value__ - _1_4_NOTE;
        }

        frame_4_4_partLeft->setGeometry (__4_4_ZERO_LEFT);
        frame_4_4_partRigth->setGeometry(__4_4_ZERO_RIGTH);
        return value__;
    }

    int StepMatrix
    ::set1_8_getRest  (int value__) noexcept
    {
        if( value__ >= _1_8_NOTE )
        {
            frame_1_8_set->setAutoFillBackground(true);
            return value__ - _1_8_NOTE;
        }

        frame_1_8_set->setAutoFillBackground(false);
        return value__;
    }

    int StepMatrix
    ::set1_16_getRest (int value__) noexcept
    {
        if( value__ >= _1_16_NOTE )
        {
            frame_1_16_set->setAutoFillBackground(true);
            return value__ - _1_16_NOTE;
        }

        frame_1_16_set->setAutoFillBackground(false);
        return value__;
    }

    int StepMatrix
    ::set1_32_getRest (int value__) noexcept
    {
        if( value__ >= _1_32_NOTE )
        {
            frame_1_32_set->setAutoFillBackground(true);
            return value__ - _1_32_NOTE;
        }

        frame_1_32_set->setAutoFillBackground(false);
        return value__;
    }

    void StepMatrix
    ::set2_96 (int value__) noexcept
    {
        if( value__ >= 2*_1_96_NOTE )
        {
            frame_2_96_part->setGeometry(__2_96_FULL);
            return;
        }

        if( value__ >= _1_96_NOTE )
        {
            frame_2_96_part->setGeometry(__2_96_HALF);
            return;
        }

        frame_2_96_part->setGeometry(__2_96_ZERO);
        return;
    }
}       /// EO @namespace gui_elements
