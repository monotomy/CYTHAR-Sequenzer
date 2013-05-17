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

#ifndef DC_GUI_BAR_TOMOC_H_INCLUDED
#define DC_GUI_BAR_TOMOC_H_INCLUDED

#include <dc_gui_patternmaster.uiced.h>

#include <stuff/blockguard.h>
#include <guistuff/child_initializer.h>

#include <extendQt_drag_n_drop.2moc.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

#include <QTimer>

namespace dc_gui{

    using namespace dc_objects;

    /***********************************************************************/
    //! \class  Patternmaster_Initializer
    /***********************************************************************/
    class Patternmaster;
    class Patternmaster_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            SUM_ELEMENTS    = 16,
            LEFT            = 0,
            TOP             = 0,
            HEIGTH          = 87,
            WIDTH           = 35,
            _2LEFT_SPACE    = 5,
            _4GROUP_SPACE   = 15,
        };

        friend class Patternmaster;
        typedef guistruff::_4GroupSpaceInitializer
        <
            Patternmaster,
            SUM_ELEMENTS,
            LEFT,
            TOP,
            HEIGTH,
            WIDTH,
            _2LEFT_SPACE,
            _4GROUP_SPACE
        > Patternmaster_4GroupSpaceInitializer;

    public:
        Patternmaster_Initializer() noexcept = default;
        ~Patternmaster_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    /***********************************************************************/
    /*! \class  Patternmaster
    */
    /***********************************************************************/
    class Patternmaster :
        public extendQt::DRAGnDROP_QWidget,
        public Ui::Patternmaster,

        public Events_blockable,

        public RelativePatternObserver_V2<Patternmaster>,
        public SelecteddetailSequencerObserver_V2
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(Patternmaster)

        typedef RelativePatternObserver_V2<Patternmaster> this_relPATTERN_OBSERVER;
        typedef SelecteddetailSequencerObserver_V2        this_dtlSEQUENCER_OBSERVER;

        friend Patternmaster_Initializer::Patternmaster_4GroupSpaceInitializer;
        Patternmaster ();
        void init() noexcept;
        void update() noexcept;
        ~Patternmaster();

        virtual void property_changed(AT_(Temporary,SELECTED_PROJECT)) noexcept override;

        virtual void RELATIVE_OBSERVER_CHANGED(Pattern) noexcept override;
        virtual void selected_observed_object_changed(forUNIQUE_TYPE(Pattern)) noexcept override;
        bool iam_selected_yet{false};
        void set_selected() noexcept;

        virtual void property_changed(AT_(Pattern,IS_MUTED)) noexcept override;
        void set_mute() noexcept;

        virtual void property_changed(AT_(Pattern,MUTE_TIME)) noexcept override;
        void set_mute_time() noexcept;

        inline virtual void property_changed(AT_(Sequencer,TAKT_POS)) noexcept override;
    private slots:
        void change_mute_tmer_interval() noexcept;
    private:
        void start_mute_tmer() noexcept;
        QTimer _mute_in_takt_timer{this};
        bool is_mute_time_blink{false};
    private slots:
        void blink_timer_mute() noexcept;

    private slots:
        void on_pb_actionButton_clicked() noexcept;
        void on_dial_time_valueChanged(int value__) noexcept;
        void on_pb_mute_clicked() noexcept;

    private:
        //! DRAGnDROP *******************************************************************
        DRAGnDROP___relOBSERVER___DRAG_FROM_THIS_OBSERVER(this_relPATTERN_OBSERVER)
        DRAGnDROP___relOBSERVER___ACCEPT_DROPS_FROM(this_relPATTERN_OBSERVER)
        virtual void same_type_is_dropped(extendQt::DragObject const* drag_source_object__) noexcept override
        {
            auto source(static_cast<typename this_relPATTERN_OBSERVER::TYPE_Object2Observe_T*>(drag_source_object__->source()));
            // Kopiert die eigenen Daten
            relOBS_(this_relPATTERN_OBSERVER)->copy_from_source(source);
            // Kopiert Daten nur vom Takt,nicht Patternsaite
            for(TYPE_index_child takt_id{0} ; takt_id != Takt_per_Pattern ; ++takt_id )
            {
                relOBS_(this_relPATTERN_OBSERVER)->takt(takt_id)->copy_from_source(source->takt(takt_id));
                relOBS_(this_relPATTERN_OBSERVER)->takt(takt_id)->this_Taktsaiten_in_Takt::copy_childdata_from_source(source->takt(takt_id),copyDEEPNESS_(2));
                //relOBS_(this_relPATTERN_OBSERVER)->takt(takt_id)->this_Taktsaiten_in_Takt::copy_childdata_from_source(source->takt(takt_id),copyDEEPNESS_(2));
            }

           /*
            auto takt(static_cast<Takt_in_Pattern_T*>(relOBS_(this_relPATTERN_OBSERVER)));
                takt->this_Taktsaiten_in_Takt::copy_childdata_from_source(source,copyDEEPNESS_(this_relPATTERN_OBSERVER::TYPE_Object2Observe_T::CHILD_COPY_DEEPNESS));
        */
        }

        //! Pfad zur eigenen sub_docu
        virtual std::string doc_file_name() const noexcept override;
    };

    inline void Patternmaster
    ::property_changed(AT_(Sequencer,TAKT_POS)) noexcept
    {
        //  ABKOPPELN VON ZEIT-KRITISCHEN THREADS IN DEN MAINLOOP
        QMetaObject::invokeMethod(this,
                                  "change_mute_tmer_interval",
                                  Qt::ConnectionType::QueuedConnection);
    }

}   /// EO namespace dc_gui
#endif // DC_GUI_BAR_TOMOC_H_INCLUDED
