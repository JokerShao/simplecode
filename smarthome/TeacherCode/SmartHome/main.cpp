#include "mainpage.h"
#include <QApplication>
#include "QFontDatabase"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QString f = QString("/usr/share/fonts/wqy/wqy1.ttf");
    int nIndex = QFontDatabase::addApplicationFont(f);
    if(nIndex != -1) {
        QStringList strList(QFontDatabase::applicationFontFamilies(nIndex));
        if (strList.count() > 0) {
            QFont fontThis(strList.at(0));
            fontThis.setPointSize(9);
            a.setFont(fontThis);
        }
    }

    MainPage w;
    w.show();

    return a.exec();
}
