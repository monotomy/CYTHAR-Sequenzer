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

#ifndef OBJECT_STEP_HPP_INCLUDED
#define OBJECT_STEP_HPP_INCLUDED

#include <dc_standard_types.h>
#include <dc_standard_values.h>

#include <uniques.hpp>

#include <tuple>

namespace dc_objects{

    //! ********************************************************************
    //! ********************************************************************
    //! \Step
    //! ********************************************************************
    //! ********************************************************************
    //! ********************************************************************
//!\Indize
    enum class StepPropertiesIndex : uint8_t
    {
        OFFSET,
        OFFSET_OPERATOR,
        OFFSET_OPERAND,
        OFFSET_2_INTERVAL_OPERATOR,
        OFFSET_INTERVAL_2_REPEAT_OPERATOR,
        OFFSET_FIT_TO_RANGE,

        VELOCITY,
        VELOCITY_OPERATOR,
        VELOCITY_OPERAND,
        VELOCITY_2_INTERVAL_OPERATOR,
        VELOCITY_INTERVAL_2_REPEAT_OPERATOR,
        VELOCITY_FIT_TO_RANGE,

        LENGTH,
        LENGTH_OPERATOR,
        LENGTH_OPERAND,
        LENGTH_2_INTERVAL_OPERATOR,
        LENGTH_INTERVAL_2_REPEAT_OPERATOR,
        LENGTH_FIT_TO_RANGE,

        DELAY,
        REPEAT_TIMES,

        INTERVAL,
        INTERVAL_OPERATOR,
        INTERVAL_OPERAND,

        IS_MUTED,
        IS_INIT
    };

//!\Typedef
    typedef bool TYPE_fit_2_range;
    typedef std::tuple
    <
        TYPE_offset,
        TYPE_operator,
        TYPE_operand,
        TYPE_operator,
        TYPE_operator,
        TYPE_fit_2_range,

        TYPE_velocity,
        TYPE_operator,
        TYPE_operand,
        TYPE_operator,
        TYPE_operator,
        TYPE_fit_2_range,

        TYPE_lengthy,
        TYPE_operator,
        TYPE_operand,
        TYPE_operator,
        TYPE_operator,
        TYPE_fit_2_range,

        TYPE_delay_inClocks,
        TYPE_repeat_times,

        TYPE_interval,
        TYPE_operator,
        TYPE_operand,

        TYPE_is_mute,
        TYPE_is_init
    >
    StepPropertiesTuple;

    typedef std::array<std::string, std::tuple_size<StepPropertiesTuple>::value> TYPE_StepPropertiesNames;
    static const TYPE_StepPropertiesNames StepPropertiesNames
    {{
        STRING_prop_OFFSET,
        STRING_prop_OFFSET_OPERATOR,
        STRING_prop_OFFSET_OPERAND,
        STRING_prop_OFFSET_2_INTERVAL_OPERATOR,
        STRING_prop_OFFSET_INTERVAL_2_REPEAT_OPERATOR,
        STRING_prop_OFFSET_FIT_TO_RANGE,

        STRING_prop_VELOCITY,
        STRING_prop_VELOCITY_OPERATOR,
        STRING_prop_VELOCITY_OPERAND,
        STRING_prop_VELOCITY_2_INTERVAL_OPERATOR,
        STRING_prop_VELOCITY_INTERVAL_2_REPEAT_OPERATOR,
        STRING_prop_VELOCITY_FIT_TO_RANGE,

        STRING_prop_LENGTH,
        STRING_prop_LENGTH_OPERATOR,
        STRING_prop_LENGTH_OPERAND,
        STRING_prop_LENGTH_2_INTERVAL_OPERATOR,
        STRING_prop_LENGTH_INTERVAL_2_REPEAT_OPERATOR,
        STRING_prop_LENGTH_FIT_TO_RANGE,

        STRING_prop_DELAY,
        STRING_prop_REPEAT_TIMES,

        STRING_prop_INTERVAL,
        STRING_prop_INTERVAL_OPERATOR,
        STRING_prop_INTERVAL_OPERAND,

        STRING_prop_IS_MUTED,
        STRING_prop_IS_INIT
    }};

//!\Defaultwerte
    static constexpr TYPE_offset            Step_DEFAULT_OFFSET = 0;
    static constexpr TYPE_operator          Step_DEFAULT_OFFSET_OPERATOR = static_cast<TYPE_operator>(OPERATOR::NOT);
    static constexpr TYPE_operand           Step_DEFAULT_OFFSET_OPERAND = 0;
    static constexpr TYPE_operator          Step_DEFAULT_OFFSET_2_INTERVAL_OPERATOR = static_cast<TYPE_operator>(OPERATOR::NOT);
    static constexpr TYPE_operator          Step_DEFAULT_OFFSET_INTERVAL_2_REPEAT_OPERATOR = static_cast<TYPE_operator>(OPERATOR::NOT);
    static constexpr TYPE_fit_2_range       Step_DEFAULT_OFFSET_FIT_TO_RANGE = true;

    static constexpr TYPE_velocity          Step_DEFAULT_VELOCITY = 0;
    static constexpr TYPE_operator          Step_DEFAULT_VELOCITY_OPERATOR = static_cast<TYPE_operator>(OPERATOR::NOT);
    static constexpr TYPE_operand           Step_DEFAULT_VELOCITY_OPERAND = 0;
    static constexpr TYPE_operator          Step_DEFAULT_VELOCITY_2_INTERVAL_OPERATOR = static_cast<TYPE_operator>(OPERATOR::NOT);
    static constexpr TYPE_operator          Step_DEFAULT_VELOCITY_INTERVAL_2_REPEAT_OPERATOR = static_cast<TYPE_operator>(OPERATOR::NOT);
    static constexpr TYPE_fit_2_range       Step_DEFAULT_VELOCITY_FIT_TO_RANGE = true;

    static constexpr TYPE_lengthy           Step_DEFAULT_LENGTH = 0;
    static constexpr TYPE_operator          Step_DEFAULT_LENGTH_OPERATOR = static_cast<TYPE_operator>(OPERATOR::NOT);
    static constexpr TYPE_operand           Step_DEFAULT_LENGTH_OPERAND = 0;
    static constexpr TYPE_operator          Step_DEFAULT_LENGTH_2_INTERVAL_OPERATOR = static_cast<TYPE_operator>(OPERATOR::NOT);
    static constexpr TYPE_operator          Step_DEFAULT_LENGTH_INTERVAL_2_REPEAT_OPERATOR = static_cast<TYPE_operator>(OPERATOR::NOT);
    static constexpr TYPE_fit_2_range       Step_DEFAULT_LENGTH_FIT_TO_RANGE = true;

    static constexpr TYPE_delay_inClocks    Step_DEFAULT_DELAY_inCLOCKS = 0;
    static constexpr TYPE_repeat_times      Step_DEFAULT_REPEAT_TIMES = 0;

    static constexpr TYPE_lengthy           Step_DEFAULT_INTERVAL = 0;
    static constexpr TYPE_operator          Step_DEFAULT_INTERVAL_OPERATOR = static_cast<TYPE_operator>(OPERATOR::PLUS);
    static constexpr TYPE_operand           Step_DEFAULT_INTERVAL_OPERAND = 0;

    static constexpr TYPE_is_mute           Step_DEFAULT_IS_MUTE = false;
    static constexpr TYPE_is_init           Step_DEFAULT_IS_INIT =false;

    static constexpr StepPropertiesTuple DEFAULT_StepPropertiesTuple
    {
        std::make_tuple(Step_DEFAULT_OFFSET,
                        Step_DEFAULT_OFFSET_OPERATOR,
                        Step_DEFAULT_OFFSET_OPERAND,
                        Step_DEFAULT_OFFSET_2_INTERVAL_OPERATOR,
                        Step_DEFAULT_OFFSET_INTERVAL_2_REPEAT_OPERATOR,
                        Step_DEFAULT_OFFSET_FIT_TO_RANGE,

                        Step_DEFAULT_VELOCITY,
                        Step_DEFAULT_VELOCITY_OPERATOR,
                        Step_DEFAULT_VELOCITY_OPERAND,
                        Step_DEFAULT_VELOCITY_2_INTERVAL_OPERATOR,
                        Step_DEFAULT_VELOCITY_INTERVAL_2_REPEAT_OPERATOR,
                        Step_DEFAULT_VELOCITY_FIT_TO_RANGE,

                        Step_DEFAULT_LENGTH,
                        Step_DEFAULT_LENGTH_OPERATOR,
                        Step_DEFAULT_LENGTH_OPERAND,
                        Step_DEFAULT_LENGTH_2_INTERVAL_OPERATOR,
                        Step_DEFAULT_LENGTH_INTERVAL_2_REPEAT_OPERATOR,
                        Step_DEFAULT_LENGTH_FIT_TO_RANGE,

                        Step_DEFAULT_DELAY_inCLOCKS,
                        Step_DEFAULT_REPEAT_TIMES,

                        Step_DEFAULT_INTERVAL,
                        Step_DEFAULT_INTERVAL_OPERATOR,
                        Step_DEFAULT_INTERVAL_OPERAND,

                        Step_DEFAULT_IS_MUTE,
                        Step_DEFAULT_IS_INIT)
    };

//!\Objectsructuredef
    typedef objectsructure::Properties
    <
        StepPropertiesIndex,
        StepPropertiesTuple,
        objectsructure::PROPERTY_OBSERVER_MODE::IS_OBSERVEABLE
    >
    StepProperties;

//!\Compatibilitydef
    typedef UniqueList
    <
        UNIQUE_IDENTIFICATIONS::Step,
        UNIQUE_IDENTIFICATIONS::Taktsaite,
        UNIQUE_IDENTIFICATIONS::Takt
    >
    TYPELIST_2Clipboard_is_copyCompatible;

//!\Compatibilitydef
    typedef UniqueList
    <
        UNIQUE_IDENTIFICATIONS::Step,
        UNIQUE_IDENTIFICATIONS::MainwindowClipboard
    >
    TYPELIST_2Step_is_copyCompatible;

//!\class Step
    class Step final :
        public StepProperties,

        public UNIQUE<UNIQUE_IDENTIFICATIONS::Step>,
        public TYPELIST_2Step_is_copyCompatible,

        public objectsructure::HAS_NO_CHILDARRAY
    {
    public:
        Step() noexcept;
        ~Step() noexcept = default;

    private:
        //!\Databaseinformations
        friend class phys::MemPhysMediator;

        typedef std::tuple<> TYPELIST_childs;

        static const std::string& _KEY_NAME;
        static const TYPE_StepPropertiesNames& _ENTITY_NAMES;
    };

}

#endif // OBJECT_STEP_HPP_INCLUDED
