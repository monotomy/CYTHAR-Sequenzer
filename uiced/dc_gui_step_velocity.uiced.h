/********************************************************************************
** Form generated from reading UI file 'dc_gui_step_velocity.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_STEP_VELOCITY_H
#define DC_GUI_STEP_VELOCITY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_progressbar
{
public:
    QFrame *frame_frame;
    QFrame *frame_content;

    void setupUi(QWidget *progressbar)
    {
        if (progressbar->objectName().isEmpty())
            progressbar->setObjectName(QString::fromUtf8("progressbar"));
        progressbar->resize(28, 16);
        frame_frame = new QFrame(progressbar);
        frame_frame->setObjectName(QString::fromUtf8("frame_frame"));
        frame_frame->setGeometry(QRect(0, 0, 28, 4));
        QPalette palette;
        QBrush brush(QColor(120, 120, 120, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(118, 118, 117, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        frame_frame->setPalette(palette);
        frame_frame->setFrameShape(QFrame::Box);
        frame_content = new QFrame(frame_frame);
        frame_content->setObjectName(QString::fromUtf8("frame_content"));
        frame_content->setGeometry(QRect(1, 1, 5, 2));
        QPalette palette1;
        QBrush brush2(QColor(170, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        frame_content->setPalette(palette1);
        frame_content->setFrameShape(QFrame::Box);

        retranslateUi(progressbar);

        QMetaObject::connectSlotsByName(progressbar);
    } // setupUi

    void retranslateUi(QWidget *progressbar)
    {
        Q_UNUSED(progressbar);
    } // retranslateUi

};

namespace Ui {
    class progressbar: public Ui_progressbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_STEP_VELOCITY_H
