#include "mediumspot.h"

MediumSpot::MediumSpot(int const& newNumberOfSpot)
{
   numberOfSpot =newNumberOfSpot;
}

int MediumSpot::getNumberOfSpot() const{
    return this->numberOfSpot;
}
