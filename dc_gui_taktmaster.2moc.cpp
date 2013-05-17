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

#include <dc_gui_taktmaster.2moc.h>

#include <dc_gui_inits.h>
#include <dc_gui_styles.h>

#include <dc_midi_sequencer_timer.h>

#include <cast/lexical_cast.hpp>

#include <object_dependstrategy.h>

#include <dc_standard_values.h>

namespace dc_gui{

//! \class Taktmaster_Initializer
    void Taktmaster_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        Taktmaster_4GroupSpaceInitializer::initialize_at_frame(parent_frame);
    }

//!\class Taktchain

    void Taktchain
    ::SELECTED_OBSERVER_CHANGED(Pattern) noexcept
    {
        if(tmpGET_(SELECTED_TAKTCHAIN_TAKT_ID) == this_relTAKTCHAIN_OBSERVER::_absolut_id_in_parent)
        {
                tmpSET_(SELECTED_TAKTCHAIN_LEVEL_ID, this_relTAKTCHAIN_OBSERVER::_absolut_id_in_parent);

                auto selected_taktchain_at_level(tmpGET_(SELECTED_PATTERN)
                                                 ->takt(tmpGET_(SELECTED_TAKTCHAIN_TAKT_ID))
                                                 ->taktchain(tmpGET_(SELECTED_TAKTCHAIN_LEVEL_ID)));

                tmpSET_(SELECTED_TAKTCHAIN, selected_taktchain_at_level);
        }

        update();
    }


        //! Dieser Chain wurde aktiviert
    void Taktchain
    ::SELECTED_OBSERVER_CHANGED(Taktchain) noexcept
    {
        update();
    }

    void Taktchain
    ::set_selected() noexcept
    {
        //if(this_relTAKTCHAIN_OBSERVER::is_my_relative_selected())
        if(tmpGET_(SELECTED_TAKTCHAIN_TAKT_ID) == this_relTAKTCHAIN_OBSERVER::_absolut_id_in_parent)
        {
            DCSTYLE->set_mutedButtonPalette(pb_actionButton);
            DCSTYLE->set_mutedButtonPalette(pb_actionButton_2);
        }
        else
        {
            DCSTYLE->set_defaultMasterPalette(pb_actionButton);
            DCSTYLE->set_defaultMasterPalette(pb_actionButton_2);
        }

    }

    void Taktchain
    ::property_changed(AT_(Temporary,SELECTED_TAKTCHAIN_LEVEL_ID)) noexcept
    {
        this_relTAKTCHAIN_OBSERVER::Policy_change_Object2Observe_T::change(this);

        set_selected_level();

        update();
    }

    void Taktchain
    ::set_selected_level() noexcept
    {
        if(tmpGET_(SELECTED_TAKTCHAIN_LEVEL_ID) == this_relTAKTCHAIN_OBSERVER::_absolut_id_in_parent)
            DCSTYLE->set_visibleMasterPalette(pb_timeDummy);
        else
            DCSTYLE->set_defaultMasterPalette(pb_timeDummy);
    }

    void Taktchain
    ::property_changed(AT_(Temporary,SELECTED_TAKTCHAIN_TAKT_ID)) noexcept
    {
        set_selected();
    }

    void Taktchain
    ::set_for() noexcept
    {
        auto for_(relGET_(this_relTAKTCHAIN_OBSERVER, FOR));
        if(for_ >= ENUM_takt_chain_mode::MODE_ENDLESS)
            label_for->setText("oo");
        else if (for_ == 0)
            label_for->setText("X");
        else
            label_for->setText(build_label_value_string("F", relGET_(this_relTAKTCHAIN_OBSERVER, FOR)).c_str());
    }

    void Taktchain
    ::set_next() noexcept
    {
        int next_or_mode{relGET_(this_relTAKTCHAIN_OBSERVER, NEXT)};
        switch(next_or_mode)
        {
        case ENUM_takt_chain_mode::MODE_AUTO_LOOP:
            label_next->setText("AC");
            //label_next->setNum(this_selTAKT_OBSERVER::_id_in_parent);
            break;

        case ENUM_takt_chain_mode::MODE_TO_MASTER:
            label_next->setText("M");
            break;

        default:
            label_next->setNum(next_or_mode+HUMAN_COUNT);
            break;
        }
    }

    void Taktchain
    ::set_overwrite_target_level() noexcept
    {
        int next_or_mode{relGET_(this_relTAKTCHAIN_OBSERVER, OVERWRITE_TARGET_LEVEL)};
        switch(next_or_mode)
        {
        case ENUM_takt_chain_level_mode::MODE_AUTO_LEVEL:
            label_target_chain_level->setText("L++");
            break;
        default:
            label_target_chain_level->setText(build_label_value_string("L", next_or_mode+HUMAN_COUNT).c_str());
            break;
        }
    }

    Taktchain
    ::Taktchain()
    {
        setupUi(this);
    }

    void Taktchain
    ::init() noexcept
    {
        update();
        set_selected_level();
    }

    void Taktchain
    ::update() noexcept
    {
        set_for();
        set_next();
        set_selected();
        set_overwrite_target_level();
    }

//! \class  Taktmaster
    Taktmaster
    ::Taktmaster () :
        _takt_chain{new Taktchain{}}
    {
        setupUi(this);

        _takt_chain->setParent(this);
        _takt_chain->setGeometry(0,33,35,35);
        _takt_chain->show();

        InitButtonText::set_first_string_then_number<Taktmaster>(FIRST_TAKTMASTER_BUTTON_STRING, pb_actionButton);
    }

    void Taktmaster
    ::init() noexcept
    {
        connect(&_overhide_timer,
                SIGNAL(timeout()),
                this,
                SLOT(set_blink_overhide()));
        _overhide_timer.setInterval(250);

        //dial_time->setStyle(motifstyle);

        update();

        _takt_chain->init();
    }

    void Taktmaster
    ::update() noexcept
    {
        set_selected();
        set_running();
        setup_blink_overhide();
    }

    Taktmaster
    ::~Taktmaster()
    {
        _overhide_timer.stop();
    }

    void Taktmaster
    ::RELATIVE_OBSERVER_CHANGED(Takt) noexcept
    {
        if(this_relTAKT_OBSERVER::_absolut_id_in_parent == 0)
            on_pb_actionButton_clicked();

        update();
    }

    void Taktmaster
    ::SELECTED_OBSERVER_CHANGED(Takt) noexcept
    {
        update();
    }

    void Taktmaster
    ::set_selected() noexcept
    {
        if(this_relTAKT_OBSERVER::is_my_relative_selected())
            set_iam_selected();
        else
            set_iam_not_selected();
    }

    void Taktmaster
    ::set_running() noexcept
    {
/// Absolute Ids verwenden!
for(unsigned int pattern_id{0} ; pattern_id != Pattern_per_Project ; ++pattern_id )
    if(dc_midi::Timers::takt_chain[pattern_id]->parent_pattern() == tmpGET_(SELECTED_PATTERN))
    {
        if(tmpGET_(SELECTED_PATTERN)->takt(this_relTAKT_OBSERVER::_absolut_id_in_parent)
           == relOBS_(this_relTAKT_OBSERVER))
        {
            auto current_chain_level(dc_midi::Timers::takt_chain[pattern_id]->current_takt_chain_level(this_relTAKT_OBSERVER::_absolut_id_in_parent));
            label_current_chain_level->setText(std::string{"L" + lexical_cast<std::string>(current_chain_level+HUMAN_COUNT)}.c_str());
            // Nur den aktuellen Takt anzeigen
            if(dc_midi::Timers::takt_chain[pattern_id]->current_running_takt_id() == this_relTAKT_OBSERVER::_absolut_id_in_parent)
            {
                auto current_chain_for_time(dc_midi::Timers::takt_chain[pattern_id]->current_takt_chain_for_time(this_relTAKT_OBSERVER::_absolut_id_in_parent));
                if(current_chain_for_time == 0)
                    label_current_for_time->setText("");
                else
                    label_current_for_time->setNum(int{current_chain_for_time});
            }
            else
                label_current_for_time->setText("");
        }


    }


        if(selGET_(this_dtlSEQUENCER_OBSERVER, TAKT_POS) == this_relTAKT_OBSERVER::_absolut_id_in_parent)
            set_iam_running();
        else
            set_iam_not_running();

        // Markiere Running Takt
        setup_blink_overhide();

        // Setze TaktOffset Per Master Markierung
        if(relGET_(this_dtlPATTERN_OBSERVER, USE_TAKT_OFFSET_per) == USE_PER_MODE::USE_PER_MODE_RUN_MASTER)
        {
            set_taktoffset_per_master();
        }

        // Setze TaktOffset Per Master Markierung
        if(relGET_(this_dtlPATTERN_OBSERVER, USE_TAKT_OFFSET_per) == USE_PER_MODE::USE_PER_MODE_RUN_CURRENT)
        {
            set_taktoffset_per_run();
        }
    }

    void Taktmaster
    ::set_iam_selected() noexcept
    {
        DCSTYLE->set_defaultMasterPalette(label_current_chain_level);
        DCSTYLE->set_defaultMasterPalette(label_current_for_time);
        DCSTYLE->set_visibleMasterPalette(pb_actionButton);
        iam_selected_yet = true;
    }

    void Taktmaster
    ::set_iam_not_selected() noexcept
    {
        if(iam_running_yet == false)
        {
            DCSTYLE->set_defaultMasterPalette(label_current_chain_level);
            DCSTYLE->set_defaultMasterPalette(label_current_for_time);
            DCSTYLE->set_defaultMasterPalette(pb_actionButton);
        }


        iam_selected_yet = false;
    }

    void Taktmaster
    ::set_taktoffset_per_master() noexcept
    {
        if(iam_running_yet == true)
        {
            DCSTYLE->set_overhideTrueTaktPalette(pb_plus);
            DCSTYLE->set_overhideTrueTaktPalette(pb_minus);
        }
        else
        {
            DCSTYLE->set_defaultMasterPalette(pb_plus);
            DCSTYLE->set_defaultMasterPalette(pb_minus);
        }
    }

    void Taktmaster
    ::set_taktoffset_per_run() noexcept
    {
        if(iam_overhide_yet == true)
        {
            DCSTYLE->set_overhideTrueTaktPalette(pb_plus);
            DCSTYLE->set_overhideTrueTaktPalette(pb_minus);
        }
        else
        {
            DCSTYLE->set_defaultMasterPalette(pb_plus);
            DCSTYLE->set_defaultMasterPalette(pb_minus);
        }
    }

    void Taktmaster
    ::set_iam_running() noexcept
    {
        if(iam_selected_yet == false)
        {
            DCSTYLE->set_overhideTrueTaktPalette(label_current_chain_level);
            DCSTYLE->set_overhideTrueTaktPalette(label_current_for_time);
            DCSTYLE->set_overhideTrueTaktPalette(pb_actionButton);
        }


///USE_TAKT_OFFSET_per,
///USE_TAKTSAITE_OFFSET_per,
///USE_TAKTSAITE_MUTE_per
        iam_running_yet = true;
    }

    void Taktmaster
    ::set_iam_not_running() noexcept
    {
        if(iam_selected_yet == false)
        {
            DCSTYLE->set_defaultMasterPalette(label_current_chain_level);
            DCSTYLE->set_defaultMasterPalette(label_current_for_time);
            DCSTYLE->set_defaultMasterPalette(pb_actionButton);
        }


        iam_running_yet = false;
    }

    void Taktmaster
    ::setup_blink_overhide() noexcept
    {
        using namespace dc_midi;

/*
/// TODO nochmal überdenken, besser wäre eine getfunktion im timer mit taktübergabe oder so?
//for(unsigned int pattern_id{0} ; pattern_id != Pattern_per_Project ; ++pattern_id )
    TYPE_index_child parent_pattern_id{this_dtlPATTERN_OBSERVER::_absolut_id_in_parent};
    std::cout << int{parent_pattern_id} << std::endl;
    if(Timers::takt_chain[parent_pattern_id]->parent_pattern() == tmpGET_(SELECTED_PATTERN))
    {
        if(relOBS_(this_relTAKT_OBSERVER) == Timers::takt_chain[parent_pattern_id]->current_running_takt())
        {

*/


for(unsigned int pattern_id{0} ; pattern_id != Pattern_per_Project ; ++pattern_id )
    if(Timers::takt_chain[pattern_id]->parent_pattern() == tmpGET_(SELECTED_PATTERN))
    {
        if(tmpGET_(SELECTED_PATTERN)->takt(this_relTAKT_OBSERVER::_absolut_id_in_parent)
           == Timers::takt_chain[pattern_id]->current_running_takt())
        {
            if(iam_overhide_yet == true)
                return; // allready
            else
            {
                _overhide_timer.start();
                //DCSTYLE->set_overhideTrueTaktPalette(_takt_chain->label_target_chain_level);
                //DCSTYLE->set_overhideTrueTaktPalette(_takt_chain->pb_timeDummy);

                iam_overhide_yet = true;
            }
        }
        else
            if(iam_overhide_yet == false)
                return; // allready
            else
            {
                _overhide_timer.stop();
                //DCSTYLE->set_defaultMasterPalette(_takt_chain->label_target_chain_level);
                //DCSTYLE->set_defaultMasterPalette(_takt_chain->pb_timeDummy);

                set_blink_overhide_false();
                iam_overhide_yet = false;
            }
    }
}

    void Taktmaster
    ::set_blink_overhide() noexcept
    {
        if(is_blinking_overhide_yet)
            set_blink_overhide_false();
        else
            set_blink_overhide_true();
    }

    void Taktmaster
    ::set_blink_overhide_true() noexcept
    {
///DCSTYLE->set_overhideTrueTaktPalette(pb_plus);
///DCSTYLE->set_overhideTrueTaktPalette(pb_minus);
        DCSTYLE->set_overhideTrueTaktPalette(label_current_chain_level);
        DCSTYLE->set_overhideTrueTaktPalette(label_current_for_time);
        DCSTYLE->set_overhideTrueTaktPalette(pb_actionButton);

        is_blinking_overhide_yet = true;
    }

    void Taktmaster
    ::set_blink_overhide_false() noexcept
    {
        if(iam_selected_yet == true)
        {
            DCSTYLE->set_defaultMasterPalette(label_current_chain_level);
            DCSTYLE->set_defaultMasterPalette(label_current_for_time);
            DCSTYLE->set_visibleMasterPalette(pb_actionButton);
///DCSTYLE->set_visibleMasterPalette(pb_plus);
///DCSTYLE->set_visibleMasterPalette(pb_minus);
        }
        else
        {
            DCSTYLE->set_defaultMasterPalette(label_current_chain_level);
            DCSTYLE->set_defaultMasterPalette(label_current_for_time);
            DCSTYLE->set_defaultMasterPalette(pb_actionButton);
///DCSTYLE->set_defaultMasterPalette(pb_plus);
///DCSTYLE->set_defaultMasterPalette(pb_minus);
        }

        is_blinking_overhide_yet = false;
    }

    void Taktmaster
    ::on_pb_actionButton_clicked() noexcept
    {
        this_relTAKT_OBSERVER::replace_selected_with_relative();
    }

    void Taktmaster
    ::on_pb_plus_clicked() noexcept
    {
        relOBS_(this_relTAKT_OBSERVER)->increase_property<TaktPropertiesIndex::OFFSET>();
    }

    void Taktmaster
    ::on_pb_minus_clicked() noexcept
    {
        relOBS_(this_relTAKT_OBSERVER)->decrease_property<TaktPropertiesIndex::OFFSET>();
    }

//!\DRAGnDROP
    QPixmap Taktmaster
    ::drag_pixmap() noexcept
    {
        bg->setVisible(false);
        QPixmap pixmap_of_me(QPixmap::grabWidget(this));
        bg->setVisible(true);

        return std::move(pixmap_of_me);
    }

    std::string Taktmaster
    ::additional_drag_text() const noexcept
    {
        return dc_export::Takt2Tabulator::convert2string(relOBS_(this_dtlPATTERN_OBSERVER),
                                                         relOBS_(this_relTAKT_OBSERVER));
    }

    extendQt::TYPE_vector_additional_numeric_drag_data Taktmaster
    ::additional_numeric_drag_data() const noexcept
    {
        extendQt::TYPE_vector_additional_numeric_drag_data taktsaiten_offsets{};
        auto takt(relOBS_(this_relTAKT_OBSERVER));
        for(TYPE_index_child taktsaite_id{0} ; taktsaite_id!=GLOBAL_supportedSAITES ; ++taktsaite_id)
            taktsaiten_offsets.push_back(takt->taktsaite(taktsaite_id)->get_property<TaktsaitePropertiesIndex::OFFSET>());

        return taktsaiten_offsets;
    }

    bool Taktmaster
    ::compare_is_additional_data_dropable(extendQt::DragObject const* drag_source_object__) const noexcept
    {
        if(drag_source_object__->additional_data_vector().size() == GLOBAL_supportedSAITES)
            return true;
        else
            return false;
    }

    void Taktmaster
    ::additional_data_is_dropped(extendQt::TYPE_vector_additional_numeric_drag_data const& numeric_drag_data__) noexcept
    {
        auto takt(relOBS_(this_relTAKT_OBSERVER));
        for(TYPE_index_child taktsaite_id{0} ; taktsaite_id!=GLOBAL_supportedSAITES ; ++taktsaite_id)
        {
            auto accord_offset(numeric_drag_data__[taktsaite_id]);
            takt->taktsaite(taktsaite_id)->set_property<TaktsaitePropertiesIndex::OFFSET>(accord_offset);
        }
    }

    std::string Taktmaster
    ::doc_file_name() const noexcept
    {
        return DOC_TAKTMASTER;
    }
}
