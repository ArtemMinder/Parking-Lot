#include "parkingfloor.h"

ParkingFloor::ParkingFloor(int const& newNumber)
{
  numberOfFloor = newNumber;
}

int ParkingFloor::getNumberOfFloor()const{
    return numberOfFloor;
}

void ParkingFloor::updateDisplayBoard(const std::string &newInfo){

}
