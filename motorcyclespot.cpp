#include "motorcyclespot.h"

MotorcycleSpot::MotorcycleSpot(int const& newNumberOfSpot)
{
   numberOfSpot =newNumberOfSpot;
}

int MotorcycleSpot::getNumberOfSpot() const{
    return this->numberOfSpot;
}
