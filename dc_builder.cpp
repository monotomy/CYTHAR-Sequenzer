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

#include <dc_builder.h>

#include <phys_mem_disk_mediator.h>
#include <phys_database.h>

#include <midi_ports.h>
#include <dc_midi_in.h>

#include <dc_gui_step.2moc.h>
#include <dc_gui_taktsaite.2moc.h>
#include <dc_gui_patternmaster.2moc.h>
#include <dc_gui_patternsaite_mute.2moc.h>
#include <dc_gui_taktsaite_velocity.2moc.h>
#include <dc_gui_taktmaster.2moc.h>
#include <dc_gui_taktsaite_mute.2moc.h>
#include <dc_gui_stepmaster.2moc.h>
#include <dc_gui_stepeditor.2moc.h>
#include <dc_gui_midideviceeditor.2moc.h>
#include <dc_gui_tuneslidereditor.2moc.h>
#include <dc_gui_rebeca.2moc.h>
#include <dc_gui_mainwindow.2moc.h>

#include <dc_ticker_generator.h>
#include <dc_midi_message_factory.h>
#include <dc_midi_sequencer_timer.h>

#include <QApplication>
#include <QThread>
#include <QDir>

#include <dc_log_informations.h>

#include <guistuff/child_initializer.h>

#include <QFontDatabase>

#include <dc_log_informations.h>

#ifdef __MAC__
    #include <crossplatt_fontsize_fix.hpp>
#endif // __MAC__



namespace dc{

    int Builder
    ::build() noexcept
    {
        std::cout << " ----------------- CYTHAR Sequenzer ---------------" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "web:   ------- www.cythar.sequenzer.org -----------" << std::endl;
        std::cout << "forum: ---- www.forum.cythar.sequenzer.org --------" << std::endl;
        std::cout << "" << std::endl;

        build_dc();
        buildQtApp();

        return 81;
    }

    int Builder
    ::build_dc()
    {

        develINFO_(BUILD, "temporary")
        dc_objects::Temporary::singleton();

        develINFO_(BUILD, "memory data")
        dc_objects::BuildMemory::singleton();

        phys::MemPhysMediator::singleton()->read_from_phys();

        develINFO_(INIT, "timer")
        dc_midi::Timers::init_timers__after_temporary();

        develINFO_(EXEC, "rt midi out")
        dc_midi::MidiOutPortsPerApi::singleton()->init();

        develINFO_(EXEC, "rt midi in")
        dc_midi::MidiIn::singleton()->init();

        return 81;
    }

    int Builder
    ::buildQtApp()
    {
    static int argc{0};
    static char **argv{};

        develINFO_(INIT, "qt")
        _qtApp = new QApplication{argc,argv, true};

        develINFO_(SET, "style plastique") // motif, oxygen, plastique
        _qtApp->setStyle("plastique");

        develINFO_(SET, "low gui priority")
        QThread::currentThread()->setPriority(QThread::Priority::LowPriority);

        develINFO_(INIT, "gui elements")
        if( buildQtGui() == false )
            throw nullptr;

        //QFontDatabase::addApplicationFont("fonts/sans");

        return 81;
    }

    int Builder
    ::buildQtGui() noexcept
    {
        using namespace dc_gui;

        develINFO_(BUILD, "mainwindow")
        auto mainwin(Mainwindow::singleton());
        mainwin->init();

        /* Top Midle-Master */
        develINFO_(BUILD, "stepmaster")
        StepMaster_Initializer{}.initialize_at_frame(mainwin->frame_stepMaster);

        /* Top Left */
        develINFO_(BUILD, "stepeditor")
        Stepeditor_Initializer{}.initialize_at_frame(mainwin->frame_stepeditor_container);

        /* Rigth of Top Middle-Body */
        //develINFO_(BUILD, "stepeditor")
        //TaktsaiteVelocity_Initializer{}.initialize_at_frame(mainwin->frame_taktsaite_velocity);

        /* Top Middle-Body */
        develINFO_(BUILD, "steps")
        Step_Initializer{}.initialize_at_frame(mainwin->frame_chord_ofSteps_0);
        Step_Initializer{}.initialize_at_frame(mainwin->frame_chord_ofSteps_1);
        Step_Initializer{}.initialize_at_frame(mainwin->frame_chord_ofSteps_2);
        Step_Initializer{}.initialize_at_frame(mainwin->frame_chord_ofSteps_3);
        Step_Initializer{}.initialize_at_frame(mainwin->frame_chord_ofSteps_4);
        Step_Initializer{}.initialize_at_frame(mainwin->frame_chord_ofSteps_5);

        /* Rigth of Middle-Body */
        //develINFO_(BUILD, "barstring mute")
        //TaktsaiteMute_Initializer{}.initialize_at_frame(mainwin->frame_taktsaite_mute);

        /* Top Right */
        develINFO_(BUILD, "rebeca")
        Rebeca_Initializer{}.initialize_at_frame(mainwin->frame_repeateditor);

        /* Middle Midle-Master */
        develINFO_(BUILD, "barmaster")
        Taktmaster_Initializer{}.initialize_at_frame(mainwin->frame_barMaster);

        /* Buttom Left */
        develINFO_(BUILD, "pattern tuneeditor")
        Tuneslidereditor_Initializer{}.initialize_at_frame(mainwin->frame_Slidereditorcontainer);
        Tuneslider_Initializer{}.initialize_at_frame(mainwin->frame_Slidereditorcontainer);
        Tunevaluebox_Initializer{}.initialize_at_frame(mainwin->frame_tunevaluebox);

        /* Buttom Midle-Master */
        develINFO_(BUILD, "patternmaster")
        Patternmaster_Initializer{}.initialize_at_frame(mainwin->frame_patternMaster);

        /* Rigth of Middle-Body */
        //develINFO_(BUILD, "patternstring mute")
        //PatternsaiteMute_Initializer{}.initialize_at_frame(mainwin->frame_patternsaite_mute);

        /* Buttom Middle-Body */
        develINFO_(BUILD, "barstrings")
        Taktsaite_Initializer{}.initialize_at_frame(mainwin->frame_chords_inBar_0);
        Taktsaite_Initializer{}.initialize_at_frame(mainwin->frame_chords_inBar_1);
        Taktsaite_Initializer{}.initialize_at_frame(mainwin->frame_chords_inBar_2);
        Taktsaite_Initializer{}.initialize_at_frame(mainwin->frame_chords_inBar_3);
        Taktsaite_Initializer{}.initialize_at_frame(mainwin->frame_chords_inBar_4);
        Taktsaite_Initializer{}.initialize_at_frame(mainwin->frame_chords_inBar_5);

        /* Buttom Middle-Right */
        ///std::cout << "      init: patternmute ..." << std::endl;
        ///PatternsaiteMute_Initializer{}.initialize_at_frame(mainwin->frame_patternsaitemute);

        /* Buttom Right */
        develINFO_(BUILD, "mididevices")
        Midideviceeditormaster_Initializer{}.initialize_at_frame(mainwin->frame_mididevice_container);
        Midideviceeditor_Initializer{}.initialize_at_frame(mainwin->frame_mididevice_container);

#ifdef __MAC__
        crossplatt_fontsizefix::adjust_fontsize_for_mac(mainwin);
#endif // __MAC__

        return 81;
    }

    void Builder
    ::exec() noexcept
    {
        develINFO_(EXEC, "start")

        _qtApp->connect(_qtApp,
                        SIGNAL(lastWindowClosed()),
                        _qtApp,
                        SLOT(quit()) );

        dc_gui::Mainwindow::singleton()->show();

        exec_ticker_eventloop();

        develINFO_(EXEC, "qt")
        develINFO_(DONE, "cythar is running")
        _qtApp->exec();
    }

    int Builder
    ::exec_ticker_eventloop() noexcept
    {
        develINFO_(INIT, "Sequencer")
        dc_midi::Sequencer::singleton();
        develINFO_(INIT, "message fab")
        dc_midi::MessageFactory::singleton()->init();
        develINFO_(EXEC, "critical timers")
        dc_ticker::TickerOverhead::singleton()->exec();

        return 0;
    }

    int Builder
    ::end() noexcept
    {
        // CLEANUP
        dc_ticker::TickerOverhead::singleton()->stop_for_end();
#ifndef __UNIX_JACK__
        dc_midi::MidiIn::singleton()->shut_down();
        dc_midi::MidiOutPortsPerApi::singleton()->shut_down();
#endif // __UNIX_JACK__

        // Sicherheits kopie anlegen
        std::cout << "" << std::endl;
        phys::MemPhysMediator::singleton()->set_save_db_name(phys::MemPhysMediator::singleton()->project_dir() + phys::LAST_TIME_PROJECT);
        phys::MemPhysMediator::singleton()->save_2_phys();
        std::cout << "" << std::endl;




        //dc_midi::MidiOutPortsPerApi::singleton(true);
        //dc_midi::MidiIn::singleton(true);
        //phys::MemPhysMediator::singleton(true);
        //dc_midi::MessageFactory::singleton(true);
        //dc_midi::Sequencer::singleton(true);

        //dc_midi::Sequencer::singleton(true);
        //dc_objects::BuildMemory::singleton(true);
        //dc_objects::Temporary::singleton(true);

        std::cout << "" << std::endl;
        std::cout << "if you got any error - please report at www.forum.cythar.sequenzer.org" << std::endl;
#ifdef __UNIX__
        std::cout << "thanks a lot - you can close this window now..." << std::endl;
#else
        std::cout << "thanks a lot - this window will be closed automatically in 5 sec..." << std::endl;
#endif


        return 0;
    }
}   //  namespace dc
