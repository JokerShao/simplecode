#include <QApplication>
#include <QTextCodec>
#include "mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置编码
   /* QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);*/

    mainWidget w;
    w.show();

    return a.exec();
}

