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

#include "dc_gui_step_velocity.2moc.h"

namespace dc_gui
{
    StepVelocity::StepVelocity(int min__, int max__ ) :
        QWidget   { nullptr },
        _min      { min__ },
        _max      { max__ }
    {
        this->setupUi(this);
        this->calc_setMultiplyValue();
        this->setValue(0);    // unitalisation to 0
    }

    void StepVelocity::calc_setMultiplyValue() noexcept
    {
        _multiplyValue = double(this->frame_frame->width() - LEFT_MARGIN-RIGTH_MARGIN )  /  _max; // -2 = borderpixel
    }

    void StepVelocity::setValue(int value__) noexcept
    {
        if( value__ >= _min && _max >= value__  )
        {
            this->frame_content->setGeometry(LEFT_MARGIN,TOP_MARGIN, value__*_multiplyValue , CONTEN_HIGTH );
            return;
        }

        this->frame_content->setGeometry(0,0,0,0);  // hide the bar
        return;
    }
}       /// EO @namespace gui_elements
