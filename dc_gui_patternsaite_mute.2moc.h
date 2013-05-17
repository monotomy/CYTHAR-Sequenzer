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

#ifndef DC_GUI_PATTERNSAITE_MUTE_H_INCLUDED
#define DC_GUI_PATTERNSAITE_MUTE_H_INCLUDED

#include <dc_gui_patternsaite_mute.uiced.h>

#include <class/properties.hpp>
#include <stuff/blockguard.h>
#include <guistuff/child_initializer.h>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

#include <QTimer>

namespace dc_gui{

    using namespace dc_objects;

    /***********************************************************************/
    //! \class  PatternsaiteMute_Initializer
    /***********************************************************************/
    class PatternsaiteMute;
    class PatternsaiteMute_Initializer :
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
        PatternsaiteMute_Initializer() noexcept = default;
        ~PatternsaiteMute_Initializer() noexcept = default;

        void initialize_at_frame(QFrame *parent_frame) noexcept override;
    };

    class PatternsaiteMute :
        public QWidget,
        public Ui::PatternsaiteMute,

        public Events_blockable,

        public RelativePatternsaiteObserver_V2<PatternsaiteMute>,
        public SelecteddetailSequencerObserver_V2
    {
    Q_OBJECT
    NO_COPY_NO_MOVE(PatternsaiteMute)

        typedef RelativePatternsaiteObserver_V2<PatternsaiteMute>   this_relPATTERNSAITE_OBSERVER;
        typedef SelecteddetailSequencerObserver_V2                 this_dtlSEQUENCER_OBSERVER;

        friend class PatternsaiteMute_Initializer;
        PatternsaiteMute ();
        void init() noexcept;
        void update() noexcept;
        ~PatternsaiteMute();

        virtual void RELATIVE_OBSERVER_CHANGED(Patternsaite) noexcept override;

        virtual void property_changed(AT_(Patternsaite,IS_MUTED)) noexcept override;
        virtual void property_changed(AT_(Patternsaite,MUTE_TIME)) noexcept override;
        void set_mute_time() noexcept;
        void set_mute() noexcept;

        QTimer _mute_in_takt_timer{this};
        bool is_mute_time_blink{false};
        inline virtual void property_changed(AT_(Sequencer,TAKT_POS)) noexcept override;
    private slots:
        void blink_timer_mute() noexcept;
        void change_mute_tmer_interval() noexcept;

        void on_dial_time_valueChanged(int time_in_takt__) noexcept;
        void on_pb_clicked() noexcept;
    };

    inline void PatternsaiteMute
    ::property_changed(AT_(Sequencer,TAKT_POS)) noexcept
    {
        //  ABKOPPELN VON ZEIT-KRITISCHEN THREADS IN DEN MAINLOOP
        QMetaObject::invokeMethod(this,
                                  "change_mute_tmer_interval",
                                  Qt::ConnectionType::QueuedConnection);
    }

}

#endif // DC_GUI_PATTERNSAITE_MUTE_H_INCLUDED
