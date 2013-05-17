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

#ifndef DC_GUI_DOCUMENTATION_2MOC_H_INCLUDED
#define DC_GUI_DOCUMENTATION_2MOC_H_INCLUDED

#include <string>
#include <QDir>

#include <iostream>

namespace dc_gui{

    /***********************************************************************/
    /*! \class  DocumentationWindow

        Viwer für Docfiles (html)
    */
    /***********************************************************************/

    class DocumentationWindow
    {

#ifdef __WIN__
        std::string const manual_dir{"file:///" + QDir::currentPath().toStdString() + "/doc/"};
#elif __LINUX__
        std::string const manual_dir{"file:///usr/share/cythar/doc/"};
#elif __MAC__
        std::string const manual_dir{"file:///" + QDir::currentPath().toStdString() + "/doc/"};
#endif // __WIN__
        std::string const manual_langune_string{"manual-german.pdf"};

        std::string const page_string{"#page="};
        std::string const local_manual_url{manual_dir
                                            +manual_langune_string
                                            +page_string};

    public:
        DocumentationWindow(std::string page__ = "0") noexcept;
    private:
        ~DocumentationWindow() noexcept = default;

        void showPage(std::string page__ = "0") const noexcept;
    };
}

#endif // DC_GUI_DOCUMENTATION_2MOC_H_INCLUDED
