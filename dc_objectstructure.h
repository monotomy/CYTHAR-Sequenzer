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

#ifndef DC_OBJECTS_H_INCLUDED
#define DC_OBJECTS_H_INCLUDED

#include <dc_standard_types.h>
#include <dc_standard_values.h>

#include <uniques.hpp>

#include <objectstructure.h>
#include <pattern/singleton.hpp>
#include <class/properties.hpp>

#include <string>

#include <object_step.hpp>

    /// TODO Limits -> von/bis

    /// COPYFUNKTION: Markiere Stepmaster, Taktmaster oder Patternmaster, Mark Taktsaite oder Patternsaite
    /// Mix Mutebutton mit Notenanzeige

    /// Feature: binde events an steps, so kann im step eine infoanzeige implementiert werden - ob was läuft...

    /// Copy Step

    /// Copy Accord to Takt

namespace phys{ class MemPhysMediator; }
namespace dc_objects{

    /// Castet enums 2 int
    #define enum2int(ARG_MODE__ARG_ENUM_INDEX) \
        static_cast<int>(ARG_MODE__ARG_ENUM_INDEX)

    #define int2enum(ARG_ENUMCLASS, ARG_ENUM_INDEX) \
        static_cast<ARG_ENUMCLASS>(ARG_ENUM_INDEX)








    //! ********************************************************************
    //! ********************************************************************
    //! \Taktchain
    //! ********************************************************************
    //! ********************************************************************
    //! ********************************************************************
    typedef int TYPE_takt_chain_mode;
    enum ENUM_takt_chain_mode : TYPE_takt_chain_mode
    {
        MODE_AUTO_LOOP = Taktchain_per_Takt,
        MODE_TO_MASTER,

        MODE_ENDLESS = Taktchain_per_Takt+1,
    };

    typedef int TYPE_takt_chain_level_mode;
    enum ENUM_takt_chain_level_mode : TYPE_takt_chain_level_mode
    {
        MODE_AUTO_LEVEL = Taktchain_per_Takt
    };

//!\Indize
    enum class TaktchainPropertiesIndex : int
    {
        FOR,
        NEXT,
        OVERWRITE_TARGET_LEVEL
    };

//!\Typedef
//!\Tupledef
    typedef std::tuple
    <
        TYPE_index_child,
        TYPE_index_child,
        TYPE_takt_chain_level_mode
    >
    TaktchainPropertiesTuple;

//!\Defaultwerte
    static constexpr TYPE_index_child           Taktchain_DEFAULT_FOR = 1;
    static constexpr TYPE_takt_chain_mode       Taktchain_DEFAULT_NEXT = ENUM_takt_chain_mode::MODE_AUTO_LOOP;
    static constexpr TYPE_takt_chain_level_mode Taktchain_DEFAULT_OVERWRITE_TARGET_LEVEL = 0;

    static constexpr TaktchainPropertiesTuple DEFAULT_TaktchainPropertiesTuple
    {
        std::make_tuple(Taktchain_DEFAULT_FOR,
                        Taktchain_DEFAULT_NEXT,
                        Taktchain_DEFAULT_OVERWRITE_TARGET_LEVEL)
    };

    typedef std::array<std::string, std::tuple_size<TaktchainPropertiesTuple>::value> TYPE_TaktchainPropertiesNames;
    static const TYPE_TaktchainPropertiesNames TaktchainPropertiesNames
    {{
        STRING_prop_Taktchain_FOR,
        STRING_prop_Taktchain_NEXT,
        STRING_prop_OVERWRITE_TARGET_LEVEL
    }};

//!\Objectsructuredef
    typedef objectsructure::Properties
    <
        TaktchainPropertiesIndex,
        TaktchainPropertiesTuple,
        objectsructure::PROPERTY_OBSERVER_MODE::IS_OBSERVEABLE
    >
    TaktchainProperties;

//!\class Taktchain
    class Taktchain final :
        public TaktchainProperties,

        public UNIQUE<UNIQUE_IDENTIFICATIONS::Taktchain>,

        public objectsructure::HAS_NO_CHILDARRAY
    {
    public:

        Taktchain() noexcept;
        ~Taktchain() noexcept = default;

    private:
        //!\Databaseinformations
        friend class phys::MemPhysMediator;

        typedef std::tuple<> TYPELIST_childs;

        static const std::string& _KEY_NAME;
        static const TYPE_TaktchainPropertiesNames& _ENTITY_NAMES;
    };







    //! ********************************************************************
    //! ********************************************************************
    //! \Taktsaite
    //! ********************************************************************
    //! ********************************************************************
    //! ********************************************************************
//!\Indize
    enum class TaktsaitePropertiesIndex : bool
    {
        OFFSET,
        IS_MUTED
    };

//!\Typedef
//!\Tupledef
    typedef std::tuple
    <
        TYPE_offset,
        TYPE_is_mute
    >
    TaktsaitePropertiesTuple;

//!\Defaultwerte
    static constexpr TYPE_offset    Taktsaite_DEFAULT_OFFSET = 0;
    static constexpr TYPE_is_mute   Taktsaite_DEFAULT_IS_MUTE = false;

    static constexpr TaktsaitePropertiesTuple DEFAULT_TaktsaitePropertiesTuple
    {
        std::make_tuple(Taktsaite_DEFAULT_OFFSET,
                        Taktsaite_DEFAULT_IS_MUTE)
    };

    typedef std::array<std::string, std::tuple_size<TaktsaitePropertiesTuple>::value> TYPE_TaktsaitePropertiesNames;
    static const TYPE_TaktsaitePropertiesNames TaktsaitePropertiesNames
    {{
        STRING_prop_OFFSET,
        STRING_prop_IS_MUTED
    }};

//!\Objectsructuredef
    typedef objectsructure::Properties
    <
        TaktsaitePropertiesIndex,
        TaktsaitePropertiesTuple,
        objectsructure::PROPERTY_OBSERVER_MODE::IS_OBSERVEABLE
    >
    TaktsaiteProperties;

//!\Childdef
    typedef objectsructure::ChildArray<Step,Step_per_Taktsaite> Steps_in_Taktsaite_T;

//!\Compatibilitydef
    typedef UniqueList
    <
        UNIQUE_IDENTIFICATIONS::Taktsaite
    >
    TYPELIST_2Taktsaite_is_copyCompatible;

//!\class Taktsaite
    class Taktsaite final :
        public TaktsaiteProperties,
        public Steps_in_Taktsaite_T,

        public UNIQUE<UNIQUE_IDENTIFICATIONS::Taktsaite>,
        public TYPELIST_2Taktsaite_is_copyCompatible
    {
    public:

        Taktsaite() noexcept;
        ~Taktsaite() noexcept = default;

        inline auto step(size_t step_id__) const noexcept
        -> decltype(Steps_in_Taktsaite_T::child(step_id__))
        {
            return Steps_in_Taktsaite_T::child(step_id__);
        }

        //!\DRAGnDROP
        static constexpr unsigned int CHILD_COPY_DEEPNESS{1}; // Steps

    private:
        //!\Databaseinformations
        friend class phys::MemPhysMediator;

        typedef std::tuple<Steps_in_Taktsaite_T> TYPELIST_childs;

        static const std::string& _KEY_NAME;
        static const TYPE_TaktsaitePropertiesNames& _ENTITY_NAMES;
    };

    //! ********************************************************************
    //! ********************************************************************
    //! \Takt
    //! ********************************************************************
    //! ********************************************************************
    //! ********************************************************************
    static constexpr TYPE_index_child TAKT_RUN_LINEAR = Takt_per_Pattern;
//!\Indize
    enum class TaktPropertiesIndex : uint8_t
    {
        OFFSET,
        IS_MUTED,

        ENUM_CLASS_SIZE
    };

//!\Typedef
//!\Tupledef
    typedef std::tuple
    <
        TYPE_offset,
        TYPE_is_mute
    >
    TaktPropertiesTuple;

    typedef std::array<std::string, std::tuple_size<TaktPropertiesTuple>::value> TYPE_TaktPropertiesNames;
    static const TYPE_TaktPropertiesNames TaktPropertiesNames
    {{
        STRING_prop_OFFSET,
        STRING_prop_IS_MUTED
    }};

//!\Defaultwerte
    static constexpr TYPE_offset            Takt_DEFAULT_OFFSET = 0;
    static constexpr TYPE_is_mute           Takt_DEFAULT_IS_MUTE = false;

    static constexpr TaktPropertiesTuple DEFAULT_TaktPropertiesTuple
    {
        std::make_tuple(Takt_DEFAULT_OFFSET,
                        Takt_DEFAULT_IS_MUTE)
    };

    //!\Objectsructuredef
    typedef objectsructure::Properties
    <
        TaktPropertiesIndex,
        TaktPropertiesTuple,
        objectsructure::PROPERTY_OBSERVER_MODE::IS_OBSERVEABLE
    >
    TaktProperties;

//!\Childdef
    typedef objectsructure::ChildArray<Taktsaite,Taktsaiten_per_Takt> Taktsaiten_in_Takt_T;
    typedef objectsructure::ChildArray<Taktchain,Taktchain_per_Takt> Taktchains_in_Takt_T;

//!\Compatibilitydef
    typedef UniqueList
    <
        UNIQUE_IDENTIFICATIONS::Takt
    >
    TYPELIST_2Takt_is_copyCompatible;

//!\class Takt
    class Takt final :
        public TaktProperties,
        public Taktsaiten_in_Takt_T,
        public Taktchains_in_Takt_T,

        public UNIQUE<UNIQUE_IDENTIFICATIONS::Takt>,
        public TYPELIST_2Takt_is_copyCompatible
    {
    public:
        typedef Taktsaiten_in_Takt_T this_Taktsaiten_in_Takt;

        Takt() noexcept;
        ~Takt() noexcept = default;

        inline auto taktsaite(size_t taktsaite_id__) const noexcept
        -> decltype(Taktsaiten_in_Takt_T::child(taktsaite_id__))
        {
            return Taktsaiten_in_Takt_T::child(taktsaite_id__);
        }

        inline auto taktchain(size_t taktchain_id__) const noexcept
        -> decltype(Taktchains_in_Takt_T::child(taktchain_id__))
        {
            return Taktchains_in_Takt_T::child(taktchain_id__);
        }

        //!\DRAGnDROP
        static constexpr unsigned int CHILD_COPY_DEEPNESS{2}; // Taktsaite, Steps

    private:
        //!\Databaseinformations
        friend class phys::MemPhysMediator;

        typedef std::tuple<Taktsaiten_in_Takt_T,
                           Taktchains_in_Takt_T> TYPELIST_childs;

        static const std::string& _KEY_NAME;
        static const TYPE_TaktPropertiesNames& _ENTITY_NAMES;
    };

    //! ********************************************************************
    //! ********************************************************************
    //! \Patternsaite
    //! ********************************************************************
    //! ********************************************************************
    //! ********************************************************************
//!\Indize
    enum class PatternsaitePropertiesIndex : uint8_t
    {
        TUNE_OFFSET,
        ACCORD_OFFSET,
        MIDI_DEVICE_ID_IN_DATABASE,
        MIDI_CHANNEL,
        MUTE_TIME,
        IS_MUTED,
        PORT_NAME
    };

//!\Typedef
//!\Tupledef
    typedef TYPE_offset TYPE_tune_offset;
    typedef TYPE_offset TYPE_accord_offset;
    typedef size_t TYPE_device_id_in_db;
    typedef uint8_t TYPE_midi_channel;

    typedef std::tuple
    <
        TYPE_tune_offset,
        TYPE_accord_offset,
        TYPE_device_id_in_db,
        TYPE_midi_channel,
        TYPE_mute_time_inTakt,
        TYPE_is_mute,
        std::string
    >
    PatternsaitePropertiesTuple;

    typedef std::array<std::string, std::tuple_size<PatternsaitePropertiesTuple>::value> TYPE_PatternsaitePropertiesNames;
    static const TYPE_PatternsaitePropertiesNames PatternsaitePropertiesNames
    {{
        STRING_prop_TUNE_OFFSET,
        STRING_prop_ACCORD_OFFSET,
        STRING_prop_MIDI_DEVICE_ID_IN_DATABASE,
        STRING_prop_MIDI_CHANNEL,
        STRING_prop_MUTE_TIME,
        STRING_prop_IS_MUTED,
        {"port"}
    }};

//!\Defaultwerte
    static constexpr TYPE_offset            OFFSET_IS_MUTE = -1;
    static constexpr TYPE_device_id_in_db   DEVICE_NOT_SET = 0;

    static constexpr TYPE_tune_offset       Patternsaite_DEFAULT_TUNE_OFFSET = 0;
    static constexpr TYPE_accord_offset     Patternsaite_DEFAULT_ACCORD_OFFSET = 0;
    static constexpr TYPE_device_id_in_db   Patternsaite_DEFAULT_MIDI_DEVICE_ID_IN_DATABASE = DEVICE_NOT_SET;
    static constexpr TYPE_midi_channel      Patternsaite_DEFAULT_MIDI_CHANNEL = 0;
    static constexpr TYPE_mute_time_inTakt  Patternsaite_DEFAULT_MUTE_TIME = IS_MANUAL_MUTED;
    static constexpr TYPE_is_mute           Patternsaite_DEFAULT_IS_MUTE = false;
    static const     std::string            Patternsaite_DEFAULT_PORT_NAME = "choose device";

    static const PatternsaitePropertiesTuple DEFAULT_PatternsaitePropertiesTuple
    {
        std::make_tuple(Patternsaite_DEFAULT_TUNE_OFFSET,
                        Patternsaite_DEFAULT_ACCORD_OFFSET,
                        Patternsaite_DEFAULT_MIDI_DEVICE_ID_IN_DATABASE,
                        Patternsaite_DEFAULT_MIDI_CHANNEL,
                        Patternsaite_DEFAULT_MUTE_TIME,
                        Patternsaite_DEFAULT_IS_MUTE,
                        "choose device")
    };

//!\Objectsructuredef
    typedef objectsructure::Properties
    <
        PatternsaitePropertiesIndex,
        PatternsaitePropertiesTuple,
        objectsructure::PROPERTY_OBSERVER_MODE::IS_OBSERVEABLE
    >
    PatternsaiteProperties;

//!\Compatibilitydef
    typedef UniqueList
    <
        UNIQUE_IDENTIFICATIONS::Patternsaite
    >
    TYPELIST_2Patternsaite_is_copyCompatible;

//!\class Patternsaite
    struct Patternsaite final :
        public PatternsaiteProperties,

        public UNIQUE<UNIQUE_IDENTIFICATIONS::Patternsaite>,
        public TYPELIST_2Patternsaite_is_copyCompatible,

        public objectsructure::HAS_NO_CHILDARRAY
    {
        Patternsaite() noexcept;
        ~Patternsaite() noexcept = default;


    private:
        //!\Databaseinformations
        friend class phys::MemPhysMediator;

        typedef std::tuple<> TYPELIST_childs;

        static const std::string& _KEY_NAME;
        static const TYPE_PatternsaitePropertiesNames& _ENTITY_NAMES;
    };

    //! ********************************************************************
    //! ********************************************************************
    //! \Pattern
    //! ********************************************************************
    //! ********************************************************************
    //! ********************************************************************
//!\Indize
    enum class PatternPropertiesIndex : uint8_t
    {
        OFFSET,
        MUTE_TIME,
        IS_MUTED,

        USE_TAKT_OFFSET_per,
        USE_TAKTSAITE_OFFSET_per,
        USE_TAKTSAITE_MUTE_per
    };

//!\Tupledef
    typedef uint8_t TYPE_overhide_byTakt;

    typedef bool TYPE_use_takt_offset_per;
    typedef bool TYPE_use_taktsaite_offset_per;
    typedef bool TYPE_use_taktmute_offset_per;

    typedef std::tuple
    <
        TYPE_offset,
        TYPE_mute_time_inTakt,
        TYPE_is_mute,

        TYPE_use_takt_offset_per,
        TYPE_use_taktsaite_offset_per,
        TYPE_use_taktmute_offset_per
    >
    PatternPropertiesTuple;

    typedef std::array<std::string, std::tuple_size<PatternPropertiesTuple>::value> TYPE_PatternPropertiesNames;
    static const TYPE_PatternPropertiesNames PatternPropertiesNames
    {{
        STRING_prop_OFFSET,
        STRING_prop_MUTE_TIME,
        STRING_prop_IS_MUTED,

        STRING_prop_USE_TAKT_OFFSET_per,
        STRING_prop_USE_TAKTSAITE_OFFSET_per,
        STRING_prop_USE_TAKTSAITE_MUTE_per
    }};

    enum USE_PER_MODE : uint8_t
    {
        USE_PER_MODE_RUN_MASTER,
        USE_PER_MODE_RUN_CURRENT
    };

//!\Defaultwerte
    static constexpr TYPE_offset                Pattern_DEFAULT_OFFSET = 0;
    static constexpr TYPE_mute_time_inTakt      Pattern_DEFAULT_MUTE_TIME = IS_MANUAL_MUTED;
    static constexpr TYPE_is_mute               Pattern_DEFAULT_IS_MUTE = false;

    static constexpr TYPE_use_takt_offset_per       Pattern_DEFAULT_USE_TAKT_OFFSET_per = USE_PER_MODE::USE_PER_MODE_RUN_MASTER;
    static constexpr TYPE_use_taktsaite_offset_per  Pattern_DEFAULT_USE_TAKTSAITE_OFFSET_per = USE_PER_MODE::USE_PER_MODE_RUN_MASTER;
    static constexpr TYPE_use_taktmute_offset_per   Pattern_DEFAULT_USE_TAKTSAITE_MUTE_per = USE_PER_MODE::USE_PER_MODE_RUN_MASTER;

    static constexpr PatternPropertiesTuple DEFAULT_PatternPropertiesTuple
    {
        std::make_tuple(Pattern_DEFAULT_OFFSET,
                        Pattern_DEFAULT_MUTE_TIME,
                        Pattern_DEFAULT_IS_MUTE,

                        Pattern_DEFAULT_USE_TAKT_OFFSET_per,
                        Pattern_DEFAULT_USE_TAKTSAITE_OFFSET_per,
                        Pattern_DEFAULT_USE_TAKTSAITE_MUTE_per)
    };

//!\Objectsructuredef
    typedef objectsructure::Properties<PatternPropertiesIndex,
                                       PatternPropertiesTuple,
                                       objectsructure::PROPERTY_OBSERVER_MODE::IS_OBSERVEABLE
    > PatternProperties;

//!\Childdef
    typedef objectsructure::ChildArray<Takt,Takt_per_Pattern> Takt_in_Pattern_T;
    typedef objectsructure::ChildArray<Patternsaite,Patternsaiten_per_Pattern> Patternsaiten_in_Pattern_T;

//!\Compatibilitydef
    typedef UniqueList
    <
        UNIQUE_IDENTIFICATIONS::Pattern
    >
    TYPELIST_2Pattern_is_copyCompatible;

//!\class Pattern
    struct Pattern final :
        public PatternProperties,
        public Takt_in_Pattern_T,
        public Patternsaiten_in_Pattern_T,

        public UNIQUE<UNIQUE_IDENTIFICATIONS::Pattern>,
        public TYPELIST_2Pattern_is_copyCompatible
    {
        Pattern() noexcept;
        ~Pattern() noexcept = default;

        inline auto takt(size_t takt_id__) const noexcept
        -> decltype(Takt_in_Pattern_T::child(takt_id__))
        {
            return Takt_in_Pattern_T::child(takt_id__);
        }

        inline auto patternsaite(size_t patternsaite_id__) const noexcept
        -> decltype(Patternsaiten_in_Pattern_T::child(patternsaite_id__))
        {
            return Patternsaiten_in_Pattern_T::child(patternsaite_id__);
        }

        //!\DRAGnDROP
        static constexpr unsigned int CHILD_COPY_DEEPNESS{3}; // Takte, Taktsaiten, Steps

    private:

        //!\Databaseinformations
        friend class phys::MemPhysMediator;

        typedef std::tuple<Takt_in_Pattern_T,
                           Patternsaiten_in_Pattern_T
        > TYPELIST_childs;

        static const std::string& _KEY_NAME;
        static const TYPE_PatternPropertiesNames& _ENTITY_NAMES;
    };

    //! ********************************************************************
    //! ********************************************************************
    //! \Project
    //! ********************************************************************
    //! ********************************************************************
    //! ********************************************************************
//!\Indize
    enum class ProjectPropertiesIndex : uint8_t
    {
        CLOCKSPEED_inBPM_x_100,
        IS_MASTER
    };

//!\Typedef
//!\Tupledef
    typedef unsigned int TYPE_clockspeed_inBPM_x_100;
    typedef bool TYPE_is_master;

    typedef std::tuple
    <
        TYPE_clockspeed_inBPM_x_100,
        TYPE_is_master
    >
    ProjectPropertiesTuple;

    typedef std::array<std::string, std::tuple_size<ProjectPropertiesTuple>::value> TYPE_ProjectPropertiesNames;
    static const TYPE_ProjectPropertiesNames ProjectPropertiesNames
    {{
        STRING_prop_CLOCKSPEED_inBPM_x_100,
        STRING_prop_IS_MASTER
    }};

//!\Defaultwerte
    static constexpr TYPE_clockspeed_inBPM_x_100   Project_DEFAULT_CLOCKSPEED_inBPM_x_100 = 120;
    static constexpr TYPE_is_master         Project_DEFAULT_IS_MASTER = true;

    static constexpr ProjectPropertiesTuple DEFAULT_ProjectPropertiesTuple
    {
        std::make_tuple(Project_DEFAULT_CLOCKSPEED_inBPM_x_100,
                        Project_DEFAULT_IS_MASTER)
    };

//!\Objectsructuredef
    typedef objectsructure::Properties
    <
        ProjectPropertiesIndex,
        ProjectPropertiesTuple,
        objectsructure::PROPERTY_OBSERVER_MODE::IS_OBSERVEABLE
    >
    ProjectProperties;

//!\Childdef
    typedef objectsructure::ChildArray<Pattern,Pattern_per_Project> Pattern_in_Project_T;

//!\class Project
    class Project :
        public ProjectProperties,
        public Pattern_in_Project_T
    {
    public:
        //Project() = delete;
        Project() noexcept;
        ~Project() noexcept = default;

        inline auto pattern(size_t pattern_id__) const noexcept
        -> decltype(Pattern_in_Project_T::child(pattern_id__))
        {
            return Pattern_in_Project_T::child(pattern_id__);
        }

    private:
        //!\Databaseinformations
        friend class phys::MemPhysMediator;

        typedef std::tuple<Pattern_in_Project_T> TYPELIST_childs;

        static const std::string& _KEY_NAME;
        static const TYPE_ProjectPropertiesNames& _ENTITY_NAMES;
    };

    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################

    //! ********************************************************************
    //! ********************************************************************
    //! \Sequencer
    //! ********************************************************************
    //! ********************************************************************
    //! ********************************************************************
//!\Indize
    enum class SequencerPropertiesIndex : uint8_t
    {
        CLOCK_POS,  // 1-96
        STEP_POS,   // 1-16
        TAKT_POS    // 1-16
    };

//!\Tupledef
    typedef std::tuple
    <
        TYPE_clockstep,
        TYPE_clockstep,
        TYPE_clockstep
    >
    SequencerPropertiesTuple;

//!\Defaultwerte
    static constexpr TYPE_clockstep     Sequencer_DEFAULT_CLOCK_POS = 0;
    static constexpr TYPE_clockstep     Sequencer_DEFAULT_STEP_POS = 0;
    static constexpr TYPE_clockstep     Sequencer_DEFAULT_TAKT_POS = 0;

    static constexpr SequencerPropertiesTuple DEFAULT_SequencerPropertiesTuple
    {
        std::make_tuple(Sequencer_DEFAULT_CLOCK_POS,
                        Sequencer_DEFAULT_STEP_POS,
                        Sequencer_DEFAULT_TAKT_POS)
    };

//!\Objectsructuredef
    typedef objectsructure::Properties
    <
        SequencerPropertiesIndex,
        SequencerPropertiesTuple,
        objectsructure::PROPERTY_OBSERVER_MODE::IS_OBSERVEABLE
    >
    SequencerProperties;

//!\class Sequencer
    class Sequencer :
        public SequencerProperties
    {
    SINGLETON_ownCTOR(Sequencer)

        Sequencer() noexcept;
    };

    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################

    //! ********************************************************************
    //! ********************************************************************
    //! \Accord
    //! ********************************************************************
    //! ********************************************************************
    //! ********************************************************************
//!\Indize
    enum : uint8_t
    {
        SAITE_e,
        SAITE_b,
        SAITE_g,
        SAITE_d,
        SAITE_A,
        SAITE_E
    };

    enum class AccordPropertiesIndex : uint8_t
    {
        SAITE_e = SAITE_e,
        SAITE_b,
        SAITE_g,
        SAITE_d,
        SAITE_A,
        SAITE_E
    };

//!\Typedef
//!\Tupledef
    typedef std::tuple
    <
        TYPE_offset,
        TYPE_offset,
        TYPE_offset,
        TYPE_offset,
        TYPE_offset,
        TYPE_offset
    >
    AccordPropertiesTuple;

//!\Defaultwerte
    static constexpr TYPE_offset    Accord_DEFAULT_SAITE_e = 0;
    static constexpr TYPE_offset    Accord_DEFAULT_SAITE_b = 0;
    static constexpr TYPE_offset    Accord_DEFAULT_SAITE_g = 0;
    static constexpr TYPE_offset    Accord_DEFAULT_SAITE_d = 0;
    static constexpr TYPE_offset    Accord_DEFAULT_SAITE_A = 0;
    static constexpr TYPE_offset    Accord_DEFAULT_SAITE_E = 0;

    static constexpr AccordPropertiesTuple DEFAULT_AccordPropertiesTuple
    {
        std::make_tuple(Accord_DEFAULT_SAITE_e,
                        Accord_DEFAULT_SAITE_b,
                        Accord_DEFAULT_SAITE_g,
                        Accord_DEFAULT_SAITE_d,
                        Accord_DEFAULT_SAITE_A,
                        Accord_DEFAULT_SAITE_E)
    };

//!\Objectsructuredef
    typedef objectsructure::Properties
    <
        AccordPropertiesIndex,
        AccordPropertiesTuple,
        objectsructure::PROPERTY_OBSERVER_MODE::NOT_OBSERVEABLE // not required yet, change if need...
    >
    AccordProperties;

//!\class Accord
    struct Accord final :
        public AccordProperties
    {
        Accord() noexcept;
        ~Accord() noexcept = default;

        Accord(TYPE_offset e__,
               TYPE_offset b__,
               TYPE_offset g__,
               TYPE_offset d__,
               TYPE_offset A__,
               TYPE_offset E__) noexcept;

        //!\DatabaseKeyName
        static constexpr const char* _KEY_NAME{"_a"};
    };

    static const Accord TUNE_EAdgbe{76,71,67,62,57,52};
    static const Accord TUNE_Drum{61,46,44,38,35,36};

    static const Accord ACCORD_dur{0,0,1,2,2,0};
    static const Accord ACCORD_mol{0,0,0,2,2,0};
    static const Accord ACCORD_7{0,0,1,0,2,0};
    static const Accord ACCORD_mol7{0,0,0,0,2,0};
    static const Accord ACCORD_maj7{4,4,4,2,-1,-1};
    static const Accord ACCORD_sus4{0,0,2,2,2,0};
    static const Accord ACCORD_6{0,2,1,2,2,0};
    static const Accord ACCORD_sus2{2,5,4,2,-1,-1};

    /***********************************************************************/
    /*! \AccordDatabase
    */
    /***********************************************************************/
    typedef objectsructure::ObjectDatabase<Accord> TYPE_AccordDatabase;

    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################

    /***********************************************************************/
    /*! \Temporary

        Verwaltung von Sitzungsdaten, welche nicht gepeichert werden sollen.
    */
    /***********************************************************************/
//!\Indize
    enum class TemporaryPropertiesIndex : uint8_t
    {
        SELECTED_STEP,
        SELECTED_TAKTCHAIN,
        SELECTED_TAKTCHAIN_TAKT_ID,
        SELECTED_TAKTCHAIN_LEVEL_ID,
        SELECTED_TAKTSAITE,
        SELECTED_TAKT,
        SELECTED_PATTERN,
        SELECTED_PATTERNSAITE,
        SELECTED_PROJECT,

        SEQUENCER,
        IS_NOTFYING,
        IS_PAUSE,

        IS_COPY_ON,
        IS_PAST_ON,

        TUNEEDITOR_SHOW,
        REBECA_SHOW,

        IS_TAKTCHAIN_SET_TO_ALL,

        ENUM_CLASS_SIZE
    };

//!\Typedef
//!\Tupledef
    //  Temporary Objects
    typedef bool TYPE_is_notifying;
    typedef bool TYPE_is_pause;

    typedef bool TYPE_is_copy_on;
    typedef bool TYPE_is_past_on;
    typedef bool TYPE_tuneeditor_show;

    uint8_t static constexpr GUI_ACCORD_sliderMAX     =   12;   //  Ändert die Sliderauflösung der Gui
    uint8_t static constexpr GUI_ACCORD_sliderPageSTEP=   1;
    uint8_t static constexpr GUI_TUNE_sliderMAX       =   130;  //  ... je nach angezeigtem Type
    uint8_t static constexpr GUI_TUNE_sliderPageSTEP  =   12;

    enum TUNEEDITOR_SHOW : uint8_t
    {
        TUNEEDITOR_SHOW_TUNE,
        TUNEEDITOR_SHOW_ACCORD
    };

    typedef uint8_t TYPE_rebeca_show;
    enum REBECA_SHOW : TYPE_rebeca_show
    {
        REBECA_SHOW_NOTE,
        REBECA_SHOW_VELOCITY,
        REBECA_SHOW_LENGTH
    };


    typedef std::tuple
    <
        Step*,
        Taktchain*,
        TYPE_index_child,
        TYPE_index_child,
        Taktsaite*,
        Takt*,
        Pattern*,
        Patternsaite*,
        Project*,

        Sequencer*,
        TYPE_is_notifying,
        TYPE_is_pause,

        TYPE_is_copy_on,
        TYPE_is_past_on,
        TYPE_tuneeditor_show,
        TYPE_rebeca_show,

        bool
    >
    TemporaryPropertiesTuple;

//!\Defaultwerte
    static constexpr Step*         Temporary_DEFAULT_STEP = nullptr;
    static constexpr Taktchain*    Temporary_DEFAULT_TAKTCHAIN = nullptr;
    static constexpr TYPE_index_child    Temporary_DEFAULT_TAKTCHAIN_TAKT_ID = 0;
    static constexpr TYPE_index_child    Temporary_DEFAULT_TAKTCHAIN_LEVEL_ID = 0;
    static constexpr Taktsaite*    Temporary_DEFAULT_TAKTSAITE = nullptr;
    static constexpr Takt*         Temporary_DEFAULT_TAKT = nullptr;
    static constexpr Pattern*      Temporary_DEFAULT_PATTERN = nullptr;
    static constexpr Patternsaite* Temporary_DEFAULT_PATTERNSAITE = nullptr;
    static constexpr Project*      Temporary_DEFAULT_PROJECT = nullptr;

    static constexpr Sequencer*         Temporary_DEFAULT_SEQUENCER = nullptr;
    static constexpr TYPE_is_notifying  Temporary_DEFAULT_IS_NOTIFYING = false;
    static constexpr TYPE_is_pause      Temporary_DEFAULT_IS_PAUSE = false;

    static constexpr TYPE_is_copy_on        Temporary_DEFAULT_IS_COPY_ON = false;
    static constexpr TYPE_is_past_on        Temporary_DEFAULT_IS_PAST_ON = false;

    static constexpr TYPE_tuneeditor_show   Temporary_DEFAULT_TUNEDITOR_SHOW = TUNEEDITOR_SHOW::TUNEEDITOR_SHOW_TUNE;
    static constexpr TYPE_rebeca_show       Temporary_DEFAULT_REBECA_SHOW = REBECA_SHOW::REBECA_SHOW_NOTE;

    static constexpr bool Temporary_DEFAULT_IS_TAKTCHAIN_SET_TO_ALL = false;

    static constexpr TemporaryPropertiesTuple DEFAULT_TemporaryPropertiesTuple
    {
        std::make_tuple(Temporary_DEFAULT_STEP,
                        Temporary_DEFAULT_TAKTCHAIN,
                        Temporary_DEFAULT_TAKTCHAIN_TAKT_ID,
                        Temporary_DEFAULT_TAKTCHAIN_LEVEL_ID,
                        Temporary_DEFAULT_TAKTSAITE,
                        Temporary_DEFAULT_TAKT,
                        Temporary_DEFAULT_PATTERN,
                        Temporary_DEFAULT_PATTERNSAITE,
                        Temporary_DEFAULT_PROJECT,

                        Temporary_DEFAULT_SEQUENCER,
                        Temporary_DEFAULT_IS_NOTIFYING,
                        Temporary_DEFAULT_IS_PAUSE,

                        Temporary_DEFAULT_IS_COPY_ON,
                        Temporary_DEFAULT_IS_PAST_ON,

                        Temporary_DEFAULT_TUNEDITOR_SHOW,
                        Temporary_DEFAULT_REBECA_SHOW,

                        Temporary_DEFAULT_IS_TAKTCHAIN_SET_TO_ALL)
    };

//!\Objectsructuredef
    typedef objectsructure::Properties
    <
        TemporaryPropertiesIndex,
        TemporaryPropertiesTuple,
        objectsructure::PROPERTY_OBSERVER_MODE::IS_OBSERVEABLE
    >
    TemporaryProperties;

//!\class Temporary
    class Temporary :
        public TemporaryProperties
    {
    SINGLETON_ownCTOR(Temporary)

        Temporary() noexcept;
    };

    typedef typename TemporaryProperties::TYPE_PropertyObserver_T TYPE_temporaryObserver;

    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################

//!\Defaultwerte
    static constexpr TYPE_index_child   BuildMemory_DEFAULT_selectedPattern = 0;
    static constexpr TYPE_index_child   BuildMemory_DEFAULT_selectedTakt = 0;
    static constexpr TYPE_index_child   BuildMemory_DEFAULT_selectedTaktchain = 0;
    static constexpr TYPE_index_child   BuildMemory_DEFAULT_selectedTaktsaite = 0;
    static constexpr TYPE_index_child   BuildMemory_DEFAULT_selectedStep = 0;

    //!\struct BuildMemory
    class BuildMemory{
    SINGLETON_ownCTOR(BuildMemory)

        BuildMemory() noexcept
        {
            exec();
        }

        void exec()
        {
            Temporary* temporary{Temporary::singleton()};

            //! Sequencer
            Sequencer* sequencer{Sequencer::singleton()};
            temporary->set_property<TemporaryPropertiesIndex::SEQUENCER>(sequencer);

            //! Database
            Project* project{new Project{ /* TODO LOAD DATA */ }};
            temporary->set_property<TemporaryPropertiesIndex::SELECTED_PROJECT>(project);

            Pattern* selected_pattern{project->pattern(BuildMemory_DEFAULT_selectedPattern)};
            temporary->set_property<TemporaryPropertiesIndex::SELECTED_PATTERN>(selected_pattern);

            Takt* selected_takt{selected_pattern->takt(BuildMemory_DEFAULT_selectedTakt)};
            temporary->set_property<TemporaryPropertiesIndex::SELECTED_TAKT>(selected_takt);

            Taktchain* selected_taktchain{selected_takt->taktchain(BuildMemory_DEFAULT_selectedTaktchain)};
            temporary->set_property<TemporaryPropertiesIndex::SELECTED_TAKTCHAIN>(selected_taktchain);

            Taktsaite* selected_taktsaite{selected_takt->taktsaite(BuildMemory_DEFAULT_selectedTaktsaite)};
            temporary->set_property<TemporaryPropertiesIndex::SELECTED_TAKTSAITE>(selected_taktsaite);

            Step* selected_step{selected_taktsaite->step(BuildMemory_DEFAULT_selectedStep)};
            temporary->set_property<TemporaryPropertiesIndex::SELECTED_STEP>(selected_step);
        }
    };
}

/// Temmporäre datenbank für zb für geräte
/// Statische datenbanken zb für Accorde, Takte etc...
/// Seperate Projektdatenbanken

///#include <dc_objects.hpp>

#endif // DC_OBJECTS_H_INCLUDED
