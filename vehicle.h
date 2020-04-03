#ifndef VEHICLE_H
#define VEHICLE_H

#include <QApplication>
#include <entrancepanel.h>

class Vehicle
{
public:
    Vehicle(std::string const& newNumber, Enums::VehicleType newType);
    void takeTicket();
private:
    std::string licenseNumber = {};
    Enums::VehicleType vehicleType ={};
    EntrancePanel *enter;
};

#endif // VEHICLE_H
