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

#ifndef DC_GUI_REPEATEDITOR_2MOC_H_INCLUDED
#define DC_GUI_REPEATEDITOR_2MOC_H_INCLUDED

#include <dc_gui_rebeca.uiced.h>
#include <guistuff/child_initializer.h>
#include <stuff/blockguard.h>

#include <extendQt_drag_n_drop.2moc.h>

#include <class/properties.hpp>

#include <dc_algorithm_rebeca.hpp>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

namespace dc_gui{

    using namespace dc_objects;

    /***********************************************************************/
    //! \class  Rebeca_Initializer
    /***********************************************************************/
    class Rebeca;
    class Rebeca_Initializer :
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
        Rebeca_Initializer() noexcept = default;
        ~Rebeca_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    /***********************************************************************/
    /*! \class  Rebeca
        \brief  Ändert und zeigt die Werte des RepeatAlgorithmus an.
    */
    /***********************************************************************/
    class Rebeca :
        public extendQt::DRAGnDROP_QWidget,
        public Ui::Rebeca,

        public Events_blockable,

        public SelecteddetailStepObserver_V2
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(Rebeca)

        typedef SelecteddetailStepObserver_V2 this_dtlSTEP_OBSERVER;

        friend class Rebeca_Initializer;
        Rebeca ();
        void init() noexcept;
        ~Rebeca() = default;

        //! Aktualisiert die Anzeige
        virtual void RELATIVE_OBSERVER_CHANGED(Step) noexcept override;
        void update() noexcept;

        //! Tab ****************************************************************
        virtual void property_changed(AT_(Temporary,REBECA_SHOW)) noexcept override;
        void set_view_mode() noexcept;

        //! Aktualisiert die Anzeige
        //! OFFSET *************************************************************
        virtual void property_changed(AT_(Step,OFFSET)) noexcept override;
        virtual void property_changed(AT_(Step,OFFSET_OPERATOR)) noexcept override;
        virtual void property_changed(AT_(Step,OFFSET_OPERAND)) noexcept override;
        virtual void property_changed(AT_(Step,OFFSET_2_INTERVAL_OPERATOR)) noexcept override;
        virtual void property_changed(AT_(Step,OFFSET_INTERVAL_2_REPEAT_OPERATOR)) noexcept override;
        virtual void property_changed(AT_(Step,OFFSET_FIT_TO_RANGE)) noexcept override;

        //! VELOCITY ***********************************************************
        virtual void property_changed(AT_(Step,VELOCITY)) noexcept override;
        virtual void property_changed(AT_(Step,VELOCITY_OPERATOR)) noexcept override;
        virtual void property_changed(AT_(Step,VELOCITY_OPERAND)) noexcept override;
        virtual void property_changed(AT_(Step,VELOCITY_2_INTERVAL_OPERATOR)) noexcept override;
        virtual void property_changed(AT_(Step,VELOCITY_INTERVAL_2_REPEAT_OPERATOR)) noexcept override;
        virtual void property_changed(AT_(Step,VELOCITY_FIT_TO_RANGE)) noexcept override;

        //! LENGTH *************************************************************
        virtual void property_changed(AT_(Step,LENGTH)) noexcept override;
        virtual void property_changed(AT_(Step,LENGTH_OPERATOR)) noexcept override;
        virtual void property_changed(AT_(Step,LENGTH_OPERAND)) noexcept override;
        virtual void property_changed(AT_(Step,LENGTH_2_INTERVAL_OPERATOR)) noexcept override;
        virtual void property_changed(AT_(Step,LENGTH_INTERVAL_2_REPEAT_OPERATOR)) noexcept override;
        virtual void property_changed(AT_(Step,LENGTH_FIT_TO_RANGE)) noexcept override;

        //! ALL ****************************************************************
        virtual void property_changed(AT_(Step,DELAY)) noexcept override;
        virtual void property_changed(AT_(Step,REPEAT_TIMES)) noexcept override;
        virtual void property_changed(AT_(Step,INTERVAL)) noexcept override;
        virtual void property_changed(AT_(Step,INTERVAL_OPERATOR)) noexcept override;
        virtual void property_changed(AT_(Step,INTERVAL_OPERAND)) noexcept override;

        void set_original() noexcept;
        void set_original_operator() noexcept;
        void set_original_operand() noexcept;
        void set_original2interval_operator() noexcept;
        void set_original_interval2result_operator() noexcept;
        void set_fit_to_range() noexcept;

        void set_delay() noexcept;
        void set_repeat_times() noexcept;
        void set_interval() noexcept;
        void set_interval_operator() noexcept;
        void set_interval_operand() noexcept;

        void fill_cb_results() noexcept;

    private slots:
        //! Userinputs schreiben
        void on_input_delay_valueChanged(int) noexcept;
        void on_input_repeat_valueChanged(int) noexcept;
        void on_input_intervall_valueChanged(int) noexcept;
        void on_cb_intervall_operator_currentIndexChanged(int) noexcept;
        void on_input_intervall_operand_valueChanged(int) noexcept;
        void on_cb_intervall2original_operator_currentIndexChanged(int) noexcept;
        void on_cb_original_operator_currentIndexChanged(int) noexcept;
        void on_input_original_operand_valueChanged(int) noexcept;
        void on_cb_intervall_original_result2repeat_operator_currentIndexChanged(int) noexcept;

        //! Ändert Ansicht
        void on_pb_tab_length_clicked() noexcept;
        void on_pb_tab_velocity_clicked() noexcept;
        void on_pb_tab_note_clicked() noexcept;

        //! Ändert fit to range Mode
        void on_pb_fir_to_range_clicked() noexcept;

        //! Presets ************************************************************
        void on_pb_preset_inc_interval_clicked() noexcept;
        void on_pb_preset_dec_interval_clicked() noexcept;
        void on_pb_preset_dur_clicked() noexcept;
        void on_pb_preset_mol_clicked() noexcept;
        void on_pb_preset_inc_velocity_clicked() noexcept;
        void on_pb_preset_dec_velocity_clicked() noexcept;
        void on_pb_preset_inc_length_clicked() noexcept;
        void on_pb_preset_dec_length_clicked() noexcept;

    private:
        //! DRAGnDROP ***************************************************************
        //! Pfad zur eigenen sub_docu
        virtual std::string doc_file_name() const noexcept override;
    };

}   /// EO namspace dc_gui

#endif // DC_GUI_REPEATEDITOR_2MOC_H_INCLUDED
