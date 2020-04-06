#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include "Types.h"

class ParkingTicket
{
public:
    ParkingTicket(int const& newParkingPlace, std::string const& newLicenseNumber, Types::VehicleType const & newType);
private:
    int parkingPlace = 0;
    std::string licenseNumber = {};
    Types::VehicleType type ={};

};

#endif // PARKINGTICKET_H
