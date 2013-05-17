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

#ifndef PHYS_MEM_DISK_MEDIATOR_HPP_INCLUDED
#define PHYS_MEM_DISK_MEDIATOR_HPP_INCLUDED

#include <cast/lexical_cast.hpp>

#include <tuple>

namespace phys{

//!\class MemPhysMediator
    inline std::string MemPhysMediator
    ::build_level_key(std::string const& until_parent__key__,
                      TYPE_index_child child_id_in_parent__,
                      std::string const& child_key__) const noexcept
    {
        return until_parent__key__
               +lexical_cast<std::string>(child_id_in_parent__)
               +child_key__;
    }

    inline std::string MemPhysMediator
    ::build_property_key(std::string const& level_key__,
                         std::string const& property_key__) const noexcept
    {
        return level_key__ + property_key__;
    }

//! READ **********************************************************
    template<class TYPE_properties_owner>
    inline void MemPhysMediator
    ::read_properties_fromDb_2(Database* db__,
                               TYPE_properties_owner* properties_owner__,
                               std::string const& this_level_key__) noexcept
    {
        typedef decltype(properties_owner__->data_container()) TYPE_data_container;
        TYPE_data_container properties_data_container;
        for(size_t property{0};
            property!= properties_owner__->_ENTITY_NAMES.size();
            ++property )
        {
            properties_data_container[property]
            = db__->get_entity(build_property_key(this_level_key__,
                                                  properties_owner__->_ENTITY_NAMES[property]));
        }

        properties_owner__->set_data_container(properties_data_container);
    }

    template<class TYPE_for_child,
             class TYPE_child_owner
    >
    inline void MemPhysMediator
    ::exec_read_child_properties_from_db_2(Database* db__,
                                          TYPE_child_owner * child_owner__,
                                          std::string const& parent_key_list__) noexcept
    {
        TYPE_index_child count_our_id{0};

        auto childs_in_object(child_owner__->begin(Loki::Type2Type<TYPE_for_child>()));
        std::string level_key{};
        while(childs_in_object != child_owner__->end(Loki::Type2Type<TYPE_for_child>()))
        {
            level_key = build_level_key(parent_key_list__,count_our_id,(*childs_in_object)->_KEY_NAME);

            // Properties des Child lesen
            read_properties_fromDb_2(db__,
                                     (*childs_in_object),
                                     level_key);

            // Rekursion für alle ChildChilds der Typeliste
            typedef typename TYPE_for_child::TYPELIST_childs TYPELIST_childs_ofChild_T;
            static constexpr int child_typelist_size(std::tuple_size<TYPELIST_childs_ofChild_T>::value);
            // ChildChilds auffordern daten seines childs zu schreiben
            exec_read_child_child_properties_from_db_2(db__,
                                                       (*childs_in_object),
                                                       level_key,
                                                       Loki::Int2Type<child_typelist_size-1>());
            ++count_our_id;
            ++childs_in_object;
        }
    }

    template<class TYPE_child_owner,
             int TYPELIST_ID_current_Child
    >
    inline void MemPhysMediator
    ::exec_read_child_child_properties_from_db_2(Database* db__,
                                                 TYPE_child_owner* parent__,
                                                 std::string const& parent_key_list__,
                                                 Loki::Int2Type<TYPELIST_ID_current_Child>) noexcept
    {
        typedef typename std::remove_reference<TYPE_child_owner>::type TYPE_parent;
        typedef typename TYPE_parent::TYPELIST_childs TYPELIST_childs;
        typedef typename std::tuple_element<TYPELIST_ID_current_Child, TYPELIST_childs>::type TYPE_current_child;

        // Lesen der Properties des Childs
        exec_read_child_properties_from_db_2<typename TYPE_current_child::TYPE_child_T>(db__,
                                                                                        static_cast<TYPE_current_child const*>(parent__),
                                                                                        parent_key_list__);
        // Rekursiver selbstruf
        exec_read_child_child_properties_from_db_2(db__,
                                                   parent__,
                                                   parent_key_list__,
                                                   Loki::Int2Type<TYPELIST_ID_current_Child-1>());
    }

    template<class TYPE_child_owner>
    inline void MemPhysMediator
    ::exec_read_child_child_properties_from_db_2(Database*,
                                                 TYPE_child_owner*,
                                                 std::string const&,
                                                 Loki::Int2Type<-1>) noexcept
    {
        // Done
    }

//! WRITE *********************************************************
    template<class TYPE_properties_owner>
    inline void MemPhysMediator
    ::write_properties_2_db_from(Database* db__,
                                 TYPE_properties_owner const* properties_owner__,
                                 std::string const& this_level_key__) noexcept
    {
        std::string current_key{};
        auto properties_data_container(properties_owner__->data_container());
        for(size_t property{0};
            property!= properties_data_container.size();
            ++property )
        {
            db__->replace_entity(build_property_key(this_level_key__,
                                                    properties_owner__->_ENTITY_NAMES[property]),
                                 properties_data_container[property]);
        }
    }

    template<class TYPE_for_child,
             class TYPE_child_owner
    >
    inline void MemPhysMediator
    ::exec_write_child_properties_2_db_for(Database * db__,
                               TYPE_child_owner const* child_owner,
                               std::string const& parent_key_list__) noexcept
    {
        TYPE_index_child count_our_id{0};
        std::string level_key{};
        auto childs_in_object(child_owner->begin(Loki::Type2Type<TYPE_for_child>()));
        while(childs_in_object != child_owner->end(Loki::Type2Type<TYPE_for_child>()))
        {
            level_key = build_level_key(parent_key_list__,
                                        count_our_id,
                                        (*childs_in_object)->_KEY_NAME);
            // Properties des child schreiben
            write_properties_2_db_from(db__,
                                       (*childs_in_object),
                                        level_key);


            // Rekursion für alle ChildChilds der Typeliste
            typedef typename TYPE_for_child::TYPELIST_childs TYPELIST_childs_ofChild_T;
            static constexpr int child_typelist_size(std::tuple_size<TYPELIST_childs_ofChild_T>::value);

            // ChildChilds auffordern Properties ihrer childs zu schreiben
            exec_write_child_child_properties_2_db_from(db__,
                                                        (*childs_in_object),
                                                        level_key,
                                                        Loki::Int2Type<child_typelist_size-1>());
            ++count_our_id;
            ++childs_in_object;
        }
    }

    template<class TYPE_child_owner,
             int TYPELIST_current_Child_ID
    >
    inline void MemPhysMediator
    ::exec_write_child_child_properties_2_db_from(Database * db__,
                                                  TYPE_child_owner const* parent__,
                                                  std::string const& parent_key_list__,
                                                  Loki::Int2Type<TYPELIST_current_Child_ID>) noexcept
    {
        typedef typename std::remove_reference<TYPE_child_owner>::type TYPE_parent;
        typedef typename TYPE_parent::TYPELIST_childs TYPELIST_childs;
        typedef typename std::tuple_element<TYPELIST_current_Child_ID, TYPELIST_childs>::type TYPE_current_child;

        exec_write_child_properties_2_db_for<typename TYPE_current_child::TYPE_child_T>(db__,
                                                                                        static_cast<TYPE_current_child const*>(parent__),
                                                                                        parent_key_list__);
        // Rekursiver selbstruf
        exec_write_child_child_properties_2_db_from(db__,
                                                    parent__,
                                                    parent_key_list__,
                                                    Loki::Int2Type<TYPELIST_current_Child_ID-1>());
    }

    template<class TYPE_child_owner>
    inline void MemPhysMediator
    ::exec_write_child_child_properties_2_db_from(Database*,
                                                  TYPE_child_owner const*,
                                                  std::string const&,
                                                  Loki::Int2Type<-1>) noexcept
    {
        // Done
    }
}

#endif // PHYS_MEM_DISK_MEDIATOR_HPP_INCLUDED
