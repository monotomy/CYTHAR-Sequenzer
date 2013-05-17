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

#ifndef CLASSPROPERTYS_H_INCLUDED
#define CLASSPROPERTYS_H_INCLUDED

#define NO_COPY(ARG_CLASSNAME) \
    ARG_CLASSNAME(ARG_CLASSNAME const &) = delete; \
    ARG_CLASSNAME operator=(ARG_CLASSNAME const &) = delete;

#define NO_MOVE(ARG_CLASSNAME) \
    ARG_CLASSNAME(ARG_CLASSNAME const&&) = delete; \
    ARG_CLASSNAME operator=(ARG_CLASSNAME const&&) = delete;

#define NO_COPY_NO_MOVE(ARG_CLASSNAME) \
        NO_COPY(ARG_CLASSNAME) \
        NO_MOVE(ARG_CLASSNAME)

#define NOT_INSTANCEABLE(ARG_CLASSNAME) \
        ARG_CLASSNAME() = delete; \
        NO_COPY_NO_MOVE(ARG_CLASSNAME)

#define PROTECTED_DCTOR(ARG_CLASSNAME) \
        protected: \
            ~ARG_CLASSNAME() noexcept = default; \
        private:

#define virtual_indbug virtual

#endif // CLASSPROPERTYS_H_INCLUDED
