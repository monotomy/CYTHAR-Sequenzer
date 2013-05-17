/********************************************************************************
** Form generated from reading UI file 'dc_gui_Bar.ui'
**
** Created by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_BAR_H
#define DC_GUI_BAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bar
{
public:
    QPushButton *pb_actionButton;
    QPushButton *pb_minus;
    QPushButton *pb_actionDummy;
    QPushButton *pb_plus;

    void setupUi(QWidget *Bar)
    {
        if (Bar->objectName().isEmpty())
            Bar->setObjectName(QString::fromUtf8("Bar"));
        Bar->resize(94, 40);
        pb_actionButton = new QPushButton(Bar);
        pb_actionButton->setObjectName(QString::fromUtf8("pb_actionButton"));
        pb_actionButton->setGeometry(QRect(0, 0, 35, 24));
        pb_actionButton->setFlat(true);
        pb_minus = new QPushButton(Bar);
        pb_minus->setObjectName(QString::fromUtf8("pb_minus"));
        pb_minus->setGeometry(QRect(0, 24, 18, 11));
        QFont font;
        font.setPointSize(5);
        pb_minus->setFont(font);
        pb_actionDummy = new QPushButton(Bar);
        pb_actionDummy->setObjectName(QString::fromUtf8("pb_actionDummy"));
        pb_actionDummy->setGeometry(QRect(0, 0, 35, 24));
        pb_actionDummy->setCheckable(true);
        pb_plus = new QPushButton(Bar);
        pb_plus->setObjectName(QString::fromUtf8("pb_plus"));
        pb_plus->setGeometry(QRect(17, 24, 18, 11));
        pb_plus->setFont(font);
        pb_minus->raise();
        pb_actionDummy->raise();
        pb_plus->raise();
        pb_actionButton->raise();

        retranslateUi(Bar);

        QMetaObject::connectSlotsByName(Bar);
    } // setupUi

    void retranslateUi(QWidget *Bar)
    {
        pb_minus->setText(QApplication::translate("Bar", "-", 0, QApplication::UnicodeUTF8));
        pb_actionDummy->setText(QApplication::translate("Bar", "BAR", 0, QApplication::UnicodeUTF8));
        pb_plus->setText(QApplication::translate("Bar", "+", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Bar);
    } // retranslateUi

};

namespace Ui {
    class Bar: public Ui_Bar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_BAR_H
