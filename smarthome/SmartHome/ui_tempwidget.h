/********************************************************************************
** Form generated from reading UI file 'tempwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPWIDGET_H
#define UI_TEMPWIDGET_H

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

class Ui_TempWidget
{
public:
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *tmpPosix;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar_4;
    QProgressBar *progressBar_5;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *tmpHome;
    QLabel *label_23;
    QLabel *tmpApa;
    QLabel *label_24;
    QLabel *tmpOrg;
    QLabel *label_26;
    QLabel *tmpVar;

    void setupUi(QWidget *TempWidget)
    {
        if (TempWidget->objectName().isEmpty())
            TempWidget->setObjectName(QStringLiteral("TempWidget"));
        TempWidget->resize(1024, 600);
        TempWidget->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(TempWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(160, -20, 871, 520));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 50, 91, 51));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 140, 91, 51));
        label_2->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 230, 91, 51));
        label_3->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 310, 91, 61));
        label_4->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(220, 400, 101, 61));
        label_5->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        tmpPosix = new QLabel(frame);
        tmpPosix->setObjectName(QStringLiteral("tmpPosix"));
        tmpPosix->setGeometry(QRect(500, 50, 91, 31));
        tmpPosix->setStyleSheet(QStringLiteral("background-color: rgb(239, 41, 41);"));
        tmpPosix->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(320, 60, 171, 23));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        progressBar_2 = new QProgressBar(frame);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(320, 150, 171, 23));
        progressBar_2->setValue(24);
        progressBar_2->setTextVisible(false);
        progressBar_3 = new QProgressBar(frame);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setGeometry(QRect(320, 240, 171, 23));
        progressBar_3->setValue(24);
        progressBar_3->setTextVisible(false);
        progressBar_4 = new QProgressBar(frame);
        progressBar_4->setObjectName(QStringLiteral("progressBar_4"));
        progressBar_4->setGeometry(QRect(320, 330, 171, 23));
        progressBar_4->setValue(24);
        progressBar_4->setTextVisible(false);
        progressBar_5 = new QProgressBar(frame);
        progressBar_5->setObjectName(QStringLiteral("progressBar_5"));
        progressBar_5->setGeometry(QRect(320, 420, 171, 23));
        progressBar_5->setValue(24);
        progressBar_5->setTextVisible(false);
        label_21 = new QLabel(frame);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(500, 80, 91, 31));
        label_21->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_21->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(frame);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(500, 180, 91, 31));
        label_22->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_22->setAlignment(Qt::AlignCenter);
        tmpHome = new QLabel(frame);
        tmpHome->setObjectName(QStringLiteral("tmpHome"));
        tmpHome->setGeometry(QRect(500, 150, 91, 31));
        tmpHome->setStyleSheet(QStringLiteral("background-color: rgb(239, 41, 41);"));
        tmpHome->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(frame);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(500, 260, 91, 31));
        label_23->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_23->setAlignment(Qt::AlignCenter);
        tmpApa = new QLabel(frame);
        tmpApa->setObjectName(QStringLiteral("tmpApa"));
        tmpApa->setGeometry(QRect(500, 230, 91, 31));
        tmpApa->setStyleSheet(QStringLiteral("background-color: rgb(239, 41, 41);"));
        tmpApa->setAlignment(Qt::AlignCenter);
        label_24 = new QLabel(frame);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(500, 350, 91, 31));
        label_24->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_24->setAlignment(Qt::AlignCenter);
        tmpOrg = new QLabel(frame);
        tmpOrg->setObjectName(QStringLiteral("tmpOrg"));
        tmpOrg->setGeometry(QRect(500, 320, 91, 31));
        tmpOrg->setStyleSheet(QStringLiteral("background-color: rgb(239, 41, 41);"));
        tmpOrg->setAlignment(Qt::AlignCenter);
        label_26 = new QLabel(frame);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(500, 440, 91, 31));
        label_26->setStyleSheet(QString::fromUtf8("font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_26->setAlignment(Qt::AlignCenter);
        tmpVar = new QLabel(frame);
        tmpVar->setObjectName(QStringLiteral("tmpVar"));
        tmpVar->setGeometry(QRect(500, 410, 91, 31));
        tmpVar->setStyleSheet(QStringLiteral("background-color: rgb(239, 41, 41);"));
        tmpVar->setAlignment(Qt::AlignCenter);

        retranslateUi(TempWidget);

        QMetaObject::connectSlotsByName(TempWidget);
    } // setupUi

    void retranslateUi(QWidget *TempWidget)
    {
        TempWidget->setWindowTitle(QApplication::translate("TempWidget", "Form", 0));
        label->setText(QApplication::translate("TempWidget", "Posix\346\225\231\345\256\244", 0));
        label_2->setText(QApplication::translate("TempWidget", "Home\346\225\231\345\256\244", 0));
        label_3->setText(QApplication::translate("TempWidget", "Aparche\346\225\231\345\256\244", 0));
        label_4->setText(QApplication::translate("TempWidget", "Org\346\225\231\345\256\244", 0));
        label_5->setText(QApplication::translate("TempWidget", "Var\346\225\231\345\256\244", 0));
        tmpPosix->setText(QString());
        label_21->setText(QApplication::translate("TempWidget", "\345\272\246", 0));
        label_22->setText(QApplication::translate("TempWidget", "\345\272\246", 0));
        tmpHome->setText(QString());
        label_23->setText(QApplication::translate("TempWidget", "\345\272\246", 0));
        tmpApa->setText(QString());
        label_24->setText(QApplication::translate("TempWidget", "\345\272\246", 0));
        tmpOrg->setText(QString());
        label_26->setText(QApplication::translate("TempWidget", "\345\272\246", 0));
        tmpVar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TempWidget: public Ui_TempWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPWIDGET_H
