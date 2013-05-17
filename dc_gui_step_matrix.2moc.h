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

#ifndef GUI_ELEMENT_PROGRESSBARMATRIX_H___
#define GUI_ELEMENT_PROGRESSBARMATRIX_H___

#include <dc_gui_step_matrix.uiced.h>

#include <class/properties.hpp>

namespace dc_gui
{
    enum NOTE_CONSTANTS
    {
        FULL_NOTE   = 96,
        _3_4_NOTE   = 72,
        _2_4_NOTE   = 48,
        _1_4_NOTE   = 24,
        _1_8_NOTE   = 12,
        _1_16_NOTE  = 6,
        _1_32_NOTE  = 3,
        _1_96_NOTE  = 1,
    };

    /* Für die Grafische darstellung der Quadrate und Rechtecke in den 5 Matrixquadraten */
    static const QRect __4_4_FULL_LEFT  (0,0,3,6);
    static const QRect __4_4_FULL_RIGTH (3,0,3,6);
    static const QRect __4_4_HALF_LEFT  (0,3,3,3);
    static const QRect __4_4_ZERO_LEFT  (0,0,0,0);
    static const QRect __4_4_HALF_RIGTH (3,0,3,3);
    static const QRect __4_4_ZERO_RIGTH (0,0,0,0);

    static const QRect __2_96_FULL      (22,0,6,6);
    static const QRect __2_96_HALF      (22,0,6,3);
    static const QRect __2_96_ZERO      (22,0,0,0);

    class StepMatrix :
        public QWidget,
        public Ui::matrix
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(StepMatrix)

        int  set4_4_getRest  (int value__) noexcept;  // Q1
        int  set1_8_getRest  (int value__) noexcept;  // Q2
        int  set1_16_getRest (int value__) noexcept;  // Q3
        int  set1_32_getRest (int value__) noexcept;  // Q4
        void set2_96         (int value__) noexcept;  // Q5

    public:

        StepMatrix();
        ~StepMatrix() = default;

        void setValue(int value__) noexcept;
    };
}
#endif  /// GUI_ELEMENT_PROGRESSBARMATRIX_H
