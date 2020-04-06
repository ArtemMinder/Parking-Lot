#include "parkinglot.h"
#include "view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ParkingLot w(1,17,53,14,10,10,17);
    Vehicle audi("7777AB-1",Types::VehicleType::MiniCooper);
    w.receiveCar(audi);
    Vehicle aud("7777AB-1",Types::VehicleType::Car);
    w.receiveCar(aud);
    Vehicle au("7777AB-1",Types::VehicleType::Bus);
    w.receiveCar(au);
    Vehicle aut("7777AB-1",Types::VehicleType::Moto);
    w.receiveCar(aut);
    Vehicle aue("7777AB-1",Types::VehicleType::Moto);
    w.receiveCar(aue);
    Vehicle auts("7777AB-1",Types::VehicleType::ElectroCar);
    w.receiveCar(auts);
    Vehicle autv("7777AB-1",Types::VehicleType::HandicappedCar);
    w.receiveCar(autv);
    return a.exec();
}
