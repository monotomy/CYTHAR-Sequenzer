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

#include <dc_ticker_generator.h>

namespace dc_ticker{

    Ticker
    ::Ticker() noexcept
    {
    }

    Ticker
    ::~Ticker() noexcept
    {
        //stop_clock_gen();
    }

    void Ticker
    ::init() noexcept
    {
    }

    void Ticker
    ::set_intervall(TYPE_clockspeed_inBPM_x_100 bpm_x_100_) noexcept
    {
        _microsec_per_clock = bpm_to_microsec(float{bpm_x_100_}/100);
    }

    void Ticker
    ::start_clock_gen() noexcept
    {
        // -> start paralell thread
        if(_is_running == true)
            return;
        else
        {
            _is_running = true;
            cross_thread ticklooper(&dc_ticker::Ticker::tickLoop, this);

            ticklooper.detach();
        }
    }

    void Ticker
    ::stop_clock_gen() noexcept
    {
        _is_running = false;
    }

    void Ticker
    ::set_notifying(bool status__) noexcept
    {
        _is_notifying = status__;
        if(_is_master == true)
            start_clock_gen();
    }

    void Ticker
    ::set_master(bool status__) noexcept
    {
        _is_master = status__;
    }

//!\class TickerOverhead
    TickerOverhead
    ::TickerOverhead() noexcept
    {
        init();
    }

    TickerOverhead
    ::~TickerOverhead() noexcept
    {
    }

    void TickerOverhead
    ::stop_for_end() noexcept
    {
        Ticker::singleton()->stop_clock_gen();
        Ticker::singleton()->set_notifying(false);
        Ticker::singleton()->set_master(false);
    }

    void TickerOverhead
    ::exec() noexcept
    {
        Ticker::singleton()->start_clock_gen();
    }

    void TickerOverhead
    ::init() noexcept
    {
        Ticker::singleton()->set_master(selGET_(this_dtlPROJECT_OBSERVER,IS_MASTER));
        Ticker::singleton()->set_intervall(selGET_(this_dtlPROJECT_OBSERVER,CLOCKSPEED_inBPM_x_100));
        Ticker::singleton()->set_notifying(tmpGET_(IS_NOTFYING));
    }

    void TickerOverhead
    ::property_changed(AT_(Project,IS_MASTER)) noexcept
    {
        if(selGET_(this_dtlPROJECT_OBSERVER,IS_MASTER) == true)
            Ticker::singleton()->start_clock_gen();
        else
            Ticker::singleton()->stop_clock_gen();

        Ticker::singleton()->set_master(selGET_(this_dtlPROJECT_OBSERVER,IS_MASTER));
    }

    void TickerOverhead
    ::property_changed(AT_(Project,CLOCKSPEED_inBPM_x_100)) noexcept
    {
        Ticker::singleton()->set_intervall(selGET_(this_dtlPROJECT_OBSERVER,CLOCKSPEED_inBPM_x_100));
    }

    void TickerOverhead
    ::property_changed(AT_(Temporary,IS_NOTFYING)) noexcept
    {
        Ticker::singleton()->set_notifying(tmpGET_(IS_NOTFYING));
    }

    void TickerOverhead
    ::restart() noexcept
    {
        Ticker::singleton()->notify_subjects_event_at_start();
    }
}
