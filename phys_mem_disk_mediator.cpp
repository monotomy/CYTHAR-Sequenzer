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

#include <phys_mem_disk_mediator.h>

#include <stdint.h>

#include <dc_log_informations.h>

//! Verzeichnisse
#ifdef __WIN__
    #include <windows.h>
    #include <shlobj.h>
    static char HOME_DIR[ MAX_PATH ];
    static const char* get_home_dir()
    {
        SHGetFolderPath( NULL, CSIDL_APPDATA, NULL, 0, HOME_DIR );
        return HOME_DIR;
    }
#elif __LINUX__
    static const char* HOME_DIR{"/usr/share"};
    static const char* get_home_dir()
    {
        return HOME_DIR;
    }
#elif __MAC__
    static const char* HOME_DIR{"/Users/Shared"};
    static const char* get_home_dir()
    {
        return HOME_DIR;
    }
#else
    static const char* HOME_DIR{"COMPILE ERROR - No Plattform defined"};
    static const char* get_home_dir()
    {
        return HOME_DIR;
    }
#endif

namespace phys{

    static constexpr uint8_t IS_FILE =0x8;
    static constexpr uint8_t IS_DIR = 0x4;

//!\class MemPhysMediator
    MemPhysMediator
    ::MemPhysMediator() :
        _home_dir{get_home_dir()},
        _2load_db_name_and_path{_work_dir+LAST_TIME_PROJECT},
        _2save_db_name_and_path{_work_dir+LAST_TIME_PROJECT}
    {
    }

    void MemPhysMediator
    ::set_save_db_name(std::string const& db_name__) noexcept
    {
        _2save_db_name_and_path = db_name__;

        develINFO_(SET_DB_SAVE_NAME, _2save_db_name_and_path)
    }

    void MemPhysMediator
    ::set_load_db_name(std::string const& db_name__) noexcept
    {
        _2load_db_name_and_path = db_name__;

        develINFO_(SET_DB_LOAD_NAME, _2load_db_name_and_path)
    }

    std::string MemPhysMediator
    ::project_dir() const noexcept
    {
        return _work_dir;
    }

    std::string MemPhysMediator
    ::project_dir_and_current_project() const noexcept
    {
        return _2load_db_name_and_path;
    }



    std::string MemPhysMediator
    ::database_savename() const noexcept
    {
        return _2save_db_name_and_path;
    }

//! READ **********************************************************
    void MemPhysMediator
    ::read_from_phys() noexcept
    {
        develINFO_(LOAD, _2load_db_name_and_path)

        using namespace dc_objects;
        auto project(tmpGET_(SELECTED_PROJECT));
        auto database(Database::getDatabase(_2load_db_name_and_path));

        database->read();

        std::string first_level_key__{project->_KEY_NAME};
        // Liest daten des Projectes
        read_properties_fromDb_2(database, project, first_level_key__);
        // Startet rekursives laden der Childs und ChildChilds
        exec_read_child_properties_from_db_2<dc_objects::Pattern>(database,
                                                                  project,
                                                                  first_level_key__);

        database->clear_cache();
    }

    void MemPhysMediator
    ::save_2_phys() noexcept
    {
        develINFO_(SAVE, _2save_db_name_and_path)

        using namespace dc_objects;
        auto project(tmpGET_(SELECTED_PROJECT));
        auto database(Database::getDatabase(_2save_db_name_and_path));

        database->open();

        std::string first_level_key__{project->_KEY_NAME};
        // Schreibt die Daten der ersten ebene.
        write_properties_2_db_from(database, project, first_level_key__);
        // Startet rekursives schreibern der Childs & ChildChilds
        exec_write_child_properties_2_db_for<dc_objects::Pattern>(database,
                                                                  project,
                                                                  first_level_key__);

        database->close();
    }
//! WRITE *********************************************************
}
