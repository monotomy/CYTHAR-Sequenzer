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

#include <phys_database.h>

#include <string>

namespace phys
{
    static Database* DATABASE;

//! \class Database
    Database* Database
    ::getDatabase(std::string dbName__)
    {
        DATABASE = new Database{dbName__};
        return DATABASE;
    }

    Database* Database
    ::getDatabase()
    {
        return DATABASE;
    }

    Database
    ::Database(std::string dbName__) :
        _dbName{dbName__}
    {}

    void Database
    ::open() noexcept
    {
        _projectfile.open(_dbName, std::ios::out);
    }

    void Database
    ::close() noexcept
    {
        _projectfile.close();
    }

    void Database
    ::read() noexcept
    {

        std::ifstream read_from_projectfile(_dbName);
        if (read_from_projectfile.is_open())
        {
            std::string line;
            auto n(std::string::npos);
            while (read_from_projectfile.good())
            {
                getline(read_from_projectfile,line);

                n = line.find(KEY_COMMA_VALUE_SEPERATOR);
                if(n != std::string::npos)
                    _in_cache[line.substr(0, n)] = line.substr(n+1);

            }
            read_from_projectfile.close();
        }

    }

    void Database
    ::clear_cache() noexcept
    {
        _in_cache.clear();
    }
}
