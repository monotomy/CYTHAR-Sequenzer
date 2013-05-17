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

#include <dc_gui_taktsaite_velocity.2moc.h>

#include <dc_gui_styles.h>

#include <cast/lexical_cast.hpp>

namespace dc_gui{

//! \class TaktsaiteVelocity_Initializer
    void TaktsaiteVelocity_Initializer::
    initialize_at_frame(QFrame *parent_frame) noexcept
    {
        for( int elements{0} ; sum_elements != elements ; ++elements )
        {
            TaktsaiteVelocity* taktsaite_mute{new TaktsaiteVelocity{}};

            taktsaite_mute->setGeometry(left,
                                      top_first + elements*height,
                                      width,
                                      height);
            taktsaite_mute->setParent(parent_frame);
            taktsaite_mute->setVisible(true);
            //patternsaite_mute->init();
        }
    }

//!\class TaktsaiteVelocity
    TaktsaiteVelocity
    ::TaktsaiteVelocity()
    {
        setupUi(this);

        dial_time->setStyle(motifstyle);

        //DCSTYLE->set_mutedButtonPalette(pb);
    }

    void TaktsaiteVelocity
    ::on_dial_time_valueChanged(int) noexcept
    {
        //pb->setText(any2string(time_in_takt__).c_str());
    }

}
