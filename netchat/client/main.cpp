//#include "loginwidget.h"
//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    LoginWidget w;
//    w.show();

//    return a.exec();
//}


#include <QApplication>
#include "loginwidget.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置编码
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);

    LoginWidget w;
    w.show();

    return a.exec();
}

