#ifndef VEHICLE_H
#define VEHICLE_H

#include "Types.h"

class Vehicle
{
public:
    Vehicle(std::string const& newLicenseNumber, Types::VehicleType const& newType);
    std::string getLicense()const;
    Types::VehicleType getType()const;
    void takeTicket();
    ~Vehicle();
private:
    std::string licenseNumber = {};
    Types::VehicleType type = {};
};

#endif // VEHICLE_H
