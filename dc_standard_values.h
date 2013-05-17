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

#ifndef DC_STANDARD_VALUES_H_INCLUDED
#define DC_STANDARD_VALUES_H_INCLUDED

#include <dc_standard_types.h>
#include <string>

    static const std::string CYTHAR_MAIN_URL{"http://www.cythar.sequenzer.org"};

    static constexpr TYPE_midichannel   GM_midichannel_perDevice = 16;

    static constexpr TYPE_index_child GLOBAL_supportedSAITES = 6;
    static constexpr TYPE_index_child Step_per_Taktsaite = 16;
    static constexpr TYPE_index_child Taktsaiten_per_Takt = GLOBAL_supportedSAITES;
    static constexpr TYPE_index_child Taktsaiten_per_Patternsaite = 16;
    static constexpr TYPE_index_child Taktchain_per_Takt = 16;
    static constexpr TYPE_index_child Takt_per_Pattern = 16;
    static constexpr TYPE_index_child Patternsaiten_per_Pattern = GLOBAL_supportedSAITES;
    static constexpr TYPE_index_child Pattern_per_Project = 16;

    static constexpr TYPE_clockstep     GM_clock_per_takt = 96;
    static constexpr TYPE_clockstep     GM_steps_per_takt = 16;
    static constexpr TYPE_clockstep     GM_clock_per_step = GM_clock_per_takt/GM_steps_per_takt;

    static constexpr TYPE_note NOTE_MAX = 127;
    static constexpr TYPE_note NOTE_MIN = 0;
    static constexpr TYPE_offset OFFSET_MAX = 127;
    static constexpr TYPE_offset OFFSET_MIN = -128;
    static constexpr TYPE_velocity VELOCITY_MAX = 127;
    static constexpr TYPE_velocity VELOCITY_MIN = 0;
    static constexpr TYPE_lengthy LENGTH_MAX = GM_clock_per_takt*16;
    static constexpr TYPE_lengthy LENGTH_MIN = 0;
    static constexpr short DELAY_MAX = LENGTH_MAX;
    static constexpr short DELAY_MIN = LENGTH_MIN;

    static constexpr uint8_t SUPPORTED_SONGMODE_LEVEL = 3;


    static const std::string DOC_MANUAL_COMPLETE{"2"};
    static const std::string DOC_PATTERNSAITE_EDITOR{"12"};
    static const std::string DOC_STEPEDITOR{"14"};
    static const std::string DOC_STEPMASTER{"14"};
    static const std::string DOC_STEPBUTTON{"13"};
    static const std::string DOC_MIDIDEVICE_EDITOR{"15"};
    static const std::string DOC_PATTERNMASTER{"15"};
    static const std::string DOC_TAKTMASTER{"16"};
    static const std::string DOC_TAKTSAITEN{"17"};
    static const std::string DOC_REBECA{"24"};


    typedef bool TYPE_NOT_UNIQUE;

    //!\Indize die von einem Objekt unterstützen Eigenschaften im Tuple
    //!\Typedef typedef, welche nur für diesen objekttype relevant sind
    //!\Tupledef tuple typedef
    //!\Defaultwerte Initialisationswerte
    //!\Objectsructuredef typedef der Propertyclass von objectstructure.h
    //!\Childdef welche kinder hat das objekt - ChildArray von objectstructure.h
    //!\Compatibilitydef

    //! ********************************************************************
    //! ********************************************************************
    //! \GLOBAL
    //! ********************************************************************
    //! ********************************************************************
    //! ********************************************************************
    enum MISC_STUFF
    {
        HUMAN_COUNT = 1 // Offset von 0 zu 1
    };

    //!\Defaultwerte


    static constexpr bool IS_MANUAL_MUTED = 0;

    //! Stringvergabe für die Datenbankschlüssel - Keine DUPLIKATE!
    //! Meist verwendete am kürzesten halten - performance
    typedef const std::string TYPE_db_key;

    //!\RESERVIERT
    //static const std::string KEY_COMMA_VALUE_SEPERATOR{","};

    //! TYPES
    static TYPE_db_key STRING_type_Project{""};
    static TYPE_db_key STRING_type_Pattern{"+"};
    static TYPE_db_key STRING_type_Patternsaite{"*"};
    static TYPE_db_key STRING_type_Takt{"%"};
    static TYPE_db_key STRING_type_Taktchain{"^"};
    static TYPE_db_key STRING_type_Taktsaite{"&"};
    static TYPE_db_key STRING_type_Step{"/"};

    //! PROPERTIES
    static TYPE_db_key STRING_prop_CLOCKSPEED_inBPM_x_100               {"a"};
    static TYPE_db_key STRING_prop_IS_MASTER                            {"b"};
    static TYPE_db_key STRING_prop_OFFSET                               {"c"};


    static TYPE_db_key STRING_prop_MUTE_TIME                            {"f"};
    static TYPE_db_key STRING_prop_IS_MUTED                             {"g"};
    static TYPE_db_key STRING_prop_RUN_TIMES                            {"h"};
    static TYPE_db_key STRING_prop_JUMP_2_AFTER_THAT                    {"i"};
    static TYPE_db_key STRING_prop_WAIT_TIMES                           {"j"};
    static TYPE_db_key STRING_prop_TUNE_OFFSET                          {"k"};
    static TYPE_db_key STRING_prop_ACCORD_OFFSET                        {"l"};
    static TYPE_db_key STRING_prop_MIDI_DEVICE_ID_IN_DATABASE           {"m"};
    static TYPE_db_key STRING_prop_MIDI_CHANNEL                         {"n"};
    static TYPE_db_key STRING_prop_VELOCITY                             {"o"};
    static TYPE_db_key STRING_prop_LENGTH                               {"p"};
    static TYPE_db_key STRING_prop_DELAY                                {"q"};
    static TYPE_db_key STRING_prop_REPEAT_TIMES                         {"r"};
    static TYPE_db_key STRING_prop_IS_INIT                              {"s"};
    static TYPE_db_key STRING_prop_INTERVAL                             {"t"};

    static TYPE_db_key STRING_prop_OFFSET_OPERATOR                      {"u"};
    static TYPE_db_key STRING_prop_OFFSET_OPERAND                       {"v"};
    static TYPE_db_key STRING_prop_VELOCITY_OPERATOR                    {"w"};
    static TYPE_db_key STRING_prop_VELOCITY_OPERAND                     {"x"};
    static TYPE_db_key STRING_prop_LENGTH_OPERATOR                      {"y"};
    static TYPE_db_key STRING_prop_LENGTH_OPERAND                       {"z"};
    static TYPE_db_key STRING_prop_INTERVAL_OPERATOR                    {"A"};
    static TYPE_db_key STRING_prop_INTERVAL_OPERAND                     {"B"};

    static TYPE_db_key STRING_prop_OFFSET_2_INTERVAL_OPERATOR           {"C"};
    static TYPE_db_key STRING_prop_OFFSET_INTERVAL_2_REPEAT_OPERATOR    {"D"};

    static TYPE_db_key STRING_prop_VELOCITY_2_INTERVAL_OPERATOR         {"E"};
    static TYPE_db_key STRING_prop_VELOCITY_INTERVAL_2_REPEAT_OPERATOR  {"F"};

    static TYPE_db_key STRING_prop_LENGTH_2_INTERVAL_OPERATOR           {"G"};
    static TYPE_db_key STRING_prop_LENGTH_INTERVAL_2_REPEAT_OPERATOR    {"H"};

    static TYPE_db_key STRING_prop_OFFSET_FIT_TO_RANGE                  {"I"};
    static TYPE_db_key STRING_prop_VELOCITY_FIT_TO_RANGE                {"J"};
    static TYPE_db_key STRING_prop_LENGTH_FIT_TO_RANGE                  {"K"};

    static TYPE_db_key STRING_prop_USE_TAKT_OFFSET_per                  {"R"};
    static TYPE_db_key STRING_prop_USE_TAKTSAITE_OFFSET_per             {"S"};
    static TYPE_db_key STRING_prop_USE_TAKTSAITE_MUTE_per               {"T"};

    static TYPE_db_key STRING_prop_OVERWRITE_TARGET_LEVEL               {"U"};
    static TYPE_db_key STRING_prop_Taktchain_FOR                        {"V"};
    static TYPE_db_key STRING_prop_Taktchain_NEXT                       {"W"};

    //! ********************************************************************
    //! ********************************************************************
    //! \Rebeca
    //! ********************************************************************
    //! ********************************************************************
    //! ********************************************************************
//!\Operators
    enum class OPERATOR : TYPE_operator
    {
        NOT,
        PLUS,
        MINUS,
        MULTI,
        DIV,
        MODULA
    };


#endif // DC_STANDARD_VALUES_H_INCLUDED
