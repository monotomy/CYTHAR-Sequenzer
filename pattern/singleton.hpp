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

#ifndef SINGLETON_HPP_INCLUDED
#define SINGLETON_HPP_INCLUDED

#include <dc_log_informations.h>
#include <class/properties.hpp>

/**********************************************************************/
//! \class Singleton (NoThrow / noexcept)
/**********************************************************************/
//! Singleton Access foo mit NO_MOVE_NO_COPY
#define SINGLETON_foo(ARG_CLASSNAME) \
    NO_COPY_NO_MOVE(ARG_CLASSNAME) \
    public: \
        static inline ARG_CLASSNAME* singleton(bool kill_the_singleton = false) \
        { \
            static ARG_CLASSNAME *this__{nullptr}; \
            if(this__ != nullptr) \
                if(kill_the_singleton != true) \
                    return this__; \
                else \
                { \
                    delete this__; \
                    return nullptr; \
                } \
            else \
            { \
                this__ = new ARG_CLASSNAME{}; \
                return this__; \
            } \
        } \
    private:

//! Einfaches Singleton ohne Ctor
#define SINGLETON_ownCTOR(ARG_CLASSNAME) \
    private: \
        virtual ~ARG_CLASSNAME() noexcept \
        { \
            DCTOR_LOGFILE_DEBUG_(ARG_CLASSNAME) \
        }; \
    SINGLETON_foo(ARG_CLASSNAME)

//! Koplettes Singleton mit Ctor, AccessFoo und NO_COPY_NO_MOVE
#define SINGLETON(ARG_CLASSNAME) \
    private: \
        ARG_CLASSNAME() noexcept = default; \
        SINGLETON_ownCTOR(ARG_CLASSNAME)


/**********************************************************************/
//! \class Singleton (Throwable)
/**********************************************************************/
//! Einfaches throwable Singleton ohne Ctor
#define SINGLETON_ownCTOR_throwable(ARG_CLASSNAME) \
    NO_COPY_NO_MOVE(ARG_CLASSNAME) \
    private: \
        virtual ~ARG_CLASSNAME()  \
        { \
            DCTOR_LOGFILE_DEBUG_(ARG_CLASSNAME) \
        } \
    public: \
    static inline ARG_CLASSNAME* singleton(bool kill_the_singleton = false) \
    { \
        static ARG_CLASSNAME *this__{nullptr}; \
        if(this__ != nullptr) \
            if(kill_the_singleton != true) \
                return this__; \
            else \
            { \
                delete this__; \
                return nullptr; \
            } \
        else \
        { \
            this__ = new ARG_CLASSNAME{}; \
            return this__; \
        } \
    } \
    private:

//! Koplettes Singleton mit throwable Ctor, AccessFoo und NO_COPY_NO_MOVE
#define SINGLETON_throwable(ARG_CLASSNAME) \
    SINGLETON_ownCTOR_throwable(ARG_CLASSNAME) \
        ARG_CLASSNAME() = default; \
    private:

#endif // SINGLETON_HPP_INCLUDED
