#ifndef HANDICAPPEDSPOT_H
#define HANDICAPPEDSPOT_H

#include "parkingspot.h"

class HandicappedSpot : public ParkingSpot
{
public:
    HandicappedSpot(int const& newNumberOfSpot);
    int getNumberOfSpot() const;
private:
    int numberOfSpot = 0;
    Types::SpotType type = Types::SpotType::Handicapped;
};

#endif // HANDICAPPEDSPOT_H
