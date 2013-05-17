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

#ifndef DC_GUI_TAKTSAITE_MUTE_H_INCLUDED
#define DC_GUI_TAKTSAITE_MUTE_H_INCLUDED

#include <dc_gui_taktsaite_mute.uiced.h>

#include <guistuff/child_initializer.h>

#include <class/properties.hpp>

namespace dc_gui{

    /***********************************************************************/
    //! \class  TaktsaiteMute_Initializer
    /***********************************************************************/
    class TaktsaiteMute;
    class TaktsaiteMute_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            sum_elements    = 6,

            height          = 40,
            width           = 51,
            top_first       = 0,
            left            = 0
        };

    public:
        TaktsaiteMute_Initializer() noexcept = default;
        ~TaktsaiteMute_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    class TaktsaiteMute :
        public QWidget,
        public Ui::TaktsaiteMute
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(TaktsaiteMute)

        friend class TaktsaiteMute_Initializer;
        TaktsaiteMute ();
        void init() noexcept;
        void update() noexcept;
        ~TaktsaiteMute() = default;

    private slots:
        void on_pb_clicked() noexcept;
    };

}

#endif // DC_GUI_TAKTSAITE_MUTE_H_INCLUDED
