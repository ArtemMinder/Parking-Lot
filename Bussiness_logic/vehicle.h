#ifndef VEHICLE_H
#define VEHICLE_H

#include "Types.h"

class Vehicle
{
public:
    Vehicle(std::string const& newLicenseNumber, Types::VehicleType const& newType, int const& newparkingTime);
    int getParkingTime()const;
    std::string getLicense()const;
    Types::VehicleType getType()const;
    ~Vehicle();
private:
    int parkingTime = 0;
    std::string licenseNumber = {};
    Types::VehicleType type = {};
};

#endif // VEHICLE_H
