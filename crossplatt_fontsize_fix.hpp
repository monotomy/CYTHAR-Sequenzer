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

#ifndef CROSSPLATT_FONTSIZE_FIX_HPP_INCLUDED
#define CROSSPLATT_FONTSIZE_FIX_HPP_INCLUDED

#include <QObject>
#include <QObjectList>
#include <QStringList>
#include <QFont>
#include <QWidget>
#include <QComboBox>
#include <QLabel>

namespace crossplatt_fontsizefix{

    static void adjust_fontsize_for_mac(QWidget *rootWidget)
    {
        if (rootWidget == NULL)
            return;

        QObject *child = NULL;
        QObjectList Containers;
        QObject *container  = NULL;
        //QStringList DoNotAffect;

        int increase_button_size_operand = 3;
        int increase_other_size_operand = 1;

        // Append root to containers
        Containers.append(rootWidget);
        while (!Containers.isEmpty())
        {
            container = Containers.takeFirst();
            if (container != NULL)
            {
                for (int ChIdx=0; ChIdx < container->children().size(); ChIdx++)
                {
                    child = container->children()[ChIdx];
                    //if (child->isWidgetType() == false)
                    //    continue;
                    // Append containers to Stack for recursion
                    if (child->children().size() > 0)
                        Containers.append(child);

                    QWidget *widget = qobject_cast<QWidget *>(child);
                    if (widget != NULL)
                    {
                        QFont font = widget->font();

                        QPushButton *button = qobject_cast<QPushButton *>(child);
                        if(button != NULL)
                            // QButton & QLabel have other size than the rest
                            font.setPointSize(font.pointSize()+increase_button_size_operand);
                        else
                        {
                            QLabel *label = qobject_cast<QLabel *>(child);
                            if(label != NULL)
                                // QButton & QLabel have other size than the rest
                                font.setPointSize(font.pointSize()+increase_button_size_operand);
                            else
                                // Rest
                                font.setPointSize(font.pointSize()+increase_other_size_operand);
                        }


                        widget->setFont(font);
                    }
                }
            }
        }
    }

}

#endif // CROSSPLATT_FONTSIZE_FIX_HPP_INCLUDED
