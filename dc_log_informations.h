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

#ifndef LOG__H_INCLUDED
#define LOG__H_INCLUDED

#include <string>

namespace logg{

    static const std::string SET_DB_SAVE_NAME{"s.save     : "};
    static const std::string SET_DB_LOAD_NAME{"s.load     : "};

    static const std::string BUILD      {"build      : "};
    static const std::string INIT       {"init       : "};
    static const std::string LOAD       {"load       : "};
    static const std::string SAVE       {"save       : "};
    static const std::string SET        {"set        : "};
    static const std::string EXEC       {"exec       : "};
    static const std::string SHOW       {"show       : "};
    static const std::string DONE       {"done       : "};
    static const std::string SEND       {"send       : "};
    static const std::string DCTOR      {"cleanup    : "};

    static const std::string _3ERR      {"3th-Error  : "};
    static const std::string _ERR       {"Error      : "};
    static const std::string _MIDI      {"midi       : "};
    static const std::string _USERDEBUG {"user debug : "};

    /***********************************************************************/
    /*! \class Info

        Runtime Output in Console
    */
    /***********************************************************************/
    class Log2File;
    class Info
    {
        Info() noexcept = default;
        ~Info() noexcept = default;

    public:
        static inline Info* singleton()
        {
            static Info *const this__{new Info{}};
            return this__;
        }

    public:
    #define develINFO_(ARG_INFORMATION_STRING, ARG_ADDITIONAL_INFORMATION) \
    logg::Info::singleton()->set_info(ARG_INFORMATION_STRING \
                                     +ARG_ADDITIONAL_INFORMATION);
        void set_info(std::string const& info__);
    };



    /***********************************************************************/
    /*! \class Log2File
    */
    /***********************************************************************/


    #define DCTOR_LOGFILE_DEBUG_(ARG_CLASSNAME) develINFO_(DCTOR, #ARG_CLASSNAME);

    class Log2File
    {
    public:
        static void write(std::string const& message__);
    };
}

using namespace logg;

#endif // LOG__H_INCLUDED
