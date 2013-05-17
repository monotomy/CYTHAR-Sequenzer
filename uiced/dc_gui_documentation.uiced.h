/********************************************************************************
** Form generated from reading UI file 'dc_gui_documentation.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_DOCUMENTATION_H
#define DC_GUI_DOCUMENTATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocumentationWindow
{
public:
    QGridLayout *gridLayout;
    QPushButton *pb_pref;
    QPushButton *pb_next;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *label_content;

    void setupUi(QWidget *DocumentationWindow)
    {
        if (DocumentationWindow->objectName().isEmpty())
            DocumentationWindow->setObjectName(QString::fromUtf8("DocumentationWindow"));
        DocumentationWindow->resize(667, 669);
        DocumentationWindow->setMinimumSize(QSize(550, 650));
        DocumentationWindow->setBaseSize(QSize(550, 650));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/cythar_logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DocumentationWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(DocumentationWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pb_pref = new QPushButton(DocumentationWindow);
        pb_pref->setObjectName(QString::fromUtf8("pb_pref"));

        gridLayout->addWidget(pb_pref, 1, 0, 1, 1);

        pb_next = new QPushButton(DocumentationWindow);
        pb_next->setObjectName(QString::fromUtf8("pb_next"));

        gridLayout->addWidget(pb_next, 1, 1, 1, 1);

        scrollArea = new QScrollArea(DocumentationWindow);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 252, 249, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 253, 252, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 126, 124, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 168, 166, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        scrollArea->setPalette(palette);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 653, 627));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_content = new QLabel(scrollAreaWidgetContents);
        label_content->setObjectName(QString::fromUtf8("label_content"));

        gridLayout_2->addWidget(label_content, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 2);


        retranslateUi(DocumentationWindow);

        QMetaObject::connectSlotsByName(DocumentationWindow);
    } // setupUi

    void retranslateUi(QWidget *DocumentationWindow)
    {
        DocumentationWindow->setWindowTitle(QApplication::translate("DocumentationWindow", "CYTHAR Sequenzer inline manual", 0, QApplication::UnicodeUTF8));
        pb_pref->setText(QApplication::translate("DocumentationWindow", "pref page", 0, QApplication::UnicodeUTF8));
        pb_next->setText(QApplication::translate("DocumentationWindow", "next page", 0, QApplication::UnicodeUTF8));
        label_content->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DocumentationWindow: public Ui_DocumentationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_DOCUMENTATION_H
