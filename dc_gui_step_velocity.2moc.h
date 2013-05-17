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

#ifndef GUI_ELEMENT_PROGRESSBARSIMPLE_H_INCLUDED
#define GUI_ELEMENT_PROGRESSBARSIMPLE_H_INCLUDED

#include <dc_gui_step_velocity.uiced.h>

#include <class/properties.hpp>

namespace dc_gui{

    unsigned const int LEFT_MARGIN  = 1;
    unsigned const int RIGTH_MARGIN = 1;
    unsigned const int TOP_MARGIN   = 1;
    unsigned const int CONTEN_HIGTH = 2;

    class StepVelocity :
        public QWidget,
        public Ui::progressbar
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(StepVelocity)

        int _min    {0};
        int _max    {0};
        double  _multiplyValue  {0};

        void calc_setMultiplyValue() noexcept;

    public:
        StepVelocity(int min__ = 0, int max__ = 127 );
        ~StepVelocity() {}

        void setValue(int value__) noexcept;
    };
}       /// EO @namespace gui_elements
#endif  /// GUI_ELEMENT_PROGRESSBARSIMPLE_H_INCLUDED
