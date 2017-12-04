/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QPushButton *btnTemp;
    QPushButton *btnHumi;
    QPushButton *btnSmoke;
    QPushButton *btnAir;
    QPushButton *btnLamp;
    QPushButton *btnVideo;
    QPushButton *btnCurtain;
    QPushButton *btnOther;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btnTemp_2;
    QPushButton *btnHumi_2;
    QPushButton *btnSmoke_2;
    QPushButton *btnAir_2;
    QPushButton *btnLamp_2;
    QPushButton *btnVideo_2;
    QPushButton *btnCurtain_2;
    QPushButton *btnOther_2;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(1024, 600);
        MainWidget->setStyleSheet(QStringLiteral(""));
        btnTemp = new QPushButton(MainWidget);
        btnTemp->setObjectName(QStringLiteral("btnTemp"));
        btnTemp->setGeometry(QRect(0, 0, 151, 74));
        btnTemp->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/temp_btn.png);"));
        btnHumi = new QPushButton(MainWidget);
        btnHumi->setObjectName(QStringLiteral("btnHumi"));
        btnHumi->setGeometry(QRect(0, 75, 151, 74));
        btnHumi->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/humidity_btn.png);"));
        btnSmoke = new QPushButton(MainWidget);
        btnSmoke->setObjectName(QStringLiteral("btnSmoke"));
        btnSmoke->setGeometry(QRect(0, 150, 151, 74));
        btnSmoke->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/smoke_btn.png);"));
        btnAir = new QPushButton(MainWidget);
        btnAir->setObjectName(QStringLiteral("btnAir"));
        btnAir->setGeometry(QRect(0, 225, 151, 74));
        btnAir->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/air_condition_btn.png);"));
        btnLamp = new QPushButton(MainWidget);
        btnLamp->setObjectName(QStringLiteral("btnLamp"));
        btnLamp->setGeometry(QRect(0, 300, 151, 74));
        btnLamp->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/lamp_btn.png);"));
        btnVideo = new QPushButton(MainWidget);
        btnVideo->setObjectName(QStringLiteral("btnVideo"));
        btnVideo->setGeometry(QRect(0, 375, 151, 74));
        btnVideo->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/camera_btn.png);"));
        btnCurtain = new QPushButton(MainWidget);
        btnCurtain->setObjectName(QStringLiteral("btnCurtain"));
        btnCurtain->setGeometry(QRect(0, 450, 151, 74));
        btnCurtain->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/curtain_btn.png);"));
        btnOther = new QPushButton(MainWidget);
        btnOther->setObjectName(QStringLiteral("btnOther"));
        btnOther->setGeometry(QRect(0, 525, 151, 75));
        btnOther->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/other_dev_btn.jpg);"));
        pushButton_9 = new QPushButton(MainWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(160, 535, 130, 50));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 210, 22);\n"
"font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        pushButton_9->setAutoDefault(false);
        pushButton_9->setDefault(true);
        pushButton_9->setFlat(false);
        pushButton_10 = new QPushButton(MainWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(440, 535, 130, 50));
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 210, 22);\n"
"font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        pushButton_11 = new QPushButton(MainWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(300, 535, 130, 50));
        pushButton_11->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 210, 22);\n"
"font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        pushButton_12 = new QPushButton(MainWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(720, 535, 130, 50));
        pushButton_12->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 210, 22);\n"
"font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        pushButton_13 = new QPushButton(MainWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(580, 535, 130, 50));
        pushButton_13->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 210, 22);\n"
"font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        pushButton_14 = new QPushButton(MainWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(860, 535, 130, 50));
        pushButton_14->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 210, 22);\n"
"font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        frame = new QFrame(MainWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(159, 0, 871, 520));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 70, 241, 301));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/running_text.png);\n"
"font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label->setFrameShape(QFrame::NoFrame);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 70, 241, 301));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/alarming_text.png);\n"
"font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(570, 70, 241, 301));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img/server_text.png);\n"
"font: 11pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->raise();
        label_2->raise();
        label_3->raise();
        btnHumi->raise();
        btnTemp_2 = new QPushButton(MainWidget);
        btnTemp_2->setObjectName(QStringLiteral("btnTemp_2"));
        btnTemp_2->setGeometry(QRect(0, 0, 151, 74));
        btnTemp_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/temp_btn_select.png);"));
        btnHumi_2 = new QPushButton(MainWidget);
        btnHumi_2->setObjectName(QStringLiteral("btnHumi_2"));
        btnHumi_2->setGeometry(QRect(0, 75, 151, 74));
        btnHumi_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/huminity_btn_select.png);"));
        btnSmoke_2 = new QPushButton(MainWidget);
        btnSmoke_2->setObjectName(QStringLiteral("btnSmoke_2"));
        btnSmoke_2->setGeometry(QRect(0, 150, 151, 74));
        btnSmoke_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/smoke_btn_select.png);"));
        btnAir_2 = new QPushButton(MainWidget);
        btnAir_2->setObjectName(QStringLiteral("btnAir_2"));
        btnAir_2->setGeometry(QRect(0, 225, 151, 74));
        btnAir_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/air_condition_btn_select.png);"));
        btnLamp_2 = new QPushButton(MainWidget);
        btnLamp_2->setObjectName(QStringLiteral("btnLamp_2"));
        btnLamp_2->setGeometry(QRect(0, 300, 151, 74));
        btnLamp_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/lamp_btn_select.png);"));
        btnVideo_2 = new QPushButton(MainWidget);
        btnVideo_2->setObjectName(QStringLiteral("btnVideo_2"));
        btnVideo_2->setGeometry(QRect(0, 375, 151, 74));
        btnVideo_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/camera_btn_select.png);"));
        btnCurtain_2 = new QPushButton(MainWidget);
        btnCurtain_2->setObjectName(QStringLiteral("btnCurtain_2"));
        btnCurtain_2->setGeometry(QRect(0, 450, 151, 74));
        btnCurtain_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/curtain_btn_select.png);"));
        btnOther_2 = new QPushButton(MainWidget);
        btnOther_2->setObjectName(QStringLiteral("btnOther_2"));
        btnOther_2->setGeometry(QRect(0, 525, 151, 75));
        btnOther_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/other_dev_btn_select.png);"));
        btnTemp_2->raise();
        btnOther_2->raise();
        btnCurtain_2->raise();
        btnVideo_2->raise();
        btnLamp_2->raise();
        btnAir_2->raise();
        btnSmoke_2->raise();
        btnHumi_2->raise();
        btnTemp->raise();
        btnHumi->raise();
        btnSmoke->raise();
        btnAir->raise();
        btnLamp->raise();
        btnVideo->raise();
        btnCurtain->raise();
        btnOther->raise();
        pushButton_9->raise();
        pushButton_10->raise();
        pushButton_11->raise();
        pushButton_12->raise();
        pushButton_13->raise();
        pushButton_14->raise();
        frame->raise();

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0));
        btnTemp->setText(QString());
        btnHumi->setText(QString());
        btnSmoke->setText(QString());
        btnAir->setText(QString());
        btnLamp->setText(QString());
        btnVideo->setText(QString());
        btnCurtain->setText(QString());
        btnOther->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_9->setToolTip(QApplication::translate("MainWidget", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_9->setText(QApplication::translate("MainWidget", "\346\212\245\350\255\246\350\256\276\347\275\256", 0));
        pushButton_10->setText(QApplication::translate("MainWidget", "\347\263\273\347\273\237\346\265\213\350\257\225", 0));
        pushButton_11->setText(QApplication::translate("MainWidget", "\347\263\273\347\273\237\347\256\200\344\273\213", 0));
        pushButton_12->setText(QApplication::translate("MainWidget", "\350\277\224\345\233\236\346\241\214\351\235\242", 0));
        pushButton_13->setText(QApplication::translate("MainWidget", "\345\205\263\344\272\216\346\210\221\344\273\254", 0));
        pushButton_14->setText(QApplication::translate("MainWidget", "\351\200\200\345\207\272\347\263\273\347\273\237", 0));
        label->setText(QApplication::translate("MainWidget", "\n"
"  \347\263\273\347\273\237\350\277\220\350\241\214\346\203\205\345\206\265\345\246\202\344\270\213\357\274\232\n"
"  \346\210\220\345\212\237\346\211\223\345\274\200\347\232\204\350\256\276\345\244\207-->", 0));
        label_2->setText(QApplication::translate("MainWidget", "\n"
"  \347\263\273\347\273\237\346\212\245\350\255\246\346\203\205\345\206\265\345\246\202\344\270\213\357\274\232\n"
"  \346\255\243\345\234\250\346\212\245\350\255\246\347\232\204\350\256\276\345\244\207-->", 0));
        label_3->setText(QApplication::translate("MainWidget", "\n"
"  \346\234\215\345\212\241\345\231\250\351\223\276\346\216\245\346\203\205\345\206\265\345\246\202\344\270\213\357\274\232\n"
"  -->\346\234\215\345\212\241\345\231\250\351\223\276\346\216\245\346\210\220\345\212\237", 0));
        btnTemp_2->setText(QString());
        btnHumi_2->setText(QString());
        btnSmoke_2->setText(QString());
        btnAir_2->setText(QString());
        btnLamp_2->setText(QString());
        btnVideo_2->setText(QString());
        btnCurtain_2->setText(QString());
        btnOther_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
