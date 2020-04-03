#include "parkingspot.h"

ParkingSpot::ParkingSpot()
{

}

void ParkingSpot::setAvailability(bool const& available){
    isFree = available;
}

bool ParkingSpot::getAvailability()const{
    return isFree;
}

