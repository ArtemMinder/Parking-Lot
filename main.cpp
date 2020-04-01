#include "parkinglot.h"
#include "vehicle.h"
#include "enums.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Vehicle audi("asx",Enums::Electric);
    audi.takeTicket();
    ParkingLot w;
    w.show();
    return a.exec();
}
