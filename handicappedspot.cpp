#include "handicappedspot.h"

HandicappedSpot::HandicappedSpot(int const& newNumberOfSpot)
{
   numberOfSpot = newNumberOfSpot;
}

int HandicappedSpot::getNumberOfSpot() const{
    return this->numberOfSpot;
}
