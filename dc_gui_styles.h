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

#ifndef CYTHAR_GUI_STYLEFLYWEIGHTS_H_INCLUDED
#define CYTHAR_GUI_STYLEFLYWEIGHTS_H_INCLUDED

#include <pattern/singleton.hpp>

#include <QCleanlooksStyle>
#include <QMotifStyle>
#include <QColor>

#include <QWidget>

namespace dc_gui{

    static QCleanlooksStyle *const clearstyle(new QCleanlooksStyle{});
    static QMotifStyle *const motifstyle(new QMotifStyle{});


    /**********************************************************************/
    /*! \class  DCStyle
        \brief  Sammlung von verwendeteten standartstyles

        Klasse bietet die Styleveränderung für Gui-Elemente an.
    */
    /**********************************************************************/
    #define DCSTYLE dc_gui::DCStyle::singleton()
    class DCStyle{
    SINGLETON_foo(DCStyle)

        const QColor _uninitButtonColor {140, 140, 140, 255};   // uninitalisierter Button
        const QColor _enabledButtonColor{255, 255, 255, 255};   // Button welcher initalisiert wurde und aktiv ist
        const QColor _mutedButtonColor  {60,  60,  60,  255};   // Button welcher initalisiert wurde und inaktiv ist
        const QColor _visibleMasterColor{170, 0,   0,   255};   // Markiert einen Butten, welche ein Sichtbares Element representiert
        const QColor _defaultMasterColor{120, 120, 120, 255};   // Standardfarbe für Lauflichtbuttons/Masterbuttons
        const QColor _runningMasterColor{225, 221, 184, 255};   // Standardfarbe für Lauflichtbuttons/Masterbuttons
        const QColor _blackColor        {0, 0, 0, 255};

        const QPalette _uninitButtonPalette;
        const QPalette _mutedButtonPalette;
        const QPalette _visibleMasterPalette;
        const QPalette _defaultMasterPalette;
        const QPalette _runningMasterPalette;

        const QPalette _enabledButtonPalette;
        const QPalette _overhideTrueTaktPalette;
        const QPalette _overhideFalseTaktPalette;

        //! Initalisiert die standard Paletten
        DCStyle() noexcept;
        ~DCStyle() = default;

    public:
        //! Ändert den übergebenen Buttonstyle zu Uninit
        void set_uninitButtonPalette (QWidget *const) const noexcept;
        void set_enabledButtonPalette(QWidget *const) const noexcept;
        void set_mutedButtonPalette  (QWidget *const) const noexcept;
        void set_visibleMasterPalette(QWidget *const) const noexcept;
        void set_defaultMasterPalette(QWidget *const) const noexcept;
        void set_runningMasterPalette(QWidget *const) const noexcept;

        void set_overhideTrueTaktPalette (QWidget *const) const noexcept;
        void set_overhideFalseTaktPalette(QWidget *const) const noexcept;
    };
}
#endif  // CYTHAR_GUI_STYLEFLYWEIGHTS_H_INCLUDED
