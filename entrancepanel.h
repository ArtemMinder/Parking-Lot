#ifndef ENTRANCEPANEL_H
#define ENTRANCEPANEL_H

#include "parkingticket.h"
#include "vehicle.h"

class EntrancePanel
{
public:
    EntrancePanel(Vehicle const& newVehucle, int const& newNumberOfPlace);
    void printTicket(std::string const& newLicense, Types::VehicleType const& newType, int const& newNumberOfPlace);
private:
    Vehicle *vehicle;
    ParkingTicket *ticket;
};

#endif // ENTRANCEPANEL_H
