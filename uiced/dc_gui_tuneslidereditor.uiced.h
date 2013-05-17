/********************************************************************************
** Form generated from reading UI file 'dc_gui_tuneslidereditor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_TUNESLIDEREDITOR_H
#define DC_GUI_TUNESLIDEREDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tuneslidereditor
{
public:
    QPushButton *pb_viewAccord;
    QPushButton *pb_defaultTune;
    QPushButton *pb_viewTune;
    QPushButton *pb_defaultDrum;
    QSlider *hs_transpose;
    QPushButton *pb_accord_0;
    QPushButton *pb_accord_1;
    QPushButton *pb_accord_2;
    QPushButton *pb_accord_3;
    QPushButton *pb_accord_4;
    QPushButton *pb_accord_6;
    QPushButton *pb_accord_7;
    QPushButton *pb_accord_5;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *layout_sliderScale_3;
    QFrame *line_40;
    QFrame *line_41;
    QFrame *line_42;
    QFrame *line_43;
    QFrame *line_44;
    QFrame *line_45;
    QFrame *line_46;
    QFrame *line_47;
    QFrame *line_48;
    QFrame *line_49;
    QFrame *line_50;
    QFrame *line_51;
    QFrame *line_111;
    QLabel *label_length_2;

    void setupUi(QWidget *Tuneslidereditor)
    {
        if (Tuneslidereditor->objectName().isEmpty())
            Tuneslidereditor->setObjectName(QString::fromUtf8("Tuneslidereditor"));
        Tuneslidereditor->resize(393, 421);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        QBrush brush1(QColor(217, 217, 217, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        Tuneslidereditor->setPalette(palette);
        pb_viewAccord = new QPushButton(Tuneslidereditor);
        pb_viewAccord->setObjectName(QString::fromUtf8("pb_viewAccord"));
        pb_viewAccord->setGeometry(QRect(100, 367, 101, 34));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Sans Serif"));
        font.setPointSize(8);
        pb_viewAccord->setFont(font);
        pb_defaultTune = new QPushButton(Tuneslidereditor);
        pb_defaultTune->setObjectName(QString::fromUtf8("pb_defaultTune"));
        pb_defaultTune->setGeometry(QRect(0, 0, 101, 34));
        QPalette palette1;
        QBrush brush2(QColor(110, 110, 110, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        QBrush brush4(QColor(150, 147, 145, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_defaultTune->setPalette(palette1);
        pb_defaultTune->setFont(font);
        pb_viewTune = new QPushButton(Tuneslidereditor);
        pb_viewTune->setObjectName(QString::fromUtf8("pb_viewTune"));
        pb_viewTune->setGeometry(QRect(0, 367, 101, 34));
        pb_viewTune->setFont(font);
        pb_defaultDrum = new QPushButton(Tuneslidereditor);
        pb_defaultDrum->setObjectName(QString::fromUtf8("pb_defaultDrum"));
        pb_defaultDrum->setGeometry(QRect(100, 0, 101, 34));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_defaultDrum->setPalette(palette2);
        pb_defaultDrum->setFont(font);
        hs_transpose = new QSlider(Tuneslidereditor);
        hs_transpose->setObjectName(QString::fromUtf8("hs_transpose"));
        hs_transpose->setGeometry(QRect(10, 296, 181, 31));
        QPalette palette3;
        QBrush brush5(QColor(82, 82, 82, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        hs_transpose->setPalette(palette3);
        hs_transpose->setMinimum(-24);
        hs_transpose->setMaximum(24);
        hs_transpose->setSingleStep(1);
        hs_transpose->setPageStep(12);
        hs_transpose->setOrientation(Qt::Horizontal);
        pb_accord_0 = new QPushButton(Tuneslidereditor);
        pb_accord_0->setObjectName(QString::fromUtf8("pb_accord_0"));
        pb_accord_0->setGeometry(QRect(0, 336, 26, 21));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_accord_0->setPalette(palette4);
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Sans Serif"));
        font1.setPointSize(7);
        pb_accord_0->setFont(font1);
        pb_accord_1 = new QPushButton(Tuneslidereditor);
        pb_accord_1->setObjectName(QString::fromUtf8("pb_accord_1"));
        pb_accord_1->setGeometry(QRect(25, 336, 26, 21));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_accord_1->setPalette(palette5);
        pb_accord_1->setFont(font1);
        pb_accord_2 = new QPushButton(Tuneslidereditor);
        pb_accord_2->setObjectName(QString::fromUtf8("pb_accord_2"));
        pb_accord_2->setGeometry(QRect(50, 336, 26, 21));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_accord_2->setPalette(palette6);
        pb_accord_2->setFont(font1);
        pb_accord_3 = new QPushButton(Tuneslidereditor);
        pb_accord_3->setObjectName(QString::fromUtf8("pb_accord_3"));
        pb_accord_3->setGeometry(QRect(75, 336, 26, 21));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_accord_3->setPalette(palette7);
        pb_accord_3->setFont(font1);
        pb_accord_4 = new QPushButton(Tuneslidereditor);
        pb_accord_4->setObjectName(QString::fromUtf8("pb_accord_4"));
        pb_accord_4->setGeometry(QRect(100, 336, 26, 21));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_accord_4->setPalette(palette8);
        pb_accord_4->setFont(font1);
        pb_accord_6 = new QPushButton(Tuneslidereditor);
        pb_accord_6->setObjectName(QString::fromUtf8("pb_accord_6"));
        pb_accord_6->setGeometry(QRect(150, 336, 26, 21));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_accord_6->setPalette(palette9);
        pb_accord_6->setFont(font1);
        pb_accord_7 = new QPushButton(Tuneslidereditor);
        pb_accord_7->setObjectName(QString::fromUtf8("pb_accord_7"));
        pb_accord_7->setGeometry(QRect(175, 336, 26, 21));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_accord_7->setPalette(palette10);
        pb_accord_7->setFont(font1);
        pb_accord_5 = new QPushButton(Tuneslidereditor);
        pb_accord_5->setObjectName(QString::fromUtf8("pb_accord_5"));
        pb_accord_5->setGeometry(QRect(125, 336, 26, 21));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pb_accord_5->setPalette(palette11);
        pb_accord_5->setFont(font1);
        horizontalLayoutWidget_2 = new QWidget(Tuneslidereditor);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(9, 96, 181, 191));
        layout_sliderScale_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        layout_sliderScale_3->setSpacing(6);
        layout_sliderScale_3->setObjectName(QString::fromUtf8("layout_sliderScale_3"));
        layout_sliderScale_3->setContentsMargins(22, 0, 0, 0);
        line_40 = new QFrame(horizontalLayoutWidget_2);
        line_40->setObjectName(QString::fromUtf8("line_40"));
        QPalette palette12;
        QBrush brush6(QColor(178, 177, 177, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QBrush brush7(QColor(118, 118, 117, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_40->setPalette(palette12);
        line_40->setFrameShape(QFrame::VLine);
        line_40->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_40);

        line_41 = new QFrame(horizontalLayoutWidget_2);
        line_41->setObjectName(QString::fromUtf8("line_41"));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_41->setPalette(palette13);
        line_41->setFrameShape(QFrame::VLine);
        line_41->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_41);

        line_42 = new QFrame(horizontalLayoutWidget_2);
        line_42->setObjectName(QString::fromUtf8("line_42"));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_42->setPalette(palette14);
        line_42->setFrameShape(QFrame::VLine);
        line_42->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_42);

        line_43 = new QFrame(horizontalLayoutWidget_2);
        line_43->setObjectName(QString::fromUtf8("line_43"));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_43->setPalette(palette15);
        line_43->setFrameShape(QFrame::VLine);
        line_43->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_43);

        line_44 = new QFrame(horizontalLayoutWidget_2);
        line_44->setObjectName(QString::fromUtf8("line_44"));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_44->setPalette(palette16);
        line_44->setFrameShape(QFrame::VLine);
        line_44->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_44);

        line_45 = new QFrame(horizontalLayoutWidget_2);
        line_45->setObjectName(QString::fromUtf8("line_45"));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_45->setPalette(palette17);
        line_45->setFrameShape(QFrame::VLine);
        line_45->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_45);

        line_46 = new QFrame(horizontalLayoutWidget_2);
        line_46->setObjectName(QString::fromUtf8("line_46"));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_46->setPalette(palette18);
        line_46->setFrameShape(QFrame::VLine);
        line_46->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_46);

        line_47 = new QFrame(horizontalLayoutWidget_2);
        line_47->setObjectName(QString::fromUtf8("line_47"));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_47->setPalette(palette19);
        line_47->setFrameShape(QFrame::VLine);
        line_47->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_47);

        line_48 = new QFrame(horizontalLayoutWidget_2);
        line_48->setObjectName(QString::fromUtf8("line_48"));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_48->setPalette(palette20);
        line_48->setFrameShape(QFrame::VLine);
        line_48->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_48);

        line_49 = new QFrame(horizontalLayoutWidget_2);
        line_49->setObjectName(QString::fromUtf8("line_49"));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_49->setPalette(palette21);
        line_49->setFrameShape(QFrame::VLine);
        line_49->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_49);

        line_50 = new QFrame(horizontalLayoutWidget_2);
        line_50->setObjectName(QString::fromUtf8("line_50"));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_50->setPalette(palette22);
        line_50->setFrameShape(QFrame::VLine);
        line_50->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_50);

        line_51 = new QFrame(horizontalLayoutWidget_2);
        line_51->setObjectName(QString::fromUtf8("line_51"));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_51->setPalette(palette23);
        line_51->setFrameShape(QFrame::VLine);
        line_51->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_51);

        line_111 = new QFrame(horizontalLayoutWidget_2);
        line_111->setObjectName(QString::fromUtf8("line_111"));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        line_111->setPalette(palette24);
        line_111->setFrameShape(QFrame::VLine);
        line_111->setFrameShadow(QFrame::Sunken);

        layout_sliderScale_3->addWidget(line_111);

        label_length_2 = new QLabel(Tuneslidereditor);
        label_length_2->setObjectName(QString::fromUtf8("label_length_2"));
        label_length_2->setGeometry(QRect(140, 313, 41, 21));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush8(QColor(144, 141, 139, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette25.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        label_length_2->setPalette(palette25);
        label_length_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pb_viewAccord->raise();
        pb_viewTune->raise();
        hs_transpose->raise();
        pb_accord_0->raise();
        pb_accord_1->raise();
        pb_accord_2->raise();
        pb_accord_3->raise();
        pb_accord_4->raise();
        pb_accord_6->raise();
        pb_accord_7->raise();
        pb_accord_5->raise();
        horizontalLayoutWidget_2->raise();
        pb_defaultDrum->raise();
        pb_defaultTune->raise();
        label_length_2->raise();

        retranslateUi(Tuneslidereditor);
        QObject::connect(hs_transpose, SIGNAL(valueChanged(int)), label_length_2, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(Tuneslidereditor);
    } // setupUi

    void retranslateUi(QWidget *Tuneslidereditor)
    {
        Tuneslidereditor->setWindowTitle(QApplication::translate("Tuneslidereditor", "Form", 0, QApplication::UnicodeUTF8));
        pb_viewAccord->setText(QApplication::translate("Tuneslidereditor", "CHORD", 0, QApplication::UnicodeUTF8));
        pb_defaultTune->setText(QApplication::translate("Tuneslidereditor", "set EAdgbe", 0, QApplication::UnicodeUTF8));
        pb_viewTune->setText(QApplication::translate("Tuneslidereditor", "TUNE", 0, QApplication::UnicodeUTF8));
        pb_defaultDrum->setText(QApplication::translate("Tuneslidereditor", "set drum", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        hs_transpose->setToolTip(QApplication::translate("Tuneslidereditor", "From E  [F -11][F# -10][G -9][G# -8][A -7][A# -6][B -5][C -4][C# -3][D -2][D# -1][E][F +1][F# +2][G +3][G# +4][A +5][A# +6][B +7][C +8][C# +9][D +10][D# +11]", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pb_accord_0->setText(QApplication::translate("Tuneslidereditor", "maj", 0, QApplication::UnicodeUTF8));
        pb_accord_1->setText(QApplication::translate("Tuneslidereditor", "min", 0, QApplication::UnicodeUTF8));
        pb_accord_2->setText(QApplication::translate("Tuneslidereditor", "7", 0, QApplication::UnicodeUTF8));
        pb_accord_3->setText(QApplication::translate("Tuneslidereditor", "mi7", 0, QApplication::UnicodeUTF8));
        pb_accord_4->setText(QApplication::translate("Tuneslidereditor", "maj7", 0, QApplication::UnicodeUTF8));
        pb_accord_6->setText(QApplication::translate("Tuneslidereditor", "6", 0, QApplication::UnicodeUTF8));
        pb_accord_7->setText(QApplication::translate("Tuneslidereditor", "sus2", 0, QApplication::UnicodeUTF8));
        pb_accord_5->setText(QApplication::translate("Tuneslidereditor", "sus4", 0, QApplication::UnicodeUTF8));
        label_length_2->setText(QApplication::translate("Tuneslidereditor", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Tuneslidereditor: public Ui_Tuneslidereditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_TUNESLIDEREDITOR_H
