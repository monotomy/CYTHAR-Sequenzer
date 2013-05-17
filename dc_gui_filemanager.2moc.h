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

#ifndef DC_GUI_FILEMANAGER_2MOC_H_INCLUDED
#define DC_GUI_FILEMANAGER_2MOC_H_INCLUDED

#include <dc_gui_filemanager.uiced.h>

#include <pattern/singleton.hpp>
#include <stuff/blockguard.h>

#include <vector>
#include <string>

namespace dc_gui{

    /***********************************************************************/
    /*! \class Filemanager

        Clientzugriff auf MemPhysMediator
    */
    /***********************************************************************/
    class Filemanager :
        public QWidget,
        public Ui::Filemanager
    {
    Q_OBJECT
    SINGLETON_ownCTOR_throwable(Filemanager)

        Filemanager() noexcept;

        friend class Mainwindow;
        void show() noexcept;

    private slots:
        void on_pb_save_clicked() noexcept;
        void on_pb_load_clicked() noexcept;
        void on_pb_cancel_clicked() noexcept;
    };
}

#endif // DC_GUI_FILEMANAGER_2MOC_H_INCLUDED
