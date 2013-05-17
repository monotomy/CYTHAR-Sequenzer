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

#ifndef DC_ALGROITHM_REBECA_HPP_INCLUDED
#define DC_ALGROITHM_REBECA_HPP_INCLUDED

#include <dc_objectstructure.h>
#include <dc_objectobserver.h>
#include <stddef.h>

#include <vector>

#ifdef DEBUG
    #include <iostream>
#endif // DEBUG

namespace dc_algorithm{

    using namespace dc_objects;

    static inline int calc_one_repeat_step(int const left_hand_basevalue__,
                                           OPERATOR const _operator_,
                                           int const operand__) noexcept
    {
        switch (_operator_)
        {
        case OPERATOR::NOT:
            return left_hand_basevalue__;

        case OPERATOR::PLUS:
            return left_hand_basevalue__+operand__;

        case OPERATOR::MINUS:
            return left_hand_basevalue__-operand__ ;

        case OPERATOR::MULTI:
            if(operand__ != 0)
                return left_hand_basevalue__*operand__;
            /*else*/
            return left_hand_basevalue__;

        case OPERATOR::DIV:
            if(operand__ != 0)
                return left_hand_basevalue__/operand__;
            /*else*/
            return left_hand_basevalue__;

        case OPERATOR::MODULA:
            if(operand__ != 0)
                return left_hand_basevalue__%operand__;
            /*else*/
            return left_hand_basevalue__;

        default:
            return 0;
        }
    }

    typedef std::vector<int> TYPE_series;

    //! Berechnet eine einfache Serie
    static inline TYPE_series calc_a_series(int const left_hand_basevalue__,
                                            OPERATOR const _operator_,
                                            int const operand__,
                                            size_t const repeat_steps__) noexcept
    {
        TYPE_series results_serie{};
        if(repeat_steps__ == 0)
            return results_serie;

        int repeat_step_result_or_base{left_hand_basevalue__};
        for(size_t repeat_step{0} ; repeat_step != repeat_steps__ ; ++repeat_step)
        {
            repeat_step_result_or_base = calc_one_repeat_step(repeat_step_result_or_base,
                                                              _operator_,
                                                              operand__);
            results_serie.push_back(repeat_step_result_or_base);
        }

        return results_serie;
    }

    //! Verrechnet zwei Serien per Eintrag mit _operator_ zu neuer Serie
    inline static TYPE_series calc_two_series(TYPE_series const& left_hand_serie__,
                                              OPERATOR const _operator_,
                                              TYPE_series const& operand_serie__) noexcept
    {
    #ifdef DEBUG
        if(left_hand_serie__.size() != operand_serie__.size())
            std::cout << "BUG: Series incompatible!" << std::endl;
    #endif // DEBUG

        TYPE_series results_serie{};
        for(size_t repeat_step{0};
            repeat_step != left_hand_serie__.size();
            ++repeat_step)
        {
            results_serie.push_back(calc_one_repeat_step(left_hand_serie__[repeat_step],
                                                         _operator_,
                                                         operand_serie__[repeat_step]));
        }

        return std::move(results_serie);
    }

    //! Verrechnet Serien mit der Eintrags Id = Repeatstep
    inline static TYPE_series calc_serie_by_index(TYPE_series const& left_hand_serie__,
                                                  OPERATOR const _operator_) noexcept
    {
        TYPE_series results_serie{};
        for(size_t repeat_step{0};
            repeat_step != left_hand_serie__.size();
            ++repeat_step)
        {
            results_serie.push_back(calc_one_repeat_step(left_hand_serie__[repeat_step],
                                                         _operator_,
                                                         repeat_step));
        }

        return std::move(results_serie);
    }

    //! Berechnung von Rebeca für Interval
    static inline TYPE_series calc_rebeca_for_interval(dc_objects::Step const* step__)
    {
        //auto delay(step__->get_property<StepPropertiesIndex::DELAY>());
        auto repeat_steps(step__->get_property<StepPropertiesIndex::REPEAT_TIMES>());
        auto interval(step__->get_property<StepPropertiesIndex::INTERVAL>());
        auto operator_(step__->get_property<StepPropertiesIndex::INTERVAL_OPERATOR>());
        auto operand_(step__->get_property<StepPropertiesIndex::INTERVAL_OPERAND>());

        return calc_a_series(interval,
                             static_cast<OPERATOR>(operator_),
                             operand_,
                             repeat_steps);
    }
    //! Berechnung von Rebeca für einfache Offset Serie
    static inline TYPE_series calc_rebeca_for_offset(dc_objects::Step const* step__)
    {
        //auto delay(step__->get_property<StepPropertiesIndex::DELAY>());
        auto repeat_steps(step__->get_property<StepPropertiesIndex::REPEAT_TIMES>());
        auto offset(step__->get_property<StepPropertiesIndex::OFFSET>());
        auto operator_(step__->get_property<StepPropertiesIndex::OFFSET_OPERATOR>());
        auto operand_(step__->get_property<StepPropertiesIndex::OFFSET_OPERAND>());

        return calc_a_series(offset,
                             static_cast<OPERATOR>(operator_),
                             operand_,
                             repeat_steps);
    }
    //! Berechnung von Rebeca für einfache Velcocity Serie
    static inline TYPE_series calc_rebeca_for_velocity(dc_objects::Step const* step__)
    {
        //auto delay(step__->get_property<StepPropertiesIndex::DELAY>());
        auto repeat_steps(step__->get_property<StepPropertiesIndex::REPEAT_TIMES>());
        auto velocity(step__->get_property<StepPropertiesIndex::VELOCITY>());
        auto operator_(step__->get_property<StepPropertiesIndex::VELOCITY_OPERATOR>());
        auto operand_(step__->get_property<StepPropertiesIndex::VELOCITY_OPERAND>());

        return calc_a_series(velocity,
                             static_cast<OPERATOR>(operator_),
                             operand_,
                             repeat_steps);
    }
    //! Berechnung von Rebeca für Length
    static inline TYPE_series calc_rebeca_for_length(dc_objects::Step const* step__)
    {
        //auto delay(step__->get_property<StepPropertiesIndex::DELAY>());
        auto repeat_steps(step__->get_property<StepPropertiesIndex::REPEAT_TIMES>());
        auto length(step__->get_property<StepPropertiesIndex::LENGTH>());
        auto operator_(step__->get_property<StepPropertiesIndex::LENGTH_OPERATOR>());
        auto operand_(step__->get_property<StepPropertiesIndex::LENGTH_OPERAND>());

        return calc_a_series(length,
                             static_cast<OPERATOR>(operator_),
                             operand_,
                             repeat_steps);
    }

    template<int MIN, int MAX>
    static inline TYPE_series fit_series_to_range(TYPE_series serie__) noexcept
    {
        for(size_t i{0} ; i!= serie__.size() ; ++i)
        {
            if(serie__[i] < MIN)
            {
                serie__[i] = MIN;
                continue;
            }

            if(serie__[i] > MAX)
                serie__[i] = MAX;
        }

        return std::move(serie__);
    }

    //! Berechnung zwischen Offset-Interval & Repeat serie
    static inline TYPE_series calc_rebeca_for_offet_complete(dc_objects::Step const* step__)
    {
        // Zwischenrechnung
        auto offset2interval_serie(calc_two_series(calc_rebeca_for_offset(step__), //! atNOT will pass offset.
                                                   static_cast<OPERATOR>(step__->get_property<StepPropertiesIndex::OFFSET_2_INTERVAL_OPERATOR>()),
                                                   calc_rebeca_for_interval(step__)));
        // Final Result
        auto offset_series(calc_serie_by_index(offset2interval_serie,
                                               static_cast<OPERATOR>(step__->get_property<StepPropertiesIndex::OFFSET_INTERVAL_2_REPEAT_OPERATOR>())));
        // Abschnippel?
        if(step__->get_property<StepPropertiesIndex::OFFSET_FIT_TO_RANGE>() == true)
            offset_series = fit_series_to_range<OFFSET_MIN,OFFSET_MAX>(std::move(offset_series));

        return offset_series;
    }

    //! Berechnung zwischen Velocity-Interval & Repeat serie
    static inline TYPE_series calc_rebeca_for_velocity_complete(dc_objects::Step const* step__)
    {
        // Zwischenrechnung
        auto velocity2interval_serie(calc_two_series(calc_rebeca_for_velocity(step__), //! atNOT will pass velocity.
                                                     static_cast<OPERATOR>(step__->get_property<StepPropertiesIndex::VELOCITY_2_INTERVAL_OPERATOR>()),
                                                     calc_rebeca_for_interval(step__)));
        // Final Result
        auto velocity_series(calc_serie_by_index(velocity2interval_serie,
                                                 static_cast<OPERATOR>(step__->get_property<StepPropertiesIndex::VELOCITY_INTERVAL_2_REPEAT_OPERATOR>())));
        // Abschnippel?
        if(step__->get_property<StepPropertiesIndex::VELOCITY_FIT_TO_RANGE>() == true)
            velocity_series = fit_series_to_range<VELOCITY_MIN,VELOCITY_MAX>(std::move(velocity_series));

        return velocity_series;
    }

    //! Berechnung zwischen Length-Interval & Repeat serie
    static inline TYPE_series calc_rebeca_for_length_complete(dc_objects::Step const* step__)
    {
        // Zwischenrechnung
        auto length2interval_serie(calc_two_series(calc_rebeca_for_length(step__), //! atNOT will pass length.
                                                   static_cast<OPERATOR>(step__->get_property<StepPropertiesIndex::LENGTH_2_INTERVAL_OPERATOR>()),
                                                   calc_rebeca_for_interval(step__)));

        // Final Result
        auto length_series(calc_serie_by_index(length2interval_serie,
                                               static_cast<OPERATOR>(step__->get_property<StepPropertiesIndex::LENGTH_INTERVAL_2_REPEAT_OPERATOR>())));
        // Abschnippel?
        if(step__->get_property<StepPropertiesIndex::LENGTH_FIT_TO_RANGE>() == true)
            length_series = fit_series_to_range<LENGTH_MIN,LENGTH_MAX>(std::move(length_series));

        return length_series;
    }
}

#endif // DC_ALGROITHM_REBECA_HPP_INCLUDED
