#include "vehicle.h"

Vehicle::Vehicle(std::string const& newLicenseNumber, Types::VehicleType const& newType, int const& newparkingTime)
{
    this->licenseNumber = newLicenseNumber;
    this->type = newType;
    this->parkingTime = newparkingTime;
}

std::string Vehicle::getLicense()const{
    return this->licenseNumber;
}
Types::VehicleType Vehicle::getType()const{
    return this->type;
}

void Vehicle::takeTicket(){

}

int Vehicle::getParkingTime()const{
   return parkingTime;
}

Vehicle::~Vehicle(){

}

