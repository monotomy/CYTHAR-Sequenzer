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

#ifndef DC_OBJECTS_OBSERVER_H_INCLUDED
#define DC_OBJECTS_OBSERVER_H_INCLUDED

#include <objectobserver.scm.h> // Shortcut Makros
#include <objectstructure.h>

#include <iostream>

namespace dc_objects{

    //! @AUTOR  PatternsaiteMuteTimer hat keinen der Observer hier,
    //!         Soll das Project während der LAufzeit nochmals geändert werden,
    //!         Dann bitte PatternsaiteMuteTimer erweiteren um einen auf diesen
    //!         Observer hier basierenden.

    /***********************************************************************/
    /*! \class SelectedObjectObserver_V2

        Beobachtet "SELECTED" Objecte in Temporary.

    */
    /***********************************************************************/
    template<TemporaryPropertiesIndex SELECTED_INDEX>
    class SelectedObjectObserver_V2 :
        public std::remove_pointer<decltype(Temporary::singleton()->get_property<SELECTED_INDEX>())>::type::TYPE_PropertyObserver_T,
        public TYPE_temporaryObserver
    {
    protected:
        typedef typename std::remove_pointer<decltype(Temporary::singleton()->get_property<SELECTED_INDEX>())>::type TYPE_SelectedObject2Observe_T;
        typedef typename TYPE_SelectedObject2Observe_T::UNIQUE_TYPE UNIQUE_TYPE;
        typedef TYPE_SelectedObject2Observe_T DC_OBJECT_TYPE;    // Wird von Makros verwendet

    protected:
        //! Initalisiert Object als Temporary Observer
        SelectedObjectObserver_V2() noexcept;
        ~SelectedObjectObserver_V2() noexcept;

        //! Rückgabe des Selcted observierten Objects
        inline auto const selected_observedObject(Loki::Type2Type<TYPE_SelectedObject2Observe_T>) const noexcept
        ->TYPE_SelectedObject2Observe_T*;

    private:
        // Ruft selected_observed_object_changed
        virtual void property_changed(Loki::Type2Type<typename Temporary::TYPE_UNIQUE_T>,
                                      Loki::Int2Type<static_cast<int>(SELECTED_INDEX)>) noexcept override;

        //! Info für den Erben, wenn er überschreibt
        virtual void selected_observed_object_changed(Loki::Type2Type<UNIQUE_TYPE>) noexcept {
            /* override if need */
        };
    };

    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################

    /***********************************************************************/
    /*! \class AbsolutObjectObserver

        Ermöglich die Observation eines einzelnen, absoluten Objektes.
        Absolut ist die Id.

        Der Zeit keine überschreibung der Selectet changed Methode von
        SelectedObjectObserver_V2
    */
    /***********************************************************************/
    template
    <
        class TYPE_Object2Observe,            //  welcher object type wird absolut observiert 3. ->
        TemporaryPropertiesIndex DATABSE_INDEX, //  Datenbank index in Temporary
        class Policy_change_Object2Observe      //  Wie wird das observierte Object geändert
    >
    class AbsolutObjectObserver :
        public SelectedObjectObserver_V2<DATABSE_INDEX>,        // Diese selected Datanbank enthält die zu observierend Objekte
        public TYPE_Object2Observe::TYPE_PropertyObserver_T     // Observiert Childs der Datenbank
    {
        typedef SelectedObjectObserver_V2<DATABSE_INDEX> TYPE_SelectedDatabaseObserver_T;
        typedef typename TYPE_SelectedDatabaseObserver_T::TYPE_SelectedObject2Observe_T TYPE_Database2Observe_T;
        typedef typename TYPE_Object2Observe::TYPE_PropertyObserver_T TYPE_PropertyObserver_T;

    protected:
        TYPE_index_child _child_id;                                 // observiertes child der Datenbank
    private:
        TYPE_Object2Observe* _absolut_observed_object{nullptr};     // Observiertes Subject

    protected:
        typedef TYPE_Object2Observe TYPE_Object2Observe_T;    // Wird von Makros verwendet
        typedef typename TYPE_Object2Observe_T::TYPE_PropertiesIndex_T TYPE_PropertiesIndex_T;

        friend Policy_change_Object2Observe;
        //! Default anmeldung bei 0 Child id
        AbsolutObjectObserver(TYPE_index_child child_id = 0) noexcept;
        ~AbsolutObjectObserver() noexcept;

    private:
        //! Anmeldung bei einem zu observierend Subject
        void attach_at_absolut_observed_object(TYPE_Object2Observe*const subject__) noexcept;
        //! Abmeldung bei einem observierten Subject
        void detach_at_absolut_observed_object() noexcept;
        //!
        void set_child_id(size_t child_id__) noexcept;

    protected:
        //! Ändert das absolut observierte child zu child id
        void changed_observed_object_to(Loki::Type2Type<TYPE_Object2Observe>, size_t child_id__) noexcept;

        //! Rückgabe des absolut observieren Child
        inline auto absolut_observed_object(Loki::Type2Type<TYPE_Object2Observe>) const noexcept -> TYPE_Object2Observe*;
    };

    //! Ändert das observierte Objekt per absoluter Id / child Id
    template<class IS_A_DUMMY = TYPE_NOT_UNIQUE>
    struct ChangedAbsolutObservedObject_policy{ template<class THIS>
    static void change(THIS *const this__) noexcept{

        this__->detach_at_absolut_observed_object();

        auto observed_database(this__->selected_observedObject(Loki::Type2Type<typename THIS::TYPE_Database2Observe_T>()));
        auto absolut_observed_object(observed_database
                                     ->child(Loki::Type2Type<typename THIS::TYPE_Object2Observe_T>(),
                                            this__->_child_id));
        if(absolut_observed_object == nullptr)
            std::cout << "BUG: no nullpointer subject attach " << std::endl;
        else
            this__->attach_at_absolut_observed_object(absolut_observed_object);
    }};

    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################

    /***********************************************************************/
    /*! \class RelativObjectObserver_V2

        Ermöglicht die observierung von Absoluten objekten in Abhängikeit
        eines Selectet Parrent
    */
    /***********************************************************************/
    template
    <
        class TYPE_Object2Observe,                            //  welcher object type wird relativ observiert 3. ->
        TemporaryPropertiesIndex relativSELECTED_INDEX,         //  der eigene index
        TemporaryPropertiesIndex depend_onSELECTED_INDEX,       //  3. -> in abhängikeit zum selected object
        class Policy_change_Object2Observe,                     //  Wie wird das observierte Object geändert
        class Policy_generateIds                                //  Wie werden die Ids erzeugt
    >
    class RelativObjectObserver_V2 :
        public SelectedObjectObserver_V2<relativSELECTED_INDEX>
    {
        typedef SelectedObjectObserver_V2<relativSELECTED_INDEX> TYPE_SelectedObjectObserver_T;
        typedef typename TYPE_Object2Observe::TYPE_PropertyObserver_T TYPE_PropertyObserver_T;
        typedef typename TYPE_Object2Observe::UNIQUE_TYPE UNIQUE_TYPE;

        TYPE_Object2Observe* _relative_observedObject{nullptr};

    protected:
        typedef TYPE_Object2Observe TYPE_Object2Observe_T;    // Wird von Makros verwendet

        TYPE_index_child const _absolut_id_in_parent;
        TYPE_index_child const _absolut_parent_id;

        typedef Policy_change_Object2Observe Policy_change_Object2Observe_T;
        friend Policy_change_Object2Observe;

        //! Observiert das Relatvie object per default
        RelativObjectObserver_V2() noexcept;
        ~RelativObjectObserver_V2() noexcept;

        //! Ändert das selectet observierte objekt des gleichen Types mit dem relative observierten
        void replace_selected_with_relative() noexcept;
        //! Prüft ob das observierte Object auch das selcted observierte ist
        bool is_my_relative_selected() noexcept;

        //! Gibt das relative observierte Objekt
        inline auto relative_observedObject(Loki::Type2Type<TYPE_Object2Observe_T>) const noexcept -> TYPE_Object2Observe_T*;

    private:
        //! Beim relativen Subject an/abmelden
        void attach_at_relative_observedObject(TYPE_Object2Observe_T*const subject__) noexcept;
        void detach_at_relative_observedObject() noexcept;

        //! Info vom selected observer, das das Parent geändert wurde -> wechelt relative observiertes object
        virtual void property_changed(Loki::Type2Type<typename Temporary::TYPE_UNIQUE_T>,
                                             Loki::Int2Type<static_cast<int>(depend_onSELECTED_INDEX)>) noexcept override;
        virtual void relative_observed_object_changed(Loki::Type2Type<TYPE_Object2Observe_T>) noexcept { /* override if need */ }
    };

    //! ####################################################################
    //! ####################################################################
    //! ####################################################################
    //! ####################################################################

    /***********************************************************************/
    /*! \class SelecteddetailObserver_V2

        Policy um den Relativen Observer mit seinen Funktionen wie einen
        Selectet observer einzusetzen.
    */
    /***********************************************************************/
    template<TemporaryPropertiesIndex SELECTED_INDEX>
    struct ChangedRelativeObserver_forSelectedDetailObserver_policy{ template<class THIS>
    static void change(THIS *const this__) noexcept
    {
            this__->detach_at_relative_observedObject();

            auto selecteddatail_observed_object(Temporary::singleton()->get_property<SELECTED_INDEX>());

            this__->attach_at_relative_observedObject(selecteddatail_observed_object);
    }};
}

#include <objectobserver.hpp>

#endif // DC_OBJECTS_OBSERVER_H_INCLUDED
