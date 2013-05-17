/********************************************************************************
** Form generated from reading UI file 'dc_gui_mainwindow_clipboard.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_MAINWINDOW_CLIPBOARD_H
#define DC_GUI_MAINWINDOW_CLIPBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainwindowClipboard
{
public:
    QPushButton *pb_clipboard;

    void setupUi(QWidget *MainwindowClipboard)
    {
        if (MainwindowClipboard->objectName().isEmpty())
            MainwindowClipboard->setObjectName(QString::fromUtf8("MainwindowClipboard"));
        MainwindowClipboard->resize(400, 300);
        pb_clipboard = new QPushButton(MainwindowClipboard);
        pb_clipboard->setObjectName(QString::fromUtf8("pb_clipboard"));
        pb_clipboard->setGeometry(QRect(0, 0, 51, 88));
        QPalette palette;
        QBrush brush(QColor(80, 80, 80, 255));
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
        pb_clipboard->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(7);
        font.setBold(false);
        font.setWeight(50);
        pb_clipboard->setFont(font);

        retranslateUi(MainwindowClipboard);

        QMetaObject::connectSlotsByName(MainwindowClipboard);
    } // setupUi

    void retranslateUi(QWidget *MainwindowClipboard)
    {
        MainwindowClipboard->setWindowTitle(QApplication::translate("MainwindowClipboard", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pb_clipboard->setToolTip(QApplication::translate("MainwindowClipboard", "Clipboard: drop something to drag later", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pb_clipboard->setText(QApplication::translate("MainwindowClipboard", "clipb.\n"
"\n"
"\n"
"\n"
"\n"
"", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainwindowClipboard: public Ui_MainwindowClipboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_MAINWINDOW_CLIPBOARD_H
