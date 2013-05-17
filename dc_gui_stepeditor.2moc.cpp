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

#include <dc_gui_stepeditor.2moc.h>

#include <dc_gui_styles.h>
#include <stuff/blockguard.h>
#include <cast/lexical_cast.hpp>
#include <functions/invert.hpp>

#include <dc_algorithm_length.hpp>

namespace dc_gui{

    void showToggled(QPushButton *, bool);

//! \class Stepeditor_Initalizer
    void Stepeditor_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        Stepeditor* stepeditor{new Stepeditor{}};

        stepeditor->setGeometry(top_first,left_first,width,height);
        stepeditor->setParent(parent_frame);
        stepeditor->init();
        stepeditor->setVisible(true);
    }

//! \class  Stepeditor
    Stepeditor
    ::Stepeditor()
    {
        setupUi(this);

        slider_velocity->setStyle(clearstyle);
        slider_length  ->setStyle(clearstyle);

        init_matrixstuff();
    }

    void Stepeditor
    ::init()
    {

        update();
    }

    void Stepeditor
    ::update() noexcept
    {
        set_offset();
        set_velocity();
        set_length();
    }

    void Stepeditor
    ::RELATIVE_OBSERVER_CHANGED(Step) noexcept
    {
        update();
    }

    void Stepeditor
    ::property_changed(AT_(Step,OFFSET)) noexcept
    {
        set_offset();
    }

    void Stepeditor
    ::set_offset() noexcept
    {
        /*
        auto step_offset(GET_fromSelectedOBSERVED_aPROPERTY(Step,OFFSET));
        if( step_offset == 0 )
            pb_noteoffset->setText("");
        else
            pb_noteoffset->setText(any2string(int{step_offset}).c_str());
            */
    }

    void Stepeditor
    ::property_changed(AT_(Step,VELOCITY)) noexcept
    {
        set_velocity();
    }

    void Stepeditor
    ::set_velocity() noexcept
    {
    SET_EVENT_BLOCK

        slider_velocity->setValue(selGET_(this_selSTEP_OBSERVER,VELOCITY));
    }

    void Stepeditor
    ::property_changed(AT_(Step,LENGTH)) noexcept
    {
        set_length();
    }

    void Stepeditor
    ::set_length() noexcept
    {
    SET_EVENT_BLOCK

        auto step_length(selGET_(this_selSTEP_OBSERVER,LENGTH));
        auto step_length_rest(step_length%GM_clock_per_takt);
        slider_length->setValue(step_length_rest);
        //label_length->setNum(int(step_length_rest));
        showMatrixlength(step_length_rest);

        auto step_fulls((step_length-step_length_rest)/GM_clock_per_takt);
        input_inc_fulllengths->setValue(step_fulls);
    }

//!\SLOTS
    void Stepeditor
    ::on_slider_velocity_valueChanged(int velocity__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        selSET_(this_selSTEP_OBSERVER, VELOCITY, velocity__);
    }

    void Stepeditor
    ::on_slider_length_valueChanged(int length__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        selSET_(this_selSTEP_OBSERVER,LENGTH,length__+GM_clock_per_takt*input_inc_fulllengths->value());
    }

    void Stepeditor
    ::on_input_inc_fulllengths_valueChanged(int add_full_notes__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        auto length(selGET_(this_selSTEP_OBSERVER,LENGTH));
        length = (length % GM_clock_per_takt)
                 + add_full_notes__*GM_clock_per_takt;

        selSET_(this_selSTEP_OBSERVER,LENGTH,length);
    }

    void Stepeditor
    ::preset_double_pointed(TYPE_lengthy length__) noexcept
    {
        selSET_(this_selSTEP_OBSERVER, LENGTH, length__);
    }


    void Stepeditor
    ::on_pb_preset_double_pointed_0_clicked() noexcept
    {
        preset_triplet(dc_algorithm::make_double_pointet(GM_clock_per_takt/2));
    }

    void Stepeditor
    ::on_pb_preset_double_pointed_1_clicked() noexcept
    {
        preset_triplet(dc_algorithm::make_double_pointet(GM_clock_per_takt/4));
    }

    void Stepeditor
    ::on_pb_preset_double_pointed_2_clicked() noexcept
    {
        preset_triplet(dc_algorithm::make_double_pointet(GM_clock_per_takt/8));
    }

    void Stepeditor
    ::on_pb_preset_double_pointed_3_clicked() noexcept
    {
        preset_triplet(dc_algorithm::make_double_pointet(GM_clock_per_takt/16));
    }



    void Stepeditor
    ::preset_triplet(TYPE_lengthy length__) noexcept
    {
        selSET_(this_selSTEP_OBSERVER, LENGTH, length__);
    }

    void Stepeditor
    ::on_pb_preset_triplet_0_clicked() noexcept
    {
        preset_triplet(dc_algorithm::make_triplet(GM_clock_per_takt));
    }

    void Stepeditor
    ::on_pb_preset_triplet_1_clicked() noexcept
    {
        preset_triplet(dc_algorithm::make_triplet(GM_clock_per_takt/2));
    }

    void Stepeditor
    ::on_pb_preset_triplet_2_clicked() noexcept
    {
        preset_triplet(dc_algorithm::make_triplet(GM_clock_per_takt/4));
    }

    void Stepeditor
    ::on_pb_preset_triplet_3_clicked() noexcept
    {
        preset_triplet(dc_algorithm::make_triplet(GM_clock_per_takt/8));
    }

    std::string Stepeditor
    ::doc_file_name() const noexcept
    {
        return DOC_STEPEDITOR;
    }

//!\NOT_REFACTURED
    using namespace dc_alg;

    void Stepeditor
    ::init_matrixstuff ()  noexcept
    {
        _pb_Lengths[DOT_1_4] = pb_1_4;
        _pb_Lengths[DOT_2_4] = pb_2_4;
        _pb_Lengths[DOT_3_4] = pb_3_4;
        _pb_Lengths[DOT_FULL] = pb_4_4;
        _pb_Lengths[DOT_1_8] = pb_1_8;
        _pb_Lengths[DOT_1_16]= pb_1_16;
        _pb_Lengths[DOT_1_32]= pb_1_32;
        _pb_Lengths[DOT_1_96]= pb_1_96;
        _pb_Lengths[DOT_2_96]= pb_2_96;

        showToggled(pb_4_4,false);
        showToggled(pb_3_4,false);
        showToggled(pb_2_4,false);
        showToggled(pb_1_4,false);
        showToggled(pb_1_8,false);
        showToggled(pb_1_16,false);
        showToggled(pb_1_32,false);
        showToggled(pb_1_96,false);
        showToggled(pb_2_96,false);
    }

    void Stepeditor
    ::showMatrixlength (unsigned int length__) noexcept
    {
        _enabled_matrix_dots = LengthMatrix::get_enabled_dots(length__);

        showToggled(_pb_Lengths[DOT_FULL],_enabled_matrix_dots[DOT_FULL]);
        showToggled(_pb_Lengths[DOT_3_4],_enabled_matrix_dots[DOT_3_4]);
        showToggled(_pb_Lengths[DOT_2_4],_enabled_matrix_dots[DOT_2_4]);
        showToggled(_pb_Lengths[DOT_1_4],_enabled_matrix_dots[DOT_1_4]);
        showToggled(_pb_Lengths[DOT_1_8],_enabled_matrix_dots[DOT_1_8]);
        showToggled(_pb_Lengths[DOT_1_16],_enabled_matrix_dots[DOT_1_16]);
        showToggled(_pb_Lengths[DOT_1_32],_enabled_matrix_dots[DOT_1_32]);
        showToggled(_pb_Lengths[DOT_2_96],_enabled_matrix_dots[DOT_2_96]);
        showToggled(_pb_Lengths[DOT_1_96],_enabled_matrix_dots[DOT_1_96]);
    }

    void showToggled(QPushButton *button__, bool isToggled__)
    {
        if( isToggled__ == true )
            DCSTYLE->set_mutedButtonPalette(button__);
        else
            DCSTYLE->set_enabledButtonPalette(button__);
    }

    void Stepeditor
    ::pb_X_X_clicked(QPushButton *, unsigned int DOT_X_X__) noexcept
    {
        _enabled_matrix_dots[DOT_X_X__] = invert_numeric(_enabled_matrix_dots[DOT_X_X__]);

        auto length(dc_alg::LengthMatrix::get_length_fromDotMatrix(_enabled_matrix_dots));
        slider_length->setValue(length);
    }

    void Stepeditor::on_pb_4_4_clicked()  noexcept { pb_X_X_clicked(pb_4_4,  DOT_FULL); }
    void Stepeditor::on_pb_3_4_clicked()  noexcept { pb_X_X_clicked(pb_3_4,  DOT_3_4); }
    void Stepeditor::on_pb_2_4_clicked()  noexcept { pb_X_X_clicked(pb_2_4,  DOT_2_4); }
    void Stepeditor::on_pb_1_4_clicked()  noexcept { pb_X_X_clicked(pb_1_4,  DOT_1_4); }

    void Stepeditor::on_pb_1_8_clicked()  noexcept { pb_X_X_clicked(pb_1_8,  DOT_1_8); }
    void Stepeditor::on_pb_1_16_clicked() noexcept { pb_X_X_clicked(pb_1_16, DOT_1_16); }
    void Stepeditor::on_pb_1_32_clicked() noexcept { pb_X_X_clicked(pb_1_32, DOT_1_32); }

    void Stepeditor::on_pb_1_96_clicked() noexcept { pb_X_X_clicked(pb_1_96, DOT_1_96); }
    void Stepeditor::on_pb_2_96_clicked() noexcept { pb_X_X_clicked(pb_2_96, DOT_2_96); }

}       // namespace dc_gui
