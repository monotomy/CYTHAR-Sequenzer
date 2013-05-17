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

#ifndef PHYS_DATABASE_HPP_INCLUDED
#define PHYS_DATABASE_HPP_INCLUDED

#include <iostream>

namespace phys{

//!\class Database


    inline void Database
    ::replace_entity(std::string const& key__,
                     std::string const& entity__) noexcept
    {
        _projectfile  << key__ << KEY_COMMA_VALUE_SEPERATOR << entity__ << std::endl;
    }

    inline std::string Database
    ::get_entity(std::string const& key__) noexcept
    {
        auto found_key(_in_cache.find(key__));
        if(found_key != _in_cache.end())
            return found_key->second;

        return "";
    }
}

#endif // PHYS_DATABASE_HPP_INCLUDED
