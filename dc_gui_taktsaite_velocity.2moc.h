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

#ifndef DC_GUI_TAKTSAITE_VELOCITY_H_INCLUDED
#define DC_GUI_TAKTSAITE_VELOCITY_H_INCLUDED

#include <dc_gui_taktsaite_velocity.uiced.h>

#include <guistuff/child_initializer.h>

#include <class/properties.hpp>

namespace dc_gui{

    /***********************************************************************/
    //! \class  TaktsaiteVelocity_Initializer
    /***********************************************************************/
    class TaktsaiteVelocity;
    class TaktsaiteVelocity_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            sum_elements    = 6,

            height          = 40,
            width           = 51,
            top_first       = 0,
            left            = 5
        };

    public:
        TaktsaiteVelocity_Initializer() noexcept = default;
        ~TaktsaiteVelocity_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    class TaktsaiteVelocity :
        public QWidget,
        public Ui::TaktsaiteVelocity
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(TaktsaiteVelocity)

        friend class TaktsaiteVelocity_Initializer;
        TaktsaiteVelocity ();
        void init() noexcept;
        void update() noexcept;
        ~TaktsaiteVelocity() = default;

    private slots:
        void on_dial_time_valueChanged(int) noexcept;
    };

}

#endif // DC_GUI_TAKTSAITE_VELOCITY_H_INCLUDED
