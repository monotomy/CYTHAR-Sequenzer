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

#include <dc_gui_patternmaster.2moc.h>

#include <dc_gui_inits.h>
#include <dc_gui_styles.h>

#include <functions/invert.hpp>

#include <dc_midi_sequencer_timer.h>

#include <dc_standard_values.h>

namespace dc_gui{

//! \class Patternmaster_Initializer
    void Patternmaster_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        Patternmaster_4GroupSpaceInitializer::initialize_at_frame(parent_frame);
    }

//! \class  Patternmaster
    Patternmaster
    ::Patternmaster()
    {
        setupUi(this);

        dial_time->setStyle(motifstyle);

        InitButtonText::set_first_string_then_number<Patternmaster>(FIRST_PATTERNMASTER_BUTTON_STRING, pb_actionButton);
    }

    void Patternmaster
    ::init() noexcept
    {
        update();

        //  Signals von Std::Thread abkoppeln
        connect(&_mute_in_takt_timer,
                SIGNAL(timeout()),
                this,
                SLOT(blink_timer_mute()));
    }

    void Patternmaster
    ::update() noexcept
    {
        set_selected();
        set_mute();
        set_mute_time();
    }

    Patternmaster
    ::~Patternmaster()
    {
        _mute_in_takt_timer.stop();
    }

    void Patternmaster
    ::property_changed(AT_(Temporary,SELECTED_PROJECT)) noexcept
    {
        update();
    }

    void Patternmaster
    ::RELATIVE_OBSERVER_CHANGED(Pattern) noexcept
    {
        set_selected();
    }

    void Patternmaster
    ::selected_observed_object_changed(forUNIQUE_TYPE(Pattern)) noexcept
    {
        set_selected();
    }

    void Patternmaster
    ::set_selected() noexcept
    {
        if(this_relPATTERN_OBSERVER::is_my_relative_selected())
        {
            if(iam_selected_yet)
                return; // do nothing
            else
            {
                DCSTYLE->set_visibleMasterPalette(pb_timeDummy);
                DCSTYLE->set_visibleMasterPalette(pb_actionButton);
                DCSTYLE->set_visibleMasterPalette(dial_time);
                iam_selected_yet = true;
            }
        }
        else if(iam_selected_yet == true)
        {
            DCSTYLE->set_defaultMasterPalette(pb_timeDummy);
            DCSTYLE->set_defaultMasterPalette(pb_actionButton);
            DCSTYLE->set_defaultMasterPalette(dial_time);
            iam_selected_yet = false;
        }
    }

    void Patternmaster
    ::property_changed(AT_(Pattern,IS_MUTED)) noexcept
    {
        set_mute();
    }

    void Patternmaster
    ::set_mute() noexcept
    {
        if(relGET_(this_relPATTERN_OBSERVER, IS_MUTED) == true)
            if(relGET_(this_relPATTERN_OBSERVER, MUTE_TIME) > 0)
            {
                if(_mute_in_takt_timer.isActive() == true)
                    return;
                else
                    _mute_in_takt_timer.start();
            }
            else
            {
                DCSTYLE->set_mutedButtonPalette(pb_mute);
            }
        else
        {
            DCSTYLE->set_overhideTrueTaktPalette(pb_mute);
            if(_mute_in_takt_timer.isActive() == false)
                return;
            else
                _mute_in_takt_timer.stop();
        }
    }

    void Patternmaster
    ::blink_timer_mute() noexcept
    {
        if(is_mute_time_blink)
        {
            DCSTYLE->set_mutedButtonPalette(pb_mute);
            is_mute_time_blink = false;
        }
        else
        {
            DCSTYLE->set_overhideTrueTaktPalette(pb_mute);
            is_mute_time_blink = true;
        }
    }

    void Patternmaster
    ::property_changed(AT_(Pattern,MUTE_TIME)) noexcept
    {
        set_mute_time();
    }

    void Patternmaster
    ::set_mute_time() noexcept
    {
    SET_EVENT_BLOCK

        auto pattern_mute_time_inTakt(relGET_(this_relPATTERN_OBSERVER, MUTE_TIME));
        if( pattern_mute_time_inTakt == 0 )
        {
            pb_mute->setText("mute");
        }
        else
        {
            std::string time_label{"t " + lexical_cast<std::string>(pattern_mute_time_inTakt)};
            pb_mute->setText(time_label.c_str());
        }
        dial_time->setValue(pattern_mute_time_inTakt);
    }

    void Patternmaster
    ::change_mute_tmer_interval() noexcept
    {
        auto mute_time_left(dc_midi::Timers::pattern_mute[this_relPATTERN_OBSERVER::_absolut_id_in_parent]->time_to_mute_left());
        _mute_in_takt_timer.setInterval((1+mute_time_left)*46);
    }

    void Patternmaster
    ::on_pb_actionButton_clicked() noexcept
    {
        this_relPATTERN_OBSERVER::replace_selected_with_relative();

    }

    void Patternmaster
    ::on_dial_time_valueChanged(int value__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        relSET_(this_relPATTERN_OBSERVER, MUTE_TIME, value__);
    }

    void Patternmaster
    ::on_pb_mute_clicked() noexcept
    {
        relOBS_(this_relPATTERN_OBSERVER)->invert_property<PatternPropertiesIndex::IS_MUTED>();
    }

    std::string Patternmaster
    ::doc_file_name() const noexcept
    {
        return DOC_PATTERNMASTER;
    }
}
