/********************************************************************************
** Form generated from reading UI file 'humiwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUMIWIDGET_H
#define UI_HUMIWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HumiWidget
{
public:
    QFrame *frame;
    QProgressBar *progressBar_3;
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QProgressBar *progressBar_5;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_4;

    void setupUi(QWidget *HumiWidget)
    {
        if (HumiWidget->objectName().isEmpty())
            HumiWidget->setObjectName(QStringLiteral("HumiWidget"));
        HumiWidget->resize(1024, 600);
        frame = new QFrame(HumiWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(159, 0, 871, 520));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        progressBar_3 = new QProgressBar(frame);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setGeometry(QRect(320, 240, 171, 23));
        progressBar_3->setValue(24);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 50, 91, 51));
        label->setStyleSheet(QStringLiteral(""));
        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(320, 60, 171, 23));
        progressBar->setValue(24);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 140, 91, 51));
        label_2->setStyleSheet(QStringLiteral(""));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 230, 91, 51));
        label_3->setStyleSheet(QStringLiteral(""));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(220, 400, 101, 61));
        label_5->setStyleSheet(QStringLiteral(""));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 310, 91, 61));
        label_4->setStyleSheet(QStringLiteral(""));
        progressBar_5 = new QProgressBar(frame);
        progressBar_5->setObjectName(QStringLiteral("progressBar_5"));
        progressBar_5->setGeometry(QRect(320, 420, 171, 23));
        progressBar_5->setValue(24);
        progressBar_2 = new QProgressBar(frame);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(320, 150, 171, 23));
        progressBar_2->setValue(24);
        progressBar_4 = new QProgressBar(frame);
        progressBar_4->setObjectName(QStringLiteral("progressBar_4"));
        progressBar_4->setGeometry(QRect(320, 330, 171, 23));
        progressBar_4->setValue(24);

        retranslateUi(HumiWidget);

        QMetaObject::connectSlotsByName(HumiWidget);
    } // setupUi

    void retranslateUi(QWidget *HumiWidget)
    {
        HumiWidget->setWindowTitle(QApplication::translate("HumiWidget", "Form", 0));
        label->setText(QApplication::translate("HumiWidget", "Posix\346\225\231\345\256\244", 0));
        label_2->setText(QApplication::translate("HumiWidget", "Home\346\225\231\345\256\244", 0));
        label_3->setText(QApplication::translate("HumiWidget", "Aparche\346\225\231\345\256\244", 0));
        label_5->setText(QApplication::translate("HumiWidget", "Var\346\225\231\345\256\244", 0));
        label_4->setText(QApplication::translate("HumiWidget", "Org\346\225\231\345\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class HumiWidget: public Ui_HumiWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUMIWIDGET_H
