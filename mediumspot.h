#ifndef MEDIUMSPOT_H
#define MEDIUMSPOT_H

#include "parkingspot.h"

class MediumSpot : public ParkingSpot
{
public:
    MediumSpot();
private:
    bool isFree = true;
    int number = 0;
    //SpotType type = Medium;
};

#endif // MEDIUMSPOT_H
