#include "electricspot.h"

ElectricSpot::ElectricSpot(int const& newNumberOfSpot)
{
   numberOfSpot =newNumberOfSpot;
}

int ElectricSpot::getNumberOfSpot() const{
    return this->numberOfSpot;
}
