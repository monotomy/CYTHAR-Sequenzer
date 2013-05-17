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

#include <dc_documentation.h>

#include <QUrl>
#include <QDesktopServices>

namespace dc_gui{

//!\class DocumentationWindow
    DocumentationWindow
    ::DocumentationWindow(std::string page__) noexcept
    {
        showPage(page__);
    }

    void DocumentationWindow
    ::showPage(std::string page__) const noexcept
    {
        std::string local_manual_url_at_apge{local_manual_url
                                                +page__};
        //std::cout << local_manual_url_at_apge << std::endl;
        QDesktopServices::openUrl(QUrl(local_manual_url_at_apge.c_str()));
    }
}
