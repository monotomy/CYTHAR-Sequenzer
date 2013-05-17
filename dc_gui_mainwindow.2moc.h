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

#ifndef CYTHAR_GUI_MAINWINDOW_H_INCLUDED
#define CYTHAR_GUI_MAINWINDOW_H_INCLUDED

#include <dc_gui_mainwindow.uiced.h>
#include <dc_gui_mainwindow_clipboard.uiced.h>
#include <dc_gui_mainwindow_questmark.uiced.h>

#include <pattern/singleton.hpp>
#include <stuff/blockguard.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

#include <dc_gui_styles.h>
#include <extendQt_exclusive_box.h>
#include <extendQt_drag_n_drop.2moc.h>

#include <dc_documentation.h>

#include <dc_ticker_generator.h>

namespace dc_gui
{

    using namespace dc_objects;

    /***********************************************************************/
    /*! \class  mainwindow clipboard

        Zwischenspeicher für alle kompatiblen Drag N Drop Typen
    */
    /***********************************************************************/
    class MainwindowCopyCompatibleList :
        public TYPELIST_2Clipboard_is_copyCompatible,
        public UNIQUE<UNIQUE_IDENTIFICATIONS::MainwindowClipboard>,
        public extendQt::DRAGnDROP_CLIPBOARD
    {};

    //! Zwischenspeicher
    class MainwindowClipboard;
    struct MainwindowClipboardStore
    {
        SINGLETON_throwable(MainwindowClipboardStore)
    public:
        UNIQUE_BASE* _stored_object {nullptr};
        QPixmap _stored_pixmap {};
    };

    class Mainwindow;
    class MainwindowClipboard :
        public extendQt::DRAGnDROP_QWidget,
        public Ui::MainwindowClipboard
    {
        Q_OBJECT

        MainwindowCopyCompatibleList* _copy_compatible_list {new MainwindowCopyCompatibleList{}};

        friend class Mainwindow;
        void init() noexcept;
        MainwindowClipboard() = default;

        //! DRAGnDROP *******************************************************************
        //! Rückgabe des Objectes im Clipboard
        virtual UNIQUE_BASE* unique_source_object2drag() const noexcept override;

        //! Prüft möglich Drops gegen die UNIQE Clipboardlist, ob diese Dropable sind.
        virtual bool compare_is_source_in_target_dropable(extendQt::DragObject const* drag_source_object__) const noexcept override;

        //! Sichert gedropte Objekte im ClipboardStore sowie eine Kopie der Dragpixmap
        virtual void same_type_is_dropped(extendQt::DragObject const* drag_source_object__) noexcept override;

        //! Sicherung der DragPixmap
        QPixmap _stored_pixmap {};
        void store_a_copy_drag_pixmap(extendQt::DragObject const* drag_source_object__) noexcept;

        //! Rückgabe der gesicherten DragPixmap
        virtual QPixmap drag_pixmap() noexcept override;
    };

    /***********************************************************************/
    /*! \class  MainwindowQuestionMark

        Öffnet Dokumentation window, wenn der übergebene File verfügbar.
    */
    /***********************************************************************/
    class MainwindowQuestionMark :
        public extendQt::DRAGnDROP_QWidget,
        public Ui::MainwindowQuestmark
    {
        Q_OBJECT

        friend class Mainwindow;
        void init() noexcept;
        MainwindowQuestionMark() = default;

        //! nDROP *******************************************************************
        //! Akzeptiert alle Cythar elemente
        virtual void dragEnterEvent(QDragEnterEvent *event__) noexcept override
        {
            // Akzeptiert keine fremden Drops
            if(dynamic_cast<extendQt::DragObject const*>(event__->mimeData()) == false)
                return;

            event__->acceptProposedAction();
        }
        //! Übergibt den
        virtual void dropEvent(QDropEvent *event__) noexcept override
        {
            extendQt::DragObject const* drag_source_object(static_cast<extendQt::DragObject const*>(event__->mimeData()));
            new DocumentationWindow{drag_source_object->_doc_file_name};
        }

    private slots:
        //! Ruft die eigene Doku auf
        void on_pb_questionmark_clicked() noexcept
        {
            new DocumentationWindow{"10"};
        }
    };

    /***********************************************************************/
    /*! \class  mainwindow

    */
    /***********************************************************************/
    struct POLICY_set_mute_as_exclusive_checked
    {
        static inline void exec(QWidget*const element_2_set_exclusive_checked__) noexcept
        {
            DCSTYLE->set_mutedButtonPalette(element_2_set_exclusive_checked__);
        }
    };

    struct POLICY_set_default_as_exclusive_unchecked
    {
        static inline void exec(QWidget*const element_2_set_exclusive_unchecked__) noexcept
        {
            DCSTYLE->set_defaultMasterPalette(element_2_set_exclusive_unchecked__);
        }
    };

    class Mainwindow :
        public QWidget,
        public Ui::Mainwindow,

        public dc_ticker::TickerExternClockObserver,    // ExternClockinfo

        public Events_blockable,

        public SelecteddetailProjectObserver_V2,
        public SelecteddetailPatternObserver_V2<Mainwindow>
    {
        Q_OBJECT
        SINGLETON_ownCTOR_throwable(Mainwindow)

        typedef SelecteddetailProjectObserver_V2                this_dtlPROJECT_OBSERVER;
        typedef SelecteddetailPatternObserver_V2<Mainwindow>    this_dtlPATTERN_OBSERVER;

        Mainwindow();
    public:
        void init() noexcept;
    private:
        void update() noexcept;

        virtual void RELATIVE_OBSERVER_CHANGED(Pattern) noexcept override;

        virtual void property_changed(AT_(Project,CLOCKSPEED_inBPM_x_100)) noexcept override;
        void set_clockspeed() noexcept;

        //! Sequencer Steuerung *********************************************************
        virtual void property_changed(AT_(Project,IS_MASTER)) noexcept override;
        virtual void property_changed(AT_(Temporary,IS_NOTFYING)) noexcept override;
        virtual void property_changed(AT_(Temporary,IS_PAUSE)) noexcept override;
        void set_play() noexcept;

        void set_master() noexcept;
        inline virtual void notify_extern_clock() noexcept override;
    private slots:
        void blink_bpm_label() noexcept;
        void on_pb_master_clicked() noexcept;
        void on_pb_play_clicked() noexcept;
        void on_pb_pause_clicked() noexcept;
        void on_pb_stop_clicked() noexcept;
        void on_pb_panic_clicked() noexcept;

        void on_dial_interval_after_comma_valueChanged(int) noexcept;
        void on_hS_interval_valueChanged(int) noexcept;


        //! Use Offsets from
    private:
        virtual void property_changed(AT_(Pattern,USE_TAKT_OFFSET_per)) noexcept override;
        virtual void property_changed(AT_(Pattern,USE_TAKTSAITE_OFFSET_per)) noexcept override;
        virtual void property_changed(AT_(Pattern,USE_TAKTSAITE_MUTE_per)) noexcept override;
        void set_use_takt_offset_per_mode() noexcept;
        void set_use_taktsaite_offset_per_mode() noexcept;
        void set_use_taktsaite_mute_per_mode() noexcept;

    private slots:
        // Exclusive Box für Level_Type_Tab
        void on_pb_use_taktoffset_linear_clicked() noexcept;
        void on_pb_use_taktsaitemute_linear_clicked() noexcept;
        void on_pb_use_taktsaiteoffset_linear_clicked() noexcept;
        void on_pb_use_taktoffset_song_clicked() noexcept;
        void on_pb_use_taktsaitemute_song_clicked() noexcept;
        void on_pb_use_taktsaiteoffset_song_clicked() noexcept;

        //! Aktiviert alle Pattern mute timers
        void on_pb_mute_all_pattern_timer_clicked() noexcept;

        //! Filemanagement
        void on_pb_open_filmanager_clicked() noexcept;

        void on_pb_maximize_clicked() noexcept;

        //! Start Cleanup
        virtual void closeEvent(QCloseEvent*) noexcept override;

        //! Taktchaining *******************************************************************
    private:
        virtual void property_changed(AT_(Temporary,IS_TAKTCHAIN_SET_TO_ALL)) noexcept override;
    private slots:
        void on_dial_taktchain_for_time_valueChanged(int) noexcept;
        void on_pb_taktchain_auto_chain_clicked() noexcept;
        void on_pb_taktchain_equal_to_master_clicked() noexcept;
        void on_dial_taktchain_next_valueChanged(int) noexcept;
        void on_pb_taktchain_auto_level_clicked() noexcept;
        void on_dial_taktchain_next_level_valueChanged(int) noexcept;
        void on_pb_taktchain_set2all_clicked() noexcept;

        void set_taktchain_set_to_all() noexcept;
    private:
        virtual void property_changed(AT_(Temporary,SELECTED_TAKTCHAIN)) noexcept override;
        void set_taktchain_next() noexcept;
        void set_taktchain_for() noexcept;
        void set_taktchain_next_level() noexcept;

    private:
        //! DRAGnDROP *******************************************************************
        MainwindowClipboard _clipboard;
        //! Doc drop
        MainwindowQuestionMark _questmark;
    };

    inline void Mainwindow
    ::notify_extern_clock() noexcept
    {
        //  ABKOPPELN VON ZEIT-KRITISCHEN THREADS IN DEN MAINLOOP
        QMetaObject::invokeMethod(this,
                                  "blink_bpm_label",
                                  Qt::ConnectionType::QueuedConnection);
    }

}
#endif  // CYTHAR_GUI_MAINWINDOW_H_INCLUDED
