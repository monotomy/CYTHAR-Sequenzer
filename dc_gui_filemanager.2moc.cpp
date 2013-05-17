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

#include <dc_gui_filemanager.2moc.h>

#include <phys_mem_disk_mediator.h>

#include <guistuff/child_initializer.h>

#ifdef __MAC__
    #include <crossplatt_fontsize_fix.hpp>
#endif // __MAC__

#include <QFileDialog>




namespace dc_gui{

//!\class Filemanager
    Filemanager
    ::Filemanager() noexcept
    {
        setupUi(this);
        guistruff::set_widget_center_desktop(this);
#ifdef __MAC__
        crossplatt_fontsizefix::adjust_fontsize_for_mac(this);
#endif // __MAC__
    }

    void Filemanager
    ::show() noexcept
    {
        guistruff::set_widget_center_desktop(this);

        this->setVisible(true);
    }

    void Filemanager
    ::on_pb_save_clicked() noexcept
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save Project"),
                                                        phys::MemPhysMediator::singleton()->project_dir_and_current_project().c_str(),
                                                        tr("(*)"));
        std::cout << fileName.toStdString() << std::endl;
        if(fileName.toStdString().size() > 0)
        {
            phys::MemPhysMediator::singleton()->set_save_db_name(fileName.toStdString());
            phys::MemPhysMediator::singleton()->save_2_phys();
        }


        this->setVisible(false);
    }

    void Filemanager
    ::on_pb_load_clicked() noexcept
    {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open Project"),
                                                        phys::MemPhysMediator::singleton()->project_dir().c_str(),
                                                        tr("(*)"));
        std::cout << fileName.toStdString() << std::endl;
        if(fileName.toStdString().size() > 0)
        {
            phys::MemPhysMediator::singleton()->set_load_db_name(fileName.toStdString());
            phys::MemPhysMediator::singleton()->read_from_phys();
        }


        this->setVisible(false);
    }

    void Filemanager
    ::on_pb_cancel_clicked() noexcept
    {
        this->setVisible(false);
    }
}
