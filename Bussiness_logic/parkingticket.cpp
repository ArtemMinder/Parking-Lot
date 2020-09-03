#include "parkingticket.h"

ParkingTicket::ParkingTicket(int const& newParkingPlace, std::string const& newLicenseNumber, Types::VehicleType const & newType)
{
    this->parkingPlace = newParkingPlace;
    this->licenseNumber = newLicenseNumber;
    this->type = newType;
}
