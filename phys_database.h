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

#ifndef PHYS_DATABASE_H_INCLUDED
#define PHYS_DATABASE_H_INCLUDED

#include <class/properties.hpp>

#include <string>
#include <fstream>
#include <iostream>
#include <map>

namespace phys{

    static const std::string KEY_COMMA_VALUE_SEPERATOR{","};

    /***********************************************************************/
    /*! \class Database
        \brief Wrapper für Leveldb
    */
    /***********************************************************************/
    class MemPhysMediator;
    class Database{
    NO_COPY_NO_MOVE(Database)

        std::ofstream _projectfile;
        std::map<std::string,std::string> _in_cache{};

        std::string _dbName;

        friend class MemPhysMediator;
        static Database* getDatabase(std::string dbName__);
        void close() noexcept;
        void open() noexcept;

        void read() noexcept;
        void clear_cache() noexcept;

        Database(std::string dbName__);
        Database() = delete;
        ~Database() = default;

        inline void replace_entity(std::string const& key__,
                                   std::string const& entity__) noexcept;

        inline std::string get_entity(std::string const& key__) noexcept;

        static Database* getDatabase();
    };
}

#include <phys_database.hpp>

#endif // PHYS_DATABASE_H_INCLUDED

