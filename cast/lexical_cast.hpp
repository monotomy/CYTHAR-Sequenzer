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

#ifndef CAST_ANY2STRING_HPP_INCLUDED
#define CAST_ANY2STRING_HPP_INCLUDED

#include <boost/lexical_cast.hpp>
#include <type_traits>
#include <loki/TypeManip.h>
#include <stdint.h>
#include <sstream>

#include <dc_log_informations.h>

enum
{
    IS_NOT_ENUM = 0,
    IS_ENUM = 1,
    IS_STRING
};

//! **************************************************************************************
template<typename TYPE_return, typename TYPE_pod>  inline std::string lexical_cast(TYPE_pod, Loki::Int2Type<IS_NOT_ENUM>) noexcept;
template<typename TYPE_return, typename TYPE_enum> inline std::string lexical_cast(TYPE_enum, Loki::Int2Type<IS_ENUM>) noexcept;
template<typename TYPE_return>                     inline std::string lexical_cast(uint8_t, Loki::Int2Type<IS_NOT_ENUM>) noexcept;
template<typename TYPE_return>                     inline std::string lexical_cast(int8_t, Loki::Int2Type<IS_NOT_ENUM>) noexcept;
template<typename TYPE_return>                     inline std::string lexical_cast(bool, Loki::Int2Type<IS_NOT_ENUM>) noexcept;

inline std::string forward_string(std::string const& string_,Loki::Type2Type<std::string>) noexcept {return string_;}



//! String to String
template<typename TYPE_return, typename TYPE_any>
inline std::string lexical_cast(std::string const& string_) noexcept
{
    return string_;
}

//! Enum 2 string OR Scalar 2 string
template<typename TYPE_return, typename TYPE_any>
inline std::string lexical_cast(TYPE_any any__) noexcept
{
    return std::move(lexical_cast<std::string>(any__, Loki::Int2Type<std::is_enum<TYPE_any>::value>()));
}

//! Scalar 2 string
template<typename TYPE_return, typename TYPE_pod>
inline std::string lexical_cast(TYPE_pod pod__, Loki::Int2Type<IS_NOT_ENUM>) noexcept
{
    return std::move(boost::lexical_cast<std::string>(pod__));
}
template<typename TYPE_return>
inline std::string lexical_cast(uint8_t uchar__, Loki::Int2Type<IS_NOT_ENUM>) noexcept
{
    return std::move(boost::lexical_cast<std::string>(uint16_t{uchar__}));
}
template<typename TYPE_return>
inline std::string lexical_cast(int8_t char__, Loki::Int2Type<IS_NOT_ENUM>) noexcept
{
    return std::move(boost::lexical_cast<std::string>(int16_t{char__}));
}
template<typename TYPE_return>
inline std::string lexical_cast(bool bool__, Loki::Int2Type<IS_NOT_ENUM>) noexcept
{
    if(bool__ == true)
        return "1";
    else
        return "0";
}
//! Enum 2 string
template<typename TYPE_return, typename TYPE_enum>
inline std::string lexical_cast(TYPE_enum enum_index__, Loki::Int2Type<IS_ENUM>) noexcept
{
    return std::move(boost::lexical_cast<std::string>(static_cast<int>(enum_index__)));
}



//! **************************************************************************************
template<typename TYPE_return> inline TYPE_return lexical_cast(std::string const&, Loki::Int2Type<IS_NOT_ENUM>) noexcept;
template<typename TYPE_return> inline TYPE_return lexical_cast(std::string const&, Loki::Int2Type<IS_ENUM>) noexcept;
template<>                     inline uint8_t lexical_cast<uint8_t>(std::string const&, Loki::Int2Type<IS_ENUM>) noexcept;
template<>                     inline int8_t lexical_cast<int8_t>(std::string const&, Loki::Int2Type<IS_ENUM>) noexcept;

//! String 2 String or String 2 Value
template<typename TYPE_return> inline TYPE_return cast_2_any_or_string_2_string(std::string const& string__, Loki::Type2Type<TYPE_return>) noexcept;
template<> inline std::string cast_2_any_or_string_2_string<std::string>(std::string const& string__, Loki::Type2Type<std::string>) noexcept;

//! string 2 Enum OR string 2 Scalar
template<typename TYPE_return> inline TYPE_return lexical_cast(std::string const& string__) noexcept
{
    return lexical_cast<TYPE_return>(string__, Loki::Int2Type<std::is_enum<TYPE_return>::value>());
}

//! String 2 Scalar
template<typename TYPE_return> inline TYPE_return lexical_cast(std::string const& string__, Loki::Int2Type<IS_NOT_ENUM>) noexcept
{
    return cast_2_any_or_string_2_string<TYPE_return>(string__, Loki::Type2Type<TYPE_return>());
}

template<typename TYPE_return> inline TYPE_return cast_2_any_or_string_2_string(std::string const& string__, Loki::Type2Type<TYPE_return>) noexcept
{
    try
    {
        std::stringstream stream(string__);
        TYPE_return return_value;
        stream >> return_value;
        return return_value;
    }
    catch(...)
    {
        develINFO_(_ERR, "cast error, bad value");
        return 0;
    }
}
template<> inline std::string cast_2_any_or_string_2_string<std::string>(std::string const& string__, Loki::Type2Type<std::string>) noexcept
{
    return string__;
}

template<>
inline uint8_t lexical_cast<uint8_t>(std::string const& string__, Loki::Int2Type<IS_NOT_ENUM>) noexcept
{
    return lexical_cast<uint16_t>(string__);
}
template<>
inline int8_t lexical_cast<int8_t>(std::string const& string__, Loki::Int2Type<IS_NOT_ENUM>) noexcept
{
    return lexical_cast<uint16_t>(string__);
}
//! String 2 Enum
template<typename TYPE_return> inline TYPE_return lexical_cast(std::string const& string__, Loki::Int2Type<IS_ENUM>) noexcept
{
    return static_cast<TYPE_return>(lexical_cast<int>(string__));
}




template<typename TYPE_numeric>
static std::string build_label_value_string(std::string pre_info_, TYPE_numeric value_) noexcept
{
    return pre_info_ + lexical_cast<std::string>(value_);
}

#endif
