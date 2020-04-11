#include "parkinglot.h"
#include "view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ParkingLot w(1,17,53,14,10,10,17);
    Vehicle audi("7577AB-1",Types::VehicleType::Car, 60);
    w.receiveCar(audi);
    Vehicle mini("7447AB-1",Types::VehicleType::MiniCooper,40);
    w.receiveCar(mini);
    Vehicle ford("7687AB-1",Types::VehicleType::MiniCooper,30);
    w.receiveCar(ford);
    Vehicle mersedes("7777AB-1",Types::VehicleType::Car, 60);
    w.receiveCar(mersedes);
    Vehicle tesla("1111AB-1",Types::VehicleType::ElectroCar, 20);
    w.receiveCar(tesla);
    Vehicle tesla_s("2222AB-1",Types::VehicleType::ElectroCar, 25);
    w.receiveCar(tesla_s);
    Vehicle bmw("7777AB-1",Types::VehicleType::Moto, 40);
    w.receiveCar(bmw);
    Vehicle kawasaki("7777AB-1",Types::VehicleType::Moto, 100);
    w.receiveCar(kawasaki);
    Vehicle SMZ_S_3D("3333AB-1",Types::VehicleType::HandicappedCar, 50);
    w.receiveCar(SMZ_S_3D);
    Vehicle zil("7177AB-1",Types::VehicleType::Bus, 40);
    w.receiveCar(zil);
    Vehicle icarus("7147AB-1",Types::VehicleType::Bus, 60);
    w.receiveCar(icarus);
    Vehicle lada_riva("7887AB-2",Types::VehicleType::Car, 50);
    w.receiveCar(lada_riva);
    Vehicle ural("7777AB-1",Types::VehicleType::Moto, 60);
    w.receiveCar(ural);
    Vehicle zhiga("7777AB-2",Types::VehicleType::Car, 50);
    w.receiveCar(zhiga);
    return a.exec();
}
