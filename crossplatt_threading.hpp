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

#ifndef CROSSPLATT_THREADING_HPP_INCLUDED
#define CROSSPLATT_THREADING_HPP_INCLUDED

#include <class/properties.hpp>

#include <iostream>

#ifdef __WIN__
    #include <boost/thread.hpp>
    #include <windows.h>
    #include <ctime>
    #include <cstdio>
    #include <boost/signals2/mutex.hpp>
#elif __UNIX__
    #include <chrono>
    #include <thread>
    #include <mutex>
    #include <unistd.h>
#endif // __WIN__

namespace crossplatt_threading{

#ifdef __WIN__
    using cross_thread = boost::thread;
    using cross_mutex = boost::mutex;
#elif __UNIX__
    using cross_thread = std::thread;
    using cross_mutex = std::mutex;
#endif // __WIN__

    //! CROSS USLEEP
#ifdef __UNIX__
    struct Usleep{ NOT_INSTANCEABLE(Usleep)
    inline static int exec(long usec)
    {
        struct timeval tv;
        tv.tv_sec = usec/1000000L;
        tv.tv_usec = usec%1000000L;
        return select(0, 0, 0, 0, &tv);
    }};
#endif // __UNIX__

#ifdef __WIN__
    struct Usleep{ NOT_INSTANCEABLE(Usleep)
    inline static void exec(long usec)
    {
        boost::this_thread::sleep( boost::posix_time::microseconds(usec) );
    }};
#endif // __WIN__

}

using namespace crossplatt_threading;

#endif // CROSSPLATT_THREADING_HPP_INCLUDED
