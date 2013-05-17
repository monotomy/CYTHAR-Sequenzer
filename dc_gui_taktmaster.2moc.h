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

#ifndef DC_GUI_TAKTMASTER_2MOC_H_INCLUDED
#define DC_GUI_TAKTMASTER_2MOC_H_INCLUDED

#include <dc_gui_taktmaster.uiced.h>
#include <dc_gui_taktchain.uiced.h>

#include <extendQt_drag_n_drop.2moc.h>
#include <dc_export_takt.h>

#include <stuff/blockguard.h>
#include <guistuff/child_initializer.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>
#include <object_dependstrategy.h>



#include <QTimer>

namespace dc_gui{

    using namespace dc_objects;

    /***********************************************************************/
    //! \class  Taktmaster_Initializer
    /***********************************************************************/
    class Taktmaster;
    class Taktmaster_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            SUM_ELEMENTS    = 16,
            LEFT            = 0,
            TOP             = 0,
            HEIGTH          = 79,
            WIDTH           = 35,
            _2LEFT_SPACE    = 5,
            _4GROUP_SPACE   = 15,
        };

        friend class Taktmaster;
        typedef guistruff::_4GroupSpaceInitializer
        <
            Taktmaster,
            SUM_ELEMENTS,
            LEFT,
            TOP,
            HEIGTH,
            WIDTH,
            _2LEFT_SPACE,
            _4GROUP_SPACE
        > Taktmaster_4GroupSpaceInitializer;

    public:
        Taktmaster_Initializer() noexcept = default;
        ~Taktmaster_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    /***********************************************************************/
    /*! \class  Taktchain
    */
    /***********************************************************************/
    class Taktmaster;
    class Taktchain :
        public QWidget,
        public Ui::Taktchain,

        public RelativeTaktchainObserver_V2<Taktchain>,
        public SelectedPatternObserver_V2
    {
    Q_OBJECT

        friend class Taktmaster;

        typedef RelativeTaktchainObserver_V2<Taktchain> this_relTAKTCHAIN_OBSERVER;
        typedef SelectedPatternObserver_V2 this_selPATTERN_OBSERVER;

        virtual void SELECTED_OBSERVER_CHANGED(Pattern) noexcept override;
        inline virtual void property_changed(AT_(Taktchain,FOR)) noexcept override
        {
            //if(this_relTAKTCHAIN_OBSERVER::_absolut_id_in_parent == 0)
            //    this_relTAKTCHAIN_OBSERVER::replace_selected_with_relative();
            set_for();
        }

        inline virtual void property_changed(AT_(Taktchain,NEXT)) noexcept override
        {
            set_next();
        }

        inline virtual void property_changed(AT_(Taktchain,OVERWRITE_TARGET_LEVEL)) noexcept override
        {
            set_overwrite_target_level();
        }


        void set_for() noexcept;
        void set_next() noexcept;
        void set_overwrite_target_level() noexcept;

        //! Dieser Chain wurde aktiviert
        virtual void SELECTED_OBSERVER_CHANGED(Taktchain) noexcept override;
        virtual void RELATIVE_OBSERVER_CHANGED(Taktchain) noexcept override
        {
            //if(this_relTAKTCHAIN_OBSERVER::_absolut_id_in_parent == 0)
            //    this_relTAKTCHAIN_OBSERVER::replace_selected_with_relative();
            update();
        }

        virtual void property_changed(AT_(Temporary,SELECTED_TAKTCHAIN_LEVEL_ID)) noexcept override;
        virtual void property_changed(AT_(Temporary,SELECTED_TAKTCHAIN_TAKT_ID)) noexcept override;

    private slots:
        //! Ändert Velocity per Mausrad
        void wheelEvent(QWheelEvent*event__) noexcept
        {
            // Aktivieren
            this_relTAKTCHAIN_OBSERVER::replace_selected_with_relative();

            auto change_in_degre(event__->delta() / 80);   // Der Rückgabewert von 'delta' entspricht der 8-fachen Gradzahl
            // Welcher Wert muss geändert werden, wo ist die Maus
            if(label_target_chain_level->underMouse() == true)
                change_next_level(change_in_degre);
            else if(label_next->underMouse() == true)
                change_next(change_in_degre);
            else if(label_for->underMouse() == true)
                change_for(change_in_degre);
        }
    private:
        //! Änderd den For Wert
        void change_for(int for_) noexcept
        {
            int new_for(for_ += relGET_(this_relTAKTCHAIN_OBSERVER, FOR));

            if(new_for > ENUM_takt_chain_mode::MODE_ENDLESS)
                new_for = ENUM_takt_chain_mode::MODE_ENDLESS;
            else if(new_for <= 0)
                new_for = 0;

            relSET_(this_relTAKTCHAIN_OBSERVER, FOR, new_for);
        }
        //! Änderd den Next Wert
        void change_next(int next_) noexcept
        {
            int next(next_ += relGET_(this_relTAKTCHAIN_OBSERVER, NEXT));

            if(next > ENUM_takt_chain_mode::MODE_TO_MASTER)
                next = ENUM_takt_chain_mode::MODE_TO_MASTER;
            else if(next <= 0)
                next = 0;

            relSET_(this_relTAKTCHAIN_OBSERVER, NEXT, next);
        }
        //! Änderd den NextLevel Wert
        void change_next_level(int next_level_) noexcept
        {
            int next_level(next_level_ += relGET_(this_relTAKTCHAIN_OBSERVER, OVERWRITE_TARGET_LEVEL));

            if(next_level > ENUM_takt_chain_level_mode::MODE_AUTO_LEVEL)
                next_level = ENUM_takt_chain_level_mode::MODE_AUTO_LEVEL;
            else if(next_level <= 0)
                next_level = 0;

            relSET_(this_relTAKTCHAIN_OBSERVER, OVERWRITE_TARGET_LEVEL, next_level);
        }
    private slots:

        //! Aktivieren
        virtual void mousePressEvent(QMouseEvent*)  noexcept override
        {
            if(label_target_chain_level->underMouse() == true)
            {
                tmpSET_(SELECTED_TAKTCHAIN_LEVEL_ID, this_relTAKTCHAIN_OBSERVER::_absolut_id_in_parent);

                auto selected_taktchain_at_level(tmpGET_(SELECTED_PATTERN)
                                                 ->takt(tmpGET_(SELECTED_TAKTCHAIN_TAKT_ID))
                                                 ->taktchain(tmpGET_(SELECTED_TAKTCHAIN_LEVEL_ID)));

                tmpSET_(SELECTED_TAKTCHAIN, selected_taktchain_at_level);
            }
            else
            {
                tmpSET_(SELECTED_TAKTCHAIN_TAKT_ID, this_relTAKTCHAIN_OBSERVER::_absolut_id_in_parent);
                this_relTAKTCHAIN_OBSERVER::replace_selected_with_relative();
/*
                auto selected_taktchain_at_level(tmpGET_(SELECTED_PATTERN)
                                                 ->takt(this_relTAKTCHAIN_OBSERVER::_absolut_id_in_parent)
                                                 ->taktchain(tmpGET_(SELECTED_TAKTCHAIN_LEVEL_ID)));


                tmpSET_(SELECTED_TAKTCHAIN, selected_taktchain_at_level);
*/
            }
        }

        void set_selected() noexcept;
        void set_selected_level() noexcept;
    public:
        Taktchain();

        void init() noexcept;
        void update() noexcept;
    };

    /***********************************************************************/
    /*! \class  Taktmaster
        \brief  MasterButtonelement auf Gui (x16)
    */
    /***********************************************************************/
    class UNIQUE_TAKTMASTER_PATTERNOBSERVER{};
    class UNIQUE_TAKTMASTER_TAKTOBSERVER{};
    class Taktmaster :
        public extendQt::DRAGnDROP_QWidget,
        public Ui::Taktmaster,

        public Events_blockable,

        public SelecteddetailPatternObserver_V2<UNIQUE_TAKTMASTER_PATTERNOBSERVER>,
        public RelativeTaktObserver_V2<UNIQUE_TAKTMASTER_TAKTOBSERVER>,
        public SelecteddetailSequencerObserver_V2
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(Taktmaster)

        typedef SelecteddetailPatternObserver_V2<UNIQUE_TAKTMASTER_PATTERNOBSERVER> this_dtlPATTERN_OBSERVER;
        typedef RelativeTaktObserver_V2<UNIQUE_TAKTMASTER_TAKTOBSERVER>             this_relTAKT_OBSERVER;
        typedef SelecteddetailSequencerObserver_V2                                  this_dtlSEQUENCER_OBSERVER;


        Taktchain*const _takt_chain{nullptr};

        friend Taktmaster_Initializer::Taktmaster_4GroupSpaceInitializer;
        Taktmaster();
        void init() noexcept;
        void update() noexcept;
        ~Taktmaster();

        //! Set Running und Selected Ligth **********************************************
        virtual void SELECTED_OBSERVER_CHANGED(Takt) noexcept override;
        virtual void RELATIVE_OBSERVER_CHANGED(Takt) noexcept override;
        inline virtual void property_changed(AT_(Sequencer,TAKT_POS)) noexcept override;
        void set_selected() noexcept;
        bool iam_selected_yet{false};
        bool iam_running_yet{false};
        void set_iam_selected() noexcept;
        void set_iam_not_selected() noexcept;
        void set_iam_running() noexcept;
        void set_iam_not_running() noexcept;
        void set_taktoffset_per_master() noexcept;
        void set_taktoffset_per_run() noexcept;

    private slots:
        void set_running() noexcept;

    private:
        //! Running Takt ****************************************************************
        QTimer _overhide_timer{this};
        bool iam_overhide_yet{false};
        bool is_blinking_overhide_yet{false};
    private slots:
        void setup_blink_overhide() noexcept;
        void set_blink_overhide() noexcept;
    private:
        void set_blink_overhide_true() noexcept;
        void set_blink_overhide_false() noexcept;

    private slots:
        void on_pb_actionButton_clicked() noexcept;
        void on_pb_plus_clicked() noexcept;
        void on_pb_minus_clicked() noexcept;

    private:
        //! DRAGnDROP *******************************************************************
        DRAGnDROP___relOBSERVER___DRAG_FROM_THIS_OBSERVER(this_relTAKT_OBSERVER)
        DRAGnDROP___relOBSERVER___ACCEPT_DROPS_FROM(this_relTAKT_OBSERVER)
        //DRAGnDROP___relOBSERVER___COPY_sourceDROP_2Me(this_relTAKT_OBSERVER)
        virtual void same_type_is_dropped(extendQt::DragObject const* drag_source_object__) noexcept override
        {
            auto source(static_cast<typename this_relTAKT_OBSERVER::TYPE_Object2Observe_T*>(drag_source_object__->source()));
            // Kopiert die eigenen Daten
            relOBS_(this_relTAKT_OBSERVER)->copy_from_source(source);
            // Kopiert Daten nur vom Taktsaite,nicht Taktchain
            static_cast<Taktsaiten_in_Takt_T*>(relOBS_(this_relTAKT_OBSERVER))
                ->copy_childdata_from_source(source,
                                             copyDEEPNESS_(this_relTAKT_OBSERVER::TYPE_Object2Observe_T::CHILD_COPY_DEEPNESS));
        }

        //! Erstellt die Pixmap für den Drag-Pointer
        virtual QPixmap drag_pixmap() noexcept override;

        //! TabulatorText export in Drag
        virtual std::string additional_drag_text() const noexcept override;

        //! Erstellung eines zusätzlichen Accord-Drag Containers der Taktsaiten Offsets
        virtual extendQt::TYPE_vector_additional_numeric_drag_data additional_numeric_drag_data() const noexcept override;
        //! Prüfun, ob sich Accorde Dropen lassen, einpflegen im Dropfall
        virtual bool compare_is_additional_data_dropable(extendQt::DragObject const*) const noexcept override;
        virtual void additional_data_is_dropped(extendQt::TYPE_vector_additional_numeric_drag_data const&) noexcept override;

        //! Pfad zur eigenen sub_docu
        virtual std::string doc_file_name() const noexcept override;
    };

    inline void Taktmaster
    ::property_changed(AT_(Sequencer,TAKT_POS)) noexcept
    {
        //  ABKOPPELN VON ZEIT-KRITISCHEN THREADS IN DEN MAINLOOP
        QMetaObject::invokeMethod(this,
                                  "set_running",
                                  Qt::ConnectionType::QueuedConnection);
    }
}

#endif // DC_GUI_TAKTMASTER_2MOC_H_INCLUDED
