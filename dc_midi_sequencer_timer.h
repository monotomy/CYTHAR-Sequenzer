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

#ifndef DC_MIDI_SEQUENCER_TIMER_H_INCLUDED
#define DC_MIDI_SEQUENCER_TIMER_H_INCLUDED

#include <class/properties.hpp>
#include <pattern/singleton.hpp>

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>
#include <object_dependstrategy.h>

#include <array>

namespace dc_midi{

    using namespace dc_objects;

    class Timers;
    /**********************************************************************/
    /*! \class PatternMuteTimer

        Zählt die verbleibende Mutzeit und aktiviert/unmutet ein nicht manuel
        gemutetes Pattern auf grundlage der Sequenzerpositionen.
    */
    /**********************************************************************/
    class PatternMuteTimer :
        public AbsolutPatternObserver_V2
    {
    NO_COPY_NO_MOVE(PatternMuteTimer)

        typedef AbsolutPatternObserver_V2           this_absPATTERN_OBSERVER;

        TYPE_index_child _time_to_mute{0};

        friend class Timers;
        PatternMuteTimer() = delete;
        PatternMuteTimer(TYPE_index_child absolut_id_in_project__) noexcept;
        ~PatternMuteTimer() noexcept = default;

        //! Ändert Livetime - Reset Livetime während Timer-Laufzeit
        virtual void property_changed(AT_(Pattern,MUTE_TIME)) noexcept override;
        inline void reset_time_to_live() noexcept;

        //! Event wenn der Sequencer eine neue TAKT_POS erstellt -> calculate_mute_time()
        inline void notify_new_takt_pos() noexcept;
        inline void calculate_mute_time() noexcept;

    public:
        //! Rückgabe der verbleibenden Mutezeit
        inline auto time_to_mute_left() noexcept -> decltype(_time_to_mute);
    };

    /**********************************************************************/
    /*! \class PatternsaiteMuteTimer

        STRUCTURECHANGE : if you want use more than on project and change
                            observer automaticly, change this class!
    */
    /**********************************************************************/
    class PatternsaiteMuteTimer :
        public Patternsaite::TYPE_PropertyObserver_T
    {
    NO_COPY_NO_MOVE(PatternsaiteMuteTimer)

        typedef Patternsaite::TYPE_PropertyObserver_T TYPE_PatternsaiteObserver;

        TYPE_index_child _time_to_mute{0};
        TYPE_index_child const _parent_pattern_id;

        friend class Timers;
        PatternsaiteMuteTimer() = delete;
        PatternsaiteMuteTimer(TYPE_index_child absolut_pattern_id_in_project__,
                              TYPE_index_child absolut_patternsaite_id_in_pattern) noexcept;
        ~PatternsaiteMuteTimer() noexcept = default;

        //! Ändert Livetime - Reset Livetime während Timer-Laufzeit
        virtual void property_changed(AT_(Patternsaite,MUTE_TIME)) noexcept override;
        inline void reset_time_to_live() noexcept;

        //! Event wenn der Sequencer eine neue TAKT_POS erstellt -> calculate_mute_time()
        inline void notify_new_takt_pos() noexcept;
        inline void calculate_mute_time() noexcept;

    public:
        //! Rückgabe parent Pattern
        inline auto parent_pattern() const noexcept -> Pattern*
        {
            return tmpGET_(SELECTED_PROJECT)->pattern(_parent_pattern_id);
        }

        //! Rückgabe der verbleibenden Mutezeit
        inline auto time_to_mute_left() noexcept -> decltype(_time_to_mute);
    };


    /**********************************************************************/
    /*! \class TaktChainElement

        Wrapper fpr einen Takt und fügt die Runtime informationen hinzu.
    */
    /**********************************************************************/
    /*
    enum class ENUM_takt_chain_mode
    {
        MODE_AUTO_LOOP = -1,
        MODE_TO_MASTER = -2,
        MODE_ENDLESS = -3,
        MODE_IGNORE_THIS_LEVEL = -4
    };
    */

    class TaktChain_perPattern;
    class TaktChainElement :
        public AbsolutPatternObserver_V2,
        public SelecteddetailSequencerObserver_V2
    {
        typedef AbsolutPatternObserver_V2           this_absPATTERN_OBSERVER;
        typedef SelecteddetailSequencerObserver_V2  this_dtlSEQUENCER_OBSERVER;


        //! Von welchem Takt werden die Daten bezogen
        TYPE_index_child const _absolut_pattern_id_in_projekt;
        TYPE_index_child const _absolut_takt_id_in_pattern;

        //! Wie lang läuft der Takt
        TYPE_index_child _for_time{0};
    public:
        //! Zählt gegebenen Falls die For time, wenn nicht Endlos
        TYPE_index_child decrease_for_time () noexcept
        {
            auto parent_pattern_(tmpGET_(SELECTED_PROJECT)->pattern(_absolut_pattern_id_in_projekt));
            auto takt_in_pattern(parent_pattern_->takt(_absolut_takt_id_in_pattern));

            if(takt_in_pattern->taktchain(_chain_level)->GET_PROPERTY_(Taktchain, FOR)
               == ENUM_takt_chain_mode::MODE_ENDLESS)
                return ENUM_takt_chain_mode::MODE_ENDLESS;
            else
            {
                if(_for_time>0)
                    --_for_time;
                return _for_time;
            }

        }
        //! Gibt die For Time zurück
        TYPE_index_child for_time() const noexcept
        {
            return _for_time;
        }

    private:

        //! Aktueller Chain-Level
/// Taktchain_per_Takt
        unsigned int _chain_level{0};

   public:
        TaktChainElement(TYPE_index_child absolut_pattern_id_in_projekt_,
                         TYPE_index_child absolut_takt_id_in_pattern_) noexcept :
            _absolut_pattern_id_in_projekt{absolut_pattern_id_in_projekt_},
            _absolut_takt_id_in_pattern{absolut_takt_id_in_pattern_}
        {
            absCHANGE_(this_absPATTERN_OBSERVER, absolut_pattern_id_in_projekt_);

            reset_for_time();
        }

        TYPE_takt_chain_mode takt_chain_mode() const noexcept
        {
            auto parent_pattern_(tmpGET_(SELECTED_PROJECT)->pattern(_absolut_pattern_id_in_projekt));
            auto takt_in_pattern(parent_pattern_->takt(_absolut_takt_id_in_pattern));
                return takt_in_pattern->taktchain(_chain_level)->GET_PROPERTY_(Taktchain, NEXT);
        }

        //! Zählt den Chain Level auf und macht einen For-Time Reset,
    private:
        bool _is_ok_for_auto_loop{false};
    public:
        unsigned int current_chain_level() const noexcept
        {
            return _chain_level;
        }

        //! Wurde im AutoChain Mode "angechained"
        void chained_by_auto_loop(TYPE_index_child overwrite_chain_level_) noexcept
        {
            if(overwrite_chain_level_ == ENUM_takt_chain_level_mode::MODE_AUTO_LEVEL)
            {
                if(_chain_level+1 != Taktchain_per_Takt)
                    ++_chain_level;
                else
                    _chain_level = 0;
            }
            else
                _chain_level = overwrite_chain_level_;


            if(has_takt_velocity_values())
            {
                _is_ok_for_auto_loop = true;
            }
            else
            {
                _is_ok_for_auto_loop = false;
            }


            reset_for_time();
        }

        //! Wurde im Master Mode angechained
        void chained_by_equal2master(TYPE_index_child overwrite_chain_level_) noexcept
        {
            if(overwrite_chain_level_ == ENUM_takt_chain_level_mode::MODE_AUTO_LEVEL)
            {
                if(_chain_level+1 != Taktchain_per_Takt)
                    ++_chain_level;
                else
                    _chain_level = 0;
            }
            else
                _chain_level = overwrite_chain_level_;

            reset_for_time();
        }

        //! Wurde im Master Mode angechained
        void chained_by_absolut(TYPE_index_child overwrite_chain_level_) noexcept
        {
            if(overwrite_chain_level_ == ENUM_takt_chain_level_mode::MODE_AUTO_LEVEL)
            {
                if(_chain_level+1 != Taktchain_per_Takt)
                    ++_chain_level;
                else
                    _chain_level = 0;
            }
            else
                _chain_level = overwrite_chain_level_;

            reset_for_time();
        }

        //! Ist der Chain OK für den AUTO-LOOP-MODE
        bool is_chain_valid_for_auto_loop_mode() noexcept
        {
            bool is_valid{false};

            if(_for_time > 0 and _is_ok_for_auto_loop == true)
                is_valid = true;

            return is_valid;
        }

        bool is_chain_valid_for_equal2master() noexcept
        {
            bool is_valid{false};

            if(_for_time > 0)
                is_valid = true;

            return is_valid;
        }

        bool is_chain_valid_for_absolut() noexcept
        {
            bool is_valid{false};

            if(_for_time > 0)
                is_valid = true;

            return is_valid;
        }

        void reset() noexcept
        {
            _chain_level = 0;
            reset_for_time();
        }

    private:
        //! Setzt die _for_time vom aktuellen Chain Level
        void reset_for_time() noexcept
        {
            auto parent_pattern_(tmpGET_(SELECTED_PROJECT)->pattern(_absolut_pattern_id_in_projekt));
            auto takt_in_pattern(parent_pattern_->takt(_absolut_takt_id_in_pattern));

            _for_time = takt_in_pattern->taktchain(_chain_level)->GET_PROPERTY_(Taktchain, FOR);
        }

        bool has_takt_velocity_values() noexcept
        {
            auto parent_pattern_(tmpGET_(SELECTED_PROJECT)->pattern(_absolut_pattern_id_in_projekt));
            auto takt_in_pattern(parent_pattern_->takt(_absolut_takt_id_in_pattern));

            for(TYPE_index_child taktsaite_id{0} ; taktsaite_id != Taktsaiten_per_Takt ; ++taktsaite_id )
                for(TYPE_index_child step_id{0} ; step_id != Step_per_Taktsaite ; ++ step_id )
                {
                    auto step(takt_in_pattern->taktsaite(taktsaite_id)->step(step_id));
                    if(step->GET_PROPERTY_(Step, VELOCITY) > 0)
                        return true;
                }

            return false;
        }
    };

    class TaktChain_perPattern final :
        public AbsolutPatternObserver_V2,
        public SelecteddetailSequencerObserver_V2
    {
        typedef AbsolutPatternObserver_V2           this_absPATTERN_OBSERVER;
        typedef SelecteddetailSequencerObserver_V2  this_dtlSEQUENCER_OBSERVER;

        // Takt- Chain für absolutes pattern X
        TYPE_index_child const _absolut_pattern_id_in_projekt;
        typedef std::map<TYPE_index_child, TaktChainElement*> TYPE_takt_chain_container;
        std::map<TYPE_index_child, TaktChainElement*> _takt_chain_elements;
        TYPE_index_child _current_takt_chain_id{0};
        TYPE_index_child _current_master_takt_pos{0};

        friend class Timers;
        TaktChain_perPattern(TYPE_index_child absolut_pattern_id_in_project_) noexcept :
            _absolut_pattern_id_in_projekt{absolut_pattern_id_in_project_},
            _takt_chain_elements{build_takt_chain_elements_per_pattern(absolut_pattern_id_in_project_)}
        {
            init();
        }

        //! Erstellt Map mit TaktChainElementen
        static TYPE_takt_chain_container build_takt_chain_elements_per_pattern(TYPE_index_child absolut_pattern_id_in_project_) noexcept
        {
            TYPE_takt_chain_container takt_chain_elements{};

            // Erstellt 16 Takt-Chain elemente für diese Pattern
            for(TYPE_index_child absolut_takt_id{0} ; absolut_takt_id != Takt_per_Pattern ; ++absolut_takt_id)
                takt_chain_elements.insert({absolut_takt_id,
                                             new TaktChainElement{absolut_pattern_id_in_project_,
                                                                  absolut_takt_id}});
            return takt_chain_elements;
        }

        void init() noexcept
        {

        }

        bool has_any_takt_in_pattern_for_values() noexcept
        {
            // Prüfe ob es überhaupt elemente mit Inhalt gibt
            auto parent_pattern_(tmpGET_(SELECTED_PROJECT)->pattern(_absolut_pattern_id_in_projekt));
            for(TYPE_index_child takt_id{0} ; takt_id != Takt_per_Pattern ; ++takt_id)
            {
                auto takt(parent_pattern_->takt(takt_id));
                for(TYPE_index_child takt_chain_id{0} ; takt_chain_id < Taktchain_per_Takt; ++takt_chain_id)
                {
                    auto taktchain(takt->taktchain(takt_chain_id));
                    if(taktchain->get_property<TaktchainPropertiesIndex::FOR>() > 0)
                        return true;
                }
            }

            return false;
        }

        //! Berechnet den nächsten Takt
        void calc_next_takt_chain_element() noexcept
        {
            // Ignorieren, wenn keine Forwerte irgendwo exitieren.
            if(has_any_takt_in_pattern_for_values() == false)
                return;

            TaktChainElement *const takt_chain_element(_takt_chain_elements[_current_takt_chain_id]);

            switch (takt_chain_element->takt_chain_mode())
            {
            case  ENUM_takt_chain_mode::MODE_AUTO_LOOP :
                calc_next_not_empty_takt_pos();
                break;

            case  ENUM_takt_chain_mode::MODE_TO_MASTER :
                calc_next_equal2master_takt_pos();
                break;

            default:
                calc_absolut_next_takt_pos();
                break;
            }

        }

        void calc_next_equal2master_takt_pos() noexcept
        {
            TaktChainElement *const takt_chain_element(_takt_chain_elements[_current_takt_chain_id]);
            auto parent_pattern_(tmpGET_(SELECTED_PROJECT)->pattern(_absolut_pattern_id_in_projekt));
            auto takt_in_pattern(parent_pattern_->takt(_current_takt_chain_id));
            auto taktchain_in_takt(takt_in_pattern->taktchain(takt_chain_element->current_chain_level()));
            TYPE_index_child overwrite_chain_level{taktchain_in_takt->get_property<TaktchainPropertiesIndex::OVERWRITE_TARGET_LEVEL>()};

            if(takt_chain_element->decrease_for_time() > 0)
                ;
            else
            {

                _takt_chain_elements[_current_master_takt_pos]->chained_by_equal2master(overwrite_chain_level);
                _current_takt_chain_id = _current_master_takt_pos;
                if(_takt_chain_elements[_current_master_takt_pos]->is_chain_valid_for_equal2master() == true)
                {
                    return;
                }
                else
                {
                    calc_next_takt_chain_element();
                    return;
                }
            }
        }

        //! Berechnet den nächsten Takt im NOT-EMPTY-Mode
        void calc_next_not_empty_takt_pos() noexcept
        {
            TaktChainElement *const takt_chain_element(_takt_chain_elements[_current_takt_chain_id]);
            auto parent_pattern_(tmpGET_(SELECTED_PROJECT)->pattern(_absolut_pattern_id_in_projekt));
            auto takt_in_pattern(parent_pattern_->takt(_current_takt_chain_id));
            auto taktchain_in_takt(takt_in_pattern->taktchain(takt_chain_element->current_chain_level()));
            TYPE_index_child overwrite_chain_level{taktchain_in_takt->get_property<TaktchainPropertiesIndex::OVERWRITE_TARGET_LEVEL>()};


            if(takt_chain_element->decrease_for_time() > 0)
                ;
            else
            {
                // Suche Takt ab _current_takt_chain_id mit Velociy-Einträgen
                    for(TYPE_index_child possible_next_takt_chain_id{_current_takt_chain_id+1};
                    possible_next_takt_chain_id < Takt_per_Pattern;
                    ++possible_next_takt_chain_id)
                {
                    _takt_chain_elements[possible_next_takt_chain_id]->chained_by_auto_loop(overwrite_chain_level);
                    if(_takt_chain_elements[possible_next_takt_chain_id]->is_chain_valid_for_auto_loop_mode() == true)
                    {
                        /// FOUND VALID CHAIN
                        _current_takt_chain_id = possible_next_takt_chain_id;
                        return;
                    }
                }

                // Suche ab 0 bis _current_takt_chain_id nach Velocity-Einträgen
                for(TYPE_index_child possible_next_takt_chain_id{0};
                    possible_next_takt_chain_id != _current_takt_chain_id;
                    ++possible_next_takt_chain_id)
                {
                    _takt_chain_elements[possible_next_takt_chain_id]->chained_by_auto_loop(overwrite_chain_level);
                    if(_takt_chain_elements[possible_next_takt_chain_id]->is_chain_valid_for_auto_loop_mode() == true)
                    {
                        /// FOUND VALID CHAIN before
                        _current_takt_chain_id = possible_next_takt_chain_id;
                        return;
                    }
                }

                /// FOUND NOTHING
                _takt_chain_elements[_current_takt_chain_id]->chained_by_auto_loop(overwrite_chain_level);
                return;
            }
        }
        //! Berechnet den nächsten TAKT im RUN-TO-MASTER-MODE
        void calc_absolut_next_takt_pos() noexcept
        {
            TaktChainElement *const takt_chain_element(_takt_chain_elements[_current_takt_chain_id]);
            auto parent_pattern_(tmpGET_(SELECTED_PROJECT)->pattern(_absolut_pattern_id_in_projekt));
            auto takt_in_pattern(parent_pattern_->takt(_current_takt_chain_id));
            auto taktchain_in_takt(takt_in_pattern->taktchain(takt_chain_element->current_chain_level()));
            TYPE_index_child overwrite_chain_level{taktchain_in_takt->get_property<TaktchainPropertiesIndex::OVERWRITE_TARGET_LEVEL>()};


            if(takt_chain_element->decrease_for_time() > 0)
                ;
            else
            {

                auto possible_next_takt_chain_id(taktchain_in_takt->get_property<TaktchainPropertiesIndex::NEXT>());
                _takt_chain_elements[possible_next_takt_chain_id]->chained_by_absolut(overwrite_chain_level);
                _current_takt_chain_id = possible_next_takt_chain_id;
                if(_takt_chain_elements[possible_next_takt_chain_id]->is_chain_valid_for_absolut() == true)
                {
                    return;
                }
                else
                {
                    calc_next_takt_chain_element();
                    return;
                }
            }
        };
        //! Berechnet den nächsten TAKT im ABSOLUTE MODE

    public:
        void reset() noexcept
        {
            for(auto takt_chain : _takt_chain_elements)
            {
                takt_chain.second->reset();
            }

            _current_takt_chain_id = 0;
        }

        //! Notifymethode, stösst fortlaufende Berechnung an
        inline void notify_new_takt_pos(TYPE_index_child master_takt_pos_) noexcept
        {
            _current_master_takt_pos = master_takt_pos_;
            calc_next_takt_chain_element();
        }

        //! Gibt den aktuellen Chain Level zurück
        unsigned int current_takt_chain_level(TYPE_index_child takt_id_in_pattern_)
        {
            return _takt_chain_elements[takt_id_in_pattern_]->current_chain_level();
        }
        //! Gibt die verbleibende for zeit zurück
        unsigned int current_takt_chain_for_time(TYPE_index_child takt_id_in_pattern_)
        {
            return _takt_chain_elements[takt_id_in_pattern_]->for_time();
        }

        //! Rückgabe parent Pattern
        inline auto parent_pattern() const noexcept -> Pattern*
        {
            return tmpGET_(SELECTED_PROJECT)->pattern(_absolut_pattern_id_in_projekt);
        }
        TYPE_index_child parent_pattern_id() const noexcept
        {
            return _absolut_pattern_id_in_projekt;
        }

        //! Rückgabe parent Pattern
        inline auto current_running_takt() const noexcept -> Takt*
        {
            return tmpGET_(SELECTED_PROJECT)->pattern(_absolut_pattern_id_in_projekt)->takt(_current_takt_chain_id);
        }


        TYPE_index_child current_running_takt_id() const noexcept
        {
            return _current_takt_chain_id;
        }
    };


    /**********************************************************************/
    /*! \class Verwaltung der Timer
    */
    /**********************************************************************/
    struct Timers
    {
    NOT_INSTANCEABLE(Timers)

        static TYPE_index_child current_visible_running_takt_id() noexcept
        {
            auto selected_pattern(tmpGET_(SELECTED_PATTERN));
            for(unsigned int pattern_id{0} ; pattern_id != Pattern_per_Project ; ++pattern_id )
                if(tmpGET_(SELECTED_PROJECT)->pattern(pattern_id) == selected_pattern)
                {
                    return takt_chain[pattern_id]->current_running_takt_id();
                }


        }

        //! Je Pattern im Project einen MuteTimer
        static std::array<PatternMuteTimer*, Pattern_per_Project> pattern_mute;
        //! Je Pattern im Project 6 PatternsaitenMuteTimer
        static std::array<std::array<PatternsaiteMuteTimer*, GLOBAL_supportedSAITES>, Pattern_per_Project> patternsaite_mute;

        //! Je Pattern einen AutocChain
        static std::array<TaktChain_perPattern*, Pattern_per_Project> takt_chain;

        //! Initalisiert die Timerarrays
        static void init_timers__after_temporary() noexcept;

        static void reset_all_taktchain() noexcept
        {
            for(auto taktchain : takt_chain)
                taktchain->reset();
        }

    private:
        //! Erstellt gefüllte Arrays
        template<class TYPE_Timer, TYPE_index_child timer_to_build>
        static auto build_timer() noexcept -> std::array<TYPE_Timer*, timer_to_build>;

    private:
        friend class Sequencer;
        //! Tickt alle Timer an mit notify_new_takt_pos()
        inline static void notify_new_takt_pos(TYPE_index_child new_takt_pos__) noexcept;
    };
}

#include <dc_midi_sequencer_timer.hpp>

#endif // DC_MIDI_SEQUENCER_TIMER_H_INCLUDED
