#include "vehicle.h"

Vehicle::Vehicle(std::string const& newLicenseNumber, Types::VehicleType const& newType)
{
    this->licenseNumber = newLicenseNumber;
    this->type = newType;
}

std::string Vehicle::getLicense()const{
    return this->licenseNumber;
}
Types::VehicleType Vehicle::getType()const{
    return this->type;
}

void Vehicle::takeTicket(){

}

Vehicle::~Vehicle(){

}
