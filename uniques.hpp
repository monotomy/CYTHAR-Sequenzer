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

#ifndef UNIQUES_HPP_INCLUDED
#define UNIQUES_HPP_INCLUDED

#include <class/properties.hpp>
#include <uniques_this_app.h>

#include <array>
#include <stdint.h>

namespace uniques{

    /***********************************************************************/
    /*! \class  UNIQUE_IDENTIFICATIONS

        Auflistung aller Klassen im Projekt, welche als UNIQUE
        identifiziert werden müssen.
    */
    /***********************************************************************/
    enum class UNIQUE_IDENTIFICATIONS : uint8_t
    {
        Rebeca,
        Step,
        Taktchain,
        Taktsaite,
        Takt,
        Patternsaite,
        Pattern,
        Project,
        MainwindowClipboard,

        EMPTY
    };

    /***********************************************************************/
    /*! \class  UNIQUE / UNIQUE_BASE

        Uniue Klassen müssen diese beerben, unter angabe ihrer
        unique id ( diese muss manuell in UNIQUE_IDENTIFICATIONS
        eingepflegt werden
    */
    /***********************************************************************/
    struct UNIQUE_BASE
    {
        virtual UNIQUE_IDENTIFICATIONS unique_id() const noexcept = 0;

    protected:
        UNIQUE_BASE() noexcept = default;
        virtual_indbug ~UNIQUE_BASE() noexcept = default;
    };
    template<UNIQUE_IDENTIFICATIONS unique_id__>
    struct UNIQUE : UNIQUE_BASE
    {
        //! Eigene Einmalige Id
        enum { UNIQUE_ID = static_cast<int>(unique_id__) };
        inline virtual UNIQUE_IDENTIFICATIONS unique_id() const noexcept override
        {
            return static_cast<UNIQUE_IDENTIFICATIONS>(UNIQUE_ID);
        }

    protected:
        UNIQUE() noexcept = default;
        virtual_indbug ~UNIQUE() noexcept = default;
    };

    class EmptyBase : public UNIQUE<UNIQUE_IDENTIFICATIONS::EMPTY> {};

    /***********************************************************************/
    /*! \class  UNIQUE / UNIQUE_BASE

        Array mit Compatiblen Unique IDs

/// TODO Static const version
    */
    /***********************************************************************/
    template<UNIQUE_IDENTIFICATIONS... Uniques>
    struct UniqueList{
        const std::array<UNIQUE_IDENTIFICATIONS, sizeof...(Uniques)> _unique_list{{Uniques...}};

    protected:
        UniqueList() noexcept = default;
        virtual_indbug ~UniqueList() noexcept = default;
    };

    //! Lehre Liste, statt nullptr Rückgaben
    typedef UniqueList<>
    TYPELIST_empty_copyCompatible;

}

#endif // UNIQUES_HPP_INCLUDED
