#include "parkingdisplayboard.h"

ParkingDisplayBoard::ParkingDisplayBoard()
{

}
void ParkingDisplayBoard::setInfo(std::string const& info) {
    displayInfo = info;
}

std::string ParkingDisplayBoard::getInfo()const {
    return  displayInfo;
}
