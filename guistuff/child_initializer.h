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

#ifndef GUI_INITALIZER_H_INCLUDED
#define GUI_INITALIZER_H_INCLUDED

#include <QFrame>
#include <QDesktopWidget>

namespace guistruff{

    inline void set_widget_center_desktop(QWidget* widget__) noexcept;

    inline void set_widget_center_desktop(QWidget* widget__) noexcept
    {
        widget__->move(QApplication::desktop()->screen()->rect().center()
                       -widget__->rect().center());
    }

    class ChildInitializer
    {

    protected:
        virtual void initialize_at_frame(QFrame *) noexcept {};

        ChildInitializer()  = default;
        ~ChildInitializer() = default;
    };



    /***********************************************************************/
    /*! \functor    _4GroupSpaceInitializer
                    Initalisiert x Elemente mit extra Abstand nach 4 Elementen
    */
    /***********************************************************************/
    template
    <
        class GuiElement,
        int SUM_ELEMENTS,
        int LEFT,
        int TOP,
        int HEIGTH,
        int WIDTH,
        int _2LEFT_SPACE,
        int _4GROUP_SPACE
    >
    struct _4GroupSpaceInitializer
    {
        static void initialize_at_frame(QFrame *parent_frame) noexcept
        {
            int _4group_counter{4};
            int temp_left{LEFT};
            for( int elements{0} ; SUM_ELEMENTS != elements ; ++elements )
            {
                GuiElement* guielement{new GuiElement{}};

                if( elements != 0 )
                {
                    if( _4group_counter == 0 )
                    {
                        temp_left += WIDTH + _4GROUP_SPACE;
                        _4group_counter = 4;
                    }
                    else
                        temp_left += WIDTH + _2LEFT_SPACE;
                }
                --_4group_counter;

                guielement->setGeometry(temp_left,
                                           TOP,
                                           WIDTH,
                                           HEIGTH);
                guielement->setParent(parent_frame);
                guielement->init();
                guielement->setVisible(true);
            }
        }

        /// DEPRECATED VERSION!!! See & use the next
        static void initialize_at_frame_with_secondId(QFrame *parent_frame) noexcept
        {
            int _4group_counter{4};
            int temp_left{LEFT};
            for( int elements{0} ; SUM_ELEMENTS != elements ; ++elements )
            {
                GuiElement* guielement{new GuiElement{}};   // SECOND ID "id__" AS CTOR ARG!

                if( elements != 0 )
                {
                    if( _4group_counter == 0 )
                    {
                        temp_left += WIDTH + _4GROUP_SPACE;
                        _4group_counter = 4;
                    }
                    else
                        temp_left += WIDTH + _2LEFT_SPACE;
                }
                --_4group_counter;

                guielement->setGeometry(temp_left,
                                           TOP,
                                           WIDTH,
                                           HEIGTH);
                guielement->setParent(parent_frame);
                guielement->init();
                guielement->setVisible(true);
            }
        }

        static void initialize_at_frame_with_xyId(QFrame *parent_frame) noexcept
        {
            int _4group_counter{4};
            int temp_left{LEFT};
            for( size_t elements{0} ; SUM_ELEMENTS != elements ; ++elements )
            {
                GuiElement* guielement(new GuiElement);   // SECOND ID "id__" AS CTOR ARG!

                if( elements != 0 )
                {
                    if( _4group_counter == 0 )
                    {
                        temp_left += WIDTH + _4GROUP_SPACE;
                        _4group_counter = 4;
                    }
                    else
                        temp_left += WIDTH + _2LEFT_SPACE;
                }
                --_4group_counter;

                guielement->setGeometry(temp_left,
                                           TOP,
                                           WIDTH,
                                           HEIGTH);
                guielement->setParent(parent_frame);
                guielement->init();
                guielement->setVisible(true);
            }
        }

    };


}

#endif // GUI_INITALIZER_H_INCLUDED
