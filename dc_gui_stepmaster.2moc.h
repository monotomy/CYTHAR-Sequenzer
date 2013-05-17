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

#ifndef DC_GUI_STEPMASTER_TOMOC_H_INCLUDED
#define DC_GUI_STEPMASTER_TOMOC_H_INCLUDED

#include <dc_gui_stepmaster.uiced.h>

#include <extendQt_drag_n_drop.2moc.h>

#include <guistuff/child_initializer.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

namespace dc_gui{

    using namespace dc_objects;

    /***********************************************************************/
    //! \class  StepMaster_Initializer
    /***********************************************************************/
    class StepMaster;
    class StepMaster_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            SUM_ELEMENTS    = 16,
            LEFT            = 0,
            TOP             = 0,
            HEIGTH          = 35,
            WIDTH           = 35,
            _2LEFT_SPACE    = 5,
            _4GROUP_SPACE   = 15,
        };

        friend class StepMaster;
        typedef guistruff::_4GroupSpaceInitializer
        <
            StepMaster,
            SUM_ELEMENTS,
            LEFT,
            TOP,
            HEIGTH,
            WIDTH,
            _2LEFT_SPACE,
            _4GROUP_SPACE
        > StepMaster_4GroupSpaceInitializer;

    public:
        StepMaster_Initializer() noexcept = default;
        ~StepMaster_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    class StepMaster :
        public extendQt::DRAGnDROP_QWidget,
        public Ui::StepMaster,

        public SelecteddetailSequencerObserver_V2
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(StepMaster)

        typedef SelecteddetailSequencerObserver_V2 this_dtlSEQUENCER_OBSERVER;

        TYPE_index_child const _stepId;
        Temporary* _observed_temporary{nullptr};

        friend StepMaster_Initializer::StepMaster_4GroupSpaceInitializer;
        StepMaster();
        void init() noexcept;
        ~StepMaster() = default;

        inline virtual void property_changed(AT_(Sequencer,STEP_POS)) noexcept override;
        bool iam_running_yet{false};
    private slots:
        void set_running();

    private:
        //! DRAGnDROP *******************************************************************
        //! Erstellung eines zusätzlichen Containers mit Stepsrow an eigener Id
        virtual extendQt::TYPE_vector_additional_steprow_drag_data additional_steprow_drag_data() const noexcept override;
        //! Prüfun, ob sich Steprows Dropen lassen
        virtual bool compare_is_steprow_data_dropable(extendQt::DragObject const* drag_source_object__) const noexcept override;
        virtual void additional_steprow_is_dropped(extendQt::TYPE_vector_additional_steprow_drag_data const&) noexcept override;

        //! Erstellung eines zusätzlichen Accord-Drag Containers der Taktsaiten Offsets
        virtual extendQt::TYPE_vector_additional_numeric_drag_data additional_numeric_drag_data() const noexcept override;
        //! Prüfun, ob sich Accorde Dropen lassen, bei drop einpflegen
        virtual bool compare_is_additional_data_dropable(extendQt::DragObject const*) const noexcept override;
        virtual void additional_data_is_dropped(extendQt::TYPE_vector_additional_numeric_drag_data const&) noexcept override;
    };

    inline void StepMaster
    ::property_changed(AT_(Sequencer,STEP_POS)) noexcept
    {
        //  ABKOPPELN VON ZEIT-KRITISCHEN THREADS IN DEN MAINLOOP
        QMetaObject::invokeMethod(this,
                                  "set_running",
                                  Qt::ConnectionType::QueuedConnection);
    }
}   /// EO namespace dc_gui
#endif // DC_GUI_STEPMASTER_TOMOC_H_INCLUDED
