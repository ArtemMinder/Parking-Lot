#include <QApplication>
#include <view.h>
#include "parkinglot.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View view(0,0,0);
    return a.exec();
}
