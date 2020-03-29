#ifndef MOTORCYCLESPOT_H
#define MOTORCYCLESPOT_H

#include "parkingspot.h"

class MotorcycleSpot : public ParkingSpot
{
public:
    MotorcycleSpot();
private:
    bool isFree = true;
    int number = 0;
   // SpotType type = Medium;
};

#endif // MOTORCYCLESPOT_H
