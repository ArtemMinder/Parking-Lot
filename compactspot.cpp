#include "compactspot.h"
#include <QDebug>

CompactSpot::CompactSpot(int const& newNumberOfSpot)
{
   numberOfSpot =newNumberOfSpot;
}

int CompactSpot::getNumberOfSpot() const{
    return this->numberOfSpot;
}
