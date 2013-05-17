/********************************************************************************
** Form generated from reading UI file 'dc_gui_rebeca.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_REBECA_H
#define DC_GUI_REBECA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rebeca
{
public:
    QSpinBox *input_intervall_operand;
    QSpinBox *input_intervall;
    QFrame *line_17;
    QPushButton *pb_tab_note;
    QComboBox *cb_intervall2original_operator;
    QFrame *line_114;
    QFrame *line_109;
    QComboBox *cb_results;
    QLabel *label_intervall;
    QSpinBox *input_delay;
    QComboBox *cb_original_operator;
    QLabel *label_velocityInfo_6;
    QFrame *line_113;
    QSpinBox *input_original_operand;
    QComboBox *cb_intervall_original_result2repeat_operator;
    QFrame *line_15;
    QLabel *label_delay;
    QSpinBox *input_repeat;
    QPushButton *pb_tab_velocity;
    QFrame *line_107;
    QFrame *line_14;
    QLabel *label_repeat;
    QPushButton *pb_tab_length;
    QLabel *label_velocityInfo_7;
    QComboBox *cb_intervall_operator;
    QFrame *line_110;
    QFrame *line_111;
    QLineEdit *le_original;
    QPushButton *pb_preset_mol;
    QPushButton *pb_preset_dur;
    QPushButton *pb_preset_inc_interval;
    QPushButton *pb_preset_dec_interval;
    QPushButton *pb_preset_inc_velocity;
    QPushButton *pb_preset_dec_velocity;
    QPushButton *pb_preset_inc_length;
    QPushButton *pb_preset_dec_length;
    QPushButton *pb_fir_to_range;

    void setupUi(QWidget *Rebeca)
    {
        if (Rebeca->objectName().isEmpty())
            Rebeca->setObjectName(QString::fromUtf8("Rebeca"));
        Rebeca->resize(400, 300);
        input_intervall_operand = new QSpinBox(Rebeca);
        input_intervall_operand->setObjectName(QString::fromUtf8("input_intervall_operand"));
        input_intervall_operand->setGeometry(QRect(130, 98, 51, 16));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(input_intervall_operand->sizePolicy().hasHeightForWidth());
        input_intervall_operand->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(51, 51, 51, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(234, 234, 234, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush3(QColor(169, 167, 167, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        QBrush brush4(QColor(150, 147, 145, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        QBrush brush5(QColor(244, 244, 244, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        input_intervall_operand->setPalette(palette);
        input_intervall_operand->setAlignment(Qt::AlignCenter);
        input_intervall_operand->setMinimum(-128);
        input_intervall_operand->setMaximum(127);
        input_intervall = new QSpinBox(Rebeca);
        input_intervall->setObjectName(QString::fromUtf8("input_intervall"));
        input_intervall->setGeometry(QRect(20, 98, 51, 16));
        sizePolicy.setHeightForWidth(input_intervall->sizePolicy().hasHeightForWidth());
        input_intervall->setSizePolicy(sizePolicy);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        input_intervall->setPalette(palette1);
        input_intervall->setAlignment(Qt::AlignCenter);
        input_intervall->setMinimum(0);
        input_intervall->setMaximum(95);
        line_17 = new QFrame(Rebeca);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setGeometry(QRect(180, 55, 20, 126));
        line_17->setFrameShape(QFrame::VLine);
        line_17->setFrameShadow(QFrame::Sunken);
        pb_tab_note = new QPushButton(Rebeca);
        pb_tab_note->setObjectName(QString::fromUtf8("pb_tab_note"));
        pb_tab_note->setGeometry(QRect(0, 199, 68, 39));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(8);
        pb_tab_note->setFont(font);
        cb_intervall2original_operator = new QComboBox(Rebeca);
        cb_intervall2original_operator->setObjectName(QString::fromUtf8("cb_intervall2original_operator"));
        cb_intervall2original_operator->setGeometry(QRect(130, 118, 51, 16));
        QPalette palette2;
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        cb_intervall2original_operator->setPalette(palette2);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        cb_intervall2original_operator->setFont(font1);
        cb_intervall2original_operator->setMaxVisibleItems(20);
        line_114 = new QFrame(Rebeca);
        line_114->setObjectName(QString::fromUtf8("line_114"));
        line_114->setGeometry(QRect(100, 168, 31, 26));
        line_114->setLineWidth(1);
        line_114->setFrameShape(QFrame::HLine);
        line_114->setFrameShadow(QFrame::Sunken);
        line_109 = new QFrame(Rebeca);
        line_109->setObjectName(QString::fromUtf8("line_109"));
        line_109->setGeometry(QRect(100, 43, 36, 26));
        line_109->setLineWidth(1);
        line_109->setFrameShape(QFrame::HLine);
        line_109->setFrameShadow(QFrame::Sunken);
        cb_results = new QComboBox(Rebeca);
        cb_results->setObjectName(QString::fromUtf8("cb_results"));
        cb_results->setGeometry(QRect(50, 173, 76, 16));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        cb_results->setPalette(palette3);
        cb_results->setFont(font1);
        cb_results->setMaxVisibleItems(30);
        label_intervall = new QLabel(Rebeca);
        label_intervall->setObjectName(QString::fromUtf8("label_intervall"));
        label_intervall->setGeometry(QRect(15, 83, 61, 16));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush7(QColor(144, 141, 139, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        label_intervall->setPalette(palette4);
        label_intervall->setFont(font);
        label_intervall->setAlignment(Qt::AlignCenter);
        input_delay = new QSpinBox(Rebeca);
        input_delay->setObjectName(QString::fromUtf8("input_delay"));
        input_delay->setGeometry(QRect(20, 48, 51, 16));
        sizePolicy.setHeightForWidth(input_delay->sizePolicy().hasHeightForWidth());
        input_delay->setSizePolicy(sizePolicy);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        input_delay->setPalette(palette5);
        input_delay->setAlignment(Qt::AlignCenter);
        input_delay->setMinimum(0);
        input_delay->setMaximum(95);
        cb_original_operator = new QComboBox(Rebeca);
        cb_original_operator->setObjectName(QString::fromUtf8("cb_original_operator"));
        cb_original_operator->setGeometry(QRect(75, 138, 51, 16));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        cb_original_operator->setPalette(palette6);
        cb_original_operator->setFont(font1);
        cb_original_operator->setMaxVisibleItems(20);
        label_velocityInfo_6 = new QLabel(Rebeca);
        label_velocityInfo_6->setObjectName(QString::fromUtf8("label_velocityInfo_6"));
        label_velocityInfo_6->setGeometry(QRect(20, 118, 51, 26));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        label_velocityInfo_6->setPalette(palette7);
        label_velocityInfo_6->setFont(font);
        label_velocityInfo_6->setAlignment(Qt::AlignCenter);
        line_113 = new QFrame(Rebeca);
        line_113->setObjectName(QString::fromUtf8("line_113"));
        line_113->setGeometry(QRect(180, 168, 11, 26));
        line_113->setLineWidth(1);
        line_113->setFrameShape(QFrame::HLine);
        line_113->setFrameShadow(QFrame::Sunken);
        input_original_operand = new QSpinBox(Rebeca);
        input_original_operand->setObjectName(QString::fromUtf8("input_original_operand"));
        input_original_operand->setGeometry(QRect(130, 138, 51, 16));
        sizePolicy.setHeightForWidth(input_original_operand->sizePolicy().hasHeightForWidth());
        input_original_operand->setSizePolicy(sizePolicy);
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        input_original_operand->setPalette(palette8);
        input_original_operand->setFont(font1);
        input_original_operand->setAlignment(Qt::AlignCenter);
        input_original_operand->setMinimum(-128);
        input_original_operand->setMaximum(127);
        cb_intervall_original_result2repeat_operator = new QComboBox(Rebeca);
        cb_intervall_original_result2repeat_operator->setObjectName(QString::fromUtf8("cb_intervall_original_result2repeat_operator"));
        cb_intervall_original_result2repeat_operator->setGeometry(QRect(130, 173, 51, 16));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        cb_intervall_original_result2repeat_operator->setPalette(palette9);
        cb_intervall_original_result2repeat_operator->setFont(font1);
        cb_intervall_original_result2repeat_operator->setMaxVisibleItems(20);
        line_15 = new QFrame(Rebeca);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setGeometry(QRect(90, 55, 20, 91));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);
        label_delay = new QLabel(Rebeca);
        label_delay->setObjectName(QString::fromUtf8("label_delay"));
        label_delay->setGeometry(QRect(20, 63, 51, 16));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        label_delay->setPalette(palette10);
        label_delay->setFont(font);
        label_delay->setAlignment(Qt::AlignCenter);
        input_repeat = new QSpinBox(Rebeca);
        input_repeat->setObjectName(QString::fromUtf8("input_repeat"));
        input_repeat->setGeometry(QRect(130, 48, 51, 16));
        sizePolicy.setHeightForWidth(input_repeat->sizePolicy().hasHeightForWidth());
        input_repeat->setSizePolicy(sizePolicy);
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush);
        palette11.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        input_repeat->setPalette(palette11);
        input_repeat->setAlignment(Qt::AlignCenter);
        input_repeat->setMinimum(0);
        input_repeat->setMaximum(95);
        pb_tab_velocity = new QPushButton(Rebeca);
        pb_tab_velocity->setObjectName(QString::fromUtf8("pb_tab_velocity"));
        pb_tab_velocity->setGeometry(QRect(67, 199, 67, 39));
        pb_tab_velocity->setFont(font);
        line_107 = new QFrame(Rebeca);
        line_107->setObjectName(QString::fromUtf8("line_107"));
        line_107->setGeometry(QRect(180, 43, 11, 26));
        line_107->setLineWidth(1);
        line_107->setFrameShape(QFrame::HLine);
        line_107->setFrameShadow(QFrame::Sunken);
        line_14 = new QFrame(Rebeca);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setGeometry(QRect(144, 113, 26, 66));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);
        label_repeat = new QLabel(Rebeca);
        label_repeat->setObjectName(QString::fromUtf8("label_repeat"));
        label_repeat->setGeometry(QRect(130, 63, 51, 16));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        label_repeat->setPalette(palette12);
        label_repeat->setFont(font);
        label_repeat->setAlignment(Qt::AlignCenter);
        pb_tab_length = new QPushButton(Rebeca);
        pb_tab_length->setObjectName(QString::fromUtf8("pb_tab_length"));
        pb_tab_length->setGeometry(QRect(133, 199, 68, 39));
        pb_tab_length->setFont(font);
        label_velocityInfo_7 = new QLabel(Rebeca);
        label_velocityInfo_7->setObjectName(QString::fromUtf8("label_velocityInfo_7"));
        label_velocityInfo_7->setGeometry(QRect(55, 153, 66, 26));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        label_velocityInfo_7->setPalette(palette13);
        label_velocityInfo_7->setFont(font);
        label_velocityInfo_7->setAlignment(Qt::AlignCenter);
        cb_intervall_operator = new QComboBox(Rebeca);
        cb_intervall_operator->setObjectName(QString::fromUtf8("cb_intervall_operator"));
        cb_intervall_operator->setGeometry(QRect(75, 98, 51, 16));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::Button, brush);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush);
        palette14.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        cb_intervall_operator->setPalette(palette14);
        cb_intervall_operator->setMaxVisibleItems(20);
        line_110 = new QFrame(Rebeca);
        line_110->setObjectName(QString::fromUtf8("line_110"));
        line_110->setGeometry(QRect(50, 93, 101, 26));
        line_110->setLineWidth(1);
        line_110->setFrameShape(QFrame::HLine);
        line_110->setFrameShadow(QFrame::Sunken);
        line_111 = new QFrame(Rebeca);
        line_111->setObjectName(QString::fromUtf8("line_111"));
        line_111->setGeometry(QRect(50, 133, 101, 26));
        line_111->setLineWidth(1);
        line_111->setFrameShape(QFrame::HLine);
        line_111->setFrameShadow(QFrame::Sunken);
        le_original = new QLineEdit(Rebeca);
        le_original->setObjectName(QString::fromUtf8("le_original"));
        le_original->setGeometry(QRect(20, 138, 51, 16));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        le_original->setPalette(palette15);
        le_original->setFont(font1);
        pb_preset_mol = new QPushButton(Rebeca);
        pb_preset_mol->setObjectName(QString::fromUtf8("pb_preset_mol"));
        pb_preset_mol->setGeometry(QRect(50, 19, 51, 20));
        QPalette palette16;
        QBrush brush8(QColor(110, 110, 110, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_preset_mol->setPalette(palette16);
        pb_preset_mol->setFont(font);
        pb_preset_dur = new QPushButton(Rebeca);
        pb_preset_dur->setObjectName(QString::fromUtf8("pb_preset_dur"));
        pb_preset_dur->setGeometry(QRect(50, 0, 51, 20));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_preset_dur->setPalette(palette17);
        pb_preset_dur->setFont(font);
        pb_preset_inc_interval = new QPushButton(Rebeca);
        pb_preset_inc_interval->setObjectName(QString::fromUtf8("pb_preset_inc_interval"));
        pb_preset_inc_interval->setGeometry(QRect(0, 0, 51, 20));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_preset_inc_interval->setPalette(palette18);
        pb_preset_inc_interval->setFont(font);
        pb_preset_dec_interval = new QPushButton(Rebeca);
        pb_preset_dec_interval->setObjectName(QString::fromUtf8("pb_preset_dec_interval"));
        pb_preset_dec_interval->setGeometry(QRect(0, 19, 51, 20));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette19.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette19.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette19.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_preset_dec_interval->setPalette(palette19);
        pb_preset_dec_interval->setFont(font);
        pb_preset_inc_velocity = new QPushButton(Rebeca);
        pb_preset_inc_velocity->setObjectName(QString::fromUtf8("pb_preset_inc_velocity"));
        pb_preset_inc_velocity->setGeometry(QRect(100, 0, 51, 20));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette20.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette20.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette20.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_preset_inc_velocity->setPalette(palette20);
        pb_preset_inc_velocity->setFont(font);
        pb_preset_dec_velocity = new QPushButton(Rebeca);
        pb_preset_dec_velocity->setObjectName(QString::fromUtf8("pb_preset_dec_velocity"));
        pb_preset_dec_velocity->setGeometry(QRect(100, 19, 51, 20));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette21.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette21.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette21.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_preset_dec_velocity->setPalette(palette21);
        pb_preset_dec_velocity->setFont(font);
        pb_preset_inc_length = new QPushButton(Rebeca);
        pb_preset_inc_length->setObjectName(QString::fromUtf8("pb_preset_inc_length"));
        pb_preset_inc_length->setGeometry(QRect(150, 0, 51, 20));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette22.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette22.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette22.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_preset_inc_length->setPalette(palette22);
        pb_preset_inc_length->setFont(font);
        pb_preset_dec_length = new QPushButton(Rebeca);
        pb_preset_dec_length->setObjectName(QString::fromUtf8("pb_preset_dec_length"));
        pb_preset_dec_length->setGeometry(QRect(150, 19, 51, 20));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette23.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette23.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette23.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette23.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette23.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_preset_dec_length->setPalette(palette23);
        pb_preset_dec_length->setFont(font);
        pb_fir_to_range = new QPushButton(Rebeca);
        pb_fir_to_range->setObjectName(QString::fromUtf8("pb_fir_to_range"));
        pb_fir_to_range->setGeometry(QRect(20, 173, 26, 16));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette24.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette24.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette24.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette24.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette24.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_fir_to_range->setPalette(palette24);
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Sans Serif"));
        font2.setPointSize(7);
        pb_fir_to_range->setFont(font2);
        line_111->raise();
        line_110->raise();
        line_14->raise();
        line_15->raise();
        input_intervall_operand->raise();
        input_intervall->raise();
        line_17->raise();
        pb_tab_note->raise();
        cb_intervall2original_operator->raise();
        line_114->raise();
        line_109->raise();
        cb_results->raise();
        label_intervall->raise();
        input_delay->raise();
        cb_original_operator->raise();
        label_velocityInfo_6->raise();
        line_113->raise();
        input_original_operand->raise();
        cb_intervall_original_result2repeat_operator->raise();
        label_delay->raise();
        input_repeat->raise();
        pb_tab_velocity->raise();
        line_107->raise();
        label_repeat->raise();
        pb_tab_length->raise();
        label_velocityInfo_7->raise();
        cb_intervall_operator->raise();
        le_original->raise();
        pb_preset_mol->raise();
        pb_preset_dur->raise();
        pb_preset_inc_interval->raise();
        pb_preset_dec_interval->raise();
        pb_preset_inc_velocity->raise();
        pb_preset_dec_velocity->raise();
        pb_preset_inc_length->raise();
        pb_preset_dec_length->raise();
        pb_fir_to_range->raise();

        retranslateUi(Rebeca);

        QMetaObject::connectSlotsByName(Rebeca);
    } // setupUi

    void retranslateUi(QWidget *Rebeca)
    {
#ifndef QT_NO_TOOLTIP
        input_intervall_operand->setToolTip(QApplication::translate("Rebeca", "Interval operand", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        input_intervall_operand->setPrefix(QString());
#ifndef QT_NO_TOOLTIP
        input_intervall->setToolTip(QApplication::translate("Rebeca", "Interval left hand", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        input_intervall->setPrefix(QString());
        pb_tab_note->setText(QApplication::translate("Rebeca", "NOTE", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cb_intervall2original_operator->setToolTip(QApplication::translate("Rebeca", "Interval 2 original result operand", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        cb_results->setToolTip(QApplication::translate("Rebeca", "Rebeca result data", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_intervall->setText(QApplication::translate("Rebeca", "interval", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        input_delay->setToolTip(QApplication::translate("Rebeca", "Delay", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        input_delay->setPrefix(QString());
#ifndef QT_NO_TOOLTIP
        cb_original_operator->setToolTip(QApplication::translate("Rebeca", "original operator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_velocityInfo_6->setText(QApplication::translate("Rebeca", "orginal", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        input_original_operand->setToolTip(QApplication::translate("Rebeca", "Original operand", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        input_original_operand->setPrefix(QString());
#ifndef QT_NO_TOOLTIP
        cb_intervall_original_result2repeat_operator->setToolTip(QApplication::translate("Rebeca", "Repeat 2 interval/original result operand", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_delay->setText(QApplication::translate("Rebeca", "delay", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        input_repeat->setToolTip(QApplication::translate("Rebeca", "Repeat steps", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        input_repeat->setPrefix(QString());
        pb_tab_velocity->setText(QApplication::translate("Rebeca", "VELOCITY", 0, QApplication::UnicodeUTF8));
        label_repeat->setText(QApplication::translate("Rebeca", "repeat", 0, QApplication::UnicodeUTF8));
        pb_tab_length->setText(QApplication::translate("Rebeca", "LENGTH", 0, QApplication::UnicodeUTF8));
        label_velocityInfo_7->setText(QApplication::translate("Rebeca", "results", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cb_intervall_operator->setToolTip(QApplication::translate("Rebeca", "Interval operator", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        le_original->setToolTip(QApplication::translate("Rebeca", "Original left hand", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pb_preset_mol->setText(QApplication::translate("Rebeca", "min", 0, QApplication::UnicodeUTF8));
        pb_preset_dur->setText(QApplication::translate("Rebeca", "maj", 0, QApplication::UnicodeUTF8));
        pb_preset_inc_interval->setText(QApplication::translate("Rebeca", "int+", 0, QApplication::UnicodeUTF8));
        pb_preset_dec_interval->setText(QApplication::translate("Rebeca", "int-", 0, QApplication::UnicodeUTF8));
        pb_preset_inc_velocity->setText(QApplication::translate("Rebeca", "vel+", 0, QApplication::UnicodeUTF8));
        pb_preset_dec_velocity->setText(QApplication::translate("Rebeca", "vel-", 0, QApplication::UnicodeUTF8));
        pb_preset_inc_length->setText(QApplication::translate("Rebeca", "len+", 0, QApplication::UnicodeUTF8));
        pb_preset_dec_length->setText(QApplication::translate("Rebeca", "len-", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pb_fir_to_range->setToolTip(QApplication::translate("Rebeca", "Fit to large values to allowed range", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pb_fir_to_range->setText(QApplication::translate("Rebeca", "fit", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Rebeca);
    } // retranslateUi

};

namespace Ui {
    class Rebeca: public Ui_Rebeca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_REBECA_H
