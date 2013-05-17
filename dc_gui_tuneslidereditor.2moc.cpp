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

#include <dc_gui_tuneslidereditor.2moc.h>

#include <stuff/blockguard.h>
#include <functions/invert.hpp>
#include <dc_gui_styles.h>

#include <gm_midistandard.h>
#include <string>

#include <dc_standard_values.h>

namespace dc_gui{

//! \class Tuneslider_Initializer
    void Tuneslider_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        for( int elements{0} ; sum_elements != elements ; ++elements )
        {
            Tuneslider* tuneslider{new Tuneslider{}};

            tuneslider->setGeometry(left,
                                    top_first + elements*height,
                                    width,
                                    height);
            tuneslider->setParent(parent_frame);
            tuneslider->setVisible(true);
            tuneslider->init();
        }
    }

//! \class Tuneslider
    Tuneslider
    ::Tuneslider ()
    {
        setupUi(this);
        hs_slider->setStyle(clearstyle);
    }

    void Tuneslider
    ::init() noexcept
    {
        update();
    }

    void Tuneslider
    ::update() noexcept
    {
        set_tune();
        set_accord();
    }

    void Tuneslider
    ::RELATIVE_OBSERVER_CHANGED(Patternsaite) noexcept
    {
        update();
    }

    void Tuneslider
    ::SELECTED_OBSERVER_CHANGED(Pattern) noexcept
    {
        update();
    }

    void Tuneslider
    ::property_changed(AT_(Temporary,TUNEEDITOR_SHOW)) noexcept
    {
        update();
    }

    void Tuneslider
    ::property_changed(AT_(Patternsaite,TUNE_OFFSET)) noexcept
    {
        set_tune();
    }

    void Tuneslider
    ::set_tune() noexcept
    {
        if(tmpGET_(TUNEEDITOR_SHOW) != TUNEEDITOR_SHOW_TUNE)
            return;

    SET_EVENT_BLOCK

        hs_slider->setMaximum (GUI_TUNE_sliderMAX);
        hs_slider->setPageStep(GUI_TUNE_sliderPageSTEP);

        hs_slider->setValue(relGET_(this_relPATTERNSAITE_OBSERVER, TUNE_OFFSET));


    }

    void Tuneslider
    ::property_changed(AT_(Patternsaite,ACCORD_OFFSET)) noexcept
    {
        set_accord();
    }

    void Tuneslider
    ::set_accord() noexcept
    {
        if(tmpGET_(TUNEEDITOR_SHOW) != TUNEEDITOR_SHOW_ACCORD)
            return;

    SET_EVENT_BLOCK

        hs_slider->setMaximum (GUI_ACCORD_sliderMAX);
        hs_slider->setPageStep(GUI_ACCORD_sliderPageSTEP);

        hs_slider->setValue(relGET_(this_relPATTERNSAITE_OBSERVER, ACCORD_OFFSET));
    }

//!\SLOTS
    void Tuneslider
    ::on_hs_slider_valueChanged(int value__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        if(tmpGET_(TUNEEDITOR_SHOW) == TUNEEDITOR_SHOW_TUNE)
            relSET_(this_relPATTERNSAITE_OBSERVER, TUNE_OFFSET, value__);
        else
            relSET_(this_relPATTERNSAITE_OBSERVER, ACCORD_OFFSET, value__);
    }


//! \class Tuneslidereditor_Initializer
    void Tuneslidereditor_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        Tuneslidereditor* tuneslidereditor{new Tuneslidereditor{}};

        tuneslidereditor->setGeometry(top,left,width,height);
        tuneslidereditor->setParent(parent_frame);
        tuneslidereditor->setVisible(true);
        tuneslidereditor->init();
    }

//! \class Tuneslidereditor
    Tuneslidereditor
    ::Tuneslidereditor ()
    {
        setupUi(this);

        hs_transpose->setStyle(clearstyle);
    }

    void Tuneslidereditor
    ::init() noexcept
    {
        update();
    }

    void Tuneslidereditor
    ::update() noexcept
    {
        set_viewtab();
        set_transpose();
    }

    void Tuneslidereditor
    ::SELECTED_OBSERVER_CHANGED(Pattern) noexcept
    {
        update();
    }

    void Tuneslidereditor
    ::property_changed(AT_(Temporary,TUNEEDITOR_SHOW)) noexcept
    {
        set_viewtab();
    }

    void Tuneslidereditor
    ::property_changed(AT_(Pattern,OFFSET)) noexcept
    {
        set_transpose();
    }

    void Tuneslidereditor
    ::set_transpose() noexcept
    {
    SET_EVENT_BLOCK

        hs_transpose->setValue(selGET_(this_setPATTERN_OBSERVER, OFFSET));
    }

    void Tuneslidereditor
    ::set_viewtab() noexcept
    {
        if(tmpGET_(TUNEEDITOR_SHOW) == TUNEEDITOR_SHOW_TUNE)
        {
            DCSTYLE->set_defaultMasterPalette(pb_viewAccord);
            DCSTYLE->set_mutedButtonPalette(pb_viewTune);
        }
        else
        {
            DCSTYLE->set_defaultMasterPalette(pb_viewTune);
            DCSTYLE->set_mutedButtonPalette(pb_viewAccord);
        }
    }

//!\SLOTS
    void Tuneslidereditor
    ::on_pb_viewAccord_clicked() noexcept
    {
        tmpSET_(TUNEEDITOR_SHOW, TUNEEDITOR_SHOW_ACCORD);
    }

    void Tuneslidereditor
    ::on_pb_viewTune_clicked() noexcept
    {
        tmpSET_(TUNEEDITOR_SHOW, TUNEEDITOR_SHOW_TUNE);
    }

    void Tuneslidereditor
    ::on_hs_transpose_valueChanged(int offset__) noexcept
    {
        selSET_(this_setPATTERN_OBSERVER, OFFSET, offset__);
    }

    template<PatternsaitePropertiesIndex INDEX>
    void set_accord_to_pattern(Pattern const* pattern__, Accord const& accord__) noexcept
    {
        pattern__->patternsaite(SAITE_e)->set_property<INDEX>(accord__.get_property<AccordPropertiesIndex::SAITE_e>());
        pattern__->patternsaite(SAITE_b)->set_property<INDEX>(accord__.get_property<AccordPropertiesIndex::SAITE_b>());
        pattern__->patternsaite(SAITE_g)->set_property<INDEX>(accord__.get_property<AccordPropertiesIndex::SAITE_g>());
        pattern__->patternsaite(SAITE_d)->set_property<INDEX>(accord__.get_property<AccordPropertiesIndex::SAITE_d>());
        pattern__->patternsaite(SAITE_A)->set_property<INDEX>(accord__.get_property<AccordPropertiesIndex::SAITE_A>());
        pattern__->patternsaite(SAITE_E)->set_property<INDEX>(accord__.get_property<AccordPropertiesIndex::SAITE_E>());
    }

    void Tuneslidereditor
    ::on_pb_defaultTune_clicked() noexcept
    {
        on_pb_viewTune_clicked();
        set_accord_to_pattern<PatternsaitePropertiesIndex::TUNE_OFFSET>(selOBS_(this_setPATTERN_OBSERVER), TUNE_EAdgbe);
    }

    void Tuneslidereditor
    ::on_pb_defaultDrum_clicked() noexcept
    {
        on_pb_viewTune_clicked();
        set_accord_to_pattern<PatternsaitePropertiesIndex::TUNE_OFFSET>(selOBS_(this_setPATTERN_OBSERVER), TUNE_Drum);
    }

    void Tuneslidereditor
    ::on_pb_accord_0_clicked() noexcept
    {
        on_pb_viewAccord_clicked();
        set_accord_to_pattern<PatternsaitePropertiesIndex::ACCORD_OFFSET>(selOBS_(this_setPATTERN_OBSERVER), ACCORD_dur);
    }

    void Tuneslidereditor
    ::on_pb_accord_1_clicked() noexcept
    {
        on_pb_viewAccord_clicked();
        set_accord_to_pattern<PatternsaitePropertiesIndex::ACCORD_OFFSET>(selOBS_(this_setPATTERN_OBSERVER), ACCORD_mol);
    }


    void Tuneslidereditor
    ::on_pb_accord_2_clicked() noexcept
    {
        on_pb_viewAccord_clicked();
        set_accord_to_pattern<PatternsaitePropertiesIndex::ACCORD_OFFSET>(selOBS_(this_setPATTERN_OBSERVER), ACCORD_7);
    }

    void Tuneslidereditor
    ::on_pb_accord_3_clicked() noexcept
    {
        on_pb_viewAccord_clicked();
        set_accord_to_pattern<PatternsaitePropertiesIndex::ACCORD_OFFSET>(selOBS_(this_setPATTERN_OBSERVER), ACCORD_mol7);
    }

    void Tuneslidereditor
    ::on_pb_accord_4_clicked() noexcept
    {
        on_pb_viewAccord_clicked();
        set_accord_to_pattern<PatternsaitePropertiesIndex::ACCORD_OFFSET>(selOBS_(this_setPATTERN_OBSERVER), ACCORD_maj7);
    }

    void Tuneslidereditor
    ::on_pb_accord_5_clicked() noexcept
    {
        on_pb_viewAccord_clicked();
        set_accord_to_pattern<PatternsaitePropertiesIndex::ACCORD_OFFSET>(selOBS_(this_setPATTERN_OBSERVER), ACCORD_sus4);
    }

    void Tuneslidereditor
    ::on_pb_accord_6_clicked() noexcept
    {
        on_pb_viewAccord_clicked();
        set_accord_to_pattern<PatternsaitePropertiesIndex::ACCORD_OFFSET>(selOBS_(this_setPATTERN_OBSERVER), ACCORD_6);
    }

    void Tuneslidereditor
    ::on_pb_accord_7_clicked() noexcept
    {
        on_pb_viewAccord_clicked();
        set_accord_to_pattern<PatternsaitePropertiesIndex::ACCORD_OFFSET>(selOBS_(this_setPATTERN_OBSERVER), ACCORD_sus2);
    }

    QPixmap Tuneslidereditor
    ::drag_pixmap() noexcept
    {
        QPixmap pixmap_of_me(QPixmap::grabWidget(static_cast<QWidget*>(this->parent())));

        return std::move(pixmap_of_me);
    }

    std::string Tuneslidereditor
    ::doc_file_name() const noexcept
    {
        return DOC_MIDIDEVICE_EDITOR;
    }

//! \class Tunevaluebox_Initializer
    void Tunevaluebox_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        for( int elements{0} ; sum_elements != elements ; ++elements )
        {
            Tunevaluebox* tunevaluebox{new Tunevaluebox{}};

            tunevaluebox->setGeometry(left,
                                      top_first + elements*height,
                                      width,
                                      height);
            tunevaluebox->setParent(parent_frame);
            tunevaluebox->setVisible(true);
            tunevaluebox->init();
        }
    }

//!\class Tunevaluebox
    Tunevaluebox::
    Tunevaluebox () :
        QWidget     {nullptr}
    {
        setupUi(this);
    }

    void Tunevaluebox
    ::init() noexcept
    {
        update();
    }

    void Tunevaluebox
    ::update() noexcept
    {
        set_boxcontent();
        set_mute();
    }

    void Tunevaluebox
    ::RELATIVE_OBSERVER_CHANGED(Patternsaite) noexcept
    {
        update();
    }

    void Tunevaluebox
    ::property_changed(AT_(Pattern,OFFSET)) noexcept
    {
        update();
    }

    void Tunevaluebox
    ::property_changed(AT_(Patternsaite,ACCORD_OFFSET)) noexcept
    {
        update();
    }

    void Tunevaluebox
    ::property_changed(AT_(Patternsaite,TUNE_OFFSET)) noexcept
    {
        update();
    }

    void Tunevaluebox
    ::set_boxcontent() noexcept
    {
        auto pattern_offset(relGET_(this_dtlPATTERN_OBSERVER, OFFSET));
        auto tune_offset(relGET_(this_relPATTERNSAITE_OBSERVER, TUNE_OFFSET));
        auto accord_offset(relGET_(this_relPATTERNSAITE_OBSERVER, ACCORD_OFFSET));

        if( tune_offset < 0 || accord_offset < 0 )
        {
            pb->setText("X");
        }
        else
        {
            int tune_and_accord{tune_offset+accord_offset+pattern_offset};

            if( tune_and_accord > 127 or tune_and_accord < 0)
            {
                pb->setText("X");
                return;
            }


            std::string tune_and_accord_str{ lexical_cast<std::string>(tune_and_accord)};
            std::string tune_and_accord_notestr{gm_standard::halftone2str[tune_and_accord] + "\n"};
            std::string tune_and_accord_drumstr{gm_standard::halftone2full_drum_str[tune_and_accord]};
            std::string tune_and_accord_short_drumstr{gm_standard::halftone2short_drum_str[tune_and_accord]};

            std::string tune_and_accord_notestr_and_str{tune_and_accord_notestr + tune_and_accord_str + " " + tune_and_accord_short_drumstr };

            pb->setText(tune_and_accord_notestr_and_str.c_str());

            pb->setToolTip(tune_and_accord_drumstr.c_str());
        }
    }

    void Tunevaluebox
    ::property_changed(AT_(Patternsaite,IS_MUTED)) noexcept
    {
        set_mute();
    }

    void Tunevaluebox
    ::set_mute() noexcept
    {
        if(relGET_(this_relPATTERNSAITE_OBSERVER, IS_MUTED))
        {
            DCSTYLE->set_mutedButtonPalette(pb);
        }
        else
        {
            auto tune_offset(relGET_(this_relPATTERNSAITE_OBSERVER, TUNE_OFFSET));
            auto accord_offset(relGET_(this_relPATTERNSAITE_OBSERVER, ACCORD_OFFSET));

            if( tune_offset < 0 || accord_offset < 0 )
            {
                // Auch gemutet.
                DCSTYLE->set_mutedButtonPalette(pb);
            }
            else
            {
                DCSTYLE->set_defaultMasterPalette(pb);
            }
        }
    }

//!\SLOTS
    void Tunevaluebox
    ::on_pb_clicked() noexcept
    {
        relOBS_(this_relPATTERNSAITE_OBSERVER)->invert_property<PatternsaitePropertiesIndex::IS_MUTED>();
    }

}   /// EO namespace dc_gui
