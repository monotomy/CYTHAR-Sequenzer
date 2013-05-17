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

#ifndef OBJECTSTRUCTURE_H_INCLUDED
#define OBJECTSTRUCTURE_H_INCLUDED

#include <stdint.h>

#include <set>
#include <tuple>
#include <type_traits>
#include <array>
#include <map>
#include <vector>
#include <iostream>

#include <loki/TypeManip.h>

#include <pattern/singleton.hpp>

#include <mutex>

namespace phys{ class MemPhysMediator; }
namespace objectsructure
{
    /***********************************************************************/
    /*! \PropertyObserver Pattern - PropertyObserver_Observer

        PropertyObserver_Observer zum beerben für Obervatoren unter angabe
        eines einzigartigen Wertes (TYPE_FOR_UNIQUE_OBSERVER) als
        Templateargument.

        Derzeit für Indexgrösse 20 notify Methothen implementiert.

        Um ein Subjekt zu observieren, attach & detach Methoden von:
            attach_as_observer_atProperty_subject
            detach_at_observedProperty_subject
        verwenden.

        Detach muss vom Client selbst übernommen werden!
    */
    /***********************************************************************/
//!\class PropertyObserver_Observer
    template<class UNIQUE_TYPE>
    struct PropertyObserver_Subject;

    template<class UNIQUE_TYPE>
    class PropertyObserver_Observer
    {
    NO_COPY_NO_MOVE(PropertyObserver_Observer)

        PropertyObserver_Subject<UNIQUE_TYPE>* _observed_subject{nullptr};

    protected:
        PropertyObserver_Observer() noexcept;
        ~PropertyObserver_Observer() noexcept = default;

        //!\GET_OBSERVED_SUBJECT Besser lesbares erreichen des Observierten Subjectes
        #define GET_OBSERVED_SUBJECT(__ARG_TYPE__)                                                      \
        static_cast<__ARG_TYPE__*>                                                                      \
        (                                                                                               \
            objectsructure::PropertyObserver_Observer<__ARG_TYPE__::UNIQUE_TYPE>::my_observedSubject()  \
        )

        auto my_observedSubject() const noexcept
        -> decltype(_observed_subject)
        {
        #ifdef DEBUG
            if(_observed_subject == nullptr)
                std::cout << "Nicht initalisiertes Subject angefordert" << std::endl;
        #endif // DEBUG
            return _observed_subject;
        }

        //! Bei den Subjekten an oder abmelden
        void attach_as_observer_atProperty_subject(PropertyObserver_Subject<UNIQUE_TYPE> *const subject_to_observe__) noexcept;
        void detach_at_observedProperty_subject() noexcept;

    public:
        /*! Oberver notify Methoden

            Geht zu lasten der Wiederholung, ist aber ein verständlicher Weg.

            Erben müssen diese Funktionen überschreiben unter Angabe des Index,
            anderenfalls werden diese Ignoriert.
        */
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<0>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<1>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<2>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<3>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<4>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<5>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<6>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<7>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<8>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<9>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<10>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<11>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<12>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<13>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<14>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<15>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<16>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<17>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<18>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<19>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<20>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<21>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<22>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<23>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<24>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<25>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<26>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<27>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<28>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }
        inline virtual void property_changed(Loki::Type2Type<UNIQUE_TYPE>, Loki::Int2Type<29>) noexcept { /* wird ignoriert wenn nicht überschrieben */ }

        /*! \AT_UNIQUE_INDEX

            Makro kann zur Vereinfachung in den Notify-Methoden eingesetzt werden.
            Argument ist einer UNIQUE_Class und der Index der enthaltenen Eiegenschaften
        */
        #define AT_(ARG_TYPE, ARG_PROPERTY_INDEX)        \
        Loki::Type2Type<typename dc_objects::ARG_TYPE::UNIQUE_TYPE>,                                 \
        Loki::Int2Type<static_cast<int>(dc_objects::ARG_TYPE::UNIQUE_TYPE::UNIQUE_INDEX::ARG_PROPERTY_INDEX)>
    };

    /***********************************************************************/
    /*! \PropertyObserver Pattern - PropertyObserver_Subject

        PropertyObserver_Subject nur für Modul interne Benutzung.

        Aber um sich beim Subject als Observer zu melden, attach und detach
        verwenden.
    */
    /***********************************************************************/
//!\class PropertyObserver_Subject
    template<class UNIQUE_TYPE>
    struct PropertyObserver_Subject
    {
    NO_COPY_NO_MOVE(PropertyObserver_Subject)

        typedef PropertyObserver_Observer<UNIQUE_TYPE> TYPE_PropertyObserver_T;
        #define forUNIQUE_TYPE(ARG_ObjectType) \
        Loki::Type2Type<typename dc_objects::ARG_ObjectType::TYPE_UNIQUE_T>
        typedef UNIQUE_TYPE TYPE_UNIQUE_T;

    protected:
        std::set<PropertyObserver_Observer<UNIQUE_TYPE>*> _my_property_observer{};

        PropertyObserver_Subject() noexcept;
        virtual_indbug ~PropertyObserver_Subject() noexcept = default;

    private:
        friend class PropertyObserver_Observer<UNIQUE_TYPE>;
        //! Meldet einen Observer beim Suject an
        void attach_property_observer(PropertyObserver_Observer<UNIQUE_TYPE> *const property_observer__) noexcept;
        //! Meldet einen Observer beim Suject ab
        void detach_property_observer(PropertyObserver_Observer<UNIQUE_TYPE> *const property_observer__) noexcept;
    };

    /***********************************************************************/
    /*! \Properties_publicMethodes - zum beerben

        Klasse bietet standard Methoden für Client set/get. Die Daten werden
        in einem Tuple, dessen Type bei Template instanzierung übergenben
        werden muss, gespeichert.
    */
    /***********************************************************************/
    //! Option, ob observer informiert werden sollen
    enum class PROPERTY_OBSERVER_MODE : bool
    {
        NOT_OBSERVEABLE = false,
        IS_OBSERVEABLE = true
    };

//!\class Properties
    template<class TYPE_PropertiesIndex_T>
    class GEN_UNIQUE_TYPE final
    {
    NO_COPY_NO_MOVE(GEN_UNIQUE_TYPE)

    protected:
        GEN_UNIQUE_TYPE() noexcept = default;
        ~GEN_UNIQUE_TYPE() noexcept = default;
    public:
        typedef TYPE_PropertiesIndex_T UNIQUE_INDEX;
    };
    template
    <
        class TYPE_PropertiesIndex,
        class TYPE_PropertiesTuple,
        PROPERTY_OBSERVER_MODE IsObserveable = PROPERTY_OBSERVER_MODE::NOT_OBSERVEABLE
    >
    struct Properties :
        public PropertyObserver_Subject<GEN_UNIQUE_TYPE<TYPE_PropertiesIndex>>
    {
    NO_COPY_NO_MOVE(Properties)

        //std::mutex only_one_thread_can_write;

        typedef GEN_UNIQUE_TYPE<TYPE_PropertiesIndex> UNIQUE_TYPE;
        typedef TYPE_PropertiesIndex TYPE_PropertiesIndex_T;

    private:
        //! Wertspeicher aller Eigenschaften
        TYPE_PropertiesTuple _properties_tuple;

        /// Initialisierungswerte für Wiederherstellungs optionen
        static TYPE_PropertiesTuple _our_init_properties;
        static void set_static_init_properties(TYPE_PropertiesTuple const& init_properties__) noexcept;

    protected:
        //! Initialisierung nur mit einem Tuple möglich
        explicit inline Properties(TYPE_PropertiesTuple const& properties_tuple__) noexcept;
        Properties() = delete;
        virtual_indbug ~Properties() noexcept = default;

    public:
        //! SET - GET ****************************************************
        //! \GET_PROPERTY Rückgabe der angeforderten Eigenschaft für Clienten
        #define GET_PROPERTY_(ARG_TYPE, ARG_PROPERTY_INDEX)           \
        get_property<dc_objects::ARG_TYPE::UNIQUE_TYPE::UNIQUE_INDEX::ARG_PROPERTY_INDEX>()

        //! \SET_PROPERTY schreiben einer Eigenschaft für Clienten
        #define SET_PROPERTY_(ARG_TYPE, ARG_PROPERTY_INDEX, ARG_PROPERTY_VALUE)           \
        set_property<dc_objects::ARG_TYPE::UNIQUE_TYPE::UNIQUE_INDEX::ARG_PROPERTY_INDEX>(ARG_PROPERTY_VALUE)

        // Cast from enum class to int
        #define GET_atINDEX std::get<static_cast<unsigned int>(INDEX)>
        //! Gibt eine Eigenschaft aus dem Tuple zurück
        template<TYPE_PropertiesIndex INDEX>
        inline auto get_property() const noexcept
        -> typename std::remove_reference<decltype(GET_atINDEX(_properties_tuple))>::type
        {
            return GET_atINDEX(_properties_tuple);
        }

        template<int INDEX>
        inline auto get_property(Loki::Int2Type<INDEX>) const noexcept
        -> typename std::remove_reference<decltype(GET_atINDEX(_properties_tuple))>::type
        {
            return GET_atINDEX(_properties_tuple);
        }

        //! Setzen einer Eigenschaft, überschreibend
        template<TYPE_PropertiesIndex INDEX, typename autoTYPE_OF_ARGUMENT> ///typename std::remove_reference<decltype(GET_atINDEX(_properties_tuple))>::type
        inline void set_property(autoTYPE_OF_ARGUMENT property_value__) noexcept;

        //! Direktes erhöhen einer Eigenschaft um operand
        template<TYPE_PropertiesIndex INDEX>
        inline void increase_property(int operand__ = 1) noexcept;

        //! Direktes verkleinern einer Eigenschaft um operand
        template<TYPE_PropertiesIndex INDEX>
        inline void decrease_property(int operand__ = 1) noexcept;

        //! Invertieren der Eigenschaft
        template<TYPE_PropertiesIndex INDEX>
        inline void invert_property() noexcept;

        //! COPY INTERN ***************************************************
        //! Kopiert das Tuple von Source zu Target mit observerrufen
        inline void copy_from_source(Properties const* source__) noexcept;
    private:
        //! Copyloop für Tuple
        template<int TUPLE_LEVEL>
        inline void copy_from_source(Properties const* source__, Loki::Int2Type<TUPLE_LEVEL>);
        //! Copyloop end
        inline void copy_from_source(Properties const* source__, Loki::Int2Type<-1>);


        //! READ **********************************************************
        //! Konvertierung der Daten in Strings um diese zu speichern.
        friend class phys::MemPhysMediator;
        typedef std::array<std::string,std::tuple_size<TYPE_PropertiesTuple>::value> TYPE_data_container;
        auto data_container() const noexcept -> TYPE_data_container;

        //! Rekursion
        template<int TUPLE_LEVEL>
        inline void fill_data_container(TYPE_data_container&,
                                        Loki::Int2Type<TUPLE_LEVEL>) const noexcept;
        //! Ende der Rekursion
        inline void fill_data_container(TYPE_data_container&,
                                        Loki::Int2Type<-1>) const noexcept;

        //! WRITE *********************************************************
        //! Einfügen der Daten von Stings
        void set_data_container(TYPE_data_container const&) noexcept;

        //! Rekursion
        template<int TUPLE_LEVEL>
        inline void set_data_from_container(TYPE_data_container const&,
                                            Loki::Int2Type<TUPLE_LEVEL>) noexcept;
        //! Ende der Rekursion
        inline void set_data_from_container(TYPE_data_container const&,
                                            Loki::Int2Type<-1>) noexcept;
    };
    //! Werte welche beim einlesen Irgnoriert werden und standard initalisiert.
    static const std::string EMPTY_VALUE{""};

    /***********************************************************************/
    /*! \ChildArray - zum beerben

        Klasse bietet verwaltung von Childs in einem Array an.
        Die Childs werden per default initialisiert.
    */
    /***********************************************************************/
    static constexpr bool ChildArray_SINGLE_CHILD = 1;
    static constexpr bool ChildArray_SINGLE_CHILD_ACCESS = 0;

    /***********************************************************************/
    /*! \get_default_filled_array

        Erstellt ein Array mit stadard, neu erstellten Objekten.
    */
    /***********************************************************************/
    template<class array_T> array_T get_default_filled_array() noexcept;

//!\class ChildArray
    template
    <
        class TYPE_child,
        size_t childs_per_parent,
        class UNIQUE_TYPE_FOR_MULTY_DERIVE = bool
    >
    class ChildArray
    {
    NO_COPY_NO_MOVE(ChildArray)

        typedef std::array<TYPE_child*,childs_per_parent> TYPE_childsArry;
        TYPE_childsArry const _childs = get_default_filled_array<TYPE_childsArry>();

    protected:
        ChildArray() noexcept = default;
        virtual_indbug ~ChildArray() noexcept;

        inline TYPE_child* child(size_t child_id__) const noexcept;

        //! COPY  **********************************************************
        //! Kopiert die Daten der SourceChilds in die eigenen Childs
        inline void copy_childdata_from_source(ChildArray const* source__) noexcept;
    public:
        //! Rekursieves Kopieren der Child_ofChilds, angegeben werden muss die Childtiefe.
        // 0 = nur die eigenen Childs
        #define copyDEEPNESS_(ARG_DEEPNESS_inINT) \
        Loki::Int2Type<ARG_DEEPNESS_inINT>()
        template<int DEEPNESS_ofCOPY_CHILD_ofCHILDDATA>
        inline void copy_childdata_from_source(ChildArray const* source__,
                                               Loki::Int2Type<DEEPNESS_ofCOPY_CHILD_ofCHILDDATA>) noexcept;

        //! Kopiert nur die Daten der direkter Childs
        inline void copy_childdata_from_source(ChildArray const* source__,
                                               Loki::Int2Type<1>) noexcept;
    private:
        //! Rekursionsende
        inline void copy_childdata_from_source(ChildArray const* source__,
                                               Loki::Int2Type<0>) noexcept;

        //! ITER **********************************************************
        friend class phys::MemPhysMediator;
        typedef TYPE_child TYPE_child_T;
        typedef ChildArray TYPE_ChildArray_T;
        auto begin(Loki::Type2Type<TYPE_child>) const noexcept
        -> decltype(this->_childs.begin())
        {
            return _childs.begin();
        }

        auto end(Loki::Type2Type<TYPE_child>) const noexcept
        -> decltype(this->_childs.end())
        {
            return _childs.end();
        }
    };

    /***********************************************************************/
    /*! \HAS_NO_CHILDARRAY - zum beerben

        Rekursionsende für Objecte, welche Childs sind, aber selbst keine zum
        Kopieren besitzen.
    */
    /***********************************************************************/
    class HAS_NO_CHILDARRAY
    {
    protected:
        HAS_NO_CHILDARRAY() noexcept = default;
        ~HAS_NO_CHILDARRAY() noexcept = default;

    public:
        template<class Dummy_ChildArray>
        inline void copy_childdata_from_source(Dummy_ChildArray const*,
                                               Loki::Int2Type<0>) noexcept{
            /* IGNORE COPY CALLS */
        }
        static constexpr unsigned int CHILD_COPY_DEEPNESS{0};
    };


    /***********************************************************************/
    /*! \ChildMap - zum beerben

        Klasse bietet verwaltung von Childs in einer Map an.
        Keine default Childinitalisation.
        Dynamische Grösse
    */
    /***********************************************************************/
//!\class ChildMap
    template
    <
        class child_T,
        class UNIQUE_TYPE_FOR_MULTY_DERIVE = bool
    >
    class ChildMap
    {
    NO_COPY_NO_MOVE(ChildMap)

        #define _KEY first
        #define _CHILD second
        typedef std::map<size_t,child_T*> TYPE_childsMap;
    protected:
        /// TODO private, aber probleme mit begin end von datenbank
        TYPE_childsMap _childs{};

    protected:
        ChildMap() noexcept = default;
        virtual_indbug ~ChildMap() noexcept;

        inline child_T* child(size_t child_id__) noexcept;
        inline void insert_child__(size_t child_id__, child_T*const child__) noexcept
        {
            _childs[child_id__] = child__;
        }
/// TODO, der zugriff war irgendwie buggi, erinnere ich mich und packte es in die datenbank...
/// Bitte malanschaun.
/*
        auto begin() const noexcept
        -> decltype(this->_childs.begin())
        {
            return _childs.begin();
        }

        auto end() const noexcept
        -> decltype(this->_childs.end())
        {
            return _childs.end();
        }
*/
    };

    /***********************************************************************/
    /*! \ObjectDatabase

        Verwaltung von dynamischen Objekten mit ChildMap
    */
    /***********************************************************************/
//!\Operators
    enum class DatabasePropertiesIndex : uint8_t
    {
        CHILD_ID_ADDED,
        CHILD_ID_CHANGED,
        CHILD_ID_REMOVED
    };

//!\Typedef
    typedef size_t TYPE_childId_added;
    typedef size_t TYPE_childId_changed;
    typedef size_t TYPE_childId_removed;

//!\Tupledef
    typedef std::tuple
    <
        TYPE_childId_added,
        TYPE_childId_changed,
        TYPE_childId_removed
    >
    DatabasePropertiesTuple;

//!\Defaultwerte
    static constexpr TYPE_childId_added     Database_DEFAULT_CHILD_ID_ADDED = 0;
    static constexpr TYPE_childId_changed   Database_DEFAULT_CHILD_ID_CHANGED = 0;
    static constexpr TYPE_childId_removed   Database_DEFAULT_CHILD_ID_REMOVED = 0;

    static constexpr DatabasePropertiesTuple DEFAULT_DatabasePropertiesTuple
    {
        std::make_tuple(Database_DEFAULT_CHILD_ID_ADDED,
                        Database_DEFAULT_CHILD_ID_CHANGED,
                        Database_DEFAULT_CHILD_ID_REMOVED)
    };

//!\Objectsructuredef
    typedef objectsructure::Properties
    <
        DatabasePropertiesIndex,
        DatabasePropertiesTuple,
        objectsructure::PROPERTY_OBSERVER_MODE::IS_OBSERVEABLE
    >
    DatabaseProperties;

//!\class ObjectDatabase
    template
    <
        class ChildType
    >
    class ObjectDatabase :
        public DatabaseProperties,
        public objectsructure::ChildMap<ChildType>
    {
    SINGLETON_ownCTOR(ObjectDatabase)

        ObjectDatabase() noexcept :
            DatabaseProperties{DEFAULT_DatabasePropertiesTuple}
        {};

    public:
        typedef ChildType TYPE_CHILD;

        inline auto entity(size_t child_id__) noexcept
        -> decltype(this->ChildMap<ChildType>::child(child_id__))
        {
            return ChildMap<ChildType>::child(child_id__);
        }

        inline auto child(Loki::Type2Type<ChildType>, size_t child_id__) noexcept
        -> decltype(this->ChildMap<ChildType>::child(child_id__))
        {
            return ChildMap<ChildType>::child(child_id__);
        }

        inline void insert_child(Loki::Type2Type<ChildType>, size_t child_id__, ChildType* child__) noexcept
        {
            ObjectDatabase<ChildType>::insert_child__(child_id__, child__);
        }

        //! Iterartion durch die Childs
        inline auto begin() const noexcept
        -> decltype(this->_childs.begin())
        {
            return ObjectDatabase<ChildType>::_childs.begin();
        }

        //! Ende Iterartion durch die Childs
        inline auto end() const noexcept
        -> decltype(this->_childs.end())
        {
            return ObjectDatabase<ChildType>::_childs.end();
        }

        //! Erstellt neues Child am ande an der ID size_of(_childs);
        inline ChildType* make_back_get() noexcept
        {
            size_t new_id{ObjectDatabase<ChildType>::_childs.size()};
            ObjectDatabase<ChildType>::_childs[new_id] = new ChildType{};

            // OBSERVER NOTIFY
            this->set_property<DatabasePropertiesIndex::CHILD_ID_ADDED>(new_id);

            return ObjectDatabase<ChildType>::_childs[new_id];
        }

        //! Sucht in allen Objekten nach einer Eigenschaft,
        //! Gibt das erste child zurück, in dem die Eigenschaft gleich der gesuchten ist
        //! ELSE nullptr
        template<typename ChildType::TYPE_PropertiesIndex_T propINDEX, typename ARGUMENT_TYPE> ///
        inline auto find_child_with(ARGUMENT_TYPE search_for__) const noexcept
        -> ChildType*
        {
            for(auto child_pair : ObjectDatabase<ChildType>::_childs)
                if(child_pair._CHILD->get_property<propINDEX>() == search_for__)
                    return child_pair._CHILD;

            return nullptr;
        }

        //!\DatabaseKeyName
        static constexpr const char* _KEY_NAME{"_db"};
    };
}

#include <objectstructure.hpp>

#endif // OBJECTSTRUCTURE_H_INCLUDED
