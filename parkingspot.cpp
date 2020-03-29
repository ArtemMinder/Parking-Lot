#include "parkingspot.h"

ParkingSpot::ParkingSpot()
{

}

void ParkingSpot::setNumber(int const& newNumber) {
    number = newNumber;
}

void ParkingSpot::setAvailability(bool const& available){
    isFree = available;
}

bool ParkingSpot::getAvailability()const{
    return isFree;
}

int ParkingSpot::getNumber()const {
    return number;
}
