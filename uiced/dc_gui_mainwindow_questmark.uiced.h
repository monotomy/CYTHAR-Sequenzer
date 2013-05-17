/********************************************************************************
** Form generated from reading UI file 'dc_gui_mainwindow_questmark.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_MAINWINDOW_QUESTMARK_H
#define DC_GUI_MAINWINDOW_QUESTMARK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainwindowQuestmark
{
public:
    QPushButton *pb_questionmark;

    void setupUi(QWidget *MainwindowQuestmark)
    {
        if (MainwindowQuestmark->objectName().isEmpty())
            MainwindowQuestmark->setObjectName(QString::fromUtf8("MainwindowQuestmark"));
        MainwindowQuestmark->resize(400, 300);
        pb_questionmark = new QPushButton(MainwindowQuestmark);
        pb_questionmark->setObjectName(QString::fromUtf8("pb_questionmark"));
        pb_questionmark->setGeometry(QRect(0, 0, 51, 35));
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
        pb_questionmark->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("MuseJazz"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        pb_questionmark->setFont(font);

        retranslateUi(MainwindowQuestmark);

        QMetaObject::connectSlotsByName(MainwindowQuestmark);
    } // setupUi

    void retranslateUi(QWidget *MainwindowQuestmark)
    {
        MainwindowQuestmark->setWindowTitle(QApplication::translate("MainwindowQuestmark", "Form", 0, QApplication::UnicodeUTF8));
        pb_questionmark->setText(QApplication::translate("MainwindowQuestmark", "?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainwindowQuestmark: public Ui_MainwindowQuestmark {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_MAINWINDOW_QUESTMARK_H
