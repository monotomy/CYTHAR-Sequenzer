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

#ifndef DC_GUI_SLIDEREDITORMASTER_2MOC_H_INCLUDED
#define DC_GUI_SLIDEREDITORMASTER_2MOC_H_INCLUDED

#include <dc_gui_tuneslider.uiced.h>
#include <dc_gui_tuneslidereditor.uiced.h>
#include <dc_gui_tunevaluebox.uiced.h>

#include <extendQt_drag_n_drop.2moc.h>

#include <guistuff/child_initializer.h>
#include <stuff/blockguard.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

namespace dc_gui{

    using namespace dc_objects;

    /***********************************************************************/
    //! \class  Tuneslider_Initializer
    /***********************************************************************/
    class Tuneslider;
    class Tuneslider_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            sum_elements    = 6,

            height          = 34,
            width           = 201,
            top_first       = 92,
            left            = 10
        };

    public:
        Tuneslider_Initializer() noexcept = default;
        ~Tuneslider_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    /***********************************************************************/
    /*! \class  Tuneslider
    */
    /***********************************************************************/
    class Tuneslider :
        public QWidget,
        public Ui::Tuneslider,

        public Events_blockable,

        public SelectedPatternObserver_V2,
        public RelativePatternsaiteObserver_V2<Tuneslider>
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(Tuneslider)

        typedef RelativePatternsaiteObserver_V2<Tuneslider> this_relPATTERNSAITE_OBSERVER;

        friend class Tuneslider_Initializer;
        Tuneslider ();
        void init() noexcept;
        void update() noexcept;
        ~Tuneslider() = default;

        virtual void RELATIVE_OBSERVER_CHANGED(Patternsaite) noexcept override;
        virtual void SELECTED_OBSERVER_CHANGED(Pattern) noexcept override;

        virtual void property_changed(AT_(Temporary,TUNEEDITOR_SHOW)) noexcept override;
        virtual void property_changed(AT_(Patternsaite,TUNE_OFFSET)) noexcept override;
        void set_tune() noexcept;

        virtual void property_changed(AT_(Patternsaite,ACCORD_OFFSET)) noexcept override;
        void set_accord() noexcept;

    private slots:
        void on_hs_slider_valueChanged(int value__) noexcept;
    };

    /***********************************************************************/
    //! \class  Tuneslidereditor_Initializer
    /***********************************************************************/
    class Tuneslidereditor;
    class Tuneslidereditor_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            height  = 401,
            width   = 221,
            top     = 0,
            left    = 0,
        };

    public:
        Tuneslidereditor_Initializer() noexcept = default;
        ~Tuneslidereditor_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    /***********************************************************************/
    /*! \class  Tuneslidereditor
        \brief  Editieren der Mididaten von allen
    */
    /***********************************************************************/
    class Tuneslidereditor :
        public extendQt::DRAGnDROP_QWidget,
        public Ui::Tuneslidereditor,

        public Events_blockable,

        public SelectedPatternObserver_V2
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(Tuneslidereditor)

        typedef SelectedPatternObserver_V2 this_setPATTERN_OBSERVER;

        friend class Tuneslidereditor_Initializer;
        Tuneslidereditor();
        void init() noexcept;
        void update() noexcept;
        ~Tuneslidereditor() = default;


        virtual void SELECTED_OBSERVER_CHANGED(Pattern) noexcept override;
        virtual void property_changed(AT_(Temporary,TUNEEDITOR_SHOW)) noexcept override;
        void set_viewtab() noexcept;

        virtual void property_changed(AT_(Pattern,OFFSET)) noexcept override;
        void set_transpose() noexcept;

    private slots:
        //! Wechselt zwischen den Reitern/Tabs
        void on_pb_viewAccord_clicked() noexcept;
        void on_pb_viewTune_clicked() noexcept;

        void on_hs_transpose_valueChanged(int offset__) noexcept;

        //! Setzt default Tune od. Drum
        void on_pb_defaultTune_clicked() noexcept;
        void on_pb_defaultDrum_clicked() noexcept;

        //! Default Accorde
        void on_pb_accord_0_clicked() noexcept;
        void on_pb_accord_1_clicked() noexcept;
        void on_pb_accord_2_clicked() noexcept;
        void on_pb_accord_3_clicked() noexcept;
        void on_pb_accord_4_clicked() noexcept;
        void on_pb_accord_5_clicked() noexcept;
        void on_pb_accord_6_clicked() noexcept;
        void on_pb_accord_7_clicked() noexcept;

    private:
        //! DRAGnDROP *******************************************************************
        //! Erstellt eine Kopie inkl. des Parent Frame.
        virtual QPixmap drag_pixmap() noexcept override;
        //! Pfad zur eigenen sub_docu
        virtual std::string doc_file_name() const noexcept override;
    };

    /***********************************************************************/
    //! \class  Tunevaluebox_Initializer
    /***********************************************************************/
    class Tunevaluebox;
    class Tunevaluebox_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            sum_elements    = 6,

            height          = 34,
            width           = 51,
            top_first       = 0,
            left            = 0
        };

    public:
        Tunevaluebox_Initializer() noexcept = default;
        ~Tunevaluebox_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    /***********************************************************************/
    /*! \class  Tunevaluebox
    */
    /***********************************************************************/
    typedef RelativePatternsaiteObserver_V2<struct unique_tunevaluebox_A> RelativePatternsaiteObserver_V2_Tunevaluebox;
    typedef SelecteddetailPatternObserver_V2<struct unique_tunevaluebox_B> SelecteddetailPatternObserver_V2_Tunevaluebox;

    class Tunevaluebox :
        public QWidget,
        public Ui::Tunevaluebox,

        public RelativePatternsaiteObserver_V2_Tunevaluebox,
        public SelecteddetailPatternObserver_V2_Tunevaluebox
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(Tunevaluebox)

        typedef RelativePatternsaiteObserver_V2_Tunevaluebox this_relPATTERNSAITE_OBSERVER;
        typedef SelecteddetailPatternObserver_V2_Tunevaluebox this_dtlPATTERN_OBSERVER;

        friend class Tunevaluebox_Initializer;
        Tunevaluebox ();
        void init() noexcept;
        void update() noexcept;
        ~Tunevaluebox() = default;

        virtual void RELATIVE_OBSERVER_CHANGED(Patternsaite) noexcept override;
        virtual void property_changed(AT_(Pattern,OFFSET)) noexcept override;
        virtual void property_changed(AT_(Patternsaite,ACCORD_OFFSET)) noexcept override;
        virtual void property_changed(AT_(Patternsaite,TUNE_OFFSET)) noexcept override;
        void set_boxcontent() noexcept;
        virtual void property_changed(AT_(Patternsaite,IS_MUTED)) noexcept override;
        void set_mute() noexcept;

    private slots:
        void on_pb_clicked() noexcept;
    };
}

#endif // DC_GUI_SLIDEREDITORMASTER_2MOC_H_INCLUDED
