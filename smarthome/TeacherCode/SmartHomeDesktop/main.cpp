#include "homepage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomePage w;
    w.show();

    return a.exec();
}
