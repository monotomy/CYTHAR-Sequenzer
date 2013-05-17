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

#ifndef DC_EXPORT_TAKT_H_INCLUDED
#define DC_EXPORT_TAKT_H_INCLUDED

#include <string>
#include <cast/lexical_cast.hpp>
#include <class/properties.hpp>

#include <dc_standard_types.h>

#include <gm_midistandard.h>

namespace dc_objects
{
    class Pattern;
    class Takt;
}

namespace dc_export{

    /***********************************************************************/
    /*! \class  Takt2Tabulator

        Konvertiert einen Takt in einem Pattern zu einem Gitarrentab

        Example:

         .:: CYTHAR Sequencer :::: guitar tabexporter v.1 ::.
        ****  *********** *********** *********** ***********
        E5  |0-----0-----0-----0-----------------0-----------|
        B4  |------1-----------------1-----------------------|
        G4  |0-----------------0-----------------0-----------|
        D4  |2-----------------------2-----------------------|
        A3  |3-----------------3-----------------------------|
        E3  |------------------------------------0-----------|
        ____ ________________________________________________

         V: |115---82----127---107---------------108---------|
         V: |------105---------------105---------------------|
         V: |105---------------75----------------121---------|
         V: |75----------------------105---------------------|
         V: |120---------------90----------------------------|
         V: |------------------------------------121---------|
        ____ ________________________________________________

         L: |36----48----36----30----------------24----------|
         L: |------36----------------30----------------------|
         L: |30----------------49----------------43----------|
         L: |30----------------------30----------------------|
         L: |30----------------31----------------------------|
         L: |------------------------------------36----------|
        **** ************************************************
         ':: more information at www.cythar.sequenzer.org ::'
    */
    /***********************************************************************/
    struct Takt2Tabulator
    {
    NOT_INSTANCEABLE(Takt2Tabulator)

        //! Gibt einen Takt in Tabulatorschreibweise zurück
        static std::string convert2string(dc_objects::Pattern const*const parrent_pattern__,
                                          dc_objects::Takt const*const takt_to_export__) noexcept;

    private:
        //! Erweitert den String des Wertes um Sonderzeichen, bis er die size_per_step Länge hat.
        static std::string make_fit_string(std::string const& value_string__) noexcept;

        //! Erstellt den String am Lineanfang aus dem Tunewert
        static std::string begin_line_tune_info(dc_objects::Pattern const*const parrent_pattern__,
                                                TYPE_index_child current_saite_id__) noexcept;

        //! Fügt Leerzeichen an einen String an, bis er die gewünschte Länge hat.
        static std::string make_line_begin_fit_string(std::string const& begin_value_string__,
                                                      size_t string_size__) noexcept;
    };
}

#endif // DC_EXPORT_TAKT_H_INCLUDED
