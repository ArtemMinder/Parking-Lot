#include "parkingticket.h"

ParkingTicket::ParkingTicket()
{

}

void ParkingTicket::setInfo(std::string const& newLicesneNumber, Enums::VehicleType const& newType,
                            int const& newNumberOfTicket, time_t newStartTime, int const& newNumberOfPlace)
{
    licenseNumber = newLicesneNumber;
    type = newType;
    numberOfTicket = newNumberOfTicket;
    startTime = newStartTime;
    rate->getRate(newType);
    numberOfPlace = newNumberOfPlace;
}

std::string ParkingTicket::getLicenseNumber()const{
   return licenseNumber;
}
Enums::VehicleType  ParkingTicket::getTicketType()const{
   return type;
}
int ParkingTicket::getNumberOfTicket()const{
    return numberOfTicket;
}
time_t ParkingTicket::getStartTime()const{
    return startTime;
}

int ParkingTicket::getNumberOfPlace()const{
    return numberOfPlace;
}
