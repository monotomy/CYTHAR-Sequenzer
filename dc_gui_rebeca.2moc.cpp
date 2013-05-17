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

#include <dc_gui_rebeca.2moc.h>

#include <functions/invert.hpp>
#include <cast/lexical_cast.hpp>

#include <dc_algorithm_rebeca.hpp>

#include <dc_gui_styles.h>

#include <QColor>

#include <dc_standard_values.h>

namespace dc_gui{

//! \class Rebeca_Initalizer
    void Rebeca_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        Rebeca* repeateditor{new Rebeca{}};

        repeateditor->setGeometry(top_first,left_first,width,height);
        repeateditor->setParent(parent_frame);
        repeateditor->init();
        repeateditor->setVisible(true);
    }

//! \class Rebeca
    Rebeca
    ::Rebeca()
    {
        setupUi(this);
    }

    void fill_operator_cb(QComboBox* operator_box__) noexcept;
    void fill_operator_cb(QComboBox* operator_box__) noexcept
    {
        operator_box__->addItem("not");
        operator_box__->addItem("+");
        operator_box__->addItem("-");
        operator_box__->addItem("*");
        operator_box__->addItem("/");
        operator_box__->addItem("%");
    }

    void Rebeca
    ::init() noexcept
    {
    SET_EVENT_BLOCK
        fill_operator_cb(cb_intervall_operator);
        fill_operator_cb(cb_intervall2original_operator);
        fill_operator_cb(cb_original_operator);
        fill_operator_cb(cb_intervall_original_result2repeat_operator);

        set_view_mode();
    }

    void Rebeca
    ::RELATIVE_OBSERVER_CHANGED(Step) noexcept
    {
        update();
    }
    void Rebeca
    ::update() noexcept
    {
        set_delay();
        set_repeat_times();
        set_interval();
        set_interval_operator();
        set_interval_operand();

        set_original();
        set_original_operator();
        set_original_operand();
        set_original2interval_operator();
        set_original_interval2result_operator();

        set_fit_to_range();

        fill_cb_results();
    }

    void Rebeca
    ::property_changed(AT_(Temporary,REBECA_SHOW)) noexcept
    {
        set_view_mode();
    }

    void Rebeca
    ::set_view_mode() noexcept
    {
        DCSTYLE->set_defaultMasterPalette(pb_tab_note);
        DCSTYLE->set_defaultMasterPalette(pb_tab_velocity);
        DCSTYLE->set_defaultMasterPalette(pb_tab_length);

        switch (tmpGET_(REBECA_SHOW))
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            DCSTYLE->set_mutedButtonPalette(pb_tab_note);
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            DCSTYLE->set_mutedButtonPalette(pb_tab_velocity);
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            DCSTYLE->set_mutedButtonPalette(pb_tab_length);
            break;
        default:
            break;
        }

        update();
    }

    //! OFFSET *************************************************************
    void Rebeca
    ::property_changed(AT_(Step,OFFSET)) noexcept
    {
        set_original();
        fill_cb_results();
    }
    void Rebeca
    ::property_changed(AT_(Step,OFFSET_OPERATOR)) noexcept
    {
        set_original_operator();
        fill_cb_results();
    }
    void Rebeca
    ::property_changed(AT_(Step,OFFSET_OPERAND)) noexcept
    {
        set_original_operand();
        fill_cb_results();
    }
    void Rebeca
    ::property_changed(AT_(Step,OFFSET_2_INTERVAL_OPERATOR)) noexcept
    {
        set_original2interval_operator();
        fill_cb_results();
    }
    void Rebeca
    ::property_changed(AT_(Step,OFFSET_INTERVAL_2_REPEAT_OPERATOR)) noexcept
    {
        set_original_interval2result_operator();
        fill_cb_results();
    }

    void Rebeca
    ::property_changed(AT_(Step,OFFSET_FIT_TO_RANGE)) noexcept
    {
        set_fit_to_range();
        fill_cb_results();
    }

    //! VELOCITY ***********************************************************
    void Rebeca
    ::property_changed(AT_(Step,VELOCITY)) noexcept
    {
        set_original();
        fill_cb_results();
    }
    void Rebeca
    ::property_changed(AT_(Step,VELOCITY_OPERATOR)) noexcept
    {
        set_original_operator();
        fill_cb_results();
    }
    void Rebeca
    ::property_changed(AT_(Step,VELOCITY_OPERAND)) noexcept
    {
        set_original_operand();
        fill_cb_results();
    }
    void Rebeca
    ::property_changed(AT_(Step,VELOCITY_2_INTERVAL_OPERATOR)) noexcept
    {
        set_original2interval_operator();
        fill_cb_results();
    }
    void Rebeca
    ::property_changed(AT_(Step,VELOCITY_INTERVAL_2_REPEAT_OPERATOR)) noexcept
    {
        set_original_interval2result_operator();
        fill_cb_results();
    }

    void Rebeca
    ::property_changed(AT_(Step,VELOCITY_FIT_TO_RANGE)) noexcept
    {
        set_fit_to_range();
        fill_cb_results();
    }

    //! LENGTH *************************************************************
    void Rebeca
    ::property_changed(AT_(Step,LENGTH)) noexcept
    {
        set_original();
        fill_cb_results();
    }
    void Rebeca
    ::property_changed(AT_(Step,LENGTH_OPERATOR)) noexcept
    {
        set_original_operator();
        fill_cb_results();
    }
    void Rebeca
    ::property_changed(AT_(Step,LENGTH_OPERAND)) noexcept
    {
        set_original_operand();
        fill_cb_results();
    }
    void Rebeca
    ::property_changed(AT_(Step,LENGTH_2_INTERVAL_OPERATOR)) noexcept
    {
        set_original2interval_operator();
        fill_cb_results();
    }
    void Rebeca
    ::property_changed(AT_(Step,LENGTH_INTERVAL_2_REPEAT_OPERATOR)) noexcept
    {
        set_original_interval2result_operator();
        fill_cb_results();
    }

    void Rebeca
    ::property_changed(AT_(Step,LENGTH_FIT_TO_RANGE)) noexcept
    {
        set_fit_to_range();
        fill_cb_results();
    }

    //! ALL ****************************************************************
    void Rebeca
    ::property_changed(AT_(Step,DELAY)) noexcept
    {
        set_delay();
        fill_cb_results();
    }

    void Rebeca
    ::property_changed(AT_(Step,REPEAT_TIMES)) noexcept
    {
        set_repeat_times();
        fill_cb_results();
    }

    void Rebeca
    ::property_changed(AT_(Step,INTERVAL)) noexcept
    {
        set_interval();
        fill_cb_results();
    }

    void Rebeca
    ::property_changed(AT_(Step,INTERVAL_OPERATOR)) noexcept
    {
        set_interval_operator();
        fill_cb_results();
    }

    void Rebeca
    ::property_changed(AT_(Step,INTERVAL_OPERAND)) noexcept
    {
        set_interval_operand();
        fill_cb_results();
    }

    //! ALL ****************************************************************
    void Rebeca
    ::set_original() noexcept
    {
    SET_EVENT_BLOCK

        switch (tmpGET_(REBECA_SHOW))
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            le_original->setText(lexical_cast<std::string>(relGET_(this_dtlSTEP_OBSERVER,OFFSET)).c_str());
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            le_original->setText(lexical_cast<std::string>(relGET_(this_dtlSTEP_OBSERVER,VELOCITY)).c_str());
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            le_original->setText(lexical_cast<std::string>(relGET_(this_dtlSTEP_OBSERVER,LENGTH)).c_str());
            break;
        default:
            break;
        }
    }

    void Rebeca
    ::set_original_operator() noexcept
    {
    SET_EVENT_BLOCK

        switch (tmpGET_(REBECA_SHOW))
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            cb_original_operator->setCurrentIndex(relGET_(this_dtlSTEP_OBSERVER,OFFSET_OPERATOR));
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            cb_original_operator->setCurrentIndex(relGET_(this_dtlSTEP_OBSERVER,VELOCITY_OPERATOR));
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            cb_original_operator->setCurrentIndex(relGET_(this_dtlSTEP_OBSERVER,LENGTH_OPERATOR));
            break;
        default:
            break;
        }
    }
    void Rebeca
    ::set_original_operand() noexcept
    {
    SET_EVENT_BLOCK

        switch (tmpGET_(REBECA_SHOW))
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            input_original_operand->setValue(relGET_(this_dtlSTEP_OBSERVER,OFFSET_OPERAND));
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            input_original_operand->setValue(relGET_(this_dtlSTEP_OBSERVER,VELOCITY_OPERAND));
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            input_original_operand->setValue(relGET_(this_dtlSTEP_OBSERVER,LENGTH_OPERAND));
            break;
        default:
            break;
        }
    }
    void Rebeca
    ::set_original2interval_operator() noexcept
    {
    SET_EVENT_BLOCK

        switch (tmpGET_(REBECA_SHOW))
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            cb_intervall2original_operator->setCurrentIndex(relGET_(this_dtlSTEP_OBSERVER,OFFSET_2_INTERVAL_OPERATOR));
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            cb_intervall2original_operator->setCurrentIndex(relGET_(this_dtlSTEP_OBSERVER,VELOCITY_2_INTERVAL_OPERATOR));
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            cb_intervall2original_operator->setCurrentIndex(relGET_(this_dtlSTEP_OBSERVER,LENGTH_2_INTERVAL_OPERATOR));
            break;
        default:
            break;
        }
    }
    void Rebeca
    ::set_original_interval2result_operator() noexcept
    {
    SET_EVENT_BLOCK

        switch (tmpGET_(REBECA_SHOW))
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            cb_intervall_original_result2repeat_operator->setCurrentIndex(relGET_(this_dtlSTEP_OBSERVER,OFFSET_INTERVAL_2_REPEAT_OPERATOR));
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            cb_intervall_original_result2repeat_operator->setCurrentIndex(relGET_(this_dtlSTEP_OBSERVER,VELOCITY_INTERVAL_2_REPEAT_OPERATOR));
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            cb_intervall_original_result2repeat_operator->setCurrentIndex(relGET_(this_dtlSTEP_OBSERVER,LENGTH_INTERVAL_2_REPEAT_OPERATOR));
            break;
        default:
            break;
        }
    }

    void Rebeca
    ::fill_cb_results() noexcept
    {
        cb_results->clear();

        static const std::string spacer{" : "};
        // Eintrag des standard step inkl. delay
        auto const delay(relGET_(this_dtlSTEP_OBSERVER, DELAY));
        auto const rebeaca_show(tmpGET_(REBECA_SHOW));
        switch (rebeaca_show)
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            cb_results->addItem((lexical_cast<std::string>(delay)
                                 +spacer
                                 +lexical_cast<std::string>(relGET_(this_dtlSTEP_OBSERVER, OFFSET))).c_str());
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            cb_results->addItem((lexical_cast<std::string>(delay)
                                 +spacer
                                 +lexical_cast<std::string>(relGET_(this_dtlSTEP_OBSERVER, VELOCITY))).c_str());
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            cb_results->addItem((lexical_cast<std::string>(delay)
                                 +spacer
                                 +lexical_cast<std::string>(relGET_(this_dtlSTEP_OBSERVER, LENGTH))).c_str());
            break;
        default:
            break;
        }

        dc_algorithm::TYPE_series value_serie;
        switch (rebeaca_show)
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            value_serie = dc_algorithm::calc_rebeca_for_offet_complete(relOBS_(this_dtlSTEP_OBSERVER));
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            value_serie = dc_algorithm::calc_rebeca_for_velocity_complete(relOBS_(this_dtlSTEP_OBSERVER));
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            value_serie = dc_algorithm::calc_rebeca_for_length_complete(relOBS_(this_dtlSTEP_OBSERVER));
            break;
        default:
            break;
        }

        // Eintrag der Seite zum Interval schirtt
        std::string current_line_string;
        static const QColor color_red("red");
        bool is_in_range(false);
        auto results_interval(dc_algorithm::calc_rebeca_for_interval(relOBS_(this_dtlSTEP_OBSERVER)));
        for(size_t current_result{0};
            current_result != value_serie.size();
            ++current_result)
        {
            current_line_string = lexical_cast<std::string>(results_interval[current_result])
                                  +spacer
                                  +lexical_cast<std::string>(value_serie[current_result]);

            // Checke ob das Delay in der Range ist
            if(results_interval[current_result] < DELAY_MIN or results_interval[current_result] > DELAY_MAX )
                is_in_range = false;
            else
                is_in_range = true;

            // Checke den Wert, ob er in der Range ist
            if( is_in_range == true)
            {
                switch (rebeaca_show)
                {
                case  REBECA_SHOW::REBECA_SHOW_NOTE:
                    is_in_range = ( value_serie[current_result] > OFFSET_MIN
                                    and value_serie[current_result] <= OFFSET_MAX );
                    break;
                case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
                    is_in_range = ( value_serie[current_result] > VELOCITY_MIN
                                    and value_serie[current_result] <= VELOCITY_MAX );
                    break;
                case  REBECA_SHOW::REBECA_SHOW_LENGTH:
                    is_in_range = ( value_serie[current_result] > LENGTH_MIN
                                    and value_serie[current_result] <= LENGTH_MAX );
                    break;
                default:
                    break;
                }
            }

            // Einfärben wenn ausser bereich
            if(is_in_range == false)
            {
                cb_results->addItem(current_line_string.c_str(),color_red);
                const QModelIndex idx = cb_results->model()->index(current_result+1, 0);
                cb_results->model()->setData(idx, color_red, Qt::BackgroundColorRole);
            }
            else
                cb_results->addItem(current_line_string.c_str());
        }
    }

    void Rebeca
    ::set_fit_to_range() noexcept
    {
        bool is_fit_to_range{false};
        switch (tmpGET_(REBECA_SHOW))
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            is_fit_to_range = relGET_(this_dtlSTEP_OBSERVER, OFFSET_FIT_TO_RANGE);
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            is_fit_to_range = relGET_(this_dtlSTEP_OBSERVER, VELOCITY_FIT_TO_RANGE);
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            is_fit_to_range = relGET_(this_dtlSTEP_OBSERVER, LENGTH_FIT_TO_RANGE);
            break;
        default:
            break;
        }

        if(is_fit_to_range == true)
            DCSTYLE->set_mutedButtonPalette(pb_fir_to_range);
        else
            DCSTYLE->set_defaultMasterPalette(pb_fir_to_range);
    }

    void Rebeca
    ::set_delay() noexcept
    {
    SET_EVENT_BLOCK

        input_delay->setValue(relGET_(this_dtlSTEP_OBSERVER,DELAY));
    }

    void Rebeca
    ::set_repeat_times() noexcept
    {
    SET_EVENT_BLOCK

        input_repeat->setValue(relGET_(this_dtlSTEP_OBSERVER,REPEAT_TIMES));
    }

    void Rebeca
    ::set_interval() noexcept
    {
    SET_EVENT_BLOCK

        input_intervall->setValue(relGET_(this_dtlSTEP_OBSERVER,INTERVAL));
    }

    void Rebeca
    ::set_interval_operator() noexcept
    {
    SET_EVENT_BLOCK

        cb_intervall_operator->setCurrentIndex(relGET_(this_dtlSTEP_OBSERVER,INTERVAL_OPERATOR));
    }

    void Rebeca
    ::set_interval_operand() noexcept
    {
    SET_EVENT_BLOCK

        input_intervall_operand->setValue(relGET_(this_dtlSTEP_OBSERVER,INTERVAL_OPERAND));
    }

//!\SLOTS
    void Rebeca
    ::on_input_delay_valueChanged(int delay__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        relSET_(this_dtlSTEP_OBSERVER, DELAY, delay__);
    }

    void Rebeca
    ::on_input_repeat_valueChanged(int repeat__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        relSET_(this_dtlSTEP_OBSERVER, REPEAT_TIMES, repeat__);
    }

    void Rebeca
    ::on_input_intervall_valueChanged(int interval__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        relSET_(this_dtlSTEP_OBSERVER, INTERVAL, interval__);
    }

    void Rebeca
    ::on_cb_intervall_operator_currentIndexChanged(int operator__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        relSET_(this_dtlSTEP_OBSERVER, INTERVAL_OPERATOR, operator__);
    }

    void Rebeca
    ::on_input_intervall_operand_valueChanged(int operand__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        relSET_(this_dtlSTEP_OBSERVER, INTERVAL_OPERAND, operand__);
    }

    void Rebeca
    ::on_cb_intervall2original_operator_currentIndexChanged(int operator__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        switch (tmpGET_(REBECA_SHOW))
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            relSET_(this_dtlSTEP_OBSERVER, OFFSET_2_INTERVAL_OPERATOR, operator__);
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            relSET_(this_dtlSTEP_OBSERVER, VELOCITY_2_INTERVAL_OPERATOR, operator__);
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            relSET_(this_dtlSTEP_OBSERVER, LENGTH_2_INTERVAL_OPERATOR, operator__);
            break;
        default:
            break;
        }
    }

    void Rebeca
    ::on_cb_original_operator_currentIndexChanged(int operator__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        switch (tmpGET_(REBECA_SHOW))
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            relSET_(this_dtlSTEP_OBSERVER, OFFSET_OPERATOR, operator__);
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            relSET_(this_dtlSTEP_OBSERVER, VELOCITY_OPERATOR, operator__);
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            relSET_(this_dtlSTEP_OBSERVER, LENGTH_OPERATOR, operator__);
            break;
        default:
            break;
        }
    }

    void Rebeca
    ::on_input_original_operand_valueChanged(int operand__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        switch (tmpGET_(REBECA_SHOW))
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            relSET_(this_dtlSTEP_OBSERVER, OFFSET_OPERAND, operand__);
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            relSET_(this_dtlSTEP_OBSERVER, VELOCITY_OPERAND, operand__);
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            relSET_(this_dtlSTEP_OBSERVER, LENGTH_OPERAND, operand__);
            break;
        default:
            break;
        }
    }

    void Rebeca
    ::on_cb_intervall_original_result2repeat_operator_currentIndexChanged(int operator__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        switch (tmpGET_(REBECA_SHOW))
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            relSET_(this_dtlSTEP_OBSERVER, OFFSET_INTERVAL_2_REPEAT_OPERATOR, operator__);
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            relSET_(this_dtlSTEP_OBSERVER, VELOCITY_INTERVAL_2_REPEAT_OPERATOR, operator__);
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            relSET_(this_dtlSTEP_OBSERVER, LENGTH_INTERVAL_2_REPEAT_OPERATOR, operator__);
            break;
        default:
            break;
        }
    }

    void Rebeca
    ::on_pb_tab_length_clicked() noexcept
    {
        tmpSET_(REBECA_SHOW, REBECA_SHOW_LENGTH);
    }

    void Rebeca
    ::on_pb_tab_velocity_clicked() noexcept
    {
        tmpSET_(REBECA_SHOW, REBECA_SHOW_VELOCITY);
    }

    void Rebeca
    ::on_pb_tab_note_clicked() noexcept
    {
        tmpSET_(REBECA_SHOW, REBECA_SHOW_NOTE);
    }

    void Rebeca
    ::on_pb_fir_to_range_clicked() noexcept
    {
        switch (tmpGET_(REBECA_SHOW))
        {
        case  REBECA_SHOW::REBECA_SHOW_NOTE:
            relOBS_(this_dtlSTEP_OBSERVER)->invert_property<StepPropertiesIndex::OFFSET_FIT_TO_RANGE>();
            break;
        case  REBECA_SHOW::REBECA_SHOW_VELOCITY:
            relOBS_(this_dtlSTEP_OBSERVER)->invert_property<StepPropertiesIndex::VELOCITY_FIT_TO_RANGE>();
            break;
        case  REBECA_SHOW::REBECA_SHOW_LENGTH:
            relOBS_(this_dtlSTEP_OBSERVER)->invert_property<StepPropertiesIndex::LENGTH_FIT_TO_RANGE>();
            break;
        default:
            break;
        }
    }

    //! Presets ************************************************************
    void Rebeca
    ::on_pb_preset_inc_interval_clicked() noexcept
    {
        relSET_(this_dtlSTEP_OBSERVER, REPEAT_TIMES, 2);
        relSET_(this_dtlSTEP_OBSERVER, INTERVAL, 0);
        relSET_(this_dtlSTEP_OBSERVER, INTERVAL_OPERAND, 12);
        relSET_(this_dtlSTEP_OBSERVER, INTERVAL_OPERATOR, static_cast<TYPE_operator>(OPERATOR::PLUS));
    }

    void Rebeca
    ::on_pb_preset_dec_interval_clicked() noexcept
    {
        relSET_(this_dtlSTEP_OBSERVER, REPEAT_TIMES, 2);
        relSET_(this_dtlSTEP_OBSERVER, INTERVAL, 36);
        relSET_(this_dtlSTEP_OBSERVER, INTERVAL_OPERAND, 12);
        relSET_(this_dtlSTEP_OBSERVER, INTERVAL_OPERATOR, static_cast<TYPE_operator>(OPERATOR::MINUS));
    }

    void Rebeca
    ::on_pb_preset_dur_clicked() noexcept
    {
        on_pb_tab_note_clicked();

        relSET_(this_dtlSTEP_OBSERVER, REPEAT_TIMES, 2);
        relSET_(this_dtlSTEP_OBSERVER, OFFSET_OPERAND, 4);
        relSET_(this_dtlSTEP_OBSERVER, OFFSET_OPERATOR, static_cast<TYPE_operator>(OPERATOR::PLUS));
        relSET_(this_dtlSTEP_OBSERVER, OFFSET_2_INTERVAL_OPERATOR, static_cast<TYPE_operator>(OPERATOR::NOT));
        relSET_(this_dtlSTEP_OBSERVER, OFFSET_INTERVAL_2_REPEAT_OPERATOR, static_cast<TYPE_operator>(OPERATOR::MINUS));
    }

    void Rebeca
    ::on_pb_preset_mol_clicked() noexcept
    {
        on_pb_tab_note_clicked();

        relSET_(this_dtlSTEP_OBSERVER, REPEAT_TIMES, 2);
        relSET_(this_dtlSTEP_OBSERVER, OFFSET_OPERAND, 3);
        relSET_(this_dtlSTEP_OBSERVER, OFFSET_OPERATOR, static_cast<TYPE_operator>(OPERATOR::PLUS));
        relSET_(this_dtlSTEP_OBSERVER, OFFSET_2_INTERVAL_OPERATOR, static_cast<TYPE_operator>(OPERATOR::NOT));
        relSET_(this_dtlSTEP_OBSERVER, OFFSET_INTERVAL_2_REPEAT_OPERATOR, static_cast<TYPE_operator>(OPERATOR::PLUS));
    }

    void Rebeca
    ::on_pb_preset_inc_velocity_clicked() noexcept
    {
        on_pb_tab_velocity_clicked();

        relSET_(this_dtlSTEP_OBSERVER, VELOCITY_OPERAND, 20);
        relSET_(this_dtlSTEP_OBSERVER, VELOCITY_OPERATOR, static_cast<TYPE_operator>(OPERATOR::PLUS));
        relSET_(this_dtlSTEP_OBSERVER, VELOCITY_2_INTERVAL_OPERATOR, static_cast<TYPE_operator>(OPERATOR::NOT));
        relSET_(this_dtlSTEP_OBSERVER, VELOCITY_INTERVAL_2_REPEAT_OPERATOR, static_cast<TYPE_operator>(OPERATOR::PLUS));
    }

    void Rebeca
    ::on_pb_preset_dec_velocity_clicked() noexcept
    {
        on_pb_tab_velocity_clicked();

        relSET_(this_dtlSTEP_OBSERVER, VELOCITY_OPERAND, 20);
        relSET_(this_dtlSTEP_OBSERVER, VELOCITY_OPERATOR, static_cast<TYPE_operator>(OPERATOR::MINUS));
        relSET_(this_dtlSTEP_OBSERVER, VELOCITY_2_INTERVAL_OPERATOR, static_cast<TYPE_operator>(OPERATOR::NOT));
        relSET_(this_dtlSTEP_OBSERVER, VELOCITY_INTERVAL_2_REPEAT_OPERATOR, static_cast<TYPE_operator>(OPERATOR::MINUS));
    }

    void Rebeca
    ::on_pb_preset_inc_length_clicked() noexcept
    {
        on_pb_tab_length_clicked();

        relSET_(this_dtlSTEP_OBSERVER, LENGTH_OPERAND, 6);
        relSET_(this_dtlSTEP_OBSERVER, LENGTH_OPERATOR, static_cast<TYPE_operator>(OPERATOR::PLUS));
        relSET_(this_dtlSTEP_OBSERVER, LENGTH_2_INTERVAL_OPERATOR, static_cast<TYPE_operator>(OPERATOR::NOT));
        relSET_(this_dtlSTEP_OBSERVER, LENGTH_INTERVAL_2_REPEAT_OPERATOR, static_cast<TYPE_operator>(OPERATOR::MULTI));
    }

    void Rebeca
    ::on_pb_preset_dec_length_clicked() noexcept
    {
        on_pb_tab_length_clicked();

        relSET_(this_dtlSTEP_OBSERVER, LENGTH_OPERAND, -6);
        relSET_(this_dtlSTEP_OBSERVER, LENGTH_OPERATOR, static_cast<TYPE_operator>(OPERATOR::PLUS));
        relSET_(this_dtlSTEP_OBSERVER, LENGTH_2_INTERVAL_OPERATOR, static_cast<TYPE_operator>(OPERATOR::NOT));
        relSET_(this_dtlSTEP_OBSERVER, LENGTH_INTERVAL_2_REPEAT_OPERATOR, static_cast<TYPE_operator>(OPERATOR::MULTI));
    }

    std::string Rebeca
    ::doc_file_name() const noexcept
    {
        return DOC_REBECA;
    }
}

