#ifndef HANDICAPPEDSPOT_H
#define HANDICAPPEDSPOT_H

#include "parkingspot.h"

class HandicappedSpot : public ParkingSpot
{
public:
    HandicappedSpot();
private:
    bool isFree = true;
    int number = 0;
    //SpotType type = Medium;
};

#endif // HANDICAPPEDSPOT_H
