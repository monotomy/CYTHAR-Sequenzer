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

#ifndef DC_GUI_MIDIDEVICEEDITOR_2MOC_H_INCLUDED
#define DC_GUI_MIDIDEVICEEDITOR_2MOC_H_INCLUDED

#include <dc_gui_midideviceeditormaster.uiced.h>
#include <dc_gui_midideviceeditor.uiced.h>

#include <extendQt_drag_n_drop.2moc.h>

#include <stuff/functions.h>
#include <guistuff/child_initializer.h>
#include <stuff/blockguard.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

#include <midi_ports.h>

namespace dc_gui{

    using namespace dc_objects;

    /***********************************************************************/
    //! \class  Midideviceeditor_Initializer
    /***********************************************************************/
    class Midideviceeditor;
    class Midideviceeditor_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            sum_elements    = 6,

            height          = 34,
            width           = 201,
            top_first       = 92,
            left            = 20
        };

    public:
        Midideviceeditor_Initializer() noexcept = default;
        ~Midideviceeditor_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    static constexpr int width_cb_device_normal{111};
    static constexpr int width_cb_device_large{161};

    /***********************************************************************/
    /*! \class  Midideviceeditor
        \brief  Editieren der Mididaten von einzelnen PatternSaiten
    */
    /***********************************************************************/
    class UNIQUE_guiMidideviceeditor_forPatternsaiteobserver{};

    class Midideviceeditormaster;
    class Midideviceeditor :
        public QWidget,
        public Ui::Midideviceeditor,

        public Events_blockable,

        public RelativePatternsaiteObserver_V2<UNIQUE_guiMidideviceeditor_forPatternsaiteobserver>,
        public SelectedPatternObserver_V2
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(Midideviceeditor)

        typedef RelativePatternsaiteObserver_V2<UNIQUE_guiMidideviceeditor_forPatternsaiteobserver> this_relPATTERNSAITE_OBSERVER;
        typedef SelectedPatternObserver_V2 this_selPATTERN_OBSERVER;

        friend class Midideviceeditor_Initializer;
        Midideviceeditor();
        void init() noexcept;
        void update() noexcept;
        ~Midideviceeditor() = default;

        virtual void RELATIVE_OBSERVER_CHANGED(Patternsaite) noexcept override;

        virtual void property_changed(AT_(Patternsaite,PORT_NAME)) noexcept override;
        virtual void property_changed(AT_(Patternsaite,MIDI_CHANNEL)) noexcept override;

        void last_time_scan() noexcept;
        void update_devices_from_db() noexcept;
        void set_device(int) noexcept;
        void set_channel() noexcept;

        friend class Midideviceeditormaster;
        void refresh_devices() noexcept;

    private slots:
        void on_cb_device_currentIndexChanged (int) noexcept;
        void on_cb_channel_currentIndexChanged(int) noexcept;

   private slots:
        //! Vergrösserung der cb_device Combo
        void enterEvent(QEvent *)
        {
            cb_device->setGeometry(cb_device->x(),
                                   cb_device->y(),
                                   width_cb_device_large,
                                   cb_device->height());

        }
        //! Normalisieren der Grösse von der cb_device Combo
        void leaveEvent(QEvent *)
        {
            cb_device->setGeometry(cb_device->x(),
                                    cb_device->y(),
                                    width_cb_device_normal,
                                    cb_device->height());
        }
    };

    /***********************************************************************/
    //! \class  Midideviceeditormaster_Initializer
    /***********************************************************************/
    class Midideviceeditormaster;
    class Midideviceeditormaster_Initializer :
        public guistruff::ChildInitializer
    {
        enum : int
        {
            height  = 401,
            width   = 201,
            top     = 0,
            left    = 0,
        };

    public:
        Midideviceeditormaster_Initializer() noexcept = default;
        ~Midideviceeditormaster_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    /***********************************************************************/
    /*! \class  Midideviceeditormaster
        \brief  Editieren der Mididaten von allen
    */
    /***********************************************************************/
    class Midideviceeditormaster :
        public extendQt::DRAGnDROP_QWidget,
        public Ui::Midideviceeditormaster,

        public SelectedPatternObserver_V2,

        public dc_midi::MidiOutPortsPerApiGUIInterface
    {
    Q_OBJECT
    SINGLETON_foo(Midideviceeditormaster)

        typedef SelectedPatternObserver_V2              this_selPATTERN_OBSERVER;

        friend class Midideviceeditormaster_Initializer;
        Midideviceeditormaster();
        ~Midideviceeditormaster();
        void init() noexcept;
        void update() noexcept;

    private:
        //! Um die Midideviceeditoren über ein Refresh zu informieren.
        friend class Midideviceeditor;
        std::vector<Midideviceeditor*> my_observer{};
        void attach_midideviceeditor(Midideviceeditor* midideviceeditor__) noexcept
        {
            my_observer.push_back(midideviceeditor__);
        }
        void notify_midideviceeditor_about_refresh() noexcept
        {
            for(auto midideviceeditor : my_observer)
                midideviceeditor->refresh_devices();
        }

        //! Feedback von MidiOut, dass die Ports refresht wurden
        virtual void notify_refreshed_ports() noexcept override
        {
            notify_midideviceeditor_about_refresh();
            update();
        }

    private slots:
        //! Schreibt für alle Patternsaiten den Channel und Device
        void on_pB_set2all_clicked() noexcept;
        //! -> refresh über hardware ankurbeln.
        void on_pB_refresh_clicked() noexcept;

        //! Setzt in Device Port Id
        void on_pb_set_midi_in_device_clicked() noexcept;

        void enterEvent(QEvent *)
        {
                cb_device_all->setGeometry(cb_device_all->x(),
                                           cb_device_all->y(),
                                           width_cb_device_large,
                                           cb_device_all->height());

                cb_device_in->setGeometry(cb_device_in->x(),
                                           cb_device_in->y(),
                                           width_cb_device_large,
                                           cb_device_in->height());
        }

        void leaveEvent(QEvent *)
        {
                cb_device_all->setGeometry(cb_device_all->x(),
                                           cb_device_all->y(),
                                           width_cb_device_normal,
                                           cb_device_all->height());

                cb_device_in->setGeometry(cb_device_in->x(),
                                           cb_device_in->y(),
                                           width_cb_device_normal,
                                           cb_device_in->height());
        }

    private:
        //! DRAGnDROP *******************************************************************
        //! Erstellt eine Kopie inkl. des Parent Frame.
        virtual QPixmap drag_pixmap() noexcept override;
        //! Pfad zur eigenen sub_docu
        virtual std::string doc_file_name() const noexcept override;
    };
}   /// EO namespace dc_gui

#endif // DC_GUI_MIDIDEVICEEDITOR_2MOC_H_INCLUDED
