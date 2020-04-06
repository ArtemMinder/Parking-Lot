#include "parkingticket.h"
#include <QDebug>
#include <iostream>

ParkingTicket::ParkingTicket(int const& newParkingPlace, std::string const& newLicenseNumber, Types::VehicleType const & newType)
{
    this->parkingPlace = newParkingPlace;
    this->licenseNumber = newLicenseNumber;
    this->type = newType;
   /* std::cout<<"mesto - "<<parkingPlace<<std::endl;
    std::cout<<"nomer - "<<licenseNumber<<std::endl;
    qDebug()<<"type - "<<type;*/

}
