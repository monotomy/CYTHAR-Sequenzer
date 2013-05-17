#!/usr/bin/make -f
# Makefile for CYTHAR-Sequenzer #
# ----------------------------- #
# Created by falkTX
#

CXX ?= g++
STRIP ?= strip

DEBUG ?= false

ifeq ($(DEBUG),true)
BUILD_FLAGS += -O0 -g
BUILD_FLAGS += -DDEBUG
else
BUILD_FLAGS += -O2 -mtune=generic
BUILD_FLAGS += -DNDEBUG
endif

BUILD_FLAGS += -D__UNIX__ -D__LINUX__ -D__UNIX_JACK__
BUILD_FLAGS += -I. -Imoced -Iuiced -I3th_party
BUILD_FLAGS += $(shell pkg-config --cflags QtCore QtGui jack)
BUILD_FLAGS += -std=gnu++0x $(CXXFLAGS)

LINK_FLAGS = $(shell pkg-config --libs QtCore QtGui jack) $(LDFLAGS)

# --------------------------------------------------------------

OBJS = \
	dc_alg_lengthmatrix.cpp.o \
	dc_builder.cpp.o \
	dc_documentation.cpp.o \
	dc_export_takt.cpp.o \
	dc_gui_filemanager.2moc.cpp.o \
	dc_gui_mainwindow.2moc.cpp.o \
	dc_gui_midideviceeditor.2moc.cpp.o \
	dc_gui_patternmaster.2moc.cpp.o \
	dc_gui_patternsaite_mute.2moc.cpp.o \
	dc_gui_rebeca.2moc.cpp.o \
	dc_gui_step.2moc.cpp.o \
	dc_gui_stepeditor.2moc.cpp.o \
	dc_gui_stepmaster.2moc.cpp.o \
	dc_gui_step_matrix.2moc.cpp.o \
	dc_gui_step_velocity.2moc.cpp.o \
	dc_gui_styles.cpp.o \
	dc_gui_taktmaster.2moc.cpp.o \
	dc_gui_taktsaite.2moc.cpp.o \
	dc_gui_taktsaite_mute.2moc.cpp.o \
	dc_gui_taktsaite_velocity.2moc.cpp.o \
	dc_gui_tuneslidereditor.2moc.cpp.o \
	dc_log_informations.cpp.o \
	dc_midi_in.cpp.o \
	dc_midi_message.cpp.o \
	dc_midi_message_factory.cpp.o \
	dc_midi_sequencer.cpp.o \
	dc_midi_sequencer_timer.cpp.o \
	dc_objectstructure.cpp.o \
	dc_ticker_generator.cpp.o \
	extendQt_drag_n_drop.2moc.cpp.o

OBJS += \
	main.cpp.o \
	midi_ports.cpp.o \
	objectstructure.cpp.o \
	phys_database.cpp.o \
	phys_mem_disk_mediator.cpp.o

OBJS += \
	moced/dc_gui_filemanager.moced.cpp.o \
	moced/dc_gui_mainwindow.moced.cpp.o \
	moced/dc_gui_midideviceeditor.moced.cpp.o \
	moced/dc_gui_patternmaster.moced.cpp.o \
	moced/dc_gui_patternsaite_mute.moced.cpp.o \
	moced/dc_gui_rebeca.moced.cpp.o \
	moced/dc_gui_stepeditor.moced.cpp.o \
	moced/dc_gui_stepmaster.moced.cpp.o \
	moced/dc_gui_step_matrix.moced.cpp.o \
	moced/dc_gui_step.moced.cpp.o \
	moced/dc_gui_step_velocity.moced.cpp.o \
	moced/dc_gui_taktmaster.moced.cpp.o \
	moced/dc_gui_taktsaite.moced.cpp.o \
	moced/dc_gui_taktsaite_mute.moced.cpp.o \
	moced/dc_gui_taktsaite_velocity.moced.cpp.o \
	moced/dc_gui_tuneslidereditor.moced.cpp.o \
	moced/extendQt_drag_n_drop.moced.cpp.o
# moced/deprecated___dc_gui_documentation.moced.cpp.o

OBJS += \
	3th_party/rtmidi-2.0.1/RtMidi.cpp.o

TARGET = cythar

# --------------------------------------------------------------

all: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

debug:
	$(MAKE) DEBUG=true

# --------------------------------------------------------------

%.cpp.o: %.cpp
	$(CXX) $< $(BUILD_FLAGS) -c -o $@

$(TARGET): $(OBJS)
	$(CXX) $^ $(LINK_FLAGS) -o $@
ifneq ($(DEBUG),true)
	$(STRIP) $@
endif
