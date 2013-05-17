/********************************************************************************
** Form generated from reading UI file 'dc_gui_patternsaite_mute.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_PATTERNSAITE_MUTE_H
#define DC_GUI_PATTERNSAITE_MUTE_H

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

class Ui_PatternsaiteMute
{
public:
    QPushButton *pb;
    QDial *dial_time;
    QPushButton *pb_timeDummy;
    QFrame *bg;

    void setupUi(QWidget *PatternsaiteMute)
    {
        if (PatternsaiteMute->objectName().isEmpty())
            PatternsaiteMute->setObjectName(QString::fromUtf8("PatternsaiteMute"));
        PatternsaiteMute->resize(94, 49);
        pb = new QPushButton(PatternsaiteMute);
        pb->setObjectName(QString::fromUtf8("pb"));
        pb->setGeometry(QRect(0, 0, 21, 31));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb->sizePolicy().hasHeightForWidth());
        pb->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(7);
        pb->setFont(font);
        dial_time = new QDial(PatternsaiteMute);
        dial_time->setObjectName(QString::fromUtf8("dial_time"));
        dial_time->setGeometry(QRect(19, 2, 34, 30));
        dial_time->setMinimum(0);
        dial_time->setMaximum(16);
        dial_time->setPageStep(1);
        pb_timeDummy = new QPushButton(PatternsaiteMute);
        pb_timeDummy->setObjectName(QString::fromUtf8("pb_timeDummy"));
        pb_timeDummy->setGeometry(QRect(20, 0, 31, 31));
        QPalette palette;
        QBrush brush(QColor(110, 110, 110, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pb_timeDummy->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Sans Serif"));
        pb_timeDummy->setFont(font1);
        bg = new QFrame(PatternsaiteMute);
        bg->setObjectName(QString::fromUtf8("bg"));
        bg->setGeometry(QRect(0, 0, 51, 31));
        QPalette palette1;
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush3(QColor(255, 255, 220, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        bg->setPalette(palette1);
        bg->setFrameShape(QFrame::StyledPanel);
        bg->setFrameShadow(QFrame::Raised);
        bg->setLineWidth(1);
        bg->raise();
        pb_timeDummy->raise();
        dial_time->raise();
        pb->raise();

        retranslateUi(PatternsaiteMute);

        QMetaObject::connectSlotsByName(PatternsaiteMute);
    } // setupUi

    void retranslateUi(QWidget *PatternsaiteMute)
    {
        Q_UNUSED(PatternsaiteMute);
    } // retranslateUi

};

namespace Ui {
    class PatternsaiteMute: public Ui_PatternsaiteMute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_PATTERNSAITE_MUTE_H
