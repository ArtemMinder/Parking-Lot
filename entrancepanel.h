#ifndef ENTRANCEPANEL_H
#define ENTRANCEPANEL_H

#include "vehicle.h"
#include "parkingticket.h"

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
