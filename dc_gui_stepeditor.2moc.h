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

#ifndef CYTHAR_GUI_STEPEDITOR_H_INCLUDED
#define CYTHAR_GUI_STEPEDITOR_H_INCLUDED

#include <dc_gui_stepeditor.uiced.h>

#include <guistuff/child_initializer.h>
#include <stuff/blockguard.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

#include <dc_alg_lengthmatrix.h>

#include <extendQt_drag_n_drop.2moc.h>

namespace dc_gui{

    using namespace dc_objects;

    /***********************************************************************/
    //! \class  Stepeditor_Initializer
    /***********************************************************************/
    class Stepeditor;
    class Stepeditor_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            height          = 238,
            width           = 201,
            top_first       = 0,
            left_first      = 0,
        };

    public:
        Stepeditor_Initializer() noexcept = default;
        ~Stepeditor_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    /***********************************************************************/
    //! \class  Stepeditor
    /***********************************************************************/
    class Stepeditor :
        public extendQt::DRAGnDROP_QWidget,
        public Ui::Stepeditor,

        public Events_blockable,

        public virtual SelecteddetailStepObserver_V2
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(Stepeditor)

        typedef SelectedStepObserver_V2 this_selSTEP_OBSERVER;

        friend class Stepeditor_Initializer;
        Stepeditor();
        ~Stepeditor() = default;
        void init();

        //! Aktualisiert die Anzeige
        virtual void RELATIVE_OBSERVER_CHANGED(Step) noexcept override;
        void update() noexcept;

        //! Aktualisiert die Anzeige
        virtual void property_changed(AT_(Step,OFFSET)) noexcept override;
        void set_offset() noexcept;

        virtual void property_changed(AT_(Step,VELOCITY)) noexcept override;
        void set_velocity() noexcept;

        virtual void property_changed(AT_(Step,LENGTH)) noexcept override;
        void set_length() noexcept;

    private slots:
        void on_slider_velocity_valueChanged(int) noexcept;
        void on_slider_length_valueChanged(int) noexcept;
        void on_input_inc_fulllengths_valueChanged(int) noexcept;

    private:
        void preset_double_pointed(TYPE_lengthy) noexcept;
    private slots:
        void on_pb_preset_double_pointed_0_clicked() noexcept;
        void on_pb_preset_double_pointed_1_clicked() noexcept;
        void on_pb_preset_double_pointed_2_clicked() noexcept;
        void on_pb_preset_double_pointed_3_clicked() noexcept;

    private:
        void preset_triplet(TYPE_lengthy) noexcept;
    private slots:
        void on_pb_preset_triplet_0_clicked() noexcept;
        void on_pb_preset_triplet_1_clicked() noexcept;
        void on_pb_preset_triplet_2_clicked() noexcept;
        void on_pb_preset_triplet_3_clicked() noexcept;

    private:
        //! DRAGnDROP ***************************************************************
        //! Pfad zur eigenen sub_docu
        virtual std::string doc_file_name() const noexcept override;

    private:

//!\NOT_REFACTURED
        QPushButton *_pb_Lengths[dc_alg::MATRIX_SUM_DOTS];
        dc_alg::LengthMatrix::MatrixDotArray_Type _enabled_matrix_dots
        {
            {
                false,
                false,
                false,
                false,
                false,
                false,
                false,
                false,
                false
            }
        };


        void init_matrixstuff() noexcept;

    private:
        void showMatrixlength(unsigned int) noexcept;

    private:
        /* Templatefunktion für nachfolgende Slots */
        void pb_X_X_clicked   ( QPushButton*, unsigned int) noexcept;
    private slots:
        void on_pb_4_4_clicked()  noexcept;
        void on_pb_3_4_clicked()  noexcept;
        void on_pb_2_4_clicked()  noexcept;
        void on_pb_1_4_clicked()  noexcept;
        void on_pb_1_8_clicked()  noexcept;
        void on_pb_1_16_clicked() noexcept;
        void on_pb_1_32_clicked() noexcept;

        void on_pb_1_96_clicked() noexcept;
        void on_pb_2_96_clicked() noexcept;
    };
}   /// EO namespace dc_gui

#endif  // CYTHAR_GUI_STEPEDITOR_H_INCLUDED
