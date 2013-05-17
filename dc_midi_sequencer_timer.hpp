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

#ifndef DC_MIDI_SEQUENCER_TIMER_HPP_INCLUDED
#define DC_MIDI_SEQUENCER_TIMER_HPP_INCLUDED

namespace dc_midi{

//!\class PatternMuteTimer
    inline void PatternMuteTimer
    ::notify_new_takt_pos() noexcept
    {
        calculate_mute_time();
    }

    inline void PatternMuteTimer
    ::calculate_mute_time() noexcept
    {
        if(absGET_(this_absPATTERN_OBSERVER, IS_MUTED) == true)
        {
            // IGNORIERT MANUEL GEMUTETE PATTERN
            if(absGET_(this_absPATTERN_OBSERVER, MUTE_TIME) != IS_MANUAL_MUTED)
            {
                if(_time_to_mute != 0)
                    --_time_to_mute;
                else
                {
                    // Setzt das object wieder UNMUTED
                    absSET_(this_absPATTERN_OBSERVER, IS_MUTED, false);
                    // Livetime Reset
                    reset_time_to_live();
                }
            }
        }
    }

    inline void PatternMuteTimer
    ::reset_time_to_live() noexcept
    {
        _time_to_mute = absGET_(this_absPATTERN_OBSERVER, MUTE_TIME);
    }

    inline auto PatternMuteTimer
    ::time_to_mute_left() noexcept -> decltype(_time_to_mute)
    {
        return _time_to_mute;
    }

//!\class PatternsaiteMuteTimer
    inline void PatternsaiteMuteTimer
    ::reset_time_to_live() noexcept
    {
        auto absolut_observed_patternsaite(static_cast<Patternsaite*>(my_observedSubject()));
        _time_to_mute = absolut_observed_patternsaite->get_property<PatternsaitePropertiesIndex::MUTE_TIME>();
    }

    inline void PatternsaiteMuteTimer
    ::notify_new_takt_pos() noexcept
    {
        calculate_mute_time();
    }

    inline void PatternsaiteMuteTimer
    ::calculate_mute_time() noexcept
    {
        auto absolut_observed_patternsaite(static_cast<Patternsaite*>(my_observedSubject()));
        if(absolut_observed_patternsaite->get_property<PatternsaitePropertiesIndex::IS_MUTED>() == true)
        {
            // IGNORIERT MANUEL GEMUTETE PATTERN
            if(absolut_observed_patternsaite->get_property<PatternsaitePropertiesIndex::MUTE_TIME>() != IS_MANUAL_MUTED)
            {
                if(_time_to_mute != 0)
                    --_time_to_mute;
                else
                {
                    // Setzt das object wieder UNMUTED
                    absolut_observed_patternsaite->set_property<PatternsaitePropertiesIndex::IS_MUTED>(false);
                    // Livetime Reset
                    reset_time_to_live();
                }
            }
        }
    }

    inline auto PatternsaiteMuteTimer
    ::time_to_mute_left() noexcept -> decltype(_time_to_mute)
    {
        return _time_to_mute;
    }


//!\class Timers
    inline void
    Timers::notify_new_takt_pos(TYPE_index_child new_takt_pos__) noexcept
    {
        for(auto pattern_mute_timer : Timers::pattern_mute)
            pattern_mute_timer->notify_new_takt_pos();

        for(auto takt_chain_per_pattern : Timers::takt_chain)
            takt_chain_per_pattern->notify_new_takt_pos(new_takt_pos__);

        for(auto patternsaites_per_pattern : Timers::patternsaite_mute)
            for(auto patternsaite : patternsaites_per_pattern)
                patternsaite->notify_new_takt_pos();
    }

    template<class TYPE_Timer, TYPE_index_child timer_to_build>
    auto Timers
    ::build_timer() noexcept
    -> std::array<TYPE_Timer*, timer_to_build>
    {
        std::array<TYPE_Timer*, timer_to_build> new_timers;

        for(TYPE_index_child id{0}; id != timer_to_build; ++id)
            new_timers[id] = new TYPE_Timer{id};

        return std::move(new_timers);
    }
}

#endif // DC_MIDI_SEQUENCER_TIMER_HPP_INCLUDED
