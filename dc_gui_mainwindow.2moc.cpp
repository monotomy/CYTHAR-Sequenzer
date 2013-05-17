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

#include <dc_gui_mainwindow.2moc.h>

#include <dc_gui_styles.h>

#include <stdint.h>
#include <functions/invert.hpp>
//#include <generic_callback_switch.hpp>

#include <midi_ports.h>
#include <dc_midi_sequencer.h>
#include <dc_ticker_generator.h>

#include <dc_gui_filemanager.2moc.h>

#include <guistuff/child_initializer.h>

#include <QShortcut>

#include <version.h>

#include <dc_builder.h>


namespace dc_gui{

    static std::string const mainwindow_title_version("CYTHAR Sequenzer - " + std::string{AutoVersion::FULLVERSION_STRING});

//!\class MainwindowClipboard
    void MainwindowClipboard
    ::init() noexcept
    {
        setupUi(this);
    }

    UNIQUE_BASE* MainwindowClipboard
    ::unique_source_object2drag() const noexcept
    {
        static EmptyBase* empty_base{new EmptyBase()};
        if(MainwindowClipboardStore::singleton()->_stored_object != nullptr)
            return MainwindowClipboardStore::singleton()->_stored_object;
        else
            return empty_base;
    }

    bool MainwindowClipboard
    ::compare_is_source_in_target_dropable(extendQt::DragObject const* drag_source_object__) const noexcept
    {
        return drag_source_object__->is_target_copy_compatible_to_source(_copy_compatible_list);
    }

    void MainwindowClipboard
    ::same_type_is_dropped(extendQt::DragObject const* drag_source_object__) noexcept
    {
        if(static_cast<dc_objects::Step const*>(drag_source_object__->source()))
            MainwindowClipboardStore::singleton()->_stored_object = static_cast<dc_objects::Step*>(drag_source_object__->source());

        if(static_cast<UNIQUE<UNIQUE_IDENTIFICATIONS::Takt> const*>(drag_source_object__->source()))
            MainwindowClipboardStore::singleton()->_stored_object = static_cast<dc_objects::Takt*>(drag_source_object__->source());

        if(static_cast<UNIQUE<UNIQUE_IDENTIFICATIONS::Taktsaite> const*>(drag_source_object__->source()))
            MainwindowClipboardStore::singleton()->_stored_object = static_cast<dc_objects::Taktsaite*>(drag_source_object__->source());

        store_a_copy_drag_pixmap(drag_source_object__);
    }

    void MainwindowClipboard
    ::store_a_copy_drag_pixmap(extendQt::DragObject const* drag_source_object__) noexcept
    {
        _stored_pixmap = drag_source_object__->_backup_pixmap;
    }

    QPixmap MainwindowClipboard
    ::drag_pixmap() noexcept
    {
        return _stored_pixmap;
    }

//!\class MainwindowClipboard
    void MainwindowQuestionMark
    ::init() noexcept
    {
        setupUi(this);
    }

//!\class Mainwindow
    Mainwindow::Mainwindow() :
        _clipboard{}
    {
        setupUi(this);
        this->setWindowTitle(mainwindow_title_version.c_str());

        dc_ticker::Ticker::singleton()->attach_extern_clock_observer(this);

        _clipboard.init();
        _clipboard.setParent(frame_clipboard);

        _questmark.init();
        _questmark.setParent(frame_questmark);

        dial_taktchain_next->setStyle(motifstyle);
        dial_taktchain_for_time->setStyle(motifstyle);
        dial_taktchain_next_level->setStyle(motifstyle);

        hS_interval->setStyle(clearstyle);
    }

    void Mainwindow
    ::closeEvent(QCloseEvent*) noexcept
    {
        this->setVisible(false);
        dc::Builder::singleton()->end();
    }

    void Mainwindow
    ::init() noexcept
    {
        guistruff::set_widget_center_desktop(this);

        set_taktchain_set_to_all();

        update();
    }

    void Mainwindow
    ::update() noexcept
    {
        set_clockspeed();

        set_use_takt_offset_per_mode();
        set_use_taktsaite_offset_per_mode();
        set_use_taktsaite_mute_per_mode();

        set_master();

        set_taktchain_next();
        set_taktchain_for();
        set_taktchain_next_level();

        set_play();
    }

    void Mainwindow
    ::RELATIVE_OBSERVER_CHANGED(Pattern) noexcept
    {
        update();
    }

    void Mainwindow
    ::property_changed(AT_(Project,CLOCKSPEED_inBPM_x_100)) noexcept
    {
        set_clockspeed();
    }

    void Mainwindow
    ::set_clockspeed() noexcept
    {
        int clockspeed_in_bpm_x_100(selGET_(this_dtlPROJECT_OBSERVER, CLOCKSPEED_inBPM_x_100));
        int clockspeed_in_bpm_round{clockspeed_in_bpm_x_100/100};
        int clockspeed_in_bpm_after_comma{clockspeed_in_bpm_x_100-clockspeed_in_bpm_round*100};

        std::string bmp_string_round{lexical_cast<std::string>(clockspeed_in_bpm_round)};
        std::string bmp_string_after_comma{lexical_cast<std::string>(clockspeed_in_bpm_after_comma)};

        std::string bmp_string{bmp_string_round + "," + bmp_string_after_comma};

        l_bpm->setText(bmp_string.c_str());
        l_bpm->setToolTip((lexical_cast<std::string>(dc_ticker::bpm_to_microsec(float{clockspeed_in_bpm_x_100}/100)) + " µ-sec per clock").c_str());

    SET_EVENT_BLOCK
        dial_interval_after_comma->setValue(clockspeed_in_bpm_after_comma);
        hS_interval->setValue(clockspeed_in_bpm_round);
    }

    void Mainwindow
    ::property_changed(AT_(Pattern,USE_TAKT_OFFSET_per)) noexcept
    {
        set_use_takt_offset_per_mode();
    }

    void Mainwindow
    ::property_changed(AT_(Pattern,USE_TAKTSAITE_OFFSET_per)) noexcept
    {
        set_use_taktsaite_offset_per_mode();
    }

    void Mainwindow
    ::property_changed(AT_(Pattern,USE_TAKTSAITE_MUTE_per)) noexcept
    {
        set_use_taktsaite_mute_per_mode();
    }

    void Mainwindow
    ::set_use_takt_offset_per_mode() noexcept
    {
        DCSTYLE->set_defaultMasterPalette(pb_use_taktoffset_song);
        DCSTYLE->set_defaultMasterPalette(pb_use_taktoffset_linear);

        if(relGET_(this_dtlPATTERN_OBSERVER, USE_TAKT_OFFSET_per) == USE_PER_MODE_RUN_CURRENT)
            DCSTYLE->set_mutedButtonPalette(pb_use_taktoffset_song);
        else
            DCSTYLE->set_mutedButtonPalette(pb_use_taktoffset_linear);
    }

    void Mainwindow
    ::set_use_taktsaite_offset_per_mode() noexcept
    {
        DCSTYLE->set_defaultMasterPalette(pb_use_taktsaiteoffset_linear);
        DCSTYLE->set_defaultMasterPalette(pb_use_taktsaiteoffset_song);

        if(relGET_(this_dtlPATTERN_OBSERVER, USE_TAKTSAITE_OFFSET_per) == USE_PER_MODE_RUN_CURRENT)
            DCSTYLE->set_mutedButtonPalette(pb_use_taktsaiteoffset_song);
        else
            DCSTYLE->set_mutedButtonPalette(pb_use_taktsaiteoffset_linear);
    }

    void Mainwindow
    ::set_use_taktsaite_mute_per_mode() noexcept
    {
        DCSTYLE->set_defaultMasterPalette(pb_use_taktsaitemute_linear);
        DCSTYLE->set_defaultMasterPalette(pb_use_taktsaitemute_song);

        if(relGET_(this_dtlPATTERN_OBSERVER, USE_TAKTSAITE_MUTE_per) == USE_PER_MODE_RUN_CURRENT)
            DCSTYLE->set_mutedButtonPalette(pb_use_taktsaitemute_song);
        else
            DCSTYLE->set_mutedButtonPalette(pb_use_taktsaitemute_linear);
    }

    void Mainwindow
    ::blink_bpm_label() noexcept
    {
        static uint8_t jump_6_clocks{0};
        ++jump_6_clocks;
        if(jump_6_clocks != 6)
            return;
        jump_6_clocks = 0;

        if(l_bpm->isVisible() == true)
            l_bpm->setVisible(false);
        else
            l_bpm->setVisible(true);
    }

    void Mainwindow
    ::property_changed(AT_(Temporary,IS_NOTFYING)) noexcept
    {
        set_play();
    }

    void Mainwindow
    ::property_changed(AT_(Temporary,IS_PAUSE)) noexcept
    {
        set_play();
    }

    void Mainwindow
    ::set_play() noexcept
    {
        if(tmpGET_(IS_NOTFYING) == true
           and tmpGET_(IS_PAUSE) == true)
        {
            DCSTYLE->set_mutedButtonPalette(pb_pause);
            DCSTYLE->set_mutedButtonPalette(pb_play);
            DCSTYLE->set_defaultMasterPalette(pb_stop);
        }
        else if(tmpGET_(IS_NOTFYING) == true
                and tmpGET_(IS_PAUSE) == false)
        {
            DCSTYLE->set_defaultMasterPalette(pb_pause);
            DCSTYLE->set_mutedButtonPalette(pb_play);
            DCSTYLE->set_defaultMasterPalette(pb_stop);
        }
        else if(tmpGET_(IS_PAUSE) == true)
        {
            DCSTYLE->set_mutedButtonPalette(pb_pause);
            DCSTYLE->set_mutedButtonPalette(pb_play);
            DCSTYLE->set_defaultMasterPalette(pb_stop);
        }
        else
        {
            DCSTYLE->set_defaultMasterPalette(pb_pause);
            DCSTYLE->set_defaultMasterPalette(pb_play);
            DCSTYLE->set_mutedButtonPalette(pb_stop);
        }
    }

    void Mainwindow
    ::property_changed(AT_(Project,IS_MASTER)) noexcept
    {
        set_master();
    }

    void Mainwindow
    ::set_master() noexcept
    {
        if(selGET_(this_dtlPROJECT_OBSERVER,IS_MASTER))
        {
            DCSTYLE->set_defaultMasterPalette(pb_master);
            set_clockspeed();
            l_bpm->setVisible(true);
        }
        else
        {
            DCSTYLE->set_mutedButtonPalette(pb_master);
            l_bpm->setText("EXT  ");
        }

    }

    void Mainwindow
    ::on_pb_master_clicked() noexcept
    {
        selOBS_(this_dtlPROJECT_OBSERVER)->invert_property<ProjectPropertiesIndex::IS_MASTER>();
    }

    void Mainwindow
    ::on_pb_play_clicked() noexcept
    {
        if(tmpGET_(IS_PAUSE) == true)
        {
            tmpSET_(IS_PAUSE, false);
            dc_midi::MidiOutPortsPerApi::singleton()->try_send_continue();

        }
        else
        {
            dc_midi::Sequencer::singleton()->reset();
            dc_midi::MidiOutPortsPerApi::singleton()->try_send_reset();
            dc_midi::MidiOutPortsPerApi::singleton()->try_send_start();

            dc_ticker::TickerOverhead::singleton()->restart();
        }


        tmpSET_(IS_NOTFYING, true);
    }

    void Mainwindow
    ::on_pb_pause_clicked() noexcept
    {
        if(tmpGET_(IS_PAUSE) == true)
        {
            tmpSET_(IS_PAUSE, false);
            tmpSET_(IS_NOTFYING, true);
            dc_midi::MidiOutPortsPerApi::singleton()->try_send_continue();
        }
        else
        {
            tmpSET_(IS_PAUSE, true);
            tmpSET_(IS_NOTFYING, false);
            dc_midi::MidiOutPortsPerApi::singleton()->try_send_stop();
        }
    }

    void Mainwindow
    ::on_pb_stop_clicked() noexcept
    {
        tmpSET_(IS_NOTFYING, false);
        tmpSET_(IS_PAUSE, false);

        dc_midi::Sequencer::singleton()->reset();
        dc_midi::MidiOutPortsPerApi::singleton()->try_send_stop();
        dc_midi::MidiOutPortsPerApi::singleton()->try_send_panic();
        dc_midi::MidiOutPortsPerApi::singleton()->try_send_reset();

        dc_midi::MessageStack<dc_midi::StaticAccess>::clean_all();
        dc_midi::Timers::reset_all_taktchain();
    }

    void Mainwindow
    ::on_pb_panic_clicked() noexcept
    {
        dc_midi::MessageStack<dc_midi::StaticAccess>::clean_all();
        dc_midi::MidiOutPortsPerApi::singleton()->try_send_panic();
    }



    void Mainwindow
    ::on_hS_interval_valueChanged(int intervall_in_bpm__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        int interval_in_bpm_x_100{intervall_in_bpm__*100+dial_interval_after_comma->value()};
        selSET_(this_dtlPROJECT_OBSERVER, CLOCKSPEED_inBPM_x_100, interval_in_bpm_x_100);
    }

    void Mainwindow
    ::on_dial_interval_after_comma_valueChanged(int intervall_in_bpm_after_comma__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        int interval_in_bpm_x_100{hS_interval->value()*100+intervall_in_bpm_after_comma__};
        selSET_(this_dtlPROJECT_OBSERVER, CLOCKSPEED_inBPM_x_100, interval_in_bpm_x_100);
    }

    void Mainwindow
    ::on_pb_use_taktoffset_linear_clicked() noexcept
    {
        relSET_(this_dtlPATTERN_OBSERVER, USE_TAKT_OFFSET_per, USE_PER_MODE_RUN_MASTER );
    }

    void Mainwindow
    ::on_pb_use_taktsaitemute_linear_clicked() noexcept
    {
        relSET_(this_dtlPATTERN_OBSERVER, USE_TAKTSAITE_MUTE_per, USE_PER_MODE_RUN_MASTER);
    }

    void Mainwindow
    ::on_pb_use_taktsaiteoffset_linear_clicked() noexcept
    {
        relSET_(this_dtlPATTERN_OBSERVER, USE_TAKTSAITE_OFFSET_per, USE_PER_MODE_RUN_MASTER);
    }

    void Mainwindow
    ::on_pb_use_taktoffset_song_clicked() noexcept
    {
        relSET_(this_dtlPATTERN_OBSERVER, USE_TAKT_OFFSET_per, USE_PER_MODE_RUN_CURRENT);
    }

    void Mainwindow
    ::on_pb_use_taktsaitemute_song_clicked() noexcept
    {
        relSET_(this_dtlPATTERN_OBSERVER, USE_TAKTSAITE_MUTE_per, USE_PER_MODE_RUN_CURRENT);
    }

    void Mainwindow
    ::on_pb_use_taktsaiteoffset_song_clicked() noexcept
    {
        relSET_(this_dtlPATTERN_OBSERVER, USE_TAKTSAITE_OFFSET_per, USE_PER_MODE_RUN_CURRENT);
    }

    void Mainwindow
    ::on_pb_mute_all_pattern_timer_clicked() noexcept
    {
        auto project(relOBS_(this_dtlPROJECT_OBSERVER));
        for(TYPE_index_child pattern_id{0} ; pattern_id != Pattern_per_Project ; ++pattern_id )
        {
            auto pattern(project->pattern(pattern_id));
            if(pattern->get_property<PatternPropertiesIndex::MUTE_TIME>() > 0)
                pattern->set_property<PatternPropertiesIndex::IS_MUTED>(true);
        }
    }

    void Mainwindow
    ::on_pb_open_filmanager_clicked() noexcept
    {
        Filemanager::singleton()->show();
    }

    void Mainwindow
    ::on_pb_maximize_clicked() noexcept
    {
        static bool isMaximized__{false};
        if( isMaximized__ == true )
        {
            this->showNormal();
            isMaximized__ = false;
        }
        else
        {
            this->showFullScreen();
            isMaximized__ = true;
        }
    }

    //! Taktchaining *******************************************************************
    void Mainwindow
    ::property_changed(AT_(Temporary,IS_TAKTCHAIN_SET_TO_ALL)) noexcept
    {
        set_taktchain_set_to_all();
    }

    void Mainwindow
    ::set_taktchain_set_to_all() noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        if(tmpGET_(IS_TAKTCHAIN_SET_TO_ALL))
            DCSTYLE->set_mutedButtonPalette(pb_taktchain_set2all);
        else
            DCSTYLE->set_defaultMasterPalette(pb_taktchain_set2all);
    }

    void Mainwindow
    ::on_dial_taktchain_for_time_valueChanged(int for_time_) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        if(tmpGET_(IS_TAKTCHAIN_SET_TO_ALL))
        {
            for(TYPE_index_child taktchain_id{0} ; taktchain_id != Taktchain_per_Takt ; ++taktchain_id)
                tmpGET_(SELECTED_PATTERN)
                ->takt(taktchain_id)
                ->taktchain(tmpGET_(SELECTED_TAKTCHAIN_LEVEL_ID))->set_property<TaktchainPropertiesIndex::FOR>(for_time_);
        }
        else
        {
            auto selected_taktchain(tmpGET_(SELECTED_TAKTCHAIN));
            selected_taktchain->set_property<TaktchainPropertiesIndex::FOR>(for_time_);
        }
    }

    void Mainwindow
    ::on_pb_taktchain_auto_chain_clicked() noexcept
    {
        if(tmpGET_(IS_TAKTCHAIN_SET_TO_ALL))
        {
            for(TYPE_index_child taktchain_id{0} ; taktchain_id != Taktchain_per_Takt ; ++taktchain_id)
                tmpGET_(SELECTED_PATTERN)
                ->takt(taktchain_id)
                ->taktchain(tmpGET_(SELECTED_TAKTCHAIN_LEVEL_ID))->set_property<TaktchainPropertiesIndex::NEXT>(ENUM_takt_chain_mode::MODE_AUTO_LOOP);
        }
        else
        {
            auto selected_taktchain(tmpGET_(SELECTED_TAKTCHAIN));
            selected_taktchain->set_property<TaktchainPropertiesIndex::NEXT>(ENUM_takt_chain_mode::MODE_AUTO_LOOP);
        }
    }

    void Mainwindow
    ::on_pb_taktchain_equal_to_master_clicked() noexcept
    {
        if(tmpGET_(IS_TAKTCHAIN_SET_TO_ALL))
        {
            for(TYPE_index_child taktchain_id{0} ; taktchain_id != Taktchain_per_Takt ; ++taktchain_id)
                tmpGET_(SELECTED_PATTERN)
                ->takt(taktchain_id)
                ->taktchain(tmpGET_(SELECTED_TAKTCHAIN_LEVEL_ID))->set_property<TaktchainPropertiesIndex::NEXT>(ENUM_takt_chain_mode::MODE_TO_MASTER);
        }
        else
        {
            auto selected_taktchain(tmpGET_(SELECTED_TAKTCHAIN));
            selected_taktchain->set_property<TaktchainPropertiesIndex::NEXT>(ENUM_takt_chain_mode::MODE_TO_MASTER);
        }
    }

    void Mainwindow
    ::on_dial_taktchain_next_valueChanged(int next_) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        if(tmpGET_(IS_TAKTCHAIN_SET_TO_ALL))
        {
            for(TYPE_index_child taktchain_id{0} ; taktchain_id != Taktchain_per_Takt ; ++taktchain_id)
                tmpGET_(SELECTED_PATTERN)
                ->takt(taktchain_id)
                ->taktchain(tmpGET_(SELECTED_TAKTCHAIN_LEVEL_ID))->set_property<TaktchainPropertiesIndex::NEXT>(next_);
        }
        else
        {
            auto selected_taktchain(tmpGET_(SELECTED_TAKTCHAIN));
            selected_taktchain->set_property<TaktchainPropertiesIndex::NEXT>(next_);
        }
    }

    void Mainwindow
    ::on_pb_taktchain_auto_level_clicked() noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        if(tmpGET_(IS_TAKTCHAIN_SET_TO_ALL))
        {
            for(TYPE_index_child taktchain_id{0} ; taktchain_id != Taktchain_per_Takt ; ++taktchain_id)
                tmpGET_(SELECTED_PATTERN)
                ->takt(taktchain_id)
                ->taktchain(tmpGET_(SELECTED_TAKTCHAIN_LEVEL_ID))->set_property<TaktchainPropertiesIndex::OVERWRITE_TARGET_LEVEL>(ENUM_takt_chain_level_mode::MODE_AUTO_LEVEL);
        }
        else
        {
            auto selected_taktchain(tmpGET_(SELECTED_TAKTCHAIN));
            selected_taktchain->set_property<TaktchainPropertiesIndex::OVERWRITE_TARGET_LEVEL>(ENUM_takt_chain_level_mode::MODE_AUTO_LEVEL);
        }
    }

    void Mainwindow
    ::on_dial_taktchain_next_level_valueChanged(int takt_target_chain_level_) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        if(tmpGET_(IS_TAKTCHAIN_SET_TO_ALL))
        {
            for(TYPE_index_child taktchain_id{0} ; taktchain_id != Taktchain_per_Takt ; ++taktchain_id)
                tmpGET_(SELECTED_PATTERN)
                ->takt(taktchain_id)
                ->taktchain(tmpGET_(SELECTED_TAKTCHAIN_LEVEL_ID))->set_property<TaktchainPropertiesIndex::OVERWRITE_TARGET_LEVEL>(takt_target_chain_level_);
        }
        else
        {
            auto selected_taktchain(tmpGET_(SELECTED_TAKTCHAIN));
            selected_taktchain->set_property<TaktchainPropertiesIndex::OVERWRITE_TARGET_LEVEL>(takt_target_chain_level_);
        }
    }

    void Mainwindow
    ::on_pb_taktchain_set2all_clicked() noexcept
    {
        tmpOBS_()->invert_property<TemporaryPropertiesIndex::IS_TAKTCHAIN_SET_TO_ALL>();
    }

    void Mainwindow
    ::property_changed(AT_(Temporary,SELECTED_TAKTCHAIN)) noexcept
    {
        set_taktchain_next();
        set_taktchain_for();
        set_taktchain_next_level();
    }

    void Mainwindow
    ::set_taktchain_next() noexcept
    {
    SET_EVENT_BLOCK

        auto next(tmpGET_(SELECTED_TAKTCHAIN)->get_property<TaktchainPropertiesIndex::NEXT>());
        dial_taktchain_next->setValue(next);
    }

    void Mainwindow
    ::set_taktchain_for() noexcept
    {
    SET_EVENT_BLOCK

        auto for_(tmpGET_(SELECTED_TAKTCHAIN)->get_property<TaktchainPropertiesIndex::FOR>());
        dial_taktchain_for_time->setValue(for_);
    }

    void Mainwindow
    ::set_taktchain_next_level() noexcept
    {
    SET_EVENT_BLOCK

        auto next_level(tmpGET_(SELECTED_TAKTCHAIN)->get_property<TaktchainPropertiesIndex::OVERWRITE_TARGET_LEVEL>());
        dial_taktchain_next_level->setValue(next_level);
    }

}   /// EO namespace dc_gui
