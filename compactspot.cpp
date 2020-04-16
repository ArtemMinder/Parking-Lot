#include "compactspot.h"

CompactSpot::CompactSpot(int const& newNumberOfSpot)
{
   numberOfSpot =newNumberOfSpot;
}

int CompactSpot::getNumberOfSpot() const{
    return this->numberOfSpot;
}
