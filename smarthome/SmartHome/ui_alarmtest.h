/********************************************************************************
** Form generated from reading UI file 'alarmtest.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMTEST_H
#define UI_ALARMTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmTest
{
public:
    QFrame *frame;
    QPushButton *pushButton;

    void setupUi(QWidget *AlarmTest)
    {
        if (AlarmTest->objectName().isEmpty())
            AlarmTest->setObjectName(QStringLiteral("AlarmTest"));
        AlarmTest->resize(1024, 600);
        frame = new QFrame(AlarmTest);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(159, 0, 871, 520));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 150, 161, 151));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/buzzer_off.ico);"));

        retranslateUi(AlarmTest);

        QMetaObject::connectSlotsByName(AlarmTest);
    } // setupUi

    void retranslateUi(QWidget *AlarmTest)
    {
        AlarmTest->setWindowTitle(QApplication::translate("AlarmTest", "Form", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AlarmTest: public Ui_AlarmTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMTEST_H
