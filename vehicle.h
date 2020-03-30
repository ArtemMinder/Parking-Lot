#ifndef VEHICLE_H
#define VEHICLE_H

#include <QApplication>

class Vehicle
{
public:
    Vehicle();
    Vehicle(std::string const& newNumber, char const& newType);
    void assigneTicket(int const& ticketNumber);
private:
    std::string licenseNumber = {};
    char vehicleType = {};
    int numberOfTicket= 0;
};

#endif // VEHICLE_H
