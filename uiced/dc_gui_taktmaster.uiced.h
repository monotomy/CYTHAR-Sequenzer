/********************************************************************************
** Form generated from reading UI file 'dc_gui_taktmaster.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_TAKTMASTER_H
#define DC_GUI_TAKTMASTER_H

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

class Ui_Taktmaster
{
public:
    QPushButton *pb_minus;
    QPushButton *pb_plus;
    QPushButton *pb_actionButton_Hidden;
    QPushButton *pb_actionButton;
    QLabel *label_current_chain_level;
    QFrame *bg;
    QLabel *label_current_for_time;

    void setupUi(QWidget *Taktmaster)
    {
        if (Taktmaster->objectName().isEmpty())
            Taktmaster->setObjectName(QString::fromUtf8("Taktmaster"));
        Taktmaster->resize(95, 104);
        pb_minus = new QPushButton(Taktmaster);
        pb_minus->setObjectName(QString::fromUtf8("pb_minus"));
        pb_minus->setGeometry(QRect(0, 67, 18, 12));
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
        pb_minus->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(5);
        pb_minus->setFont(font);
        pb_plus = new QPushButton(Taktmaster);
        pb_plus->setObjectName(QString::fromUtf8("pb_plus"));
        pb_plus->setGeometry(QRect(17, 67, 18, 12));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pb_plus->setPalette(palette1);
        pb_plus->setFont(font);
        pb_actionButton_Hidden = new QPushButton(Taktmaster);
        pb_actionButton_Hidden->setObjectName(QString::fromUtf8("pb_actionButton_Hidden"));
        pb_actionButton_Hidden->setGeometry(QRect(0, 0, 35, 34));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        pb_actionButton_Hidden->setFont(font1);
        pb_actionButton_Hidden->setFlat(true);
        pb_actionButton = new QPushButton(Taktmaster);
        pb_actionButton->setObjectName(QString::fromUtf8("pb_actionButton"));
        pb_actionButton->setGeometry(QRect(0, 0, 35, 34));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        pb_actionButton->setPalette(palette2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Sans Serif"));
        font2.setPointSize(8);
        pb_actionButton->setFont(font2);
        label_current_chain_level = new QLabel(Taktmaster);
        label_current_chain_level->setObjectName(QString::fromUtf8("label_current_chain_level"));
        label_current_chain_level->setGeometry(QRect(1, 16, 17, 16));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush3(QColor(144, 141, 139, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        QBrush brush4(QColor(169, 167, 167, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        label_current_chain_level->setPalette(palette3);
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Sans Serif"));
        font3.setPointSize(6);
        label_current_chain_level->setFont(font3);
        label_current_chain_level->setAlignment(Qt::AlignCenter);
        bg = new QFrame(Taktmaster);
        bg->setObjectName(QString::fromUtf8("bg"));
        bg->setGeometry(QRect(0, 0, 35, 79));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush5);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush5);
        bg->setPalette(palette4);
        bg->setFrameShape(QFrame::StyledPanel);
        bg->setFrameShadow(QFrame::Raised);
        bg->setLineWidth(1);
        label_current_for_time = new QLabel(Taktmaster);
        label_current_for_time->setObjectName(QString::fromUtf8("label_current_for_time"));
        label_current_for_time->setGeometry(QRect(17, 16, 17, 16));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        label_current_for_time->setPalette(palette5);
        label_current_for_time->setFont(font3);
        label_current_for_time->setAlignment(Qt::AlignCenter);
        bg->raise();
        pb_plus->raise();
        pb_minus->raise();
        pb_actionButton->raise();
        label_current_chain_level->raise();
        label_current_for_time->raise();
        pb_actionButton_Hidden->raise();

        retranslateUi(Taktmaster);
        QObject::connect(pb_actionButton_Hidden, SIGNAL(clicked()), pb_actionButton, SLOT(click()));

        QMetaObject::connectSlotsByName(Taktmaster);
    } // setupUi

    void retranslateUi(QWidget *Taktmaster)
    {
#ifndef QT_NO_TOOLTIP
        pb_minus->setToolTip(QApplication::translate("Taktmaster", "From E  [F -11][F# -10][G -9][G# -8][A -7][A# -6][B -5][C -4][C# -3][D -2][D# -1][E][F +1][F# +2][G +3][G# +4][A +5][A# +6][B +7][C +8][C# +9][D +10][D# +11]", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pb_minus->setText(QApplication::translate("Taktmaster", "-", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pb_plus->setToolTip(QApplication::translate("Taktmaster", "From E  [F -11][F# -10][G -9][G# -8][A -7][A# -6][B -5][C -4][C# -3][D -2][D# -1][E][F +1][F# +2][G +3][G# +4][A +5][A# +6][B +7][C +8][C# +9][D +10][D# +11]", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pb_plus->setText(QApplication::translate("Taktmaster", "+", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Taktmaster);
    } // retranslateUi

};

namespace Ui {
    class Taktmaster: public Ui_Taktmaster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_TAKTMASTER_H
