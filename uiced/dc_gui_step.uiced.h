/********************************************************************************
** Form generated from reading UI file 'dc_gui_Step.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_STEP_H
#define DC_GUI_STEP_H

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

class Ui_Step
{
public:
    QPushButton *pb_actionDummy;
    QPushButton *pb_minus;
    QPushButton *pb_plus;
    QFrame *frame_barContainer;
    QFrame *frame_progressbar;
    QFrame *frame_matrix;
    QLabel *label_note_foreground;
    QPushButton *pb_actionButton;
    QFrame *bg;
    QFrame *frame_has_delay;
    QFrame *frame_has_rebeca;

    void setupUi(QWidget *Step)
    {
        if (Step->objectName().isEmpty())
            Step->setObjectName(QString::fromUtf8("Step"));
        Step->resize(336, 209);
        Step->setAutoFillBackground(false);
        pb_actionDummy = new QPushButton(Step);
        pb_actionDummy->setObjectName(QString::fromUtf8("pb_actionDummy"));
        pb_actionDummy->setGeometry(QRect(0, 0, 35, 27));
        pb_minus = new QPushButton(Step);
        pb_minus->setObjectName(QString::fromUtf8("pb_minus"));
        pb_minus->setGeometry(QRect(0, 27, 18, 11));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(150, 147, 145, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pb_minus->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(7);
        pb_minus->setFont(font);
        pb_plus = new QPushButton(Step);
        pb_plus->setObjectName(QString::fromUtf8("pb_plus"));
        pb_plus->setGeometry(QRect(17, 27, 18, 11));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pb_plus->setPalette(palette1);
        pb_plus->setFont(font);
        frame_barContainer = new QFrame(Step);
        frame_barContainer->setObjectName(QString::fromUtf8("frame_barContainer"));
        frame_barContainer->setGeometry(QRect(0, 0, 35, 26));
        frame_progressbar = new QFrame(frame_barContainer);
        frame_progressbar->setObjectName(QString::fromUtf8("frame_progressbar"));
        frame_progressbar->setGeometry(QRect(4, 13, 28, 4));
        frame_matrix = new QFrame(frame_barContainer);
        frame_matrix->setObjectName(QString::fromUtf8("frame_matrix"));
        frame_matrix->setGeometry(QRect(4, 18, 30, 6));
        label_note_foreground = new QLabel(frame_barContainer);
        label_note_foreground->setObjectName(QString::fromUtf8("label_note_foreground"));
        label_note_foreground->setGeometry(QRect(0, 0, 35, 16));
        QPalette palette2;
        QBrush brush2(QColor(40, 40, 40, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(118, 118, 117, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_note_foreground->setPalette(palette2);
        label_note_foreground->setFont(font);
        label_note_foreground->setAlignment(Qt::AlignCenter);
        pb_actionButton = new QPushButton(Step);
        pb_actionButton->setObjectName(QString::fromUtf8("pb_actionButton"));
        pb_actionButton->setGeometry(QRect(0, 0, 35, 27));
        QPalette palette3;
        QBrush brush4(QColor(0, 0, 0, 0));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        QBrush brush5(QColor(223, 220, 217, 0));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush5);
        QBrush brush6(QColor(255, 255, 255, 0));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush7(QColor(239, 237, 236, 0));
        brush7.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush7);
        QBrush brush8(QColor(111, 110, 108, 0));
        brush8.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush8);
        QBrush brush9(QColor(149, 147, 145, 0));
        brush9.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        QBrush brush10(QColor(255, 128, 0, 40));
        brush10.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush10);
        palette3.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        QBrush brush11(QColor(0, 0, 192, 0));
        brush11.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Link, brush11);
        QBrush brush12(QColor(100, 74, 155, 0));
        brush12.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::LinkVisited, brush12);
        QBrush brush13(QColor(255, 0, 255, 0));
        brush13.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette3.setBrush(QPalette::Active, QPalette::NoRole, brush4);
        QBrush brush14(QColor(255, 255, 220, 0));
        brush14.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush14);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        QBrush brush15(QColor(255, 128, 0, 0));
        brush15.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush15);
        palette3.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Link, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::NoRole, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        QBrush brush16(QColor(205, 200, 198, 0));
        brush16.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Link, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::NoRole, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        pb_actionButton->setPalette(palette3);
        bg = new QFrame(Step);
        bg->setObjectName(QString::fromUtf8("bg"));
        bg->setGeometry(QRect(0, 0, 35, 38));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush17(QColor(0, 0, 0, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush17);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush17);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush17);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush17);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush17);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush17);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush17);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush17);
        QBrush brush18(QColor(255, 255, 220, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush18);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush18);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush18);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush17);
        bg->setPalette(palette4);
        bg->setFrameShape(QFrame::StyledPanel);
        bg->setFrameShadow(QFrame::Raised);
        bg->setLineWidth(1);
        frame_has_delay = new QFrame(Step);
        frame_has_delay->setObjectName(QString::fromUtf8("frame_has_delay"));
        frame_has_delay->setGeometry(QRect(4, 5, 4, 4));
        QPalette palette5;
        QBrush brush19(QColor(120, 120, 120, 255));
        brush19.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush19);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush20(QColor(77, 35, 0, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush20);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush19);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush20);
        QBrush brush21(QColor(144, 141, 139, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush21);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush20);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush20);
        frame_has_delay->setPalette(palette5);
        frame_has_delay->setAutoFillBackground(true);
        frame_has_delay->setFrameShape(QFrame::Box);
        frame_has_rebeca = new QFrame(Step);
        frame_has_rebeca->setObjectName(QString::fromUtf8("frame_has_rebeca"));
        frame_has_rebeca->setGeometry(QRect(28, 5, 4, 4));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush19);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush20);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush19);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush20);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush21);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush20);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush20);
        frame_has_rebeca->setPalette(palette6);
        frame_has_rebeca->setAutoFillBackground(true);
        frame_has_rebeca->setFrameShape(QFrame::Box);
        bg->raise();
        pb_actionDummy->raise();
        pb_minus->raise();
        pb_plus->raise();
        frame_barContainer->raise();
        frame_has_delay->raise();
        frame_has_rebeca->raise();
        pb_actionButton->raise();

        retranslateUi(Step);

        QMetaObject::connectSlotsByName(Step);
    } // setupUi

    void retranslateUi(QWidget *Step)
    {
        pb_minus->setText(QApplication::translate("Step", "-", 0, QApplication::UnicodeUTF8));
        pb_plus->setText(QApplication::translate("Step", "+", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Step);
    } // retranslateUi

};

namespace Ui {
    class Step: public Ui_Step {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_STEP_H
