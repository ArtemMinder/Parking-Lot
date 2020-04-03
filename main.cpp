#include "parkinglot.h"
#include "view.h"
#include "vehicle.h"
#include "enums.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ParkingLot w;
    Vehicle audi("AB777",Enums::VehicleType::MiniCooper);
    audi.takeTicket();
    View wii;
    wii.show();
    return a.exec();
}
