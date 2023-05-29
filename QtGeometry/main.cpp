#include "QtGeometry.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtGeometry w;
    w.show();
    return a.exec();
}
