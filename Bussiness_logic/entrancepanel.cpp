#include "entrancepanel.h"

EntrancePanel::EntrancePanel(Vehicle const& newVehucle, int const& newNumberOfPlace)
{
    printTicket(newVehucle.getLicense(), newVehucle.getType(), newNumberOfPlace);
}

void EntrancePanel::printTicket(std::string const& newLicense, Types::VehicleType const& newType, int const& newNumberOfPlace){
    ParkingTicket ticket(newNumberOfPlace, newLicense, newType);
}
