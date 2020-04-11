#ifndef VEHICLE_H
#define VEHICLE_H

#include "Types.h"

class Vehicle
{
public:
    Vehicle(std::string const& newLicenseNumber, Types::VehicleType const& newType, int const& newparkingTime);
    std::string getLicense()const;
    Types::VehicleType getType()const;
    int getParkingTime()const;
    void takeTicket();
    ~Vehicle();
private:
    std::string licenseNumber = {};
    Types::VehicleType type = {};
    int parkingTime = 0;
};

#endif // VEHICLE_H
