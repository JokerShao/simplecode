/********************************************************************************
** Form generated from reading UI file 'smokewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMOKEWIDGET_H
#define UI_SMOKEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmokeWidget
{
public:
    QFrame *frame;
    QPushButton *pushButton;

    void setupUi(QWidget *SmokeWidget)
    {
        if (SmokeWidget->objectName().isEmpty())
            SmokeWidget->setObjectName(QStringLiteral("SmokeWidget"));
        SmokeWidget->resize(1024, 600);
        frame = new QFrame(SmokeWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(159, 0, 871, 520));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 140, 361, 241));

        retranslateUi(SmokeWidget);

        QMetaObject::connectSlotsByName(SmokeWidget);
    } // setupUi

    void retranslateUi(QWidget *SmokeWidget)
    {
        SmokeWidget->setWindowTitle(QApplication::translate("SmokeWidget", "Form", 0));
        pushButton->setText(QApplication::translate("SmokeWidget", "SmokeBtn", 0));
    } // retranslateUi

};

namespace Ui {
    class SmokeWidget: public Ui_SmokeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMOKEWIDGET_H
