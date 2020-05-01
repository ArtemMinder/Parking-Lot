#include "parkinglot.h"
#include "view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ParkingLot w(1,17,53,14,10,10,17);
    w.simulate();
    return a.exec();
}
