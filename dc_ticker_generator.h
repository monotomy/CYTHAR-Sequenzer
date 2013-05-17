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

#ifndef CYTHAR_TICKER_GENERATOR_H
#define CYTHAR_TICKER_GENERATOR_H

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>

#include <pattern/singleton.hpp>
#include <stddef.h>

#include <crossplatt_threading.hpp>

namespace dc_ticker
{
    using namespace dc_objects;

    /**********************************************************************/
    /*! \class Ticker
        \brief Generiert ticks am laufenden band.
    */
    /**********************************************************************/
    class TickerExternClockObserver
    {
    protected:
        TickerExternClockObserver() noexcept = default;
        ~TickerExternClockObserver() noexcept = default;

    public:
        virtual void notify_extern_clock() noexcept {};
    };
    class TickerOverhead;
    class Ticker final
    {
    SINGLETON_foo(Ticker)

        //! Timerfunktion
        long int _microsec_per_clock{0};
        bool _is_running{false};
        bool _is_master{false};
        bool _is_notifying{false};

        cross_mutex mutex_only_one_notify{};
        inline void tickLoop() noexcept;
        //! Informiert MidiOut über Clockevent
        inline void notify_subjects_clock() noexcept;
        //! Informiert Stacks und Sequenzer über neue Clock
        inline void notify_subjects_event() noexcept;
        //! Berechnet Noten für den Ersten Step, wenn der Sequenzer startet
        inline void notify_subjects_event_at_start() noexcept;

        Ticker() noexcept;
        ~Ticker() noexcept;

        friend class TickerOverhead;
        void init() noexcept;

        void set_intervall(TYPE_clockspeed_inBPM_x_100) noexcept;
        void start_clock_gen() noexcept;
        void stop_clock_gen() noexcept;
        void set_notifying(bool) noexcept;
        void set_master(bool) noexcept;
    public:
        inline void extern_clock() noexcept;

        TickerExternClockObserver* _extern_clock_observer{nullptr};
        void attach_extern_clock_observer(TickerExternClockObserver* observer__) noexcept
        {
            _extern_clock_observer = observer__;
        }
    };

    /**********************************************************************/
    /*! \class TickerOverhead
        \brief Verwaltung für Ticker
    */
    /**********************************************************************/
    class TickerOverhead final :
        public SelecteddetailProjectObserver_V2
    {
    SINGLETON_foo(TickerOverhead)

        typedef SelecteddetailProjectObserver_V2    this_dtlPROJECT_OBSERVER;

        TickerOverhead() noexcept;
        ~TickerOverhead() noexcept;
    public:
        void exec() noexcept;

        void stop_for_end() noexcept;

    private:
        void init() noexcept;

        virtual void property_changed(AT_(Project,IS_MASTER)) noexcept override;
        virtual void property_changed(AT_(Project,CLOCKSPEED_inBPM_x_100)) noexcept override;
        virtual void property_changed(AT_(Temporary,IS_NOTFYING)) noexcept override;

    public:
        void restart() noexcept;
    };
}

#include <dc_ticker_generator.hpp>

#endif  // CYTHAR_TICKER_GENERATOR_H
