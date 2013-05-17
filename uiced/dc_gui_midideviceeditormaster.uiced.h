/********************************************************************************
** Form generated from reading UI file 'dc_gui_midideviceeditormaster.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_MIDIDEVICEEDITORMASTER_H
#define DC_GUI_MIDIDEVICEEDITORMASTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Midideviceeditormaster
{
public:
    QFrame *frame_carrier_2;
    QPushButton *pB_set2all;
    QComboBox *cb_channel_all;
    QComboBox *cb_device_all;
    QPushButton *pB_refresh;
    QFrame *line_109;
    QFrame *line_15;
    QFrame *line_16;
    QComboBox *cb_device_in;
    QPushButton *pb_set_midi_in_device;

    void setupUi(QWidget *Midideviceeditormaster)
    {
        if (Midideviceeditormaster->objectName().isEmpty())
            Midideviceeditormaster->setObjectName(QString::fromUtf8("Midideviceeditormaster"));
        Midideviceeditormaster->resize(400, 544);
        frame_carrier_2 = new QFrame(Midideviceeditormaster);
        frame_carrier_2->setObjectName(QString::fromUtf8("frame_carrier_2"));
        frame_carrier_2->setGeometry(QRect(0, 0, 201, 401));
        pB_set2all = new QPushButton(frame_carrier_2);
        pB_set2all->setObjectName(QString::fromUtf8("pB_set2all"));
        pB_set2all->setGeometry(QRect(0, 367, 201, 34));
        QPalette palette;
        QBrush brush(QColor(110, 110, 110, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush2(QColor(150, 147, 145, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pB_set2all->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(8);
        pB_set2all->setFont(font);
        cb_channel_all = new QComboBox(frame_carrier_2);
        cb_channel_all->setObjectName(QString::fromUtf8("cb_channel_all"));
        cb_channel_all->setGeometry(QRect(140, 313, 41, 28));
        QPalette palette1;
        QBrush brush3(QColor(40, 40, 40, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        QBrush brush4(QColor(176, 176, 176, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        cb_channel_all->setPalette(palette1);
        cb_channel_all->setMaxVisibleItems(20);
        cb_device_all = new QComboBox(frame_carrier_2);
        cb_device_all->setObjectName(QString::fromUtf8("cb_device_all"));
        cb_device_all->setGeometry(QRect(20, 313, 111, 28));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        cb_device_all->setPalette(palette2);
        cb_device_all->setMaxVisibleItems(20);
        pB_refresh = new QPushButton(frame_carrier_2);
        pB_refresh->setObjectName(QString::fromUtf8("pB_refresh"));
        pB_refresh->setGeometry(QRect(0, 0, 201, 34));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush5(QColor(106, 104, 100, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        pB_refresh->setPalette(palette3);
        pB_refresh->setFont(font);
        line_109 = new QFrame(frame_carrier_2);
        line_109->setObjectName(QString::fromUtf8("line_109"));
        line_109->setGeometry(QRect(15, 310, 171, 31));
        line_109->setLineWidth(1);
        line_109->setFrameShape(QFrame::HLine);
        line_109->setFrameShadow(QFrame::Sunken);
        line_15 = new QFrame(frame_carrier_2);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setGeometry(QRect(5, 325, 20, 56));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);
        line_16 = new QFrame(frame_carrier_2);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setGeometry(QRect(175, 325, 20, 56));
        line_16->setFrameShape(QFrame::VLine);
        line_16->setFrameShadow(QFrame::Sunken);
        cb_device_in = new QComboBox(frame_carrier_2);
        cb_device_in->setObjectName(QString::fromUtf8("cb_device_in"));
        cb_device_in->setGeometry(QRect(20, 45, 111, 28));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush3);
        QBrush brush6(QColor(176, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        cb_device_in->setPalette(palette4);
        cb_device_in->setMaxVisibleItems(20);
        pb_set_midi_in_device = new QPushButton(frame_carrier_2);
        pb_set_midi_in_device->setObjectName(QString::fromUtf8("pb_set_midi_in_device"));
        pb_set_midi_in_device->setGeometry(QRect(140, 45, 41, 28));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pb_set_midi_in_device->setPalette(palette5);
        pb_set_midi_in_device->setFont(font);
        line_109->raise();
        cb_device_in->raise();
        cb_device_all->raise();
        line_16->raise();
        line_15->raise();
        pB_set2all->raise();
        cb_channel_all->raise();
        pB_refresh->raise();
        pb_set_midi_in_device->raise();

        retranslateUi(Midideviceeditormaster);

        cb_device_all->setCurrentIndex(-1);
        cb_device_in->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Midideviceeditormaster);
    } // setupUi

    void retranslateUi(QWidget *Midideviceeditormaster)
    {
        pB_set2all->setText(QApplication::translate("Midideviceeditormaster", "set to all strings", 0, QApplication::UnicodeUTF8));
        pB_refresh->setText(QApplication::translate("Midideviceeditormaster", "refresh devices", 0, QApplication::UnicodeUTF8));
        pb_set_midi_in_device->setText(QApplication::translate("Midideviceeditormaster", "setIN", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Midideviceeditormaster);
    } // retranslateUi

};

namespace Ui {
    class Midideviceeditormaster: public Ui_Midideviceeditormaster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_MIDIDEVICEEDITORMASTER_H
