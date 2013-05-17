/********************************************************************************
** Form generated from reading UI file 'dc_gui_midideviceeditor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_MIDIDEVICEEDITOR_H
#define DC_GUI_MIDIDEVICEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Midideviceeditor
{
public:
    QComboBox *cb_device;
    QComboBox *cb_channel;

    void setupUi(QWidget *Midideviceeditor)
    {
        if (Midideviceeditor->objectName().isEmpty())
            Midideviceeditor->setObjectName(QString::fromUtf8("Midideviceeditor"));
        Midideviceeditor->resize(400, 300);
        cb_device = new QComboBox(Midideviceeditor);
        cb_device->setObjectName(QString::fromUtf8("cb_device"));
        cb_device->setGeometry(QRect(0, 3, 111, 25));
        QPalette palette;
        QBrush brush(QColor(40, 40, 40, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush2(QColor(150, 147, 145, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        cb_device->setPalette(palette);
        cb_device->setMaxVisibleItems(20);
        cb_channel = new QComboBox(Midideviceeditor);
        cb_channel->setObjectName(QString::fromUtf8("cb_channel"));
        cb_channel->setGeometry(QRect(120, 3, 41, 25));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        cb_channel->setPalette(palette1);
        cb_channel->setMaxVisibleItems(20);

        retranslateUi(Midideviceeditor);

        QMetaObject::connectSlotsByName(Midideviceeditor);
    } // setupUi

    void retranslateUi(QWidget *Midideviceeditor)
    {
        Midideviceeditor->setWindowTitle(QApplication::translate("Midideviceeditor", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cb_device->setToolTip(QApplication::translate("Midideviceeditor", "MIDI Device: choose an available device ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        cb_channel->setToolTip(QApplication::translate("Midideviceeditor", "MIDI Channel: choose one of 16 available channels", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class Midideviceeditor: public Ui_Midideviceeditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_MIDIDEVICEEDITOR_H
