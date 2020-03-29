#ifndef LARGESPOT_H
#define LARGESPOT_H

#include "parkingspot.h"

class LargeSpot : public ParkingSpot
{
public:
    LargeSpot();
private:
    bool isFree = true;
    int number = 0;
    //SpotType type = Medium;
};

#endif // LARGESPOT_H
