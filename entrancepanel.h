#ifndef ENTRANCEPANEL_H
#define ENTRANCEPANEL_H

#include <QApplication>
#include "parkingfloor.h"
#include "parkingticket.h"

class EntrancePanel
{
public:
    EntrancePanel();
    void printTicket(std::string newLicense, Enums::VehicleType type);
    int takePlace(Enums::VehicleType type);
private:
    ParkingFloor *floor;
    ParkingTicket *ticket;
};

#endif // ENTRANCEPANEL_H
