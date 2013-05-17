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

#ifndef OBJECT_DEPENDSTRATEGY_H_INCLUDED
#define OBJECT_DEPENDSTRATEGY_H_INCLUDED

namespace object_dependstrategy{

    /***********************************************************************/
    /*! \class  Strategy

        Ändert/Liest Properties des Target Objekts in Abhängigkeit des
        im Strategie verwaltenden Objecktes (host) gesetzten index eines
        Enum, welcher die möglichen Modes des Hosts repräsentiert.

    */
    /***********************************************************************/
    template<class ENUM_strategy_properties_index,                  // Properties Index im Strategie Host
             ENUM_strategy_properties_index HOST_STRATEGY_INDEX,    // Propertieindex des Host, hinter welchem die aktive Startegie zu finden ist.
             class ENUM_possible_strategies,                        // Enum, in dem die möglichen Strategien für den host zu finden sind
             class ENUM_startegie_depend_index>                     // Enum, mit den Abhängigkeitseinträgen
    class Strategy
    {
        static constexpr size_t possible_strategies{static_cast<size_t>(ENUM_possible_strategies::ENUM_CLASS_SIZE)};
        typedef std::map<ENUM_possible_strategies, ENUM_startegie_depend_index const> TYPE_strategie_depend_indices;

        //! Container, in dem die Beziehung zwischen possible strategies und abhängigen hergestellt wird,
        //! Der Key der Map ist die mögliche strategie, der inhalt die Abhängkeit.
        TYPE_strategie_depend_indices const _relations_to_strategy_index;

    public:
        Strategy(TYPE_strategie_depend_indices enum_2_index_relation__) noexcept :
            _relations_to_strategy_index(enum_2_index_relation__)
        {}

        Strategy() = delete;
        ~Strategy() = default;

        //! SET VERSION **********************************************************
        //! Schreibt in das Target eine Eigenschaft an den Abhängigen Index, der derzeit
        //! im Host gesetzten Strategie.
        template<class TYPE_strategy_property_host,
                 class TYPE_depend_property_owner,
                 typename TYPE_of_property>
        inline void set_property(TYPE_strategy_property_host const*const strategy_host__,
                                 TYPE_depend_property_owner*const relation_owner__,
                                 TYPE_of_property const property_value__) noexcept
        {
            // Rekursion für alle möglichen Eigenschaften des Targets
            set_property(strategy_host__->get_property(Loki::Int2Type<static_cast<int>(HOST_STRATEGY_INDEX)>()),
                         relation_owner__,
                         property_value__,
                         Loki::Int2Type<static_cast<int>(ENUM_startegie_depend_index::ENUM_CLASS_SIZE)-1>());
        }

    private:
        template<class TYPE_depend_property_owner,
                 typename TYPE_of_property,
                 int RELATION_INDEX>
        inline void set_property(ENUM_possible_strategies active_host_strategy_index,
                                 TYPE_depend_property_owner*const depend_property_owner__,
                                 TYPE_of_property const property_value__,
                                 Loki::Int2Type<RELATION_INDEX>) noexcept
        {
            // Vergleichsindex und ruf index
            ENUM_startegie_depend_index constexpr RECURSIVE_COMPARE_INDEX{static_cast<ENUM_startegie_depend_index>(RELATION_INDEX)};
            // Abhängiger Index, welcher zur aktiven Strategie engetragen ist
            auto  find_current_depend_index(_relations_to_strategy_index.find(active_host_strategy_index));
            ENUM_startegie_depend_index current_depend_index{};
            if(find_current_depend_index != _relations_to_strategy_index.end())
                current_depend_index = find_current_depend_index->second;
            else
                // Strategie nicht deffiniert
                return;

            // Entspricht der Vergleichsindex, dem Abhängigen Index, so kann der Vergleichindex als
            // Konstante zum setzen der Eigenschaft verwendet werden.
            if(RECURSIVE_COMPARE_INDEX == current_depend_index)
                depend_property_owner__->set_property<RECURSIVE_COMPARE_INDEX>(property_value__);
            else
                // Anderen Falls Rekursion, bis der Index Gefunden wird.
                set_property(active_host_strategy_index,
                             depend_property_owner__,
                             property_value__,
                             Loki::Int2Type<RELATION_INDEX-1>());
        }

        //! Rekusrionsende, kein Abhängigkeitseintag zum aktiven Strategieindex gefunden
        template<class TYPE_depend_property_owner,
                 typename TYPE_of_property>
        inline void set_property(ENUM_possible_strategies,
                                 TYPE_depend_property_owner*const,
                                 TYPE_of_property const,
                                 Loki::Int2Type<-1>) noexcept
        {
            #ifdef DEBUG
                std::cout << "DEPEND INDEX not listet" << std::endl;
            #endif // DEBUG
        }

    public:
        //! GET VERSION **********************************************************
        //! Schreibt in das Target eine Eigenschaft an den Abhängigen Index, der derzeit
        //! im Host gesetzten Strategie.
        template<typename TYPE_of_return,
                 class TYPE_strategy_property_host,
                 class TYPE_depend_property_owner
        >
        inline auto get_property(TYPE_strategy_property_host const*const strategy_host__,
                                 TYPE_depend_property_owner const*const relation_owner__) const noexcept
        -> TYPE_of_return
        {
            // Rekursion für alle möglichen Eigenschaften des Targets
            return get_property<TYPE_of_return>(strategy_host__->get_property(Loki::Int2Type<static_cast<int>(HOST_STRATEGY_INDEX)>()),
                                                relation_owner__,
                                                Loki::Int2Type<static_cast<int>(ENUM_startegie_depend_index::ENUM_CLASS_SIZE)-1>());
        }

    private:
        template<typename TYPE_of_return,
                 class TYPE_depend_property_owner,
                 int RELATION_INDEX
        >
        inline auto get_property(ENUM_possible_strategies active_host_strategy_index,
                                 TYPE_depend_property_owner const*const depend_property_owner__,
                                 Loki::Int2Type<RELATION_INDEX>) const noexcept
        -> TYPE_of_return
        {
            // Vergleichsindex und ruf index
            ENUM_startegie_depend_index constexpr RECURSIVE_COMPARE_INDEX{static_cast<ENUM_startegie_depend_index>(RELATION_INDEX)};
            // Abhängiger Index, welcher zur aktiven Strategie engetragen ist
            auto  find_current_depend_index(_relations_to_strategy_index.find(active_host_strategy_index));
            ENUM_startegie_depend_index current_depend_index{};
            if(find_current_depend_index != _relations_to_strategy_index.end())
                current_depend_index = find_current_depend_index->second;
            else
            {
            #ifdef DEBUG
                std::cout << "DEPEND INDEX not listet" << std::endl;
            #endif // DEBUG
                // Strategie nicht deffiniert
                return 0;
            }

            // Entspricht der Vergleichsindex, dem Abhängigen Index, so kann der Vergleichindex als
            // Konstante zum lesen der Eigenschaft verwendet werden.
            if(RECURSIVE_COMPARE_INDEX == current_depend_index)
                return depend_property_owner__->get_property<RECURSIVE_COMPARE_INDEX>();
            else
                // Anderen Falls Rekursion, bis der Index gefunden wird.
                return get_property<TYPE_of_return>(active_host_strategy_index,
                                                    depend_property_owner__,
                                                    Loki::Int2Type<RELATION_INDEX-1>());
        }

        //! Rekusrionsende, kein Abhängigkeitseintag zum aktiven Strategieindex gefunden
        template<typename TYPE_of_return, class TYPE_depend_property_owner>
        inline auto get_property(ENUM_possible_strategies,
                                 TYPE_depend_property_owner const*const,
                                 Loki::Int2Type<-1>) const noexcept
        -> TYPE_of_return
        {
            #ifdef DEBUG
                std::cout << "DEPEND INDEX not listet" << std::endl;
            #endif // DEBUG

            return 0;
        }
    };

    #define DEPEND_RELATION_(ARG_ENUM_STRATEGY_INDEX, ARG_DEPEND_TARGET_INDEX) \
    {ARG_ENUM_STRATEGY_INDEX, ARG_DEPEND_TARGET_INDEX}

    #define STRATEGY_(...) \
    { __VA_ARGS__ }

}

using namespace object_dependstrategy;

#endif // OBJECT_DEPENDSTRATEGY_H_INCLUDED
