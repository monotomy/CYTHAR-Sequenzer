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

#include <dc_gui_styles.h>

#include <QPalette>

namespace dc_gui{

    //! Schraubt eine Palette zusammen
    QPalette buildButtonPalette(QColor color__, QColor text_color__) noexcept;
    QPalette buildButtonPalette(QColor color__, QColor text_color__) noexcept
    {
        QPalette palette;
        QBrush brush {color__};
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);

        QBrush textbrush {text_color__};
        palette.setBrush(QPalette::Active, QPalette::ButtonText, textbrush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, textbrush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, textbrush);


        return palette;
    }

    QPalette buildPalette(QColor, QColor, QColor) noexcept;
    QPalette buildPalette(QColor cText__, QColor  cBase__, QColor cShadow__) noexcept
    {
        QPalette palette;
        QBrush bText  {cText__};
        QBrush bBase  {cBase__};
        QBrush bShadow{cShadow__};
        bText.setStyle  (Qt::SolidPattern);
        bBase.setStyle  (Qt::SolidPattern);
        bShadow.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text,   bText);
        palette.setBrush(QPalette::Active, QPalette::Base,   bBase);
        palette.setBrush(QPalette::Active, QPalette::Shadow, bShadow);
        palette.setBrush(QPalette::Active, QPalette::Button, bBase);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, bShadow);
        palette.setBrush(QPalette::Inactive, QPalette::Text,   bText);
        palette.setBrush(QPalette::Inactive, QPalette::Base,   bBase);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, bShadow);
        palette.setBrush(QPalette::Inactive, QPalette::Button, bBase);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, bShadow);
        palette.setBrush(QPalette::Disabled, QPalette::Text,   bText);
        palette.setBrush(QPalette::Disabled, QPalette::Base,   bBase);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, bShadow);
        palette.setBrush(QPalette::Disabled, QPalette::Button, bBase);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, bShadow);

        palette.setBrush(QPalette::Active, QPalette::WindowText, bText);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, bText);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, bText);


        return palette;
    }

    //! Initalisiert die standard Paletten
    DCStyle
    ::DCStyle() noexcept :
        _uninitButtonPalette { buildButtonPalette(_uninitButtonColor, _enabledButtonColor) },
        _mutedButtonPalette  { buildButtonPalette(_mutedButtonColor, _enabledButtonColor) },
        _visibleMasterPalette{ buildButtonPalette(_visibleMasterColor, _enabledButtonColor) },
        _defaultMasterPalette{ buildButtonPalette(_defaultMasterColor, _enabledButtonColor) },
        _runningMasterPalette{ buildButtonPalette(_runningMasterColor, _blackColor) },


        _enabledButtonPalette{ buildPalette(_blackColor, _enabledButtonColor, _blackColor) },
        _overhideTrueTaktPalette { buildPalette(_blackColor, _runningMasterColor, _blackColor) },
        _overhideFalseTaktPalette{ buildPalette(_enabledButtonColor, _defaultMasterColor, _blackColor) }
    {}

    void DCStyle
    ::set_uninitButtonPalette(QWidget *const button__) const noexcept
    {
        button__->setPalette(_uninitButtonPalette);
    }

    void DCStyle
    ::set_enabledButtonPalette(QWidget *const button__) const noexcept
    {
        button__->setPalette(_enabledButtonPalette);
    }

    void DCStyle
    ::set_mutedButtonPalette(QWidget *const button__) const noexcept
    {
        button__->setPalette(_mutedButtonPalette);
    }

    void DCStyle
    ::set_visibleMasterPalette(QWidget *const button__) const noexcept
    {
        button__->setPalette(_visibleMasterPalette);
    }

    void DCStyle
    ::set_defaultMasterPalette(QWidget *const button__) const noexcept
    {
        button__->setPalette(_defaultMasterPalette);
    }

    void DCStyle
    ::set_runningMasterPalette(QWidget *const button__) const noexcept
    {
        button__->setPalette(_runningMasterPalette);
    }

    void DCStyle
    ::set_overhideTrueTaktPalette (QWidget *const box__) const noexcept
    {
        box__->setPalette(_overhideTrueTaktPalette);
    }

    void DCStyle
    ::set_overhideFalseTaktPalette(QWidget *const box__) const noexcept
    {
        box__->setPalette(_overhideFalseTaktPalette);
    }
}
