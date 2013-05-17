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

#include <dc_gui_midideviceeditor.2moc.h>

#include <midi_ports.h>
#include <dc_midi_in.h>

#include <cast/lexical_cast.hpp>

#include <dc_standard_values.h>

namespace dc_gui{

//! \class Midideviceeditor_Initializer
    void Midideviceeditor_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        for( int elements{0} ; sum_elements != elements ; ++elements )
        {
            Midideviceeditor* midideviceeditor{new Midideviceeditor{}};

            midideviceeditor->setGeometry(left,
                                          top_first + elements*height,
                                          width,
                                          height);
            midideviceeditor->setParent(parent_frame);
            midideviceeditor->init();
            midideviceeditor->setVisible(true);
        }
    }

//! \class  Midideviceeditormaster
    Midideviceeditor
    ::Midideviceeditor()
    {
        setupUi(this);


    }

    void Midideviceeditor
    ::init() noexcept
    {
    SET_EVENT_BLOCK

        Midideviceeditormaster::singleton()->attach_midideviceeditor(this);

        //  Setze channel Items
        for(TYPE_midichannel channel{0} ; channel != GM_midichannel_perDevice ; ++channel)
            cb_channel->addItem(lexical_cast<std::string>(channel+HUMAN_COUNT).c_str());

        update_devices_from_db();

        last_time_scan();
        update();
    }

    void Midideviceeditor
    ::update() noexcept
    {
        update_devices_from_db();
        set_channel();
    }

    void Midideviceeditor
    ::last_time_scan() noexcept
    {
    SET_EVENT_BLOCK
        // Sucht device in Datenbank und attacht an dieses, wenn vorhanden (jetzt angeschlossen)

    }

    void Midideviceeditor
    ::RELATIVE_OBSERVER_CHANGED(Patternsaite) noexcept
    {
        update();
    }

    void Midideviceeditor
    ::property_changed(AT_(Patternsaite,PORT_NAME)) noexcept
    {
        update_devices_from_db();
    }

    void Midideviceeditor
    ::property_changed(AT_(Patternsaite,MIDI_CHANNEL)) noexcept
    {
        set_channel();
    }

    void Midideviceeditor
    ::refresh_devices() noexcept
    {
        update_devices_from_db();
    }

    void Midideviceeditor
    ::update_devices_from_db() noexcept
    {
    SET_EVENT_BLOCK

        cb_device->clear();

        auto midi_out_ports(dc_midi::MidiOutPortsPerApi::singleton());
        auto last_port_name(relGET_(this_relPATTERNSAITE_OBSERVER, PORT_NAME));
        bool is_in_patternsaite_setted_port_plugged(midi_out_ports->is_port(last_port_name));

        unsigned int port_count{0};
        int port_name_now_at_port_count{0};
        if(midi_out_ports->size() == 0)
        {
            cb_device->addItem("Err: NO DEV FOUND");
            cb_device->setEnabled(false);
        }
        else
        {
            for(auto port : *midi_out_ports)
            {
                // Prüfen ob wo das gesetzte Gerät angeschlossen ist.
                if(is_in_patternsaite_setted_port_plugged)
                    if(last_port_name == port.second->port_name())
                        port_name_now_at_port_count = port_count;

                cb_device->addItem(port.second->status_port_name().c_str());

                ++port_count;
            }
            cb_device->setEnabled(true);
        }

        if(!is_in_patternsaite_setted_port_plugged)
        {
            std::string error_connection{"errNPlg : " + last_port_name};
            cb_device->addItem(error_connection.c_str());
            set_device(port_count);
        }
        else
            set_device(port_name_now_at_port_count);
    }

    void Midideviceeditor
    ::set_device(int port_name_now_at_port_count_) noexcept
    {
    SET_EVENT_BLOCK

        cb_device->setCurrentIndex(port_name_now_at_port_count_);
    }

    void Midideviceeditor
    ::set_channel() noexcept
    {
    SET_EVENT_BLOCK

        cb_channel->setCurrentIndex(relGET_(this_relPATTERNSAITE_OBSERVER, MIDI_CHANNEL));
    }

//!\SLOTS
    void Midideviceeditor
    ::on_cb_device_currentIndexChanged (int index_) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        auto midi_out_ports(dc_midi::MidiOutPortsPerApi::singleton());
        auto midi_out_port(midi_out_ports->midi_out_port(index_));

        relSET_(this_relPATTERNSAITE_OBSERVER, PORT_NAME, midi_out_port->port_name());
    }

    void Midideviceeditor
    ::on_cb_channel_currentIndexChanged(int channel__) noexcept
    {
    RETURN_IF_EVENT_BLOCKED

        relSET_(this_relPATTERNSAITE_OBSERVER, MIDI_CHANNEL, channel__);
    }

//! \class Midideviceeditormaster_Initializer
    void Midideviceeditormaster_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        Midideviceeditormaster* deviceeditor(Midideviceeditormaster::singleton());
        deviceeditor->setGeometry(top,left,width,height);
        deviceeditor->setParent(parent_frame);
        deviceeditor->init();
        deviceeditor->setVisible(true);
    }

//! \class  Midideviceeditormaster
    Midideviceeditormaster
    ::Midideviceeditormaster()
    {
        setupUi(this);
    }

    Midideviceeditormaster
    ::~Midideviceeditormaster()
    {
        dc_midi::MidiOutPortsPerApi::singleton()->detach_gui(this);
    }

    void Midideviceeditormaster
    ::init() noexcept
    {
        //  Setze channel Items
        for(TYPE_midichannel channel{0} ; channel != GM_midichannel_perDevice ; ++channel)
            cb_channel_all->addItem(lexical_cast<std::string>(channel+HUMAN_COUNT).c_str());

        dc_midi::MidiOutPortsPerApi::singleton()->attach_gui(this);

        update();
    }

    void Midideviceeditormaster
    ::update() noexcept
    {
        // OUT DEVICES
        cb_device_all->clear();

        auto midi_out_ports(dc_midi::MidiOutPortsPerApi::singleton());
        if(midi_out_ports->size() == 0)
        {
            cb_device_all->addItem("Err: NO DEV FOUND");
            cb_device_all->setEnabled(false);
        }
        else
        {
            for(auto port : *midi_out_ports)
                cb_device_all->addItem(port.second->status_port_name().c_str());
            cb_device_all->setEnabled(true);
        }

        // IN DEVICES
        cb_device_in->clear();
        auto port_list(dc_midi::MidiIn::singleton()->get_port_list());
        if(port_list.size() == 0)
        {
            cb_device_in->addItem("Err: NO DEV FOUND");
            cb_device_in->setEnabled(false);
        }
        else
        {
            for(auto device_name : port_list )
                cb_device_in->addItem(device_name.c_str());
            cb_device_in->setEnabled(true);
        }

        auto port_id(dc_midi::MidiIn::singleton()->port_id());
        if( port_id < port_list.size() )
            cb_device_in->setCurrentIndex(dc_midi::MidiIn::singleton()->port_id());

    }

    void Midideviceeditormaster
    ::on_pB_set2all_clicked() noexcept
    {
        auto midi_out_ports(dc_midi::MidiOutPortsPerApi::singleton());
        auto midi_out_port(midi_out_ports->midi_out_port(cb_device_all->currentIndex()));
        std::string current_port_name{midi_out_port->port_name()};

        auto selected_pattern(selOBS_(this_selPATTERN_OBSERVER));
        for(TYPE_index_child patternsaite_id{0} ; patternsaite_id!=GLOBAL_supportedSAITES ; ++patternsaite_id)
        {
            auto patternsaite(selected_pattern->patternsaite(patternsaite_id));
            patternsaite->set_property<PatternsaitePropertiesIndex::PORT_NAME>(current_port_name);
            patternsaite->set_property<PatternsaitePropertiesIndex::MIDI_CHANNEL>(cb_channel_all->currentIndex());
        }
    }

    void Midideviceeditormaster
    ::on_pB_refresh_clicked() noexcept
    {
        dc_midi::MidiOutPortsPerApi::singleton()->refresh_ports();
        update();
        notify_midideviceeditor_about_refresh();
    }

    void Midideviceeditormaster
    ::on_pb_set_midi_in_device_clicked() noexcept
    {
        dc_midi::MidiIn::singleton()->change_port_id(cb_device_in->currentIndex());
    }

    QPixmap Midideviceeditormaster
    ::drag_pixmap() noexcept
    {
        QPixmap pixmap_of_me(QPixmap::grabWidget(static_cast<QWidget*>(this->parent())));

        return std::move(pixmap_of_me);
    }

    std::string Midideviceeditormaster
    ::doc_file_name() const noexcept
    {
        return DOC_MIDIDEVICE_EDITOR;
    }
}
