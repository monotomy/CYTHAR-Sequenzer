/********************************************************************************
** Form generated from reading UI file 'dc_gui_taktsaite.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_TAKTSAITE_H
#define DC_GUI_TAKTSAITE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Taktsaite
{
public:
    QPushButton *pb_actionDummy;
    QPushButton *pb_minus;
    QPushButton *pb_plus;
    QPushButton *pb_actionButton;
    QLabel *label_note_foreground;
    QFrame *bg;

    void setupUi(QWidget *Taktsaite)
    {
        if (Taktsaite->objectName().isEmpty())
            Taktsaite->setObjectName(QString::fromUtf8("Taktsaite"));
        Taktsaite->resize(135, 117);
        QFont font;
        font.setPointSize(7);
        Taktsaite->setFont(font);
        pb_actionDummy = new QPushButton(Taktsaite);
        pb_actionDummy->setObjectName(QString::fromUtf8("pb_actionDummy"));
        pb_actionDummy->setGeometry(QRect(0, 0, 35, 21));
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
        pb_actionDummy->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Sans Serif"));
        font1.setPointSize(7);
        pb_actionDummy->setFont(font1);
        pb_minus = new QPushButton(Taktsaite);
        pb_minus->setObjectName(QString::fromUtf8("pb_minus"));
        pb_minus->setGeometry(QRect(0, 21, 18, 11));
        QPalette palette1;
        QBrush brush3(QColor(140, 140, 140, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pb_minus->setPalette(palette1);
        pb_minus->setFont(font1);
        pb_plus = new QPushButton(Taktsaite);
        pb_plus->setObjectName(QString::fromUtf8("pb_plus"));
        pb_plus->setGeometry(QRect(17, 21, 18, 11));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pb_plus->setPalette(palette2);
        pb_plus->setFont(font1);
        pb_actionButton = new QPushButton(Taktsaite);
        pb_actionButton->setObjectName(QString::fromUtf8("pb_actionButton"));
        pb_actionButton->setGeometry(QRect(0, 0, 35, 21));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        pb_actionButton->setPalette(palette3);
        pb_actionButton->setFlat(true);
        label_note_foreground = new QLabel(Taktsaite);
        label_note_foreground->setObjectName(QString::fromUtf8("label_note_foreground"));
        label_note_foreground->setGeometry(QRect(0, 0, 35, 21));
        label_note_foreground->setAlignment(Qt::AlignCenter);
        bg = new QFrame(Taktsaite);
        bg->setObjectName(QString::fromUtf8("bg"));
        bg->setGeometry(QRect(0, 0, 35, 32));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        bg->setPalette(palette4);
        bg->setFrameShape(QFrame::StyledPanel);
        bg->setFrameShadow(QFrame::Raised);
        bg->setLineWidth(1);
        bg->raise();
        pb_actionDummy->raise();
        pb_minus->raise();
        pb_plus->raise();
        label_note_foreground->raise();
        pb_actionButton->raise();

        retranslateUi(Taktsaite);

        QMetaObject::connectSlotsByName(Taktsaite);
    } // setupUi

    void retranslateUi(QWidget *Taktsaite)
    {
        pb_minus->setText(QApplication::translate("Taktsaite", "-", 0, QApplication::UnicodeUTF8));
        pb_plus->setText(QApplication::translate("Taktsaite", "+", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Taktsaite);
    } // retranslateUi

};

namespace Ui {
    class Taktsaite: public Ui_Taktsaite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_TAKTSAITE_H
