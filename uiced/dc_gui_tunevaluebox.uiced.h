/********************************************************************************
** Form generated from reading UI file 'dc_gui_tunevaluebox.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_TUNEVALUEBOX_H
#define DC_GUI_TUNEVALUEBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tunevaluebox
{
public:
    QPushButton *pb;

    void setupUi(QWidget *Tunevaluebox)
    {
        if (Tunevaluebox->objectName().isEmpty())
            Tunevaluebox->setObjectName(QString::fromUtf8("Tunevaluebox"));
        Tunevaluebox->resize(400, 300);
        pb = new QPushButton(Tunevaluebox);
        pb->setObjectName(QString::fromUtf8("pb"));
        pb->setEnabled(true);
        pb->setGeometry(QRect(0, 0, 51, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(150, 147, 145, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pb->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(8);
        pb->setFont(font);

        retranslateUi(Tunevaluebox);

        QMetaObject::connectSlotsByName(Tunevaluebox);
    } // setupUi

    void retranslateUi(QWidget *Tunevaluebox)
    {
        Tunevaluebox->setWindowTitle(QApplication::translate("Tunevaluebox", "Form", 0, QApplication::UnicodeUTF8));
        pb->setText(QApplication::translate("Tunevaluebox", "40.A#.SD2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Tunevaluebox: public Ui_Tunevaluebox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_TUNEVALUEBOX_H
