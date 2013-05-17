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

#include <dc_objectstructure.h>

namespace dc_objects{

//!\class Step
    Step
    ::Step() noexcept :
        StepProperties{DEFAULT_StepPropertiesTuple}
    {}
    const std::string& Step::_KEY_NAME{STRING_type_Step};
    const TYPE_StepPropertiesNames& Step::_ENTITY_NAMES = StepPropertiesNames;

//!\class Taktchain
    Taktchain
    ::Taktchain() noexcept :
        TaktchainProperties{DEFAULT_TaktchainPropertiesTuple}
    {}
    const std::string& Taktchain::_KEY_NAME{STRING_type_Taktchain};
    const TYPE_TaktchainPropertiesNames& Taktchain::_ENTITY_NAMES = TaktchainPropertiesNames;

//!\class Taktsaite
    Taktsaite
    ::Taktsaite() noexcept :
        TaktsaiteProperties{DEFAULT_TaktsaitePropertiesTuple}
    {}
    const std::string& Taktsaite::_KEY_NAME{STRING_type_Taktsaite};
    const TYPE_TaktsaitePropertiesNames& Taktsaite::_ENTITY_NAMES = TaktsaitePropertiesNames;

//!\class Takt
    Takt
    ::Takt() noexcept :
        TaktProperties{DEFAULT_TaktPropertiesTuple}
    {}
    const std::string& Takt::_KEY_NAME{STRING_type_Takt};
    const TYPE_TaktPropertiesNames& Takt::_ENTITY_NAMES = TaktPropertiesNames;

//!\class Patternsaite
    Patternsaite
    ::Patternsaite() noexcept :
        PatternsaiteProperties{DEFAULT_PatternsaitePropertiesTuple}
    {
        this->set_property<PatternsaitePropertiesIndex::PORT_NAME>("no device set");
    }
    const std::string& Patternsaite::_KEY_NAME{STRING_type_Patternsaite};
    const TYPE_PatternsaitePropertiesNames& Patternsaite::_ENTITY_NAMES = PatternsaitePropertiesNames;

//!\class Pattern
    Pattern
    ::Pattern() noexcept :
        PatternProperties{DEFAULT_PatternPropertiesTuple}
    {}
    const std::string& Pattern::_KEY_NAME{STRING_type_Pattern};
    const TYPE_PatternPropertiesNames& Pattern::_ENTITY_NAMES = PatternPropertiesNames;

//!\class Project
    Project
    ::Project() noexcept :
        ProjectProperties{DEFAULT_ProjectPropertiesTuple}
    {}

    const std::string& Project::_KEY_NAME{STRING_type_Project};
    const TYPE_ProjectPropertiesNames& Project::_ENTITY_NAMES = ProjectPropertiesNames;

//!\class Temporary
    Temporary
    ::Temporary() noexcept :
        TemporaryProperties{DEFAULT_TemporaryPropertiesTuple}
    {}

//!\class Accord
    Accord
    ::Accord() noexcept :
        AccordProperties{DEFAULT_AccordPropertiesTuple}
    {}

    Accord
    ::Accord(TYPE_offset e__,
            TYPE_offset b__,
            TYPE_offset g__,
            TYPE_offset d__,
            TYPE_offset A__,
            TYPE_offset E__) noexcept :
        AccordProperties{DEFAULT_AccordPropertiesTuple}
    {
        set_property<AccordPropertiesIndex::SAITE_e>(e__);
        set_property<AccordPropertiesIndex::SAITE_b>(b__);
        set_property<AccordPropertiesIndex::SAITE_g>(g__);
        set_property<AccordPropertiesIndex::SAITE_d>(d__);
        set_property<AccordPropertiesIndex::SAITE_A>(A__);
        set_property<AccordPropertiesIndex::SAITE_E>(E__);
    }

//!\class Sequencer
    Sequencer
    ::Sequencer() noexcept :
        SequencerProperties{DEFAULT_SequencerPropertiesTuple}
    {}

}
