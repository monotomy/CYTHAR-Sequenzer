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

#ifndef BLOCKGUARD_H_INCLUDED__
#define BLOCKGUARD_H_INCLUDED__

#include <class/properties.hpp>

    class Events_blockable{
    NO_COPY_NO_MOVE(Events_blockable)

        bool _are_my_events_blocked{false};

    protected:
        bool are_my_events_blocked() const noexcept{
            return _are_my_events_blocked;
        }
        //! Shortcut Makro
        #define RETURN_IF_EVENT_BLOCKED \
        if(are_my_events_blocked()) \
                return;

    private:
        friend class BlockMyEvents;
        void block_events() noexcept {_are_my_events_blocked = true;}
        void unblock_events() noexcept {_are_my_events_blocked = false;};

    protected:
        Events_blockable() noexcept = default;
        ~Events_blockable() noexcept = default;
    };

    class BlockMyEvents{
    NO_COPY_NO_MOVE(BlockMyEvents)

        Events_blockable* _events_blocked_at{nullptr};
    public:
        BlockMyEvents() = delete;
        explicit BlockMyEvents(Events_blockable*const block_events_at__) noexcept
        {
            _events_blocked_at=block_events_at__;
            block_events_at__->block_events();
        }
        //! Shortcut Makro
        #define SET_EVENT_BLOCK \
        BlockMyEvents block{this};

        ~BlockMyEvents() noexcept
        {
            if(_events_blocked_at != nullptr)
                _events_blocked_at->unblock_events();
        }
    };


#endif  // LOCKGUARD_H_INCLUDED__
