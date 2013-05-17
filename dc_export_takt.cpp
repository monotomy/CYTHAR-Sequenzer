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

#include <dc_export_takt.h>

#include <stdint.h>

#include <dc_objectstructure.h>

namespace dc_export{

//!\KONSTANTS FOR EXPORT
    static constexpr uint8_t size_per_step{3};

    static const std::string EMPTY_SPACER{"-"};

    static const std::string MUTET_STEP_IN_TAB{EMPTY_SPACER + EMPTY_SPACER + EMPTY_SPACER};

    static const std::string LINE_BEGIN_INFO_TUNE{""};

    static const std::string LINE_BEGIN_STRING{"|"};
    static const std::string LINE_END_STRING{"|\n"};

    static const std::string HEADER_INTRO_STRING{"\n .:: CYTHAR Sequencer :::: guitar tabexporter 0.1 ::. \n" };
    static const std::string BUTTOM_OUTRO_STRING{" ':: information  "  + CYTHAR_MAIN_URL + " ::' \n" };

    static const std::string EMPTY_BEGIN_SPACER{"**** "};
    static const std::string TABHEADER_STRING{HEADER_INTRO_STRING
                                              +EMPTY_BEGIN_SPACER
                                              + " **"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + " **"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + " **"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + " **"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "\n"};

    static const std::string EMPTY_BEGIN_SPACER_MIDDLE{"____ "};
    static const std::string TABSPACER_STRING{EMPTY_BEGIN_SPACER_MIDDLE
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "___"
                                              + "\n\n"};

    static const std::string TABBUTTOM_STRING{EMPTY_BEGIN_SPACER
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "***"
                                              + "\n"
                                              + BUTTOM_OUTRO_STRING};
    using namespace dc_objects;

//!\class Takt2Tabulator
    std::string Takt2Tabulator
    ::convert2string(Pattern const*const parrent_pattern__,
                     Takt const*const takt_to_export__) noexcept
    {
        std::string offset_tabulatorpattern{};
        std::string velocity_tabulatorpattern{};
        std::string length_tabulatorpattern{};

        for(TYPE_index_child saite_id{0} ; saite_id != GLOBAL_supportedSAITES ; ++saite_id )
        {
            /// Erstelle Line begin
            offset_tabulatorpattern += begin_line_tune_info(parrent_pattern__, saite_id);
            velocity_tabulatorpattern += " V: " + LINE_BEGIN_STRING;
            length_tabulatorpattern += " L: " + LINE_BEGIN_STRING;

            /// Tabulator inhalt
            // Saiten
            auto patternsaite(parrent_pattern__->patternsaite(saite_id));
            auto taktsaite(takt_to_export__->taktsaite(saite_id));

            // Saitenoffsets
            auto patternsaite_accordoffset(patternsaite->get_property<PatternsaitePropertiesIndex::ACCORD_OFFSET>());
            auto taktsaite_offset(taktsaite->get_property<TaktsaitePropertiesIndex::OFFSET>());

            for(TYPE_index_child step_id{0} ; step_id != Step_per_Taktsaite ; ++step_id )
            {
                auto step(taktsaite->step(step_id));
                if(step->get_property<StepPropertiesIndex::IS_MUTED>() == false
                    and step->get_property<StepPropertiesIndex::IS_INIT>() == true)
                {
                    // Offset
                    auto step_offset(step->get_property<StepPropertiesIndex::OFFSET>());
                    offset_tabulatorpattern += make_fit_string(lexical_cast<std::string>(patternsaite_accordoffset
                                                                +taktsaite_offset
                                                                +step_offset));
                    // Velocity
                    auto step_velocity(step->get_property<StepPropertiesIndex::VELOCITY>());
                    velocity_tabulatorpattern += make_fit_string(lexical_cast<std::string>(step_velocity));

                    // Length
                    auto step_length(step->get_property<StepPropertiesIndex::LENGTH>());
                    length_tabulatorpattern += make_fit_string(lexical_cast<std::string>(step_length));
                }
                else
                {
                    // Empty entrys
                    offset_tabulatorpattern += MUTET_STEP_IN_TAB;
                    velocity_tabulatorpattern += MUTET_STEP_IN_TAB;
                    length_tabulatorpattern += MUTET_STEP_IN_TAB;
                }
            }

            // Erstelle Line End
            offset_tabulatorpattern += LINE_END_STRING;
            velocity_tabulatorpattern += LINE_END_STRING;
            length_tabulatorpattern += LINE_END_STRING;
        }

        // Zusammenschrauben von offset, velo & leng
        return TABHEADER_STRING
             + offset_tabulatorpattern
             + TABSPACER_STRING
             + velocity_tabulatorpattern
             + TABSPACER_STRING
             + length_tabulatorpattern
             + TABBUTTOM_STRING;
        }

    std::string Takt2Tabulator
    ::make_fit_string(std::string const& value_string__) noexcept
    {
        std::string fittet_string{value_string__};
        while(fittet_string.size() != size_per_step)
            fittet_string += EMPTY_SPACER;

        return std::move(fittet_string);
    }

    std::string Takt2Tabulator
    ::begin_line_tune_info(Pattern const*const parrent_pattern__,
                           TYPE_index_child current_saite_id__) noexcept
    {
        std::string line_begin_string{};
        auto patternsaite(parrent_pattern__->patternsaite(current_saite_id__));
        auto patternsaite_tune_offset(patternsaite->get_property<PatternsaitePropertiesIndex::TUNE_OFFSET>());

        line_begin_string += LINE_BEGIN_INFO_TUNE;
        line_begin_string += make_line_begin_fit_string(gm_standard::halftone2str[patternsaite_tune_offset], 4);
        line_begin_string += LINE_BEGIN_STRING;

        return std::move(line_begin_string);
    }

    std::string Takt2Tabulator
    ::make_line_begin_fit_string(std::string const& begin_value_string__,
                                 size_t string_size__) noexcept
    {
        std::string fittet_string{begin_value_string__};
        while(fittet_string.size() < string_size__)
            fittet_string += " ";

        return std::move(fittet_string);
    }
}
