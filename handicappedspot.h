#ifndef HANDICAPPEDSPOT_H
#define HANDICAPPEDSPOT_H

#include "parkingspot.h"

class HandicappedSpot : public ParkingSpot
{
public:
    HandicappedSpot();
    HandicappedSpot(int const& newNumber);
    int getNumer() const;
private:
    bool isFree = true;
    int number = 0;
    char spotType = Enums::SpotType::Handicapped;
};

#endif // HANDICAPPEDSPOT_H
