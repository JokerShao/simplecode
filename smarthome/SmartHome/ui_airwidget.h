/********************************************************************************
** Form generated from reading UI file 'airwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRWIDGET_H
#define UI_AIRWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AirWidget
{
public:
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;

    void setupUi(QWidget *AirWidget)
    {
        if (AirWidget->objectName().isEmpty())
            AirWidget->setObjectName(QStringLiteral("AirWidget"));
        AirWidget->resize(1024, 600);
        frame = new QFrame(AirWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(159, 0, 871, 520));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 140, 221, 101));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/air_condition_off.png);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 140, 221, 101));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/air_condition_off.png);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(580, 140, 221, 101));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/air_condition_off.png);"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 240, 67, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(380, 240, 91, 21));
        label_5->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(660, 240, 67, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(110, 310, 51, 26));
        spinBox_2 = new QSpinBox(frame);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(390, 310, 51, 26));
        spinBox_3 = new QSpinBox(frame);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(670, 310, 51, 26));

        retranslateUi(AirWidget);

        QMetaObject::connectSlotsByName(AirWidget);
    } // setupUi

    void retranslateUi(QWidget *AirWidget)
    {
        AirWidget->setWindowTitle(QApplication::translate("AirWidget", "Form", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QApplication::translate("AirWidget", "Posix\346\225\231\345\256\244", 0));
        label_5->setText(QApplication::translate("AirWidget", "Home\346\225\231\345\256\244", 0));
        label_6->setText(QApplication::translate("AirWidget", "Org\346\225\231\345\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class AirWidget: public Ui_AirWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRWIDGET_H
