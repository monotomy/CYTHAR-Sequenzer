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

#ifndef DC_OBJECTS_OBSERVER_HPP_INCLUDED
#define DC_OBJECTS_OBSERVER_HPP_INCLUDED

namespace dc_objects{

//!\class SelectedObjectObserver_V2
    template<TemporaryPropertiesIndex SELECTED_INDEX>
    SelectedObjectObserver_V2<SELECTED_INDEX>
    ::SelectedObjectObserver_V2() noexcept
    {
        TYPE_temporaryObserver::attach_as_observer_atProperty_subject(Temporary::singleton());
    }

    template<TemporaryPropertiesIndex SELECTED_INDEX>
    SelectedObjectObserver_V2<SELECTED_INDEX>
    ::~SelectedObjectObserver_V2() noexcept
    {
        TYPE_temporaryObserver::detach_at_observedProperty_subject();
    }

    template<TemporaryPropertiesIndex SELECTED_INDEX>
    inline auto const SelectedObjectObserver_V2<SELECTED_INDEX>
    ::selected_observedObject(Loki::Type2Type<TYPE_SelectedObject2Observe_T>) const noexcept
    ->TYPE_SelectedObject2Observe_T*
    {
    #ifdef DEBUG
        if(Temporary::singleton()->get_property<SELECTED_INDEX>() == nullptr)
            std::cout << "SELECTED nullptr request" << std::endl;
    #endif // DEBUG
        return Temporary::singleton()->get_property<SELECTED_INDEX>();
    }

    template<TemporaryPropertiesIndex SELECTED_INDEX>
    void SelectedObjectObserver_V2<SELECTED_INDEX>
    ::property_changed(Loki::Type2Type<typename Temporary::TYPE_UNIQUE_T>,
                       Loki::Int2Type<static_cast<int>(SELECTED_INDEX)>) noexcept
    {
        selected_observed_object_changed(Loki::Type2Type<UNIQUE_TYPE>());
    }

//!\class AbsolutObjectObserver
    #define TEMP_DEF_AbsolutObjectObserver \
        class TYPE_Object2Observe, \
        TemporaryPropertiesIndex DATABSE_INDEX, \
        class Policy_change_Object2Observe \

    #define TEMP_SPEZ_AbsolutObjectObserver \
        TYPE_Object2Observe, \
        DATABSE_INDEX, \
        Policy_change_Object2Observe \

    template<TEMP_DEF_AbsolutObjectObserver>
    AbsolutObjectObserver<TEMP_SPEZ_AbsolutObjectObserver>
    ::AbsolutObjectObserver(TYPE_index_child child_id) noexcept :
        _child_id{child_id}
    {
        // Anmeldung beim Child _child_id als Observer
        Policy_change_Object2Observe::change(this);
    }

    template<TEMP_DEF_AbsolutObjectObserver>
    AbsolutObjectObserver<TEMP_SPEZ_AbsolutObjectObserver>
    ::~AbsolutObjectObserver() noexcept
    {
        // Anmeldung beim Child _child_id als Observer
        detach_at_absolut_observed_object();
    }

    template<TEMP_DEF_AbsolutObjectObserver>
    void AbsolutObjectObserver<TEMP_SPEZ_AbsolutObjectObserver>
    ::attach_at_absolut_observed_object(TYPE_Object2Observe*const subject__) noexcept
    {
        TYPE_PropertyObserver_T::attach_as_observer_atProperty_subject(subject__);
        _absolut_observed_object = subject__;
    }

    template<TEMP_DEF_AbsolutObjectObserver>
    void AbsolutObjectObserver<TEMP_SPEZ_AbsolutObjectObserver>
    ::detach_at_absolut_observed_object() noexcept
    {
        TYPE_PropertyObserver_T::detach_at_observedProperty_subject();
        _absolut_observed_object = nullptr;
    }

    template<TEMP_DEF_AbsolutObjectObserver>
    void AbsolutObjectObserver<TEMP_SPEZ_AbsolutObjectObserver>
    ::set_child_id(size_t child_id__) noexcept
    {
        _child_id = child_id__;
    }

    template<TEMP_DEF_AbsolutObjectObserver>
    void AbsolutObjectObserver<TEMP_SPEZ_AbsolutObjectObserver>
    ::changed_observed_object_to(Loki::Type2Type<TYPE_Object2Observe>, size_t child_id__) noexcept
    {
        set_child_id(child_id__);
        Policy_change_Object2Observe::change(this);
    }

    template<TEMP_DEF_AbsolutObjectObserver>
    inline auto AbsolutObjectObserver<TEMP_SPEZ_AbsolutObjectObserver>
    ::absolut_observed_object(Loki::Type2Type<TYPE_Object2Observe>) const noexcept
    -> TYPE_Object2Observe*
    {
    #ifdef DEBUG
        if(_absolut_observed_object == nullptr)
            std::cout << "ABSOLUT nullptr request" << std::endl;
    #endif // DEBUG
        return _absolut_observed_object;
    }

//!\class RelativObjectObserver_V2
    #define TEMP_DEF_RelativObjectObserver \
        class TYPE_Object2Observe, \
        TemporaryPropertiesIndex relativSELECTED_INDEX, \
        TemporaryPropertiesIndex depend_onSELECTED_INDEX, \
        class Policy_change_Object2Observe, \
        class Policy_generateIds

    #define TEMP_SPEZ_RelativObjectObserver \
        TYPE_Object2Observe, \
        relativSELECTED_INDEX, \
        depend_onSELECTED_INDEX, \
        Policy_change_Object2Observe, \
        Policy_generateIds

    template<TEMP_DEF_RelativObjectObserver>
    RelativObjectObserver_V2<TEMP_SPEZ_RelativObjectObserver>
    ::RelativObjectObserver_V2() noexcept :
        _absolut_id_in_parent{Policy_generateIds::get_next()},
        _absolut_parent_id{Policy_generateIds::get_parent_id()}
    {
        // DEFAULT INITALISIERUNG DES RELATIVE OBSRVIERTEN OBJEKT
        Policy_change_Object2Observe::change(this);
    }

    template<TEMP_DEF_RelativObjectObserver>
    RelativObjectObserver_V2<TEMP_SPEZ_RelativObjectObserver>
    ::~RelativObjectObserver_V2() noexcept
    {
        detach_at_relative_observedObject();
    }

    template<TEMP_DEF_RelativObjectObserver>
    void RelativObjectObserver_V2<TEMP_SPEZ_RelativObjectObserver>
    ::replace_selected_with_relative() noexcept
    {
        Temporary::singleton()->set_property<relativSELECTED_INDEX>(relative_observedObject(Loki::Type2Type<TYPE_Object2Observe_T>()));
    }

    template<TEMP_DEF_RelativObjectObserver>
    bool RelativObjectObserver_V2<TEMP_SPEZ_RelativObjectObserver>
    ::is_my_relative_selected() noexcept
    {
        if(TYPE_SelectedObjectObserver_T::selected_observedObject(Loki::Type2Type<TYPE_Object2Observe_T>()) == _relative_observedObject)
            return true;
        else
            return false;
    }

    template<TEMP_DEF_RelativObjectObserver>
    inline auto RelativObjectObserver_V2<TEMP_SPEZ_RelativObjectObserver>
    ::relative_observedObject(Loki::Type2Type<TYPE_Object2Observe_T>) const noexcept -> TYPE_Object2Observe_T*
    {
    #ifdef DEBUG
        if(_relative_observedObject == nullptr)
            std::cout << "RELATIVE nullptr request" << std::endl;
    #endif // DEBUG
        return _relative_observedObject;
    }



    template<TEMP_DEF_RelativObjectObserver>
    void RelativObjectObserver_V2<TEMP_SPEZ_RelativObjectObserver>
    ::attach_at_relative_observedObject(TYPE_Object2Observe_T*const subject__) noexcept
    {
        TYPE_PropertyObserver_T::attach_as_observer_atProperty_subject(subject__);
        _relative_observedObject = subject__;
    }

    template<TEMP_DEF_RelativObjectObserver>
    void RelativObjectObserver_V2<TEMP_SPEZ_RelativObjectObserver>
    ::detach_at_relative_observedObject() noexcept
    {
        TYPE_PropertyObserver_T::detach_at_observedProperty_subject();
        _relative_observedObject = nullptr;
    }

    template<TEMP_DEF_RelativObjectObserver>
    inline void RelativObjectObserver_V2<TEMP_SPEZ_RelativObjectObserver>
    ::property_changed(Loki::Type2Type<typename Temporary::TYPE_UNIQUE_T>,
                       Loki::Int2Type<static_cast<int>(depend_onSELECTED_INDEX)>) noexcept
    {
        Policy_change_Object2Observe::change(this);
        relative_observed_object_changed(Loki::Type2Type<TYPE_Object2Observe_T>());
    }
}

#endif // DC_OBJECTS_OBSERVER_HPP_INCLUDED
