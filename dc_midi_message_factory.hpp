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

#ifndef CYTHAR_SEQUENCER_MIDIOUT_FACTORY_HPP_INCLUDED
#define CYTHAR_SEQUENCER_MIDIOUT_FACTORY_HPP_INCLUDED

#include <stdint.h>

#include <dc_midi_message.h>

#include <dc_midi_sequencer_timer.h>

#include <dc_algorithm_rebeca.hpp>

namespace dc_midi
{
//!\class MessageFactory
    inline void MessageFactory
    ::make_messages_to_sequencer_positions() const
    {
        if(relGET_(this_dtlSEQUENCER_OBSERVER, CLOCK_POS)%GM_clock_per_step != 0)
            return;

        auto const sequencer(selOBS_(this_dtlSEQUENCER_OBSERVER));
        auto const project(selOBS_(this_selPROJECT_OBSERVER));
        auto const master_takt_pos(relGET_(this_dtlSEQUENCER_OBSERVER, TAKT_POS));


        for(TYPE_index_child pattern_id{0};
            pattern_id != Pattern_per_Project;
            ++pattern_id)
        {
            /// PATTERN
            auto const run_pattern(project->pattern(pattern_id));
            if(run_pattern->get_property<PatternPropertiesIndex
               ::IS_MUTED>() == true)
                continue;

            /// TAKT wird in TaktChain berechnet.
            auto const run_takt(Timers::takt_chain[pattern_id]->current_running_takt());
            if(run_takt->get_property<TaktPropertiesIndex
               ::IS_MUTED>() == true)
                continue;

            /// PATTERNSAITE/TAKTSAITE
            for(TYPE_index_child saite_id{0};
                saite_id != GLOBAL_supportedSAITES;
                ++saite_id)
            {
                auto const patternsaite(run_pattern->patternsaite(saite_id));

/** TODO check name ??
                auto const device_in_db(MIDI_DeviceDatabase::singleton()->entity(device_id_in_db));
                if(device_in_db == nullptr)
                    continue;

                if(device_in_db->get_property<MIDI_DevicePropertiesIndex
                   ::IS_PLUGGED_YET>() == false)
                    continue;
*/
                // Patternsaite tune ist nicht gemutet? -> wenn nicht continue
                TYPE_offset const patternsaite_tune(patternsaite->get_property<PatternsaitePropertiesIndex::TUNE_OFFSET>());
                if(patternsaite_tune
                   == OFFSET_IS_MUTE)
                    continue;

                // Patternsaite accord ist nicht gemutet? -> wenn nicht continue
                TYPE_offset const patternsaite_accord(patternsaite->get_property<PatternsaitePropertiesIndex::ACCORD_OFFSET>());
                if(patternsaite_accord
                   == OFFSET_IS_MUTE)
                    continue;

                if(patternsaite->get_property<PatternsaitePropertiesIndex
                   ::IS_MUTED>() == true)
                    continue;

                /// TAKTSAITE
                auto const run_taktsaite(run_takt->taktsaite(saite_id));
                // Taktsaite Mute
                if(run_pattern->get_property<PatternPropertiesIndex::USE_TAKTSAITE_MUTE_per>() == USE_PER_MODE::USE_PER_MODE_RUN_MASTER)
                {
                    if(run_pattern
                       ->takt(master_takt_pos)
                       ->taktsaite(saite_id)->get_property<TaktsaitePropertiesIndex
                       ::IS_MUTED>() == true)
                       continue;
                }
                else
                    if(run_taktsaite->get_property<TaktsaitePropertiesIndex
                        ::IS_MUTED>() == true)
                        continue;


                /// STEPS
                auto const step(run_taktsaite->step(sequencer->get_property<SequencerPropertiesIndex::STEP_POS>()));
                if(step->get_property<StepPropertiesIndex
                    ::IS_INIT>() == false)
                    continue;

                if(step->get_property<StepPropertiesIndex
                    ::IS_MUTED>() == true)
                    continue;

                /// MIDI PORT
                std::string const& port_name{patternsaite->get_property<PatternsaitePropertiesIndex::PORT_NAME>()};

                /// MIDI CHANNEL
                TYPE_midi_channel const channel(patternsaite->get_property<PatternsaitePropertiesIndex::MIDI_CHANNEL>());

                /// NOTENWERT
                int note{0};
                // Pattern Offset
                TYPE_offset const pattern_offset(run_pattern->get_property<PatternPropertiesIndex::OFFSET>());

                /// TAKT OFFSET
                TYPE_offset takt_offset{0};
                if(run_pattern->get_property<PatternPropertiesIndex::USE_TAKT_OFFSET_per>() == USE_PER_MODE::USE_PER_MODE_RUN_MASTER)
                    takt_offset = run_pattern->takt(master_takt_pos)->get_property<TaktPropertiesIndex::OFFSET>();
                else
                    takt_offset = run_takt->get_property<TaktPropertiesIndex::OFFSET>();

                /// TAKTSAITE OFFSET
                TYPE_offset taktsaite_offset{0};
                if(run_pattern->get_property<PatternPropertiesIndex::USE_TAKTSAITE_OFFSET_per>() == USE_PER_MODE::USE_PER_MODE_RUN_MASTER)
                    taktsaite_offset = run_pattern
                                        ->takt(master_takt_pos)
                                        ->taktsaite(saite_id)->get_property<TaktsaitePropertiesIndex::OFFSET>();
                else
                    taktsaite_offset = run_taktsaite->get_property<TaktsaitePropertiesIndex::OFFSET>();


                note += pattern_offset;
                note += patternsaite_tune;
                note += patternsaite_accord;
                note += takt_offset;
                note += taktsaite_offset;

                /// VELOCITY
                TYPE_velocity velocity{0};
                /// LÄNGE
                TYPE_lengthy length{0};
                /// REBECA'S
                auto const repeat_steps(step->get_property<StepPropertiesIndex::REPEAT_TIMES>());
                if(repeat_steps > 0)
                {
                    for(TYPE_repeat_times repeat_step{0};
                        repeat_step != repeat_steps;
                        ++repeat_step)
                    {
                        //! Offset rebeca
                        using namespace dc_algorithm;
                        auto rebeca_note(calc_rebeca_for_offet_complete(step)[repeat_step] + note );
                        uint8_t casted_note;
                        if(rebeca_note >= OFFSET_MIN && rebeca_note <= OFFSET_MAX)
                        {
                            casted_note = rebeca_note;
                            //! Velocity rebeca
                            auto current_rebeca_velocity(calc_rebeca_for_velocity_complete(step)[repeat_step]);
                            TYPE_velocity rebeca_velocity{0};
                            if(current_rebeca_velocity > VELOCITY_MIN && current_rebeca_velocity <= VELOCITY_MAX)
                            {
                                rebeca_velocity = current_rebeca_velocity;
                                //! Length rebeca
                                auto current_rebeca_length(calc_rebeca_for_length_complete(step)[repeat_step]);
                                TYPE_velocity rebeca_length{0};
                                if(current_rebeca_length > LENGTH_MIN && current_rebeca_velocity <= LENGTH_MAX )
                                {
                                    rebeca_length = current_rebeca_length;
                                    //! Delay
                                    uint8_t delay{0};
                                    auto current_delay(calc_rebeca_for_interval(step)[repeat_step]);
                                    if(current_delay >= DELAY_MIN && current_delay <= DELAY_MAX)
                                    {
                                        delay = current_delay;
                                        // Rebeaca Message
                                        new NoteMessage{casted_note,
                                                        rebeca_velocity,
                                                        rebeca_length,
                                                        false,
                                                        port_name,
                                                        channel,
                                                        delay};
                                    }
                                }
                            }
                        }
                    }
                }

                //! NO REBECA DEFAULT STEP
                velocity = step->get_property<StepPropertiesIndex::VELOCITY>();
                if(velocity == 0)
                    continue;

                length = step->get_property<StepPropertiesIndex::LENGTH>();
                if(length == 0)
                    continue;

                note += step->get_property<StepPropertiesIndex::OFFSET>();

                // All Offset???
                TYPE_note casted_note;
                if(note <= NOTE_MIN || note >= NOTE_MAX)
                    continue;
                else
                    casted_note = note;

                /// WE HAVE A MESSAGE :-)
                new NoteMessage{casted_note,
                                velocity,
                                length,
                                false,
                                port_name,
                                channel,
                                step->get_property<StepPropertiesIndex::DELAY>()};
                    // Um den Rest kümmert sich die Message selbst, NO CLEAN UP REQUIRED HERE!
            }
        }
    }

}

#endif // CYTHAR_SEQUENCER_MIDIOUT_FACTORY_HPP_INCLUDED
