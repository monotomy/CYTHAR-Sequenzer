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

#include <dc_gui_patternsaite_mute.2moc.h>

#include <dc_gui_styles.h>

#include <cast/lexical_cast.hpp>
#include <functions/invert.hpp>

#include <dc_midi_sequencer_timer.h>

namespace dc_gui{

//! \class PatternsaiteMute_Initializer
    void PatternsaiteMute_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        for( int elements{0} ; sum_elements != elements ; ++elements )
        {
            PatternsaiteMute* patternsaite_mute{new PatternsaiteMute{}};

            patternsaite_mute->setGeometry(left,
                                      top_first + elements*height,
                                      width,
                                      height);
            patternsaite_mute->setParent(parent_frame);
            patternsaite_mute->setVisible(true);
            patternsaite_mute->init();
        }
    }

//!\class PatternsaiteMute
    PatternsaiteMute
    ::PatternsaiteMute()
    {
        setupUi(this);

        dial_time->setStyle(motifstyle);
    }

    void PatternsaiteMute
    ::init() noexcept
    {
        //  Signals von Std::Thread abkoppeln
        connect(&_mute_in_takt_timer,
                SIGNAL(timeout()),
                this,
                SLOT(blink_timer_mute()));

        update();
    }

    void PatternsaiteMute
    ::update() noexcept
    {
        set_mute_time();
        set_mute();
    }

    PatternsaiteMute
    ::~PatternsaiteMute()
    {
        _mute_in_takt_timer.stop();
    }

    void PatternsaiteMute
    ::RELATIVE_OBSERVER_CHANGED(Patternsaite) noexcept
    {
        update();
    }

    void PatternsaiteMute
    ::property_changed(AT_(Patternsaite,IS_MUTED)) noexcept
    {
        set_mute();
    }

    void PatternsaiteMute
    ::property_changed(AT_(Patternsaite,MUTE_TIME)) noexcept
    {
        set_mute_time();
    }

    void PatternsaiteMute
    ::set_mute_time() noexcept
    {
    SET_EVENT_BLOCK

        auto mute_time(relGET_(this_relPATTERNSAITE_OBSERVER, MUTE_TIME));
        dial_time->setValue(mute_time);
        pb->setText(lexical_cast<std::string>(mute_time).c_str());
    }

    void PatternsaiteMute
    ::set_mute() noexcept
    {
        if(relGET_(this_relPATTERNSAITE_OBSERVER, IS_MUTED) == true)
            if(relGET_(this_relPATTERNSAITE_OBSERVER, MUTE_TIME) > 0)
            {
                if(_mute_in_takt_timer.isActive() == true)
                    return;
                else
                    _mute_in_takt_timer.start();
            }
            else
            {
                DCSTYLE->set_mutedButtonPalette(pb);
            }
        else
        {
            DCSTYLE->set_defaultMasterPalette(pb);
            if(_mute_in_takt_timer.isActive() == false)
                return;
            else
                _mute_in_takt_timer.stop();
        }
    }

    void PatternsaiteMute
    ::blink_timer_mute() noexcept
    {
        if(is_mute_time_blink)
        {
            DCSTYLE->set_mutedButtonPalette(pb);
            is_mute_time_blink = false;
        }
        else
        {
            DCSTYLE->set_defaultMasterPalette(pb);
            is_mute_time_blink = true;
        }
    }

    void PatternsaiteMute
    ::change_mute_tmer_interval() noexcept
    {
        TYPE_index_child mute_time_left{0};
        for(TYPE_index_child pattern_id{0} ;  pattern_id != Pattern_per_Project ; ++pattern_id)
        {
            if(dc_midi::Timers::patternsaite_mute[pattern_id][this_relPATTERNSAITE_OBSERVER::_absolut_id_in_parent]->parent_pattern()
               == tmpGET_(SELECTED_PATTERN))
            {
                mute_time_left = dc_midi::Timers::patternsaite_mute[pattern_id]
                                                                   [this_relPATTERNSAITE_OBSERVER::_absolut_id_in_parent]->time_to_mute_left();
            }
        }

        _mute_in_takt_timer.setInterval((1+mute_time_left)*46);
    }

    void PatternsaiteMute
    ::on_dial_time_valueChanged(int mute_time_) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        relSET_(this_relPATTERNSAITE_OBSERVER, MUTE_TIME, mute_time_);
    }

    void PatternsaiteMute
    ::on_pb_clicked() noexcept
    {
        relOBS_(this_relPATTERNSAITE_OBSERVER)->invert_property<PatternsaitePropertiesIndex::IS_MUTED>();
    }
}
