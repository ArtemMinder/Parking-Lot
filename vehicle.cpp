#include "vehicle.h"

Vehicle::Vehicle(std::string const& newNumber, Enums::VehicleType newType)
{
  licenseNumber = newNumber;
  vehicleType = newType;
  enter = new EntrancePanel;
}

void Vehicle::takeTicket(){
    enter->printTicket(licenseNumber, vehicleType);
}
