#include "parkingspot.h"

ParkingSpot::ParkingSpot()
{

}
ParkingSpot::ParkingSpot(int const& newNumberOfSpot)
{
    this->numberOfSpot = newNumberOfSpot;
}

Types::SpotType ParkingSpot::getTypeOfSpot() const{
    return this->typeOfSpot;
}

void ParkingSpot::setAvailability(bool const& availability){
    this->isFree = availability;
}
bool ParkingSpot::getAvailability() const{
    return  this->isFree;
}
