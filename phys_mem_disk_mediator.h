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

#ifndef PHYS_MEM_DISK_MEDIATOR_H_INCLUDED
#define PHYS_MEM_DISK_MEDIATOR_H_INCLUDED

#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>

#include <pattern/singleton.hpp>

#include <string>
#include <algorithm>

#include <vector>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

#include <phys_database.h>

namespace phys{

    static const std::string LAST_TIME_PROJECT{"last session at exit"};

    /***********************************************************************/
    /*! \class MemPhysMediator

        Verwaltet lesen und schreiben zwischen physischen Speicher (DB) und
        Memory
    */
    /***********************************************************************/
    class MemPhysMediator{
    SINGLETON_ownCTOR(MemPhysMediator)

        MemPhysMediator();

        std::string const _home_dir;
        std::string const _cythar_project_dir{"/cythar-projects/"};
        std::string const _work_dir{_home_dir+_cythar_project_dir};

        std::string _2load_db_name_and_path;
        std::string _2save_db_name_and_path;

        // Erstellt den Datenbank aus vorangehenden key und child key
        inline std::string build_level_key(std::string const& until_parent__key__,
                                           TYPE_index_child child_id_in_parent__,
                                           std::string const& child_key__) const noexcept;

        // Erstellt property key aus level & property key
        inline std::string build_property_key(std::string const& level_key__,
                                              std::string const& property_key__) const noexcept;

    public:
        std::string project_dir() const noexcept;
        std::string project_dir_and_current_project() const noexcept;

        void set_save_db_name(std::string const& db_name__) noexcept;
        void set_load_db_name(std::string const& db_name__) noexcept;
        std::vector<std::string> content_in_work_dir() const noexcept;

        std::string database_savename() const noexcept;

    public:
        //! READ **********************************************************
        //! Liest das gesamte Projekt in den Momory
        void read_from_phys() noexcept;
    private:
        //! Liest die properties für die Objekte des angegebenen Types
        template<class TYPE_properties_owner>
        void read_properties_fromDb_2(Database*,
                                      TYPE_properties_owner*,
                                      std::string const& this_level_key__) noexcept;

        //! Iteriert durch alle Childs eines Types und liest deren Daten
        template<class TYPE_for_child,
                 class TYPE_child_owner
        >
        inline void exec_read_child_properties_from_db_2(Database*,
                                                         TYPE_child_owner*,
                                                         std::string const& parent_key_list__) noexcept;

        //! Rekursion für alle Childtypen, die in der Typeliste eingetragen sind
        // -> read_child_data_fromDb_2
        template<class TYPE_child_owner,
                 int TYPELIST_ID_current_Child
        >
        inline void exec_read_child_child_properties_from_db_2(Database* db__,
                                                               TYPE_child_owner* parent__,
                                                               std::string const& parent_key_list__,
                                                               Loki::Int2Type<TYPELIST_ID_current_Child>) noexcept;
        //! Rekursionsende
        template<class TYPE_child_owner>
        inline void exec_read_child_child_properties_from_db_2(Database*,
                                                               TYPE_child_owner*,
                                                               std::string const&,
                                                               Loki::Int2Type<-1>) noexcept;

    public:
        //! WRITE *********************************************************
        //! Schreibt das gesamte Projekt von Memory zu Phys db
        void save_2_phys() noexcept;
    private:
        //! Schreibt die properties für die Objekte des angegebenen Types
        template<class TYPE_properties_owner>
        inline void write_properties_2_db_from(Database*,
                                               TYPE_properties_owner const*,
                                               std::string const& this_level_key__) noexcept;

        //! Iteriert durch alle Childs eines Types und veranlasst deren Daten zu schreiben
        template<class TYPE_for_child,
                 class TYPE_child_owner
        >
        inline void exec_write_child_properties_2_db_for(Database*,
                                                         TYPE_child_owner const*,
                                                         std::string const& parent_key_list__) noexcept;

        //! Rekursion für alle Childtypen, die in der Typeliste eingetragen sind
        // -> exec_write_child_properties_2_db_for
        template<class TYPE_child_owner,
                 int TYPELIST_current_Child_ID
        >
        inline void exec_write_child_child_properties_2_db_from(Database*,
                                                                TYPE_child_owner const*,
                                                                std::string const& parent_key_list__,
                                                                Loki::Int2Type<TYPELIST_current_Child_ID>) noexcept;
        //! Rekursionsende
        template<class TYPE_child_owner>
        inline void exec_write_child_child_properties_2_db_from(Database*,
                                                                TYPE_child_owner const*,
                                                                std::string const&,
                                                                Loki::Int2Type<-1>) noexcept;
    };
}

#include <phys_mem_disk_mediator.hpp>

#endif // PHYS_MEM_DISK_MEDIATOR_H_INCLUDED
