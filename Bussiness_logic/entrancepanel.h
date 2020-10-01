#ifndef ENTRANCEPANEL_H
#define ENTRANCEPANEL_H

#include <memory>
#include "parkingticket.h"
#include "vehicle.h"

class EntrancePanel
{
public:
    EntrancePanel(Vehicle const& newVehucle, int const& newNumberOfPlace);
    void printTicket(std::string const& newLicense, Types::VehicleType const& newType, int const& newNumberOfPlace);
private:
    std::unique_ptr<Vehicle> pVehicle;
    std::unique_ptr<ParkingTicket> pTicket;
};

#endif // ENTRANCEPANEL_H
