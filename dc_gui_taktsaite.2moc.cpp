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

#include <dc_gui_taktsaite.2moc.h>

#include <dc_gui_styles.h>
#include <functions/invert.hpp>

#include <cast/lexical_cast.hpp>

#include <dc_standard_values.h>

namespace dc_gui{

//! \class Taktsaite_Initializer
    void Taktsaite_Initializer
    ::initialize_at_frame(QFrame *parent_frame) noexcept
    {
        Taktsaite_4GroupSpaceInitializer::initialize_at_frame(parent_frame);
    }

//! \class Taktsaite
    Taktsaite
    ::Taktsaite ()
    {
        setupUi(this);
    }

    void Taktsaite
    ::init() noexcept
    {
        update();
    }

    void Taktsaite
    ::update() noexcept
    {
        set_offset();
        set_mute();
        set_usedata();
    }

    void Taktsaite
    ::RELATIVE_OBSERVER_CHANGED(Takt) noexcept
    {
        update();
    }

    void Taktsaite
    ::RELATIVE_OBSERVER_CHANGED(Taktsaite) noexcept
    {
        update();
    }

    void Taktsaite
    ::property_changed(AT_(Takt,OFFSET)) noexcept
    {
        set_offset();
    }

    void Taktsaite
    ::property_changed(AT_(Taktsaite,OFFSET)) noexcept
    {
        set_offset();
    }

    void Taktsaite
    ::set_offset() noexcept
    {
        std::string label{};
        auto takt_offset(relGET_(this_relTAKT_OBSERVER, OFFSET));
        if(takt_offset != 0)
            label += lexical_cast<std::string>(takt_offset);

        label += "  ";  // Spacer

        auto taktsaite_offset(relGET_(this_relTAKTSAITE_OBSERVER, OFFSET));
        if(taktsaite_offset != 0)
            label += lexical_cast<std::string>(taktsaite_offset);

        label_note_foreground->setText(label.c_str());
    }

    void Taktsaite
    ::property_changed(AT_(Taktsaite,IS_MUTED)) noexcept
    {
        set_mute();
        set_usedata();
    }

    void Taktsaite
    ::set_mute() noexcept
    {
        if(relGET_(this_relTAKTSAITE_OBSERVER, IS_MUTED) == true)
            DCSTYLE->set_mutedButtonPalette(pb_actionDummy);
        else
            DCSTYLE->set_uninitButtonPalette(pb_actionDummy);
    }

    void Taktsaite
    ::on_pb_plus_clicked() noexcept
    {
        relOBS_(this_relTAKTSAITE_OBSERVER)->increase_property<TaktsaitePropertiesIndex::OFFSET>();
    }

    void Taktsaite
    ::on_pb_minus_clicked() noexcept
    {
        relOBS_(this_relTAKTSAITE_OBSERVER)->decrease_property<TaktsaitePropertiesIndex::OFFSET>();
    }

    void Taktsaite
    ::on_pb_actionButton_clicked() noexcept
    {
        relOBS_(this_relTAKTSAITE_OBSERVER)->invert_property<TaktsaitePropertiesIndex::IS_MUTED>();
    }

    void Taktsaite
    ::wheelEvent(QWheelEvent* event__) noexcept
    {
        if(event__->delta() > 0)
            on_pb_plus_clicked();
        else
            on_pb_minus_clicked();
    }

    std::string Taktsaite
    ::doc_file_name() const noexcept
    {
        return DOC_TAKTSAITEN;
    }
}
