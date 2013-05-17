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

#ifndef EXTENDQT_EXCLUSIVE_BOX_HPP_INCLUDED
#define EXTENDQT_EXCLUSIVE_BOX_HPP_INCLUDED

#ifdef DEBUG
    #include <iostream>
#endif // DEBUG

namespace gui{

//!\class ExclusiveBox
    #define TEMP_DEF_ExclusiveBox \
        class EnumClass, \
        class POLICY_set_exclusive, \
        class POLICY_set_unexclusive

    #define TEMP_SPEZ_ExclusiveBox \
        EnumClass, \
        POLICY_set_exclusive, \
        POLICY_set_unexclusive

    template<TEMP_DEF_ExclusiveBox>
    ExclusiveBox<TEMP_SPEZ_ExclusiveBox>
    ::ExclusiveBox(std::array<std::pair<EnumClass, QWidget*const*>, enum_size> elements_2_index__) noexcept :
        _exclusive_elements(cast_from_init_array_to_array(elements_2_index__))
    {}

    template<TEMP_DEF_ExclusiveBox>
    template<class INIT_pairARRAY>
    inline typename ExclusiveBox<TEMP_SPEZ_ExclusiveBox>::TYPE_element_container ExclusiveBox<TEMP_SPEZ_ExclusiveBox>
    ::cast_from_init_array_to_array(INIT_pairARRAY const& elements2cast__) noexcept
    {
        TYPE_element_container castet_elements;
        for(size_t i{0} ; i != enum_size ; ++i)
        {
            size_t key(static_cast<int>(elements2cast__[i].first));
            auto element_ptr2ptr(elements2cast__[i].second);

            castet_elements[key] = element_ptr2ptr;
        }

        return std::move(castet_elements);
    }


    template<TEMP_DEF_ExclusiveBox>
    inline void ExclusiveBox<TEMP_SPEZ_ExclusiveBox>
    ::set_element_per_id_exclusive(EnumClass element_id__) noexcept
    {
    #ifdef DEBUG
        if(static_cast<size_t>(element_id__) >= enum_size)
            std::cout << "BUG: Exclusive Box will access unaviable element!" << std::endl;
    #endif // DEBUG

        for(size_t id{0} ; id != enum_size ; ++ id )
            if(id != static_cast<size_t>(element_id__))
                POLICY_set_unexclusive::exec(*_exclusive_elements[id]);
            else
                POLICY_set_exclusive::exec(*_exclusive_elements[id]);
    }
}

#endif // EXTENDQT_EXCLUSIVE_BOX_HPP_INCLUDED
