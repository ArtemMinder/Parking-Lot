#include "electricspot.h"

ElectricSpot::ElectricSpot()
{

}

void ElectricSpot::setCharging(){
    isChargeOn = ePanel->getPower();
}

bool ElectricSpot::getCharging() const {
    return isChargeOn;
}
