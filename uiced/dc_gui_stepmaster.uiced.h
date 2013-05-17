/********************************************************************************
** Form generated from reading UI file 'dc_gui_StepMaster.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_STEPMASTER_H
#define DC_GUI_STEPMASTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StepMaster
{
public:
    QPushButton *pb_actionButton;

    void setupUi(QWidget *StepMaster)
    {
        if (StepMaster->objectName().isEmpty())
            StepMaster->setObjectName(QString::fromUtf8("StepMaster"));
        StepMaster->resize(94, 153);
        pb_actionButton = new QPushButton(StepMaster);
        pb_actionButton->setObjectName(QString::fromUtf8("pb_actionButton"));
        pb_actionButton->setGeometry(QRect(0, 0, 35, 35));
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
        pb_actionButton->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(7);
        pb_actionButton->setFont(font);

        retranslateUi(StepMaster);

        QMetaObject::connectSlotsByName(StepMaster);
    } // setupUi

    void retranslateUi(QWidget *StepMaster)
    {
        Q_UNUSED(StepMaster);
    } // retranslateUi

};

namespace Ui {
    class StepMaster: public Ui_StepMaster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_STEPMASTER_H
