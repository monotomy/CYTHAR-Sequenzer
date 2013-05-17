/********************************************************************************
** Form generated from reading UI file 'dc_gui_taktchain.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_TAKTCHAIN_H
#define DC_GUI_TAKTCHAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Taktchain
{
public:
    QPushButton *pb_actionButton;
    QLabel *label_for;
    QLabel *label_next;
    QPushButton *pb_actionButton_2;
    QPushButton *pb_timeDummy;
    QLabel *label_target_chain_level;

    void setupUi(QWidget *Taktchain)
    {
        if (Taktchain->objectName().isEmpty())
            Taktchain->setObjectName(QString::fromUtf8("Taktchain"));
        Taktchain->resize(211, 63);
        pb_actionButton = new QPushButton(Taktchain);
        pb_actionButton->setObjectName(QString::fromUtf8("pb_actionButton"));
        pb_actionButton->setGeometry(QRect(0, 0, 18, 18));
        QPalette palette;
        QBrush brush(QColor(170, 0, 0, 255));
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
        pb_actionButton->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(8);
        pb_actionButton->setFont(font);
        label_for = new QLabel(Taktchain);
        label_for->setObjectName(QString::fromUtf8("label_for"));
        label_for->setGeometry(QRect(1, -1, 17, 17));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush3(QColor(144, 141, 139, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        QBrush brush4(QColor(169, 167, 167, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        label_for->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Sans Serif"));
        font1.setPointSize(6);
        label_for->setFont(font1);
        label_for->setAlignment(Qt::AlignCenter);
        label_next = new QLabel(Taktchain);
        label_next->setObjectName(QString::fromUtf8("label_next"));
        label_next->setGeometry(QRect(17, -1, 17, 17));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        label_next->setPalette(palette2);
        label_next->setFont(font1);
        label_next->setAlignment(Qt::AlignCenter);
        pb_actionButton_2 = new QPushButton(Taktchain);
        pb_actionButton_2->setObjectName(QString::fromUtf8("pb_actionButton_2"));
        pb_actionButton_2->setGeometry(QRect(17, 0, 18, 18));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pb_actionButton_2->setPalette(palette3);
        pb_actionButton_2->setFont(font);
        pb_timeDummy = new QPushButton(Taktchain);
        pb_timeDummy->setObjectName(QString::fromUtf8("pb_timeDummy"));
        pb_timeDummy->setGeometry(QRect(0, 17, 35, 18));
        QPalette palette4;
        QBrush brush5(QColor(110, 110, 110, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        pb_timeDummy->setPalette(palette4);
        label_target_chain_level = new QLabel(Taktchain);
        label_target_chain_level->setObjectName(QString::fromUtf8("label_target_chain_level"));
        label_target_chain_level->setGeometry(QRect(0, 17, 35, 17));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        label_target_chain_level->setPalette(palette5);
        label_target_chain_level->setFont(font1);
        label_target_chain_level->setAlignment(Qt::AlignCenter);
        pb_actionButton_2->raise();
        pb_actionButton->raise();
        label_for->raise();
        label_next->raise();
        pb_timeDummy->raise();
        label_target_chain_level->raise();

        retranslateUi(Taktchain);

        QMetaObject::connectSlotsByName(Taktchain);
    } // setupUi

    void retranslateUi(QWidget *Taktchain)
    {
        label_target_chain_level->setText(QString());
        Q_UNUSED(Taktchain);
    } // retranslateUi

};

namespace Ui {
    class Taktchain: public Ui_Taktchain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_TAKTCHAIN_H
