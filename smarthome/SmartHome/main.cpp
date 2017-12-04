#include "mainwidget.h"
#include <QApplication>
#include <QFontDatabase>
#include "getstatethread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int nIndex = QFontDatabase::addApplicationFont(QString("/usr/wqy.ttf"));
    if(nIndex != -1)
    {
        QStringList strList(QFontDatabase::applicationFontFamilies(nIndex));

        if (strList.count() > 0)

        {

        QFont fontThis(strList.at(0));

        fontThis.setPointSize(9);

        a.setFont(fontThis);

        }
    }
    MainWidget w;
    w.show();
    return a.exec();
}
