/********************************************************************************
** Form generated from reading UI file 'dc_gui_stepeditor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_STEPEDITOR_H
#define DC_GUI_STEPEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stepeditor
{
public:
    QFrame *frame_carrier;
    QPushButton *pb_DummyButton_StepBG;
    QFrame *editbarMatrix_container;
    QFrame *frame_4_4_frame;
    QPushButton *pb_4_4;
    QPushButton *pb_1_4;
    QPushButton *pb_2_4;
    QPushButton *pb_3_4;
    QFrame *frame_1_8;
    QPushButton *pb_1_8;
    QFrame *frame_1_16;
    QPushButton *pb_1_16;
    QFrame *frame_1_32;
    QPushButton *pb_1_32;
    QFrame *frame_2_96_frame;
    QPushButton *pb_1_96;
    QPushButton *pb_2_96;
    QLabel *label_plus_0;
    QLabel *label_plus_1;
    QLabel *label_plus_2;
    QLabel *label_plus_3;
    QSlider *slider_velocity;
    QLabel *label_velocityInfo;
    QLabel *label_lengthInfo;
    QSlider *slider_length;
    QLabel *label_length_2;
    QSpinBox *input_inc_fulllengths;
    QPushButton *pb_preset_triplet_3;
    QPushButton *pb_preset_triplet_1;
    QPushButton *pb_preset_triplet_2;
    QPushButton *pb_preset_triplet_0;
    QPushButton *pb_preset_double_pointed_0;
    QPushButton *pb_preset_double_pointed_3;
    QPushButton *pb_preset_double_pointed_1;
    QPushButton *pb_preset_double_pointed_2;

    void setupUi(QWidget *Stepeditor)
    {
        if (Stepeditor->objectName().isEmpty())
            Stepeditor->setObjectName(QString::fromUtf8("Stepeditor"));
        Stepeditor->resize(201, 363);
        frame_carrier = new QFrame(Stepeditor);
        frame_carrier->setObjectName(QString::fromUtf8("frame_carrier"));
        frame_carrier->setGeometry(QRect(0, 0, 201, 241));
        frame_carrier->setAutoFillBackground(false);
        pb_DummyButton_StepBG = new QPushButton(frame_carrier);
        pb_DummyButton_StepBG->setObjectName(QString::fromUtf8("pb_DummyButton_StepBG"));
        pb_DummyButton_StepBG->setEnabled(false);
        pb_DummyButton_StepBG->setGeometry(QRect(0, 0, 201, 240));
        QPalette palette;
        QBrush brush(QColor(80, 80, 80, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pb_DummyButton_StepBG->setPalette(palette);
        pb_DummyButton_StepBG->setCheckable(true);
        pb_DummyButton_StepBG->setChecked(true);
        editbarMatrix_container = new QFrame(frame_carrier);
        editbarMatrix_container->setObjectName(QString::fromUtf8("editbarMatrix_container"));
        editbarMatrix_container->setGeometry(QRect(10, 95, 181, 41));
        QFont font;
        font.setPointSize(6);
        editbarMatrix_container->setFont(font);
        frame_4_4_frame = new QFrame(editbarMatrix_container);
        frame_4_4_frame->setObjectName(QString::fromUtf8("frame_4_4_frame"));
        frame_4_4_frame->setGeometry(QRect(0, 0, 41, 41));
        pb_4_4 = new QPushButton(frame_4_4_frame);
        pb_4_4->setObjectName(QString::fromUtf8("pb_4_4"));
        pb_4_4->setGeometry(QRect(0, 0, 20, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Sans Serif"));
        font1.setPointSize(6);
        pb_4_4->setFont(font1);
        pb_1_4 = new QPushButton(frame_4_4_frame);
        pb_1_4->setObjectName(QString::fromUtf8("pb_1_4"));
        pb_1_4->setGeometry(QRect(21, 0, 20, 21));
        pb_1_4->setFont(font1);
        pb_2_4 = new QPushButton(frame_4_4_frame);
        pb_2_4->setObjectName(QString::fromUtf8("pb_2_4"));
        pb_2_4->setGeometry(QRect(21, 20, 20, 21));
        pb_2_4->setFont(font1);
        pb_3_4 = new QPushButton(frame_4_4_frame);
        pb_3_4->setObjectName(QString::fromUtf8("pb_3_4"));
        pb_3_4->setGeometry(QRect(0, 20, 20, 21));
        pb_3_4->setFont(font1);
        frame_1_8 = new QFrame(editbarMatrix_container);
        frame_1_8->setObjectName(QString::fromUtf8("frame_1_8"));
        frame_1_8->setGeometry(QRect(50, 10, 21, 21));
        pb_1_8 = new QPushButton(frame_1_8);
        pb_1_8->setObjectName(QString::fromUtf8("pb_1_8"));
        pb_1_8->setGeometry(QRect(0, 0, 21, 21));
        pb_1_8->setFont(font1);
        frame_1_16 = new QFrame(editbarMatrix_container);
        frame_1_16->setObjectName(QString::fromUtf8("frame_1_16"));
        frame_1_16->setGeometry(QRect(80, 10, 21, 21));
        pb_1_16 = new QPushButton(frame_1_16);
        pb_1_16->setObjectName(QString::fromUtf8("pb_1_16"));
        pb_1_16->setGeometry(QRect(0, 0, 21, 21));
        pb_1_16->setFont(font1);
        frame_1_32 = new QFrame(editbarMatrix_container);
        frame_1_32->setObjectName(QString::fromUtf8("frame_1_32"));
        frame_1_32->setGeometry(QRect(110, 10, 21, 21));
        pb_1_32 = new QPushButton(frame_1_32);
        pb_1_32->setObjectName(QString::fromUtf8("pb_1_32"));
        pb_1_32->setGeometry(QRect(0, 0, 21, 21));
        pb_1_32->setFont(font1);
        frame_2_96_frame = new QFrame(editbarMatrix_container);
        frame_2_96_frame->setObjectName(QString::fromUtf8("frame_2_96_frame"));
        frame_2_96_frame->setGeometry(QRect(140, 0, 41, 41));
        pb_1_96 = new QPushButton(frame_2_96_frame);
        pb_1_96->setObjectName(QString::fromUtf8("pb_1_96"));
        pb_1_96->setGeometry(QRect(0, 0, 41, 21));
        pb_1_96->setFont(font1);
        pb_2_96 = new QPushButton(frame_2_96_frame);
        pb_2_96->setObjectName(QString::fromUtf8("pb_2_96"));
        pb_2_96->setGeometry(QRect(0, 20, 41, 21));
        pb_2_96->setFont(font1);
        label_plus_0 = new QLabel(editbarMatrix_container);
        label_plus_0->setObjectName(QString::fromUtf8("label_plus_0"));
        label_plus_0->setGeometry(QRect(40, 0, 10, 41));
        QPalette palette1;
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        QBrush brush2(QColor(144, 141, 139, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_plus_0->setPalette(palette1);
        label_plus_0->setAlignment(Qt::AlignCenter);
        label_plus_1 = new QLabel(editbarMatrix_container);
        label_plus_1->setObjectName(QString::fromUtf8("label_plus_1"));
        label_plus_1->setGeometry(QRect(70, 0, 10, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_plus_1->setPalette(palette2);
        label_plus_1->setAlignment(Qt::AlignCenter);
        label_plus_2 = new QLabel(editbarMatrix_container);
        label_plus_2->setObjectName(QString::fromUtf8("label_plus_2"));
        label_plus_2->setGeometry(QRect(100, 0, 10, 41));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_plus_2->setPalette(palette3);
        label_plus_2->setAlignment(Qt::AlignCenter);
        label_plus_3 = new QLabel(editbarMatrix_container);
        label_plus_3->setObjectName(QString::fromUtf8("label_plus_3"));
        label_plus_3->setGeometry(QRect(130, 0, 10, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_plus_3->setPalette(palette4);
        label_plus_3->setAlignment(Qt::AlignCenter);
        slider_velocity = new QSlider(frame_carrier);
        slider_velocity->setObjectName(QString::fromUtf8("slider_velocity"));
        slider_velocity->setGeometry(QRect(10, 60, 181, 30));
        QPalette palette5;
        QBrush brush3(QColor(170, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Highlight, brush3);
        QBrush brush4(QColor(217, 217, 217, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        slider_velocity->setPalette(palette5);
        slider_velocity->setMaximum(127);
        slider_velocity->setOrientation(Qt::Horizontal);
        label_velocityInfo = new QLabel(frame_carrier);
        label_velocityInfo->setObjectName(QString::fromUtf8("label_velocityInfo"));
        label_velocityInfo->setGeometry(QRect(0, 40, 201, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_velocityInfo->setPalette(palette6);
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Sans Serif"));
        font2.setPointSize(8);
        label_velocityInfo->setFont(font2);
        label_velocityInfo->setAlignment(Qt::AlignCenter);
        label_lengthInfo = new QLabel(frame_carrier);
        label_lengthInfo->setObjectName(QString::fromUtf8("label_lengthInfo"));
        label_lengthInfo->setGeometry(QRect(0, 163, 201, 31));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_lengthInfo->setPalette(palette7);
        label_lengthInfo->setFont(font2);
        label_lengthInfo->setAlignment(Qt::AlignCenter);
        slider_length = new QSlider(frame_carrier);
        slider_length->setObjectName(QString::fromUtf8("slider_length"));
        slider_length->setGeometry(QRect(10, 145, 181, 30));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        slider_length->setPalette(palette8);
        slider_length->setMaximum(96);
        slider_length->setSingleStep(6);
        slider_length->setPageStep(24);
        slider_length->setOrientation(Qt::Horizontal);
        label_length_2 = new QLabel(frame_carrier);
        label_length_2->setObjectName(QString::fromUtf8("label_length_2"));
        label_length_2->setGeometry(QRect(140, 45, 41, 26));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label_length_2->setPalette(palette9);
        label_length_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        input_inc_fulllengths = new QSpinBox(frame_carrier);
        input_inc_fulllengths->setObjectName(QString::fromUtf8("input_inc_fulllengths"));
        input_inc_fulllengths->setGeometry(QRect(135, 170, 51, 16));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(input_inc_fulllengths->sizePolicy().hasHeightForWidth());
        input_inc_fulllengths->setSizePolicy(sizePolicy);
        QPalette palette10;
        QBrush brush6(QColor(51, 51, 51, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush6);
        QBrush brush7(QColor(234, 234, 234, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        QBrush brush8(QColor(169, 167, 167, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        QBrush brush9(QColor(150, 147, 145, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        QBrush brush10(QColor(244, 244, 244, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        input_inc_fulllengths->setPalette(palette10);
        input_inc_fulllengths->setAlignment(Qt::AlignCenter);
        input_inc_fulllengths->setMinimum(0);
        input_inc_fulllengths->setMaximum(16);
        pb_DummyButton_StepBG->raise();
        editbarMatrix_container->raise();
        label_velocityInfo->raise();
        label_lengthInfo->raise();
        slider_length->raise();
        label_length_2->raise();
        slider_velocity->raise();
        input_inc_fulllengths->raise();
        pb_preset_triplet_3 = new QPushButton(Stepeditor);
        pb_preset_triplet_3->setObjectName(QString::fromUtf8("pb_preset_triplet_3"));
        pb_preset_triplet_3->setGeometry(QRect(150, 199, 51, 39));
        QPalette palette11;
        QBrush brush11(QColor(110, 110, 110, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        pb_preset_triplet_3->setPalette(palette11);
        pb_preset_triplet_3->setFont(font2);
        pb_preset_triplet_1 = new QPushButton(Stepeditor);
        pb_preset_triplet_1->setObjectName(QString::fromUtf8("pb_preset_triplet_1"));
        pb_preset_triplet_1->setGeometry(QRect(50, 199, 51, 39));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        pb_preset_triplet_1->setPalette(palette12);
        pb_preset_triplet_1->setFont(font2);
        pb_preset_triplet_2 = new QPushButton(Stepeditor);
        pb_preset_triplet_2->setObjectName(QString::fromUtf8("pb_preset_triplet_2"));
        pb_preset_triplet_2->setGeometry(QRect(100, 199, 51, 39));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        pb_preset_triplet_2->setPalette(palette13);
        pb_preset_triplet_2->setFont(font2);
        pb_preset_triplet_0 = new QPushButton(Stepeditor);
        pb_preset_triplet_0->setObjectName(QString::fromUtf8("pb_preset_triplet_0"));
        pb_preset_triplet_0->setGeometry(QRect(0, 199, 51, 39));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        pb_preset_triplet_0->setPalette(palette14);
        pb_preset_triplet_0->setFont(font2);
        pb_preset_double_pointed_0 = new QPushButton(Stepeditor);
        pb_preset_double_pointed_0->setObjectName(QString::fromUtf8("pb_preset_double_pointed_0"));
        pb_preset_double_pointed_0->setGeometry(QRect(0, 0, 51, 39));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        pb_preset_double_pointed_0->setPalette(palette15);
        pb_preset_double_pointed_0->setFont(font2);
        pb_preset_double_pointed_3 = new QPushButton(Stepeditor);
        pb_preset_double_pointed_3->setObjectName(QString::fromUtf8("pb_preset_double_pointed_3"));
        pb_preset_double_pointed_3->setGeometry(QRect(150, 0, 51, 39));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        pb_preset_double_pointed_3->setPalette(palette16);
        pb_preset_double_pointed_3->setFont(font2);
        pb_preset_double_pointed_1 = new QPushButton(Stepeditor);
        pb_preset_double_pointed_1->setObjectName(QString::fromUtf8("pb_preset_double_pointed_1"));
        pb_preset_double_pointed_1->setGeometry(QRect(50, 0, 51, 39));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        pb_preset_double_pointed_1->setPalette(palette17);
        pb_preset_double_pointed_1->setFont(font2);
        pb_preset_double_pointed_2 = new QPushButton(Stepeditor);
        pb_preset_double_pointed_2->setObjectName(QString::fromUtf8("pb_preset_double_pointed_2"));
        pb_preset_double_pointed_2->setGeometry(QRect(100, 0, 51, 39));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        pb_preset_double_pointed_2->setPalette(palette18);
        pb_preset_double_pointed_2->setFont(font2);
        QWidget::setTabOrder(slider_velocity, slider_length);
        QWidget::setTabOrder(slider_length, pb_1_4);
        QWidget::setTabOrder(pb_1_4, pb_2_4);
        QWidget::setTabOrder(pb_2_4, pb_3_4);
        QWidget::setTabOrder(pb_3_4, pb_4_4);
        QWidget::setTabOrder(pb_4_4, pb_1_8);
        QWidget::setTabOrder(pb_1_8, pb_1_16);
        QWidget::setTabOrder(pb_1_16, pb_1_32);
        QWidget::setTabOrder(pb_1_32, pb_1_96);
        QWidget::setTabOrder(pb_1_96, pb_2_96);
        QWidget::setTabOrder(pb_2_96, pb_DummyButton_StepBG);

        retranslateUi(Stepeditor);
        QObject::connect(slider_velocity, SIGNAL(valueChanged(int)), label_length_2, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(Stepeditor);
    } // setupUi

    void retranslateUi(QWidget *Stepeditor)
    {
        pb_4_4->setText(QApplication::translate("Stepeditor", "4/4", 0, QApplication::UnicodeUTF8));
        pb_1_4->setText(QApplication::translate("Stepeditor", "1/4", 0, QApplication::UnicodeUTF8));
        pb_2_4->setText(QApplication::translate("Stepeditor", "2/4", 0, QApplication::UnicodeUTF8));
        pb_3_4->setText(QApplication::translate("Stepeditor", "3/4", 0, QApplication::UnicodeUTF8));
        pb_1_8->setText(QApplication::translate("Stepeditor", "1/8", 0, QApplication::UnicodeUTF8));
        pb_1_16->setText(QApplication::translate("Stepeditor", "16.", 0, QApplication::UnicodeUTF8));
        pb_1_32->setText(QApplication::translate("Stepeditor", "32.", 0, QApplication::UnicodeUTF8));
        pb_1_96->setText(QApplication::translate("Stepeditor", "1/96", 0, QApplication::UnicodeUTF8));
        pb_2_96->setText(QApplication::translate("Stepeditor", "2/96", 0, QApplication::UnicodeUTF8));
        label_plus_0->setText(QApplication::translate("Stepeditor", "+", 0, QApplication::UnicodeUTF8));
        label_plus_1->setText(QApplication::translate("Stepeditor", "+", 0, QApplication::UnicodeUTF8));
        label_plus_2->setText(QApplication::translate("Stepeditor", "+", 0, QApplication::UnicodeUTF8));
        label_plus_3->setText(QApplication::translate("Stepeditor", "+", 0, QApplication::UnicodeUTF8));
        label_velocityInfo->setText(QApplication::translate("Stepeditor", "velocity", 0, QApplication::UnicodeUTF8));
        label_lengthInfo->setText(QApplication::translate("Stepeditor", "length", 0, QApplication::UnicodeUTF8));
        label_length_2->setText(QString());
        input_inc_fulllengths->setPrefix(QApplication::translate("Stepeditor", "+", 0, QApplication::UnicodeUTF8));
        pb_preset_triplet_3->setText(QApplication::translate("Stepeditor", "\342\214\242\n"
"1/8\n"
"", 0, QApplication::UnicodeUTF8));
        pb_preset_triplet_1->setText(QApplication::translate("Stepeditor", "\342\214\242\n"
"2/4\n"
"", 0, QApplication::UnicodeUTF8));
        pb_preset_triplet_2->setText(QApplication::translate("Stepeditor", "\342\214\242\n"
"1/4\n"
"", 0, QApplication::UnicodeUTF8));
        pb_preset_triplet_0->setText(QApplication::translate("Stepeditor", "\342\214\242\n"
"1/1\n"
"", 0, QApplication::UnicodeUTF8));
        pb_preset_double_pointed_0->setText(QApplication::translate("Stepeditor", "2/4..", 0, QApplication::UnicodeUTF8));
        pb_preset_double_pointed_3->setText(QApplication::translate("Stepeditor", "1/16..", 0, QApplication::UnicodeUTF8));
        pb_preset_double_pointed_1->setText(QApplication::translate("Stepeditor", "1/4..", 0, QApplication::UnicodeUTF8));
        pb_preset_double_pointed_2->setText(QApplication::translate("Stepeditor", "1/8..", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Stepeditor);
    } // retranslateUi

};

namespace Ui {
    class Stepeditor: public Ui_Stepeditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_STEPEDITOR_H
