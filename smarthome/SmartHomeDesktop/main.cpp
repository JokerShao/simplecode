#include "homewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomeWidget w;
    w.show();

    return a.exec();
}
