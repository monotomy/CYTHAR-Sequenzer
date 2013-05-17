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

#ifndef GUI_EXCLUSIVE_BOX_H_INCLUDED
#define GUI_EXCLUSIVE_BOX_H_INCLUDED

#include <map>
#include <array>
#include <stddef.h>

#include <QWidget>
#include <QPushButton>

namespace gui{

    /***********************************************************************/
    /*! \class  ExclusiveBox

        Alle in dieser Box hinterlegten elemente haben eine exclusive
        Eigenschaft, wärend alle weiteren diese ablegen.

        Das "wie" wird als Policy übergeben und kann frei gestalltet werden.
        Erwartet wird in der Policy die Funktion exec()

        Die elemente werden als Zeiger auf Zeiger abgelegt.

        ABER ACHTUNG: Sind die target-Zeiger nicht initalisiert, knallts ;-)
    */
    /***********************************************************************/
    template<class EnumClass,
             class POLICY_set_exclusive,
             class POLICY_set_unexclusive
    >
    class ExclusiveBox
    {
        static constexpr size_t enum_size{static_cast<size_t>(EnumClass::ENUM_CLASS_SIZE)};
        typedef std::array<QWidget*const*, enum_size> TYPE_element_container;
        TYPE_element_container const _exclusive_elements;

        ExclusiveBox() noexcept = delete;
    public:
        //! Initalisiert die Box mit Zeigern auf Zeiger im Pair wird die Beziehung zu einem Enum Index
        //! Hergestellt/übergeben.
        ExclusiveBox(std::array<std::pair<EnumClass, QWidget*const*>, enum_size> elements_2_index__) noexcept;
        ~ExclusiveBox() noexcept = default;
    private:
        /// Castet den Übergabecontainer in TYPE_element_container
        template<class INIT_pairARRAY>
        inline static TYPE_element_container cast_from_init_array_to_array(INIT_pairARRAY const& elements2cast__) noexcept;

    public:
        //! Setzt das Element nach einfüge Reigenfolge als exclusive.
        inline void set_element_per_id_exclusive(EnumClass element_id__) noexcept;
    };

    //! HELFERMAKROS UM DEN CODE LESBARER ZU GESTALTEN
    //! Initalisierung
    #define RELATION_(ARG_ENUM_TYPE, ARG_PTR2PTR_ELEMENT) \
    {ARG_ENUM_TYPE, reinterpret_cast<QWidget*const*>(&ARG_PTR2PTR_ELEMENT) }

    #define EXCLUSIVE_(...) \
    {{ __VA_ARGS__ }}

    //  enum class : ANY_ENUM
    //  {
    //      A,
    //      B,
    //      C,
    //
    //      ENUM_CLASS_SIZE         <- dont forget!
    //  };
    //
    //
    // class Any
    // {
    // typedef ExclusiveBox<LEVEL_TAB_SHOW,
    //                      POLICY_set_as_exclusive,
    //                      POLICY_set_as_unexclusive>
    // TYPE_exclusive_box;

    // TYPE_exclusive_box box{EXCLUSIVE_(RELATION_(ANY_ENUM::A, any_gui_element_a),
    //                                   RELATION_(ANY_ENUM::B, any_gui_element_b),
    //                                   RELATION_(ANY_ENUM::C, any_gui_element_c))};
    // };
}

#include <extendQt_exclusive_box.hpp>

using namespace gui;

#endif // GUI_EXCLUSIVE_BOX_H_INCLUDED
