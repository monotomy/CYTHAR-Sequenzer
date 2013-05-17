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

#ifndef DC_GUI_INITS_H_INCLUDED
#define DC_GUI_INITS_H_INCLUDED

#include <stdint.h>

#include <cast/lexical_cast.hpp>

namespace dc_objects{

    /***********************************************************************/
    /*! \GenZeroId

        Generiert je UNIQUE fortlaufend, lineare Ids.
    */
    /***********************************************************************/
    template<class UNIQUE_IT>
    struct GenZeroId
    {
    NOT_INSTANCEABLE(GenZeroId)

        static TYPE_index_child get_next() noexcept
        {
            return 0;
        }

        static TYPE_index_child get_parent_id() noexcept
        {
            return 0;
        }
    };

    static const std::string FIRST_STEPMASTER_BUTTON_STRING{"STEP"};
    static const std::string FIRST_TAKTMASTER_BUTTON_STRING{"BAR"};
    static const std::string FIRST_PATTERNMASTER_BUTTON_STRING{"PATn"};

    /***********************************************************************/
    /*! \InitButtonText

        Generiert je UNIQUE fortlaufend name sowie eine Id.
    */
    /***********************************************************************/
    struct InitButtonText
    {
    NOT_INSTANCEABLE(InitButtonText)

        template<class UNIQUE_IT, class TYPE_element>
        static void set_first_string_then_number(std::string const& first_button_text__,
                                                 TYPE_element element__) noexcept
        {
            static uint8_t our_instance_counter{0};
            ++our_instance_counter;
            if( our_instance_counter == 1 )
                element__->setText((first_button_text__+ "\n").c_str());
            else
                element__->setText((lexical_cast<std::string>(our_instance_counter)+ "\n").c_str());
        }
    };

    /***********************************************************************/
    /*! \GenEndlessLinearId

        Generiert je UNIQUE fortlaufend, lineare Ids.
    */
    /***********************************************************************/
    template<class UNIQUE_IT>
    struct GenEndlessLinearId
    {
    NOT_INSTANCEABLE(GenEndlessLinearId)

        static TYPE_index_child get_next() noexcept
        {
            static char id_counter{-1};
            return ++id_counter;
        }

        static TYPE_index_child get_parent_id() noexcept
        {
            return 0;
        }
    };

    /***********************************************************************/
    /*! \Gen_ElementId_perSaiteId

        1. Erstellt je UNIQUE-Spezialisierung fortlaufende Element Ids
        2. Berechnte ebenfalls die Saiten Id zur aktuellen Element Id
    */
    /***********************************************************************/
    template<TYPE_index_child Elements_per_Saite, class UNIQUE_IT_PER_ELEMENTTYPE>
    class GenElementId_perSaiteId
    {
    NOT_INSTANCEABLE(GenElementId_perSaiteId)

        static char counter_onSaite_elementId;
        static char current_saiteId;
    public:
        static TYPE_index_child get_next()
        {
            ++counter_onSaite_elementId;
            current_saiteId = floor(counter_onSaite_elementId/Elements_per_Saite);

            return counter_onSaite_elementId - current_saiteId*Elements_per_Saite;
        }

        static TYPE_index_child get_parent_id()
        {
            return current_saiteId;
        }
    };

    template
    <
        TYPE_index_child Elements_per_Saite,
        class UNIQUE_IT_PER_ELEMENTTYPE
    >
    char GenElementId_perSaiteId
         <
            Elements_per_Saite,
            UNIQUE_IT_PER_ELEMENTTYPE
         >
    ::counter_onSaite_elementId{-1};

    template
    <
        TYPE_index_child Elements_per_Saite,
        class UNIQUE_IT_PER_ELEMENTTYPE
    >
    char GenElementId_perSaiteId
         <
            Elements_per_Saite,
            UNIQUE_IT_PER_ELEMENTTYPE
         >
    ::current_saiteId{0};

    /***********************************************************************/
    /*! \Gen_saite_id_over_parents

    */
    /***********************************************************************/
//!\class Gen_saite_id_over_parents
    #define TEMP_DEF_Gen_saite_id_over_parents \
        TYPE_index_child Elements_to_next_parent, \
        TYPE_index_child Reset_parent_to_zero_at, \
        class UNIQUE_IT_PER_CLIENT

    #define TEMP_SPEZ_Gen_saite_id_over_parents \
        Elements_to_next_parent, \
        Reset_parent_to_zero_at, \
        UNIQUE_IT_PER_CLIENT

    template<TEMP_DEF_Gen_saite_id_over_parents>
    class Gen_saite_id_over_parents
    {
    NOT_INSTANCEABLE(Gen_saite_id_over_parents)

        static TYPE_index_child counter_saite_id;
        static TYPE_index_child counter_paren_id;
        static TYPE_index_child saite_perParent_offset_id;

        static TYPE_index_child _saite_id;
        static TYPE_index_child _paren_id;
    public:
        static TYPE_index_child get_next()
        {
            _saite_id = counter_saite_id + saite_perParent_offset_id;
            _paren_id = counter_paren_id;

            ++counter_saite_id;
            if(counter_saite_id == Elements_to_next_parent)
            {
                counter_saite_id = 0;
                ++counter_paren_id;
                if(counter_paren_id == Reset_parent_to_zero_at)
                {
                    counter_paren_id = 0;
                    ++saite_perParent_offset_id;
                }
            }

            return _saite_id;
        }

        static TYPE_index_child get_parent_id(){
            return _paren_id;
        }
    };

    template<TEMP_DEF_Gen_saite_id_over_parents>
    TYPE_index_child Gen_saite_id_over_parents<TEMP_SPEZ_Gen_saite_id_over_parents>
    ::_saite_id{0};

    template<TEMP_DEF_Gen_saite_id_over_parents>
    TYPE_index_child Gen_saite_id_over_parents<TEMP_SPEZ_Gen_saite_id_over_parents>
    ::_paren_id{0};

    template<TEMP_DEF_Gen_saite_id_over_parents>
    TYPE_index_child Gen_saite_id_over_parents<TEMP_SPEZ_Gen_saite_id_over_parents>
    ::counter_saite_id{0};

    template<TEMP_DEF_Gen_saite_id_over_parents>
    TYPE_index_child Gen_saite_id_over_parents<TEMP_SPEZ_Gen_saite_id_over_parents>
    ::counter_paren_id{0};

    template<TEMP_DEF_Gen_saite_id_over_parents>
    TYPE_index_child Gen_saite_id_over_parents<TEMP_SPEZ_Gen_saite_id_over_parents>
    ::saite_perParent_offset_id{0};
}

#endif // DC_GUI_INITS_H_INCLUDED
