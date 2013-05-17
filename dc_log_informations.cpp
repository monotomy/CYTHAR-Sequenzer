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

#include <dc_log_informations.h>

#include <iostream>

#include <fstream>

namespace logg{

//!\class Info
    void Info
    ::set_info(std::string const& info__)
    {
        std::cout << info__ << std::endl;
        Log2File::write(info__);
    }

//!\class

    void Log2File
    ::write(std::string const&)
    {
        /*
        std::ofstream _logfile;
        _logfile.open("debug.log",std::ios::out | std::ios::app);
        _logfile << message__ << "\n";
        _logfile.close();
        */
    }

}
