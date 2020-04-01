#ifndef VEHICLE_H
#define VEHICLE_H

#include <QApplication>
#include <entrancepanel.h>

class Vehicle
{
public:
    Vehicle(std::string const& newNumber, char const& newType);
    void takeTicket();
private:
    std::string licenseNumber = {};
    char vehicleType = {};
    EntrancePanel *enter;
};

#endif // VEHICLE_H
