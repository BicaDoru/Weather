#include "Weather.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Service service;
    Weather w(service);
    w.show();
    return a.exec();
}
