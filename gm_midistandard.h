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

#ifndef GM_MIDISTANDARD_H_INCLUDED
#define GM_MIDISTANDARD_H_INCLUDED

#include <stdint.h>

/*
 *   - BEFEHLE: Die erste Spalte enthält den Namen den MIDI-Befehles in „GROSSBUCHSTABEN“. Der Punkt „CONTROL
 *     CHANGE“ ist unterteilt, da unter diesem Befehl 127 verschiedene Controller verwaltet werden. Die Controller-Namen
 *     stehen in „kleinbuchstaben“.
 *   - CONTROLLER: Es sind insgesamt 127 Controller definiert. Die jeweilige Nummer wird durch das erste Datenbyte reprä-
 *     sentiert. Die Controller-Nummern 0 - 31 und 32 - 63 sind für (Schiebe-)Regler vorgesehen. Da hier meist eine feinere
 *     Abstufung als die üblichen 127 Schritte gewünscht ist, werden jeweils zwei Controller-Nummern zu einem Zweck zusam-
 *     mengefasst (0/32, 1/33, 2/34, ... 31/63). So bilden z.B. die Controller 0 und 32 den BANK SELECT Befehl. Einige Con-
 *     troller sind noch nicht vergeben.
 *   - Die Befehle für omni-, poly- und mono-mode finden heute kaum mehr Verwendung, da alle gängigen Instrumente multi-
 *     mode fähig sind.
 */

#include <array>

namespace gm_standard
{
    enum GM_1st : uint8_t
    {
        /** 1st BYTES */
        // NOTE ON          1000cccc 128 80  Tonhöhe 0-127  anschlag 0-127
        // NOTE OFF         1001cccc 144 90  Tonhöhe 0-127  loslassen 0-127 selten benutzt
        // KEY PRESSURE     1010cccc 160 A0  Tonhöhe 0-127  druck 0-127

        // PROGRAMM CHANGE  1100cccc 192 C0  0-127
        // CHANNEL PRESSURE 1101cccc 208 D0H Anschlag-Tempo
        // PITCH BENDING    1110cccc 224 E0H 0-127          0-127   zwei kombinierte Werte (1+2) für höhere Auflösung

        NOTE_ON             = 144,
        NOTE_OFF            = 128,
        KEY_PRESSURE        = 160,

        CONTROL_CHANGE      = 176,

        PROGRAMM_CHANGE     = 192,
        CHANNEL_PRESSURE    = 208,
        PITCH_BENDING       = 224,

        // SYSTEM EXLUSIVE  11110000 240 F0 SONG POSITION 11110010 242 F2 0-127 0-127 Sequencer Steuerung
        // SONG SELECT      11110011 143 F3 0-127 Sequencer Steuerung
        // TUNE REQUEST     11110110 246 F6 für analoge Synthesizer
        // END OF EXLUSIVE  11110111 247 F7 End of System Exclusive
        // TIMING CLOCK     11110000 248 F8 Sequencer Steuerung
        // START            11111010 250 FA Sequencer Steuerung
        // CONTINUE         11111011 251 FB Sequencer Steuerung
        // STOP             11111100 252 FC	Sequencer Steuerung

        // ACTIVE SENSING   11111110 254 FE Sequencer Steuerung
        // RESET            11111111 255 FF Sequencer Steuerung

        SYSTEM_EXLUSIVE     = 240,
        SONG_SELECT         = 243,
        TUNE_REQUEST        = 246,
        END_OF_EXLUSIVE     = 247,
        TIMING_CLOCK        = 248,
        START               = 250,
        CONTINUE            = 251,
        STOP                = 252,

        ACTIVE_SENSING      = 254,
        RESET               = 255
    };

    enum GM_2nd : uint8_t
    {
        /** CONTROL CHANGE 2nd BYTES */
        // bank select MSB  1011cccc 176 BO  0              herstellerabhängig
        // modulation       1011cccc 176 BO  1              0-127
        // breath control   1011cccc 176 BO  2              0-127
        // foot control     1011cccc 176 BO  4              0-127
        // portamento time  1011cccc 176 BO  5              0-127
        // data entry       1011cccc 176 BO  6              0-127
        // main volume      1011cccc 176 BO  7              0-127
        // balance          1011cccc 176 BO  8              0-127
        // panorama         1011cccc 176 BO  10             0-127
        // expression       1011cccc 176 BO  11             0-127
        // bank select LSB  1011cccc 176 BO  32
        // sustain pedal    1011cccc 176 BO  64             0 (aus), 127 (an)
        // portamento       1011cccc 176 BO  65             0 (aus), 127 (an)
        // sostenuto pedal  1011cccc 176 BO  66             0 (aus), 127 (an)
        // soft pedal       1011cccc 176 BO  67             0 (aus), 127 (an)
        // extern efx depth 1011cccc 176 BO  91             0-127
        // tremolo depht    1011cccc 176 BO  92             0-127
        // chorus deüpth    1011cccc 176 BO  93             0-127
        // detune depth     1011cccc 176 BO  94             0-127
        // phaser depth     1011cccc 176 BO  95             0-127
        // data increment   1011cccc 176 BO  96             0-127
        // data decrement   1011cccc 176 BO  97             0-127
        // sound off        1011cccc 176 BO  120            0
        // reset all contr. 1011cccc 176 BO  121            0
        // local control    1011cccc 176 BO  122            0 (aus), 127 (an)
        // all notes off    1011cccc 176 BO  123            0
        // omni off         1011cccc 176 BO  124            0 all notes off
        // omni on          1011cccc 176 BO  125            0 all notes off
        // mono mode        1011cccc 176 BO  126
        // poly mode        1011cccc 176 BO  127


        BANC_SELECT_MSB     = 0,
        MODULATION          = 1,
        BREATH_CONTROL      = 2,
        // EMPTY
        FOOT_CONTROL        = 4,
        PORTAMENTO_TIME     = 5,
        DATA_ENTRY          = 6,
        MAIN_VOLUME         = 7,
        BALANCE             = 8,
        // EMPTY
        PANORAMA            = 10,
        EXPRESSION          = 11,

        BANC_SELECT_LSB     = 32,

        SUSTAIN_PEDAL       = 64,       SUSTAIN_PEDAL_OFF = 0,      SUSTAIN_PEDAL_ON = 127,
        PORTAMENTO          = 65,       PORTAMENTO_OFF = 0,         PORTAMENTO_ON = 127,
        SOSTENUTO_PEDAL     = 66,       SOSTENUTO_PEDAL_OFF = 0,    SOSTENUTO_PEDAL_ON = 127,
        SOFT_PEDAL          = 67,       SOFT_PEDAL_OFF = 0,         SOFT_PEDAL_ON = 127,

        EXTERN_EFX_DEPTH    = 91,
        TREMOLO_DEPTH       = 92,
        CHORUS_DEPTH        = 93,
        DETUNE_DEPTH        = 94,
        PHASER_DEPTH        = 95,
        DATA_INCREMENT      = 96,
        DATA_DECREMENT      = 97,

        SOUND_OFF           = 120,
        RESET_ALL_CTRL      = 121,
        LOCAL_CONTROL       = 122,      LOCAL_CONTROL_OFF = 0,      LOCAL_CONTROL_ON = 127,
        ALL_NOTES_OFF       = 123,
        OMNI_OFF            = 124,
        OMNI_ON             = 125,
        POLY_MODE_ON        = 126,      POLY_MODE_OFF = 127,
        MONO_MODE_ON        = 127,      MONO_MODE_OFF = 126
    };

    //! Standardnoten.
    static const std::array<std::string,128> halftone2str{{
        {"C-2"},
        {"C#-2"},
        {"D-2"},
        {"D#-2"},
        {"E-2"},
        {"F-2"},
        {"F#-2"},
        {"G-2"},
        {"G#-2"},
        {"A-2"},
        {"A#-2"},
        {"B-2"},
        {"C-1"},
        {"C#-1"},
        {"D-1"},
        {"D#-1"},
        {"E-1"},
        {"F-1"},
        {"F#-1"},
        {"G-1"},
        {"G#-1"},
        {"A-1"},
        {"A#-1"},
        {"B-1"},
        {"C"},
        {"C#"},
        {"D"},
        {"D#"},
        {"E"},
        {"F"},
        {"F#"},
        {"G"},
        {"G#"},
        {"A1"},
        {"A#1"},
        {"B1"},
        {"C2"},
        {"C#2"},
        {"D2"},
        {"D#2"},
        {"E2"},
        {"F2"},
        {"F#2"},
        {"G2"},
        {"G#2"},
        {"A2"},
        {"A#2"},
        {"B2"},
        {"C3"},
        {"C#3"},
        {"D3"},
        {"D#3"},
        {"E3"},
        {"F3"},
        {"F#3"},
        {"G3"},
        {"G#3"},
        {"A3"},
        {"A#3"},
        {"B3"},
        {"C4"},
        {"C#4"},
        {"D4"},
        {"D#4"},
        {"E4"},
        {"F4"},
        {"F#4"},
        {"G4"},
        {"G#4"},
        {"A4"},
        {"A#4"},
        {"B4"},
        {"C5"},
        {"C#5"},
        {"D5"},
        {"D#5"},
        {"E5"},
        {"F5"},
        {"F#5"},
        {"G5"},
        {"G#5"},
        {"A5"},
        {"A#5"},
        {"B6"},
        {"C6"},
        {"C#6"},
        {"D6"},
        {"D#6"},
        {"E6"},
        {"F6"},
        {"F#6"},
        {"G6"},
        {"G#6"},
        {"A6"},
        {"A#6"},
        {"B7"},
        {"C7"},
        {"C#7"},
        {"D7"},
        {"D#7"},
        {"E7"},
        {"F7"},
        {"F#7"},
        {"G7"},
        {"G#7"},
        {"A7"},
        {"A#7"},
        {"B8"},
        {"C8"},
        {"C#8"},
        {"D8"},
        {"D#8"},
        {"E8"},
        {"F8"},
        {"F#8"},
        {"G8"},
        {"G#8"},
        {"A8"},
        {"A#8"},
        {"B9"},
        {"C9"},
        {"C#9"},
        {"D9"},
        {"D#9"},
        {"E9"},
        {"F9"},
        {"F#9"},
        {"G9"}}};


    //! Drumbezeichnungen Abkürzungen.
    static const std::array<std::string,128> halftone2short_drum_str{{
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"BD2"},
        {"BD"},
        {"Rim"},
        {"SN"},
        {"HC"},
        {"SN2"},
        {"lT2"},
        {"CH"},
        {"lT"},
        {"PH"},
        {"mT2"},
        {"OH"},
        {"mT"},
        {"hT2"},
        {"C"},
        {"hT"},
        {"RC"},
        {"CC"},
        {"RB"},
        {"Tam"},
        {"SC"},
        {"Cow"},
        {"C2"},
        {"vSl"},
        {"RC2"},
        {"hB"},
        {"lB"},
        {"mhC"},
        {"ohC"},
        {"lC"},
        {"hTi"},
        {"lTi"},
        {"hAg"},
        {"lAg"},
        {"Cab"},
        {"Mar"},
        {"sW"},
        {"lgW"},
        {"sG"},
        {"lgG"},
        {"Clv"},
        {"hWB"},
        {"lWB"},
        {"mCu"},
        {"oCu"},
        {"mTr"},
        {"oTr"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"}}};


    //! Drumbezeichnungen ausgeschrieben.
    static const std::array<std::string,128> halftone2full_drum_str{{
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"Bass Drum 2"},
        {"Bass Drum"},
        {"Side Stick/Rimshot"},
        {"Snare Drum"},
        {"Hand Clap"},
        {"Snare Drum 2"},
        {"Low Tom 2"},
        {"Closed Hi-hat"},
        {"Low Tom"},
        {"Pedal Hi-hat"},
        {"Mid Tom 2"},
        {"Open Hi-hat"},
        {"Mid Tom"},
        {"High Tom 2"},
        {"Crash Cymbal"},
        {"High Tom"},
        {"Ride Cymbal"},
        {"Chinese Cymbal"},
        {"Ride Bell"},
        {"Tambourine"},
        {"Splash Cymbal"},
        {"Cowbell"},
        {"Crash Cymbal 2"},
        {"Vibra Slap"},
        {"Ride Cymbal 2"},
        {"High Bongo"},
        {"Low Bongo"},
        {"Mute High Conga"},
        {"Open High Conga"},
        {"Low Conga"},
        {"High Timbale"},
        {"Low Timbale"},
        {"High Agogô"},
        {"Low Agogô"},
        {"Cabasa"},
        {"Maracas"},
        {"Short Whistle"},
        {"Long Whistle"},
        {"Short Güiro"},
        {"Long Güiro"},
        {"Claves"},
        {"High Wood Block"},
        {"Low Wood Block"},
        {"Mute Cuíca"},
        {"Open Cuíca"},
        {"Mute Triangle"},
        {"Open Triangle"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"},
        {"n/a"}}};

}   /// EO namespace gm_standard
#endif // GM_MIDISTANDARD_H_INCLUDED
