/********************************************************************************
** Form generated from reading UI file 'dc_gui_step_matrix.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DC_GUI_STEP_MATRIX_H
#define DC_GUI_STEP_MATRIX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_matrix
{
public:
    QFrame *progressbarMatrix_container;
    QFrame *frame_4_4_partLeft;
    QFrame *frame_4_4_partRigth;
    QFrame *frame_1_8_set;
    QFrame *frame_1_16_set;
    QFrame *frame_4_4_frame;
    QFrame *frame_1_32_set;
    QFrame *frame_2_96_frame;
    QFrame *frame_2_96_part;

    void setupUi(QWidget *matrix)
    {
        if (matrix->objectName().isEmpty())
            matrix->setObjectName(QString::fromUtf8("matrix"));
        matrix->resize(94, 16);
        progressbarMatrix_container = new QFrame(matrix);
        progressbarMatrix_container->setObjectName(QString::fromUtf8("progressbarMatrix_container"));
        progressbarMatrix_container->setGeometry(QRect(0, 0, 30, 6));
        QPalette palette;
        QBrush brush(QColor(120, 120, 120, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(118, 118, 117, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        progressbarMatrix_container->setPalette(palette);
        frame_4_4_partLeft = new QFrame(progressbarMatrix_container);
        frame_4_4_partLeft->setObjectName(QString::fromUtf8("frame_4_4_partLeft"));
        frame_4_4_partLeft->setGeometry(QRect(0, 3, 3, 3));
        frame_4_4_partLeft->setAutoFillBackground(true);
        frame_4_4_partRigth = new QFrame(progressbarMatrix_container);
        frame_4_4_partRigth->setObjectName(QString::fromUtf8("frame_4_4_partRigth"));
        frame_4_4_partRigth->setGeometry(QRect(3, 0, 3, 3));
        frame_4_4_partRigth->setAutoFillBackground(true);
        frame_1_8_set = new QFrame(progressbarMatrix_container);
        frame_1_8_set->setObjectName(QString::fromUtf8("frame_1_8_set"));
        frame_1_8_set->setGeometry(QRect(7, 1, 4, 4));
        frame_1_8_set->setFrameShape(QFrame::Box);
        frame_1_16_set = new QFrame(progressbarMatrix_container);
        frame_1_16_set->setObjectName(QString::fromUtf8("frame_1_16_set"));
        frame_1_16_set->setGeometry(QRect(12, 1, 4, 4));
        frame_1_16_set->setFrameShape(QFrame::Box);
        frame_4_4_frame = new QFrame(progressbarMatrix_container);
        frame_4_4_frame->setObjectName(QString::fromUtf8("frame_4_4_frame"));
        frame_4_4_frame->setGeometry(QRect(0, 0, 6, 6));
        frame_4_4_frame->setFrameShape(QFrame::Box);
        frame_1_32_set = new QFrame(progressbarMatrix_container);
        frame_1_32_set->setObjectName(QString::fromUtf8("frame_1_32_set"));
        frame_1_32_set->setGeometry(QRect(17, 1, 4, 4));
        frame_1_32_set->setFrameShape(QFrame::Box);
        frame_2_96_frame = new QFrame(progressbarMatrix_container);
        frame_2_96_frame->setObjectName(QString::fromUtf8("frame_2_96_frame"));
        frame_2_96_frame->setGeometry(QRect(22, 0, 6, 6));
        frame_2_96_frame->setFrameShape(QFrame::Box);
        frame_2_96_part = new QFrame(progressbarMatrix_container);
        frame_2_96_part->setObjectName(QString::fromUtf8("frame_2_96_part"));
        frame_2_96_part->setGeometry(QRect(22, 0, 6, 3));
        frame_2_96_part->setAutoFillBackground(true);
        frame_2_96_part->raise();
        frame_4_4_partLeft->raise();
        frame_4_4_partRigth->raise();
        frame_1_8_set->raise();
        frame_1_16_set->raise();
        frame_4_4_frame->raise();
        frame_1_32_set->raise();
        frame_2_96_frame->raise();

        retranslateUi(matrix);

        QMetaObject::connectSlotsByName(matrix);
    } // setupUi

    void retranslateUi(QWidget *matrix)
    {
        Q_UNUSED(matrix);
    } // retranslateUi

};

namespace Ui {
    class matrix: public Ui_matrix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DC_GUI_STEP_MATRIX_H
