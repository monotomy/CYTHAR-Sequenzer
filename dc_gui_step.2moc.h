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

#ifndef CYTHAR_GUI_STEP_H_INCLUDED
#define CYTHAR_GUI_STEP_H_INCLUDED

#include <dc_gui_step.uiced.h>
#include <dc_gui_step_velocity.2moc.h>
#include <dc_gui_step_matrix.2moc.h>

#include <extendQt_drag_n_drop.2moc.h>

#include <guistuff/child_initializer.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

#include <QWheelEvent>
#include <QMouseEvent>

#include <dc_gui_mainwindow.2moc.h>

namespace dc_gui{

    using namespace dc_objects;

    /***********************************************************************/
    //! \class  Step_Initializer
    /***********************************************************************/
    class Step;
    class Step_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            SUM_ELEMENTS    = 16,
            LEFT            = 0,
            TOP             = 0,
            HEIGTH          = 38,
            WIDTH           = 35,
            _2LEFT_SPACE    = 5,
            _4GROUP_SPACE   = 15,
        };

        friend class Step;
        typedef guistruff::_4GroupSpaceInitializer
        <
            Step,
            SUM_ELEMENTS,
            LEFT,
            TOP,
            HEIGTH,
            WIDTH,
            _2LEFT_SPACE,
            _4GROUP_SPACE
        > Step_4GroupSpaceInitializer;

    public:
        Step_Initializer() noexcept = default;
        ~Step_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    /***********************************************************************/
    /*! \class  Step
        \brief  Buttonelement auf Gui ( 6 x16)
    */
    /***********************************************************************/
    class MainwindowClipboardStore;
    class Step :
        public extendQt::DRAGnDROP_QWidget,
        public Ui::Step,

        public RelativeStepObserver_V2
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(Step)

        typedef RelativeStepObserver_V2 this_relSTEP_OBSERVER;

        StepVelocity*const _gui_velocity;
        StepMatrix*const _gui_matrix;

        friend Step_Initializer::Step_4GroupSpaceInitializer;
        Step();
        void init() noexcept;
        ~Step() = default;

        //! DATAMANAGEMENT **********************************************************
        //! Update der Anzeige
        void update() noexcept;

        //! Ändert den den selected Status auf der Gui
        virtual void RELATIVE_OBSERVER_CHANGED(Step) noexcept override;
        virtual void selected_observed_object_changed(forUNIQUE_TYPE(Step)) noexcept override;
        void set_selected() noexcept;
        bool iam_selected_yet{false};

        //! Zeigt die Eigenschaften des observierten Step an
        virtual void property_changed(AT_(Step,OFFSET)) noexcept override;
        void set_offset() noexcept;

        virtual void property_changed(AT_(Step,VELOCITY)) noexcept override;
        void set_velocity() noexcept;

        virtual void property_changed(AT_(Step,LENGTH)) noexcept override;
        void set_length() noexcept;

        virtual void property_changed(AT_(Step,IS_MUTED)) noexcept override;
        virtual void property_changed(AT_(Step,IS_INIT)) noexcept override;
        void set_mute() noexcept;

        virtual void property_changed(AT_(Step,DELAY)) noexcept override;
        void set_has_delay() noexcept;

        virtual void property_changed(AT_(Step,REPEAT_TIMES)) noexcept override;
        void set_has_rebeca() noexcept;

    private slots:
        //! Input vom User
        void on_pb_actionButton_clicked() noexcept;
        void on_pb_plus_clicked() noexcept;
        void on_pb_minus_clicked() noexcept;

    private:
        //! Ändert Velocity per Mausrad
        void wheelEvent(QWheelEvent*) noexcept;
        //! Inkrementiert die Länge des Steps um 16tel beim rechtsklick
        void mousePressEvent(QMouseEvent*) noexcept;

    private:
        //! DRAGnDROP ***************************************************************
        DRAGnDROP___relOBSERVER___DRAG_FROM_THIS_OBSERVER(this_relSTEP_OBSERVER)
        DRAGnDROP___relOBSERVER___ACCEPT_DROPS_FROM(this_relSTEP_OBSERVER)
        DRAGnDROP___relOBSERVER___COPY_sourceDROP_2Me(this_relSTEP_OBSERVER)

        //! Pfad zur eigenen sub_docu
        virtual std::string doc_file_name() const noexcept override;
    };
}

#endif  // CYTHAR_GUI_ELEMENTS_H_INCLUDED

