#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include <QApplication>
#include "enums.h"
#include "parkingrate.h"

class ParkingTicket
{
public:
    ParkingTicket();
    void setInfo(std::string const& newLicesneNumber, Enums::VehicleType const& newType,
                 int const& newNumberOfTicket, time_t newStartTime, int const& newNumberOfPlace);
    std::string getLicenseNumber()const;
    Enums::VehicleType getTicketType()const;
    int getNumberOfTicket()const;
    time_t getStartTime()const;
    int getNumberOfPlace()const;
private:
    std::string licenseNumber = {};
    Enums::VehicleType type = {};
    int numberOfTicket = 0;
    long long amount = 0;
    time_t startTime = {};
    ParkingRate *rate;
    int numberOfPlace = 0;
};

#endif // PARKINGTICKET_H
