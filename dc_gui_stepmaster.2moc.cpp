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

#include <dc_gui_stepmaster.2moc.h>

#include <dc_gui_styles.h>
#include <dc_gui_inits.h>

namespace dc_gui{

    using namespace dc_objects;

//! \class StepMaster_Initializer
    void StepMaster_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        StepMaster_4GroupSpaceInitializer::initialize_at_frame(parent_frame);
    }

//! \class StepMaster
    StepMaster
    ::StepMaster () :
        _stepId{GenEndlessLinearId<StepMaster>::get_next()}
    {
        setupUi(this);
        InitButtonText::set_first_string_then_number<StepMaster>(FIRST_STEPMASTER_BUTTON_STRING, pb_actionButton);
    }

    void StepMaster
    ::init() noexcept
    {
        set_running();
    }

//!\SLOTS
    void StepMaster
    ::set_running()
    {
        if(selGET_(this_dtlSEQUENCER_OBSERVER,STEP_POS) == _stepId)
        {
            if(iam_running_yet)
                return; // do nothing
            else
            {
                DCSTYLE->set_overhideTrueTaktPalette(pb_actionButton);
                iam_running_yet = true;
            }
        }
        else if(iam_running_yet == true)
        {
            DCSTYLE->set_defaultMasterPalette(pb_actionButton);
            iam_running_yet = false;
        }
    }

//!\DRAGnDROP
    extendQt::TYPE_vector_additional_steprow_drag_data StepMaster
    ::additional_steprow_drag_data() const noexcept
    {
        extendQt::TYPE_vector_additional_steprow_drag_data steprow{};
        auto selected_takt(tmpGET_(SELECTED_TAKT));
        for(TYPE_index_child taktsaite_id{0} ; taktsaite_id!=GLOBAL_supportedSAITES ; ++taktsaite_id)
        {
            auto taktsaite(selected_takt->taktsaite(taktsaite_id));
            steprow.push_back(taktsaite->step(_stepId));
        }

        return steprow;
    }

    bool StepMaster
    ::compare_is_steprow_data_dropable(extendQt::DragObject const* drag_source_object__) const noexcept
    {
        if(drag_source_object__->additional_steprow_objects().size() == GLOBAL_supportedSAITES)
            return true;
        else
            return false;
    }

    void StepMaster
    ::additional_steprow_is_dropped(extendQt::TYPE_vector_additional_steprow_drag_data const& steprow_drag_data__) noexcept
    {
        auto selected_takt(tmpGET_(SELECTED_TAKT));
        for(TYPE_index_child taktsaite_id{0} ; taktsaite_id!=GLOBAL_supportedSAITES ; ++taktsaite_id)
        {
            auto taktsaite(selected_takt->taktsaite(taktsaite_id));
            auto step(taktsaite->step(_stepId));

            step->copy_from_source(steprow_drag_data__[taktsaite_id]);
        }
    }

    extendQt::TYPE_vector_additional_numeric_drag_data StepMaster
    ::additional_numeric_drag_data() const noexcept
    {
        extendQt::TYPE_vector_additional_numeric_drag_data step_offsets{};
        auto selected_takt(tmpGET_(SELECTED_TAKT));
        for(TYPE_index_child taktsaite_id{0} ; taktsaite_id!=GLOBAL_supportedSAITES ; ++taktsaite_id)
        {
            auto taktsaite(selected_takt->taktsaite(taktsaite_id));
            auto step(taktsaite->step(_stepId));
            step_offsets.push_back(step->get_property<StepPropertiesIndex::OFFSET>());
        }

        return step_offsets;
    }

    bool StepMaster
    ::compare_is_additional_data_dropable(extendQt::DragObject const* drag_source_object__) const noexcept
    {
        if(drag_source_object__->additional_data_vector().size() == GLOBAL_supportedSAITES)
            return true;
        else
            return false;
    }

    void StepMaster
    ::additional_data_is_dropped(extendQt::TYPE_vector_additional_numeric_drag_data const& numeric_drag_data__) noexcept
    {
        auto selected_takt(tmpGET_(SELECTED_TAKT));
        for(TYPE_index_child taktsaite_id{0} ; taktsaite_id!=GLOBAL_supportedSAITES ; ++taktsaite_id)
        {
            auto taktsaite(selected_takt->taktsaite(taktsaite_id));
            auto step(taktsaite->step(_stepId));
            auto accord_offset(numeric_drag_data__[taktsaite_id]);
            step->set_property<StepPropertiesIndex::OFFSET>(accord_offset);
        }
    }
}   /// EO namespace dc_gui
