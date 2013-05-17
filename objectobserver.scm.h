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

#ifndef DC_OBJECTS_OBSERVER_SCM_H_INCLUDED
#define DC_OBJECTS_OBSERVER_SCM_H_INCLUDED

//! SHORT CUT MAKROS

    //!\TEMPORARY
        //! Get temporary (singleton)
        #define tmpOBS_() Temporary::singleton()

        //! Get property from temporary
        #define tmpGET_(ARG_PROPERTY) \
        tmpOBS_() \
            ->GET_PROPERTY_(Temporary, ARG_PROPERTY)

        //! Set property from temporary
        #define tmpSET_(ARG_PROPERTY, \
                        ARG_VALUE) \
        tmpOBS_() \
            ->SET_PROPERTY_(Temporary, ARG_PROPERTY, ARG_VALUE)

    //!\SELCETED_OBJECT
        //! Get selected subject
        #define selOBS_(ARG_OBSERVER_TYPE) \
        ARG_OBSERVER_TYPE::selected_observedObject(Loki::Type2Type<typename ARG_OBSERVER_TYPE::DC_OBJECT_TYPE>())

        //! Get property from selected subject
        #define selGET_(ARG_OBSERVER_TYPE, \
                        ARG_PROPERTY_INDEX) \
        selOBS_(ARG_OBSERVER_TYPE) \
            ->get_property<ARG_OBSERVER_TYPE::DC_OBJECT_TYPE::UNIQUE_TYPE::UNIQUE_INDEX::ARG_PROPERTY_INDEX>()

        //! Set property to selected subject
        #define selSET_(ARG_OBSERVER_TYPE, \
                        ARG_PROPERTY_INDEX, \
                        ARG_ARGUMENT) \
        selOBS_(ARG_OBSERVER_TYPE) \
            ->set_property<ARG_OBSERVER_TYPE::DC_OBJECT_TYPE::UNIQUE_TYPE::UNIQUE_INDEX::ARG_PROPERTY_INDEX>(ARG_ARGUMENT)

        //! Notify method for derivers
        #define SELECTED_OBSERVER_CHANGED(ARG_TYPE) \
        selected_observed_object_changed(Loki::Type2Type<typename dc_objects::ARG_TYPE::UNIQUE_TYPE>)

    //!\RELATIVE_OBJECT
        //! Get relative subject
        #define relOBS_(ARG_OBSERVER_TYPE) \
        ARG_OBSERVER_TYPE::relative_observedObject(Loki::Type2Type<typename ARG_OBSERVER_TYPE::DC_OBJECT_TYPE>())

        //! Get property from relative subject
        #define relGET_(ARG_OBSERVER_TYPE, \
                        ARG_PROPERTY_INDEX) \
        relOBS_(ARG_OBSERVER_TYPE) \
            ->get_property<ARG_OBSERVER_TYPE::DC_OBJECT_TYPE::UNIQUE_TYPE::UNIQUE_INDEX::ARG_PROPERTY_INDEX>()

        //! Set property to relative subject
        #define relSET_(ARG_OBSERVER_TYPE, \
                        ARG_PROPERTY_INDEX, \
                        ARG_ARGUMENT) \
        relOBS_(ARG_OBSERVER_TYPE) \
            ->set_property<ARG_OBSERVER_TYPE::TYPE_Object2Observe_T::UNIQUE_TYPE::UNIQUE_INDEX::ARG_PROPERTY_INDEX>(ARG_ARGUMENT)

        //! Notify method for derivers
        #define RELATIVE_OBSERVER_CHANGED(ARG_TYPE) \
        relative_observed_object_changed(Loki::Type2Type<typename dc_objects::ARG_TYPE>)

    //!\ABSOLUTE_OBJECT
        //! Get absolute subject
        #define absOBS_(ARG_OBSERVER_TYPE) \
        ARG_OBSERVER_TYPE::absolut_observed_object(Loki::Type2Type<typename ARG_OBSERVER_TYPE::TYPE_Object2Observe_T>())

        //! Get property from absolute subject
        #define absGET_(ARG_OBSERVER_TYPE, \
                        ARG_PROPERTY_INDEX) \
        absOBS_(ARG_OBSERVER_TYPE) \
            ->get_property<ARG_OBSERVER_TYPE::TYPE_Object2Observe_T::UNIQUE_TYPE::UNIQUE_INDEX::ARG_PROPERTY_INDEX>()

        //! Get property to absolute subject
        #define absSET_(ARG_OBSERVER_TYPE, \
                        ARG_PROPERTY_INDEX, \
                        ARG_PROPERTY_VALUE) \
        absOBS_(ARG_OBSERVER_TYPE) \
            ->set_property<ARG_OBSERVER_TYPE::TYPE_Object2Observe_T::UNIQUE_TYPE::UNIQUE_INDEX::ARG_PROPERTY_INDEX>(ARG_PROPERTY_VALUE)

        #define absCHANGE_(ARG_OBSERVER_TYPE, \
                           ARG_CHILD_INDEX) \
        ARG_OBSERVER_TYPE::changed_observed_object_to(Loki::Type2Type<typename ARG_OBSERVER_TYPE::TYPE_Object2Observe_T>(), ARG_CHILD_INDEX);

#endif // DC_OBJECTS_OBSERVER_SCM_H_INCLUDED
