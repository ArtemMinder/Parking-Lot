#include "vehicle.h"

Vehicle::Vehicle(std::string const& newNumber, char const& newType)
{
  licenseNumber = newNumber;
  vehicleType = newType;
}

void Vehicle::takeTicket(){
    enter->printTicket(licenseNumber, vehicleType);
}
