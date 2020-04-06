#include "largespot.h"

LargeSpot::LargeSpot(int const& newNumberOfSpot)
{
   numberOfSpot =newNumberOfSpot;
}

int LargeSpot::getNumberOfSpot() const{
    return this->numberOfSpot;
}
