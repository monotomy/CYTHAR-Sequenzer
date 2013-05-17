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

#include <dc_gui_step.2moc.h>

#include <dc_gui_styles.h>

#include <stuff/blockguard.h>
#include <functions/invert.hpp>
#include <cast/any2uchar.hpp>

#include <dc_standard_values.h>

#include <math.h>

namespace dc_gui{

    using namespace dc_objects;

//! \class Step_Initializer
    void Step_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        Step_4GroupSpaceInitializer::initialize_at_frame(parent_frame);
    }

//! \class Step
    Step
    ::Step() :
        _gui_velocity{new StepVelocity},
        _gui_matrix{new StepMatrix}
    {
        //  Benutzeroberfläche erstellen
        setupUi(this);

        _gui_velocity->setParent(frame_progressbar);
        _gui_matrix->setParent(frame_matrix);

         setAcceptDrops(true);
         //setMouseTracking( true );

    }

    void Step
    ::init() noexcept
    {
        update();
    }

    void Step
    ::update() noexcept
    {
        set_selected();
        set_offset();
        set_velocity();
        set_length();
        set_mute();
        set_has_rebeca();
        set_has_delay();
    }

    void Step
    ::selected_observed_object_changed(forUNIQUE_TYPE(Step)) noexcept
    {
        set_selected();
    }

    void Step
    ::RELATIVE_OBSERVER_CHANGED(Step) noexcept
    {
        set_selected();
        update();
    }

    void Step
    ::set_selected() noexcept
    {
        if(is_my_relative_selected())
            iam_selected_yet = true;
        else
            iam_selected_yet = false;

        if(iam_selected_yet)
        {
            DCSTYLE->set_visibleMasterPalette(pb_plus);
            DCSTYLE->set_visibleMasterPalette(pb_minus);
        }
        else
        {
            DCSTYLE->set_uninitButtonPalette(pb_plus);
            DCSTYLE->set_uninitButtonPalette(pb_minus);
        }
    }

    void Step
    ::property_changed(AT_(Step,OFFSET)) noexcept
    {
        set_offset();
    }

    void Step
    ::set_offset() noexcept
    {
        auto offset(relGET_(this_relSTEP_OBSERVER, OFFSET));
        if( offset == 0 )
            label_note_foreground->setText("");
        else
            label_note_foreground->setNum(offset);
    }

    void Step
    ::property_changed(AT_(Step,VELOCITY)) noexcept
    {
        set_velocity();
    }

    void Step
    ::set_velocity() noexcept
    {
        _gui_velocity->setValue(relGET_(this_relSTEP_OBSERVER, VELOCITY));
    }

    void Step
    ::property_changed(AT_(Step,LENGTH)) noexcept
    {
        set_length();
    }

    void Step
    ::set_length() noexcept
    {
        _gui_matrix->setValue(relGET_(this_relSTEP_OBSERVER, LENGTH));
    }

    void Step
    ::property_changed(AT_(Step,IS_MUTED)) noexcept
    {
        set_mute();
    }

    void Step
    ::property_changed(AT_(Step,IS_INIT)) noexcept
    {
        set_mute();
    }

    void Step
    ::set_mute() noexcept
    {
        if(relGET_(this_relSTEP_OBSERVER, IS_INIT) == false)
        {
            DCSTYLE->set_uninitButtonPalette(pb_actionDummy);
            return;
        }

        if(relGET_(this_relSTEP_OBSERVER, IS_MUTED) == false)
            DCSTYLE->set_enabledButtonPalette(pb_actionDummy);
        else
            DCSTYLE->set_mutedButtonPalette(pb_actionDummy);
    }

    void Step
    ::property_changed(AT_(Step,DELAY)) noexcept
    {
        set_has_delay();
    }

    void Step
    ::set_has_delay() noexcept
    {
        if(relGET_(this_relSTEP_OBSERVER, DELAY) > 0)
            frame_has_delay->setAutoFillBackground(true);
        else
            frame_has_delay->setAutoFillBackground(false);
    }

    void Step
    ::property_changed(AT_(Step,REPEAT_TIMES)) noexcept
    {
        set_has_rebeca();
    }

    void Step
    ::set_has_rebeca() noexcept
    {
        if(relGET_(this_relSTEP_OBSERVER, REPEAT_TIMES) > 0)
            frame_has_rebeca->setAutoFillBackground(true);
        else
            frame_has_rebeca->setAutoFillBackground(false);
    }

//!\SLOTS
    void Step
    ::on_pb_actionButton_clicked() noexcept
    {
        if( iam_selected_yet == true)
        {
            if(relGET_(this_relSTEP_OBSERVER, IS_INIT) == false)
                relSET_(this_relSTEP_OBSERVER, IS_INIT, true);

            relOBS_(this_relSTEP_OBSERVER)->invert_property<StepPropertiesIndex::IS_MUTED>();
            return;
        }
        else
        {
            replace_selected_with_relative();
        }
    }

    void Step
    ::on_pb_plus_clicked() noexcept
    {
        relOBS_(this_relSTEP_OBSERVER)->increase_property<StepPropertiesIndex::OFFSET>();
    }

    void Step
    ::on_pb_minus_clicked() noexcept
    {
        relOBS_(this_relSTEP_OBSERVER)->decrease_property<StepPropertiesIndex::OFFSET>();
    }

    void Step
    ::wheelEvent(QWheelEvent* event__) noexcept
    {
        auto change_in_degre(event__->delta() / 8);   // Der Rückgabewert von 'delta' entspricht der 8-fachen Gradzahl
        auto new_velocity(change_in_degre += relGET_(this_relSTEP_OBSERVER, VELOCITY));

        if(new_velocity > 127)
            new_velocity = 127;
        else if(new_velocity < 0)
            new_velocity = 0;

        relSET_(this_relSTEP_OBSERVER, VELOCITY, new_velocity);
    }

    void Step
    ::mousePressEvent(QMouseEvent* event__) noexcept
    {
        if(event__->button() == Qt::RightButton)
        {
            auto length(relGET_(this_relSTEP_OBSERVER, LENGTH));
            if(length < GM_clock_per_takt)
            {
                length += GM_clock_per_step;
                relSET_(this_relSTEP_OBSERVER, LENGTH, length);
            }
            else
                relSET_(this_relSTEP_OBSERVER, LENGTH, 0);
        }
    }

    std::string Step
    ::doc_file_name() const noexcept
    {
        return DOC_STEPBUTTON;
    }
}
