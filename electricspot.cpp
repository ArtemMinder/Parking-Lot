#include "electricspot.h"

ElectricSpot::ElectricSpot(){

}

ElectricSpot::ElectricSpot(int const& newNumber)
{
    number = newNumber;
}

void ElectricSpot::setCharging(){
    isChargeOn = ePanel->getPower();
}

bool ElectricSpot::getCharging() const {
    return isChargeOn;
}

int ElectricSpot::getNumer() const{
    return number;
}
