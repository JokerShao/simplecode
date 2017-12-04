/********************************************************************************
** Form generated from reading UI file 'lampwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAMPWIDGET_H
#define UI_LAMPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LampWidget
{
public:
    QFrame *frame;
    QLabel *PosixOff;
    QLabel *HomeOff;
    QLabel *OrgOff;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QRadioButton *btnPosixOn;
    QRadioButton *btnPosixOff;
    QRadioButton *btnHomeOff;
    QRadioButton *btnHomeOn;
    QRadioButton *btnOrgOff;
    QRadioButton *btnOrgOn;
    QLabel *PosixOn;
    QLabel *HomeOn;
    QLabel *OrgOn;

    void setupUi(QWidget *LampWidget)
    {
        if (LampWidget->objectName().isEmpty())
            LampWidget->setObjectName(QStringLiteral("LampWidget"));
        LampWidget->resize(1024, 600);
        frame = new QFrame(LampWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(159, 0, 871, 520));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        PosixOff = new QLabel(frame);
        PosixOff->setObjectName(QStringLiteral("PosixOff"));
        PosixOff->setGeometry(QRect(110, 80, 151, 221));
        PosixOff->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/lamp_off.png);"));
        HomeOff = new QLabel(frame);
        HomeOff->setObjectName(QStringLiteral("HomeOff"));
        HomeOff->setGeometry(QRect(330, 80, 151, 221));
        HomeOff->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/lamp_off.png);"));
        OrgOff = new QLabel(frame);
        OrgOff->setObjectName(QStringLiteral("OrgOff"));
        OrgOff->setGeometry(QRect(550, 80, 151, 221));
        OrgOff->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/lamp_off.png);"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 300, 91, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 300, 91, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(600, 300, 91, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        btnPosixOn = new QRadioButton(frame);
        btnPosixOn->setObjectName(QStringLiteral("btnPosixOn"));
        btnPosixOn->setGeometry(QRect(140, 340, 41, 23));
        btnPosixOn->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        btnPosixOn->setCheckable(true);
        btnPosixOn->setChecked(false);
        btnPosixOn->setAutoExclusive(false);
        btnPosixOff = new QRadioButton(frame);
        btnPosixOff->setObjectName(QStringLiteral("btnPosixOff"));
        btnPosixOff->setGeometry(QRect(190, 340, 51, 23));
        btnPosixOff->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        btnPosixOff->setChecked(true);
        btnPosixOff->setAutoExclusive(false);
        btnHomeOff = new QRadioButton(frame);
        btnHomeOff->setObjectName(QStringLiteral("btnHomeOff"));
        btnHomeOff->setGeometry(QRect(410, 340, 51, 23));
        btnHomeOff->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        btnHomeOff->setChecked(true);
        btnHomeOff->setAutoExclusive(false);
        btnHomeOn = new QRadioButton(frame);
        btnHomeOn->setObjectName(QStringLiteral("btnHomeOn"));
        btnHomeOn->setGeometry(QRect(360, 340, 41, 23));
        btnHomeOn->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        btnHomeOn->setChecked(false);
        btnHomeOn->setAutoExclusive(false);
        btnOrgOff = new QRadioButton(frame);
        btnOrgOff->setObjectName(QStringLiteral("btnOrgOff"));
        btnOrgOff->setGeometry(QRect(640, 340, 51, 23));
        btnOrgOff->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        btnOrgOff->setChecked(true);
        btnOrgOff->setAutoExclusive(false);
        btnOrgOn = new QRadioButton(frame);
        btnOrgOn->setObjectName(QStringLiteral("btnOrgOn"));
        btnOrgOn->setGeometry(QRect(590, 340, 41, 23));
        btnOrgOn->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        btnOrgOn->setChecked(false);
        btnOrgOn->setAutoExclusive(false);
        PosixOn = new QLabel(frame);
        PosixOn->setObjectName(QStringLiteral("PosixOn"));
        PosixOn->setGeometry(QRect(110, 80, 151, 221));
        PosixOn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/lamp_on.png);"));
        HomeOn = new QLabel(frame);
        HomeOn->setObjectName(QStringLiteral("HomeOn"));
        HomeOn->setGeometry(QRect(330, 80, 151, 221));
        HomeOn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/lamp_on.png);"));
        OrgOn = new QLabel(frame);
        OrgOn->setObjectName(QStringLiteral("OrgOn"));
        OrgOn->setGeometry(QRect(550, 80, 151, 221));
        OrgOn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/lamp_on.png);"));

        retranslateUi(LampWidget);

        QMetaObject::connectSlotsByName(LampWidget);
    } // setupUi

    void retranslateUi(QWidget *LampWidget)
    {
        LampWidget->setWindowTitle(QApplication::translate("LampWidget", "Form", 0));
        PosixOff->setText(QString());
        HomeOff->setText(QString());
        OrgOff->setText(QString());
        label_4->setText(QApplication::translate("LampWidget", "Posix\346\225\231\345\256\244", 0));
        label_5->setText(QApplication::translate("LampWidget", "Home\346\225\231\345\256\244", 0));
        label_6->setText(QApplication::translate("LampWidget", "Org\346\225\231\345\256\244", 0));
        btnPosixOn->setText(QApplication::translate("LampWidget", "\345\274\200", 0));
        btnPosixOff->setText(QApplication::translate("LampWidget", "\345\205\263", 0));
        btnHomeOff->setText(QApplication::translate("LampWidget", "\345\205\263", 0));
        btnHomeOn->setText(QApplication::translate("LampWidget", "\345\274\200", 0));
        btnOrgOff->setText(QApplication::translate("LampWidget", "\345\205\263", 0));
        btnOrgOn->setText(QApplication::translate("LampWidget", "\345\274\200", 0));
        PosixOn->setText(QString());
        HomeOn->setText(QString());
        OrgOn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LampWidget: public Ui_LampWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAMPWIDGET_H
