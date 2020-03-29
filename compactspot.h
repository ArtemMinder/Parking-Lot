#ifndef COMPACTSPOT_H
#define COMPACTSPOT_H

#include "parkingspot.h"

class CompactSpot : public ParkingSpot
{
public:
    CompactSpot();
private:
    bool isFree = true;
    int number = 0;
    //SpotType type = Medium;
};

#endif // COMPACTSPOT_H
