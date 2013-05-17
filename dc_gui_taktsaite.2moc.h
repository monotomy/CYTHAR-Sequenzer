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

#ifndef DC_GUI_PATTERNSAITE_2MOC_H_INCLUDED
#define DC_GUI_PATTERNSAITE_2MOC_H_INCLUDED

#include <dc_gui_taktsaite.uiced.h>

#include <extendQt_drag_n_drop.2moc.h>

#include <guistuff/child_initializer.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

#include <dc_gui_styles.h>

#include <dc_midi_sequencer_timer.h>

#include <QWheelEvent>

namespace dc_gui{

    using namespace dc_objects;

    /***********************************************************************/
    //! \class  Taktsaite_Initializer
    /***********************************************************************/
    class Taktsaite;
    class Taktsaite_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            SUM_ELEMENTS    = 16,
            LEFT            = 0,
            TOP             = 0,
            HEIGTH          = 32,
            WIDTH           = 35,
            _2LEFT_SPACE    = 5,
            _4GROUP_SPACE   = 15,
        };

        friend class Taktsaite;
        typedef guistruff::_4GroupSpaceInitializer
        <
            Taktsaite,
            SUM_ELEMENTS,
            LEFT,
            TOP,
            HEIGTH,
            WIDTH,
            _2LEFT_SPACE,
            _4GROUP_SPACE
        > Taktsaite_4GroupSpaceInitializer;

    public:
        Taktsaite_Initializer() noexcept = default;
        ~Taktsaite_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    /***********************************************************************/
    //! \class  Taktsaite
    /***********************************************************************/
    class Taktsaite :
        public extendQt::DRAGnDROP_QWidget,
        public Ui::Taktsaite,

        public RelativeTaktObserver_V2<dc_gui::Taktsaite>,
        public RelativeTaktsaiteObserver_V2,
        public SelecteddetailSequencerObserver_V2,
        public SelecteddetailPatternObserver_V2<dc_gui::Taktsaite>
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(Taktsaite)

        typedef RelativeTaktObserver_V2<dc_gui::Taktsaite>  this_relTAKT_OBSERVER;
        typedef RelativeTaktsaiteObserver_V2                this_relTAKTSAITE_OBSERVER;
        typedef SelecteddetailSequencerObserver_V2          this_dtlSEQUENCER_OBSERVER;
        typedef SelecteddetailPatternObserver_V2<dc_gui::Taktsaite> this_dtlPATTERN_OBSERVER;

        friend Taktsaite_Initializer::Taktsaite_4GroupSpaceInitializer;
        Taktsaite();
        void init() noexcept;
        void update() noexcept;
        ~Taktsaite() = default;

        inline virtual void property_changed(AT_(Sequencer,TAKT_POS)) noexcept override;
        virtual void property_changed(AT_(Pattern,USE_TAKTSAITE_OFFSET_per)) noexcept override
        {
            set_usedata();
        }
    private slots:
        bool is_plus_minus_overhide{false};
        bool is_actionButton_overhide{false};
        void set_usedata() noexcept
        {
            // Setze TaktOffset Per Master Markierung
            if(relGET_(this_dtlPATTERN_OBSERVER, USE_TAKTSAITE_OFFSET_per) == USE_PER_MODE::USE_PER_MODE_RUN_MASTER)
            {
                if(relGET_(this_dtlSEQUENCER_OBSERVER, TAKT_POS) == this_relTAKT_OBSERVER::_absolut_id_in_parent)
                {
                    DCSTYLE->set_overhideTrueTaktPalette(pb_plus);
                    DCSTYLE->set_overhideTrueTaktPalette(pb_minus);
                    is_plus_minus_overhide = true;
                }
                else
                {
                    DCSTYLE->set_defaultMasterPalette(pb_plus);
                    DCSTYLE->set_defaultMasterPalette(pb_minus);
                    is_plus_minus_overhide = false;
                }

            }
            // Setze TaktOffset Per Run Markierung
            else if(relGET_(this_dtlPATTERN_OBSERVER, USE_TAKTSAITE_OFFSET_per) == USE_PER_MODE::USE_PER_MODE_RUN_CURRENT)
            {
                if(dc_midi::Timers::current_visible_running_takt_id() == this_relTAKT_OBSERVER::_absolut_id_in_parent)
                {
                    DCSTYLE->set_overhideTrueTaktPalette(pb_plus);
                    DCSTYLE->set_overhideTrueTaktPalette(pb_minus);
                    is_plus_minus_overhide = true;
                }
                else
                {
                    DCSTYLE->set_defaultMasterPalette(pb_plus);
                    DCSTYLE->set_defaultMasterPalette(pb_minus);
                    is_plus_minus_overhide = false;
                }
            }
            else
            {
                if(is_plus_minus_overhide == true)
                {
                    DCSTYLE->set_defaultMasterPalette(pb_plus);
                    DCSTYLE->set_defaultMasterPalette(pb_minus);
                    is_plus_minus_overhide = false;
                }
            }


            // Setze TaktOffset Per Master Markierung
            if(relGET_(this_dtlPATTERN_OBSERVER, USE_TAKTSAITE_MUTE_per) == USE_PER_MODE::USE_PER_MODE_RUN_MASTER)
            {
                if(relGET_(this_dtlSEQUENCER_OBSERVER, TAKT_POS) == this_relTAKT_OBSERVER::_absolut_id_in_parent)
                {
                    if(relGET_(this_relTAKTSAITE_OBSERVER, IS_MUTED) == false)
                        DCSTYLE->set_overhideTrueTaktPalette(pb_actionDummy);

                    is_actionButton_overhide = true;
                }
                else
                {
                    if(relGET_(this_relTAKTSAITE_OBSERVER, IS_MUTED) == false)
                        DCSTYLE->set_defaultMasterPalette(pb_actionDummy);

                    is_actionButton_overhide = false;
                }

            }
            // Setze TaktOffset Per Run Markierung
            else if(relGET_(this_dtlPATTERN_OBSERVER, USE_TAKTSAITE_MUTE_per) == USE_PER_MODE::USE_PER_MODE_RUN_CURRENT)
            {
                if(dc_midi::Timers::current_visible_running_takt_id() == this_relTAKT_OBSERVER::_absolut_id_in_parent)
                {
                    if(relGET_(this_relTAKTSAITE_OBSERVER, IS_MUTED) == false)
                        DCSTYLE->set_overhideTrueTaktPalette(pb_actionDummy);

                    is_actionButton_overhide = true;
                }
                else
                {
                    if(relGET_(this_relTAKTSAITE_OBSERVER, IS_MUTED) == false)
                        DCSTYLE->set_defaultMasterPalette(pb_actionDummy);

                    is_actionButton_overhide = false;
                }
            }
            else
            {
                if(is_actionButton_overhide == true)
                {
                    if(relGET_(this_relTAKTSAITE_OBSERVER, IS_MUTED) == false)
                        DCSTYLE->set_defaultMasterPalette(pb_actionDummy);

                    is_actionButton_overhide = false;
                }
            }
        }
    private:

        virtual void RELATIVE_OBSERVER_CHANGED(Takt) noexcept override;
        virtual void RELATIVE_OBSERVER_CHANGED(Taktsaite) noexcept override;

        //! Aktualisiert die Anzeige
        virtual void property_changed(AT_(Takt,OFFSET)) noexcept override;
        virtual void property_changed(AT_(Taktsaite,OFFSET)) noexcept override;
        void set_offset() noexcept;

        virtual void property_changed(AT_(Taktsaite,IS_MUTED)) noexcept override;
        void set_mute() noexcept;

    private slots:
        void on_pb_plus_clicked() noexcept;
        void on_pb_minus_clicked() noexcept;
        void on_pb_actionButton_clicked() noexcept;

    private:
        //! Ändert offset per Mausrad
        void wheelEvent(QWheelEvent*) noexcept;

    private:
        //! DRAGnDROP ***************************************************************
        DRAGnDROP___relOBSERVER___DRAG_FROM_THIS_OBSERVER(this_relTAKTSAITE_OBSERVER)
        DRAGnDROP___relOBSERVER___ACCEPT_DROPS_FROM(this_relTAKTSAITE_OBSERVER)
        DRAGnDROP___relOBSERVER___COPY_sourceDROP_2Me(this_relTAKTSAITE_OBSERVER)

        //! Pfad zur eigenen sub_docu
        virtual std::string doc_file_name() const noexcept override;
    };

    inline void Taktsaite
    ::property_changed(AT_(Sequencer,TAKT_POS)) noexcept
    {
        //  ABKOPPELN VON ZEIT-KRITISCHEN THREADS IN DEN MAINLOOP
        QMetaObject::invokeMethod(this,
                                  "set_usedata",
                                  Qt::ConnectionType::QueuedConnection);
    }
}
#endif // DC_GUI_PATTERNSAITE_2MOC_H_INCLUDED
