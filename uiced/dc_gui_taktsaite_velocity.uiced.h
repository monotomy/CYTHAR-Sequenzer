/********************************************************************************
** Form generated from reading UI file 'dc_gui_taktsaite_velocity.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_TAKTSAITE_VELOCITY_H
#define DC_GUI_TAKTSAITE_VELOCITY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaktsaiteVelocity
{
public:
    QDial *dial_time;
    QPushButton *pb_timeDummy;

    void setupUi(QWidget *TaktsaiteVelocity)
    {
        if (TaktsaiteVelocity->objectName().isEmpty())
            TaktsaiteVelocity->setObjectName(QString::fromUtf8("TaktsaiteVelocity"));
        TaktsaiteVelocity->resize(94, 99);
        dial_time = new QDial(TaktsaiteVelocity);
        dial_time->setObjectName(QString::fromUtf8("dial_time"));
        dial_time->setGeometry(QRect(10, 2, 34, 35));
        QPalette palette;
        QBrush brush(QColor(163, 0, 2, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        dial_time->setPalette(palette);
        dial_time->setMinimum(0);
        dial_time->setMaximum(127);
        dial_time->setPageStep(1);
        pb_timeDummy = new QPushButton(TaktsaiteVelocity);
        pb_timeDummy->setObjectName(QString::fromUtf8("pb_timeDummy"));
        pb_timeDummy->setEnabled(false);
        pb_timeDummy->setGeometry(QRect(0, 0, 51, 37));
        pb_timeDummy->raise();
        dial_time->raise();

        retranslateUi(TaktsaiteVelocity);

        QMetaObject::connectSlotsByName(TaktsaiteVelocity);
    } // setupUi

    void retranslateUi(QWidget *TaktsaiteVelocity)
    {
        TaktsaiteVelocity->setWindowTitle(QApplication::translate("TaktsaiteVelocity", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dial_time->setToolTip(QApplication::translate("TaktsaiteVelocity", "TimeMute ::: set the number of bars to mute this pattern.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class TaktsaiteVelocity: public Ui_TaktsaiteVelocity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_TAKTSAITE_VELOCITY_H
