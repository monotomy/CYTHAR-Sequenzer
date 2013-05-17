/********************************************************************************
** Form generated from reading UI file 'dc_gui_tuneslider.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_TUNESLIDER_H
#define DC_GUI_TUNESLIDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tuneslider
{
public:
    QSlider *hs_slider;

    void setupUi(QWidget *Tuneslider)
    {
        if (Tuneslider->objectName().isEmpty())
            Tuneslider->setObjectName(QString::fromUtf8("Tuneslider"));
        Tuneslider->resize(400, 37);
        Tuneslider->setMinimumSize(QSize(0, 37));
        Tuneslider->setMaximumSize(QSize(16777215, 37));
        hs_slider = new QSlider(Tuneslider);
        hs_slider->setObjectName(QString::fromUtf8("hs_slider"));
        hs_slider->setGeometry(QRect(0, 0, 181, 29));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        QBrush brush1(QColor(217, 217, 217, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        hs_slider->setPalette(palette);
        hs_slider->setMinimum(-1);
        hs_slider->setMaximum(12);
        hs_slider->setSingleStep(1);
        hs_slider->setPageStep(12);
        hs_slider->setOrientation(Qt::Horizontal);

        retranslateUi(Tuneslider);

        QMetaObject::connectSlotsByName(Tuneslider);
    } // setupUi

    void retranslateUi(QWidget *Tuneslider)
    {
        Tuneslider->setWindowTitle(QApplication::translate("Tuneslider", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Tuneslider: public Ui_Tuneslider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_TUNESLIDER_H
