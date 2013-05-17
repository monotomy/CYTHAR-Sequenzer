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

#include <dc_midi_sequencer_timer.h>

namespace dc_midi{

//!\class PatternMuteTimer
    PatternMuteTimer
    ::PatternMuteTimer(TYPE_index_child absolut_id_in_project__) noexcept
    {
        // Observiert absolut ein Object
        absCHANGE_(this_absPATTERN_OBSERVER, absolut_id_in_project__);

        reset_time_to_live();
    }


    void PatternMuteTimer
    ::property_changed(AT_(Pattern,MUTE_TIME)) noexcept
    {
        if(absGET_(this_absPATTERN_OBSERVER, MUTE_TIME) == 0
           and _time_to_mute > 0)
        {
            absSET_(this_absPATTERN_OBSERVER, IS_MUTED, false);
        }

        reset_time_to_live();
    }

//!\class PatternsaiteMuteTimer
    PatternsaiteMuteTimer
    ::PatternsaiteMuteTimer(TYPE_index_child absolut_pattern_id_in_project__,
                          TYPE_index_child absolut_patternsaite_id_in_pattern) noexcept :
        _parent_pattern_id{absolut_pattern_id_in_project__}
    {
        auto patternsaite(tmpGET_(SELECTED_PROJECT)
                            ->pattern(absolut_pattern_id_in_project__)
                            ->patternsaite(absolut_patternsaite_id_in_pattern));
        TYPE_PatternsaiteObserver::attach_as_observer_atProperty_subject(patternsaite);
    }

    void PatternsaiteMuteTimer
    ::property_changed(AT_(Patternsaite,MUTE_TIME)) noexcept
    {
        reset_time_to_live();

        // Setzt das Patternsaite wieder unmute, wenn der Dial während mute herunter gedreht wird
        if(_time_to_mute == 0)
        {
            auto absolut_observed_patternsaite(static_cast<Patternsaite*>(my_observedSubject()));
            absolut_observed_patternsaite->set_property<PatternsaitePropertiesIndex::IS_MUTED>(false);
        }
    }

//!\class Timers
    std::array<PatternMuteTimer*, Pattern_per_Project> Timers::pattern_mute;
    std::array<TaktChain_perPattern*, Pattern_per_Project> Timers::takt_chain;
    std::array<std::array<PatternsaiteMuteTimer*, GLOBAL_supportedSAITES>, Pattern_per_Project> Timers::patternsaite_mute;

    void Timers
    ::init_timers__after_temporary() noexcept
    {
        static bool is_done{false};
        if(is_done)
            return;

        pattern_mute = Timers::build_timer<PatternMuteTimer,Pattern_per_Project>();
        takt_chain = Timers::build_timer<TaktChain_perPattern,Pattern_per_Project>();

        for(TYPE_index_child pattern_id{0}; pattern_id != Pattern_per_Project; ++pattern_id)
            for(TYPE_index_child saite_id{0}; saite_id != GLOBAL_supportedSAITES; ++saite_id)
                patternsaite_mute[pattern_id][saite_id] = new PatternsaiteMuteTimer(pattern_id, saite_id);

        is_done=true;
    }
}
