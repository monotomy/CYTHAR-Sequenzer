/********************************************************************************
** Form generated from reading UI file 'dc_gui_patternmaster.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_PATTERNMASTER_H
#define DC_GUI_PATTERNMASTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Patternmaster
{
public:
    QPushButton *pb_timeDummy;
    QPushButton *pb_actionButton;
    QDial *dial_time;
    QPushButton *pb_mute;
    QFrame *bg;

    void setupUi(QWidget *Patternmaster)
    {
        if (Patternmaster->objectName().isEmpty())
            Patternmaster->setObjectName(QString::fromUtf8("Patternmaster"));
        Patternmaster->resize(308, 153);
        pb_timeDummy = new QPushButton(Patternmaster);
        pb_timeDummy->setObjectName(QString::fromUtf8("pb_timeDummy"));
        pb_timeDummy->setGeometry(QRect(0, 52, 35, 35));
        QPalette palette;
        QBrush brush(QColor(110, 110, 110, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pb_timeDummy->setPalette(palette);
        pb_actionButton = new QPushButton(Patternmaster);
        pb_actionButton->setObjectName(QString::fromUtf8("pb_actionButton"));
        pb_actionButton->setGeometry(QRect(0, 0, 35, 34));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush2(QColor(150, 147, 145, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pb_actionButton->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        pb_actionButton->setFont(font);
        dial_time = new QDial(Patternmaster);
        dial_time->setObjectName(QString::fromUtf8("dial_time"));
        dial_time->setGeometry(QRect(2, 54, 34, 34));
        dial_time->setMinimum(0);
        dial_time->setMaximum(16);
        dial_time->setPageStep(1);
        pb_mute = new QPushButton(Patternmaster);
        pb_mute->setObjectName(QString::fromUtf8("pb_mute"));
        pb_mute->setGeometry(QRect(0, 33, 35, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Sans Serif"));
        font1.setPointSize(7);
        font1.setBold(false);
        font1.setWeight(50);
        pb_mute->setFont(font1);
        bg = new QFrame(Patternmaster);
        bg->setObjectName(QString::fromUtf8("bg"));
        bg->setGeometry(QRect(0, 0, 35, 87));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        bg->setPalette(palette2);
        bg->setFrameShape(QFrame::StyledPanel);
        bg->setFrameShadow(QFrame::Raised);
        bg->setLineWidth(1);
        bg->raise();
        pb_timeDummy->raise();
        pb_actionButton->raise();
        pb_mute->raise();
        dial_time->raise();

        retranslateUi(Patternmaster);

        QMetaObject::connectSlotsByName(Patternmaster);
    } // setupUi

    void retranslateUi(QWidget *Patternmaster)
    {
        pb_actionButton->setText(QApplication::translate("Patternmaster", "PATn", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Patternmaster);
    } // retranslateUi

};

namespace Ui {
    class Patternmaster: public Ui_Patternmaster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_PATTERNMASTER_H
