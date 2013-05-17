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

#ifndef OBJECTSTRUCTURE_HPP_INCLUDED
#define OBJECTSTRUCTURE_HPP_INCLUDED

#include <cast/lexical_cast.hpp>
#include <functions/invert.hpp>


#ifdef DEBUG
    #include <iostream>
#endif // DEBUG

namespace objectsructure
{
//!\struct PropertyObserver_Observer
    template<class UNIQUE_TYPE>
    PropertyObserver_Observer<UNIQUE_TYPE>
    ::PropertyObserver_Observer() noexcept
    {}

    template<class UNIQUE_TYPE>
    void PropertyObserver_Observer<UNIQUE_TYPE>
    ::attach_as_observer_atProperty_subject(PropertyObserver_Subject<UNIQUE_TYPE> *const subject_to_observe__) noexcept
    {
        subject_to_observe__->attach_property_observer(this);

        _observed_subject = subject_to_observe__;
    }

    template<class UNIQUE_TYPE>
    void PropertyObserver_Observer<UNIQUE_TYPE>
    ::detach_at_observedProperty_subject() noexcept
    {
        if(_observed_subject != nullptr)
            _observed_subject->detach_property_observer(this);
    }

//!\class PropertyObserver_Subject
    template<class UNIQUE_TYPE>
    PropertyObserver_Subject<UNIQUE_TYPE>
    ::PropertyObserver_Subject() noexcept
    {}

    template<class UNIQUE_TYPE>
    void PropertyObserver_Subject<UNIQUE_TYPE>
    ::attach_property_observer(PropertyObserver_Observer<UNIQUE_TYPE> *const property_observer__) noexcept
    {
        _my_property_observer.insert(property_observer__);
    }

    template<class UNIQUE_TYPE>
    void PropertyObserver_Subject<UNIQUE_TYPE>
    ::detach_property_observer(PropertyObserver_Observer<UNIQUE_TYPE> *const property_observer__) noexcept
    {
        _my_property_observer.erase(property_observer__);
    }

//!\class Properties
    #define TEMP_DEF_Properties                 \
        class PropertiesIndex,                  \
        class PropertiesTuple,                  \
        PROPERTY_OBSERVER_MODE IsObserveable

    #define TEMP_SPEZ_Properties                \
        PropertiesIndex,                        \
        PropertiesTuple,                        \
        IsObserveable

    template<TEMP_DEF_Properties>
    Properties<TEMP_SPEZ_Properties>
    ::Properties(PropertiesTuple const& properties_tuple__) noexcept :
        _properties_tuple{properties_tuple__}
    {
        static bool our_static_init_is_done{false};
        if(our_static_init_is_done)
            return;
        else
        {
            set_static_init_properties(properties_tuple__);
            our_static_init_is_done = true;
        }
        //only_one_thread_can_write.unlock();
    }

    template<TEMP_DEF_Properties>
    PropertiesTuple Properties<TEMP_SPEZ_Properties>
    ::_our_init_properties{};

    template<TEMP_DEF_Properties>
    void Properties<TEMP_SPEZ_Properties>
    ::set_static_init_properties(PropertiesTuple const& init_properties__) noexcept
    {
        _our_init_properties = init_properties__;
    }

    template<TEMP_DEF_Properties>
    template<PropertiesIndex INDEX, typename autoTYPE_OF_ARGUMENT> ///typename std::remove_reference<decltype(GET_atINDEX(_properties_tuple))>::type
    inline void Properties<TEMP_SPEZ_Properties>
    ::set_property(autoTYPE_OF_ARGUMENT property_value__) noexcept
    {
        // Schreibe Wert
        //only_one_thread_can_write.lock();
        GET_atINDEX(_properties_tuple) = property_value__;
        //only_one_thread_can_write.unlock();

        // Informiere Observer
        if(IsObserveable == PROPERTY_OBSERVER_MODE::IS_OBSERVEABLE)
        {
            for(auto property_observer : PropertyObserver_Subject<typename Properties::UNIQUE_TYPE>::_my_property_observer)
            {
                property_observer->property_changed(Loki::Type2Type<typename Properties::UNIQUE_TYPE>(),
                                                    Loki::Int2Type<static_cast<int>(INDEX)>());
            }
        }
    }

    template<TEMP_DEF_Properties>
    template<PropertiesIndex INDEX>
    inline void Properties<TEMP_SPEZ_Properties>
    ::increase_property(int operand__) noexcept
    {
        this->set_property<INDEX>(operand__ + std::get<static_cast<int>(INDEX)>(this->_properties_tuple));
    }

    template<TEMP_DEF_Properties>
    template<PropertiesIndex INDEX>
    inline void Properties<TEMP_SPEZ_Properties>
    ::decrease_property(int operand__) noexcept
    {
        this->set_property<INDEX>(std::get<static_cast<int>(INDEX)>(this->_properties_tuple)-operand__);
    }

    template<TEMP_DEF_Properties>
    template<PropertiesIndex INDEX>
    inline void Properties<TEMP_SPEZ_Properties>
    ::invert_property() noexcept
    {
        this->set_property<INDEX>(invert_numeric(std::get<static_cast<int>(INDEX)>(this->_properties_tuple)));
    }

    // Copyrekursion Start
    template<TEMP_DEF_Properties>
    inline void Properties<TEMP_SPEZ_Properties>
    ::copy_from_source(Properties const* source__) noexcept
    {
        if(this != source__)
            copy_from_source(source__, Loki::Int2Type<std::tuple_size<PropertiesTuple>::value-1>());
    }
    // Copyrekursion Loop
    template<TEMP_DEF_Properties>
    template<int TUPLE_LEVEL>
    inline void Properties<TEMP_SPEZ_Properties>
    ::copy_from_source(Properties const* source__, Loki::Int2Type<TUPLE_LEVEL>)
    {
        // Copy
        this->set_property<static_cast<PropertiesIndex>(TUPLE_LEVEL)>(
            std::get<TUPLE_LEVEL>(source__->_properties_tuple));

        // Next
        copy_from_source(source__, Loki::Int2Type<TUPLE_LEVEL-1>());
    }
    // Copyrekursion end
    template<TEMP_DEF_Properties>
    inline void Properties<TEMP_SPEZ_Properties>
    ::copy_from_source(Properties const*, Loki::Int2Type<-1>)
    {
        // done
    }

/*
    template<TEMP_DEF_Properties>
    template<int TUPLE_LEVEL>
    inline void Properties<TEMP_SPEZ_Properties>
    ::copy_from_source(Properties const* source__, Loki::Int2Type<TUPLE_LEVEL>)
    {
        // Copy
        this->set_property<static_cast<PropertiesIndex>(TUPLE_LEVEL)>(
            std::get<TUPLE_LEVEL>(source__->_properties_tuple));

        // Next
        copy_from_source(source__, Loki::Int2Type<TUPLE_LEVEL-1>());
    }
    */

    template<TEMP_DEF_Properties>
    auto Properties<TEMP_SPEZ_Properties>
    ::data_container() const noexcept
    -> typename Properties<TEMP_SPEZ_Properties>::TYPE_data_container
    {
        TYPE_data_container data_container__;
        static constexpr int datasize = std::tuple_size<PropertiesTuple>::value;

        // Start Rekursion
        fill_data_container(data_container__, Loki::Int2Type<datasize-1>());

        return std::move(data_container__);
    }

    template<TEMP_DEF_Properties>
    template<int TUPLE_LEVEL>
    inline void Properties<TEMP_SPEZ_Properties>
    ::fill_data_container(typename Properties::TYPE_data_container& data_container__,
                          Loki::Int2Type<TUPLE_LEVEL>) const noexcept
    {
        // current data
        typedef typename std::remove_reference<decltype( std::get<TUPLE_LEVEL>(this->_properties_tuple) )>::type TYPE_current;
        data_container__[TUPLE_LEVEL] = lexical_cast<std::string>( TYPE_current{std::get<TUPLE_LEVEL>(this->_properties_tuple)} );

        // Next
        fill_data_container(data_container__, Loki::Int2Type<TUPLE_LEVEL-1>());
    }

    template<TEMP_DEF_Properties>
    inline void Properties<TEMP_SPEZ_Properties>
    ::fill_data_container(typename Properties::TYPE_data_container&,
                             Loki::Int2Type<-1>) const noexcept
    {
        // done
    }


    template<TEMP_DEF_Properties>
    void Properties<TEMP_SPEZ_Properties>
    ::set_data_container(TYPE_data_container const& data_container__) noexcept
    {
        static constexpr int datasize = std::tuple_size<PropertiesTuple>::value;

        // Start Rekursion
        set_data_from_container(data_container__, Loki::Int2Type<datasize-1>());
    }

    template<TEMP_DEF_Properties>
    template<int TUPLE_LEVEL>
    inline void Properties<TEMP_SPEZ_Properties>
    ::set_data_from_container(typename Properties::TYPE_data_container const& data_container__,
                              Loki::Int2Type<TUPLE_LEVEL>) noexcept
    {
        typedef typename std::remove_reference<decltype( std::get<TUPLE_LEVEL>(this->_properties_tuple) )>::type TYPE_current;

        // Set current level from container
        if(data_container__[TUPLE_LEVEL] != EMPTY_VALUE)
            this->set_property<static_cast<PropertiesIndex>(TUPLE_LEVEL)>( lexical_cast<TYPE_current>(data_container__[TUPLE_LEVEL]) );
        else
            // Set default, wenn wert nicht verfügbar
            this->set_property<static_cast<PropertiesIndex>(TUPLE_LEVEL)>(std::get<TUPLE_LEVEL>(this->_our_init_properties));

        // Next
        set_data_from_container(data_container__, Loki::Int2Type<TUPLE_LEVEL-1>());
    }

    template<TEMP_DEF_Properties>
    inline void Properties<TEMP_SPEZ_Properties>
    ::set_data_from_container(typename Properties::TYPE_data_container const&,
                              Loki::Int2Type<-1>) noexcept
    {
        // done
    }

//!\class ChildArray
    #define TEMP_DEF_ChildArray             \
        class TYPE_child,                      \
        size_t childs_per_parent,           \
        class UNIQUE_TYPE_FOR_MULTY_DERIVE  \

    #define TEMP_SPEZ_ChildArray        \
        TYPE_child,                        \
        childs_per_parent,              \
        UNIQUE_TYPE_FOR_MULTY_DERIVE    \

    template<TEMP_DEF_ChildArray>
    ChildArray<TEMP_SPEZ_ChildArray>
    ::~ChildArray() noexcept
    {
        for(auto a_child : _childs)
            delete a_child;
    }

    template<TEMP_DEF_ChildArray>
    inline TYPE_child* ChildArray<TEMP_SPEZ_ChildArray>
    ::child(size_t child_id__) const noexcept
    {
        return _childs[child_id__];
    }

    template<TEMP_DEF_ChildArray>
    inline void ChildArray<TEMP_SPEZ_ChildArray>
    ::copy_childdata_from_source(ChildArray const* source__) noexcept
    {
        if(source__ != this)
            for(size_t current_child_id{0};
                current_child_id != childs_per_parent;
                ++current_child_id)
        {
            _childs[current_child_id]->copy_from_source(source__->_childs[current_child_id]);
        }
    }

    template<TEMP_DEF_ChildArray>
    template<int DEEPNESS_ofCOPY_CHILD_ofCHILDDATA>
    inline void ChildArray<TEMP_SPEZ_ChildArray>
    ::copy_childdata_from_source(ChildArray const* source__,
                                 Loki::Int2Type<DEEPNESS_ofCOPY_CHILD_ofCHILDDATA>) noexcept
    {
        if(source__ != this)
            for(size_t current_child_id{0};
                current_child_id != childs_per_parent;
                ++current_child_id)
        {
            // Copie der eigenen ChildDaten
            copy_childdata_from_source(source__);
            // Copiert die Daten des Child_ofChild
            // Rekursion
            _childs[current_child_id]
                ->copy_childdata_from_source(source__->_childs[current_child_id],
                                             Loki::Int2Type<DEEPNESS_ofCOPY_CHILD_ofCHILDDATA-1>());
        }
    }

    template<TEMP_DEF_ChildArray>
    inline void ChildArray<TEMP_SPEZ_ChildArray>
    ::copy_childdata_from_source(ChildArray const* source__,
                                 Loki::Int2Type<1>) noexcept
    {
        copy_childdata_from_source(source__);
    }

    template<TEMP_DEF_ChildArray>
    inline void ChildArray<TEMP_SPEZ_ChildArray>
    ::copy_childdata_from_source(ChildArray const*,
                                 Loki::Int2Type<0>) noexcept
    {
        /* Nothing */
    }

//!\get_default_filled_array
    template<class array_T>
    array_T get_default_filled_array() noexcept
    {
        typedef typename std::remove_pointer<typename array_T::value_type>::type value_type;

        array_T _array;
        for(typename array_T::size_type childs{0};
            childs != _array.max_size() ;
            ++childs )
        {
            _array[childs] = new value_type{};
        }

        return std::move(_array);
    }

//!\class ChildMap
    #define TEMP_DEF_ChildMap               \
        class child_T,                      \
        class UNIQUE_TYPE_FOR_MULTY_DERIVE  \

    #define TEMP_SPEZ_ChildMap          \
        child_T,                        \
        UNIQUE_TYPE_FOR_MULTY_DERIVE    \

    template<TEMP_DEF_ChildMap>
    ChildMap<TEMP_SPEZ_ChildMap>
    ::~ChildMap() noexcept
    {
        for(auto a_child : _childs)
            delete a_child.second;
    }

    template<TEMP_DEF_ChildMap>
    inline child_T* ChildMap<TEMP_SPEZ_ChildMap>
    ::child(size_t child_id__) noexcept
    {
        auto found_child(_childs.find(child_id__));
        if(found_child != _childs.end())
            return found_child->second;
        else
        {
        #ifdef DEBUG
            std::cout << "DEBUG: Dont find child" << std::endl;
        #endif // DEBUG
            return nullptr;
        }
    }
}

#endif // OBJECTSTRUCTURE_HPP_INCLUDED
