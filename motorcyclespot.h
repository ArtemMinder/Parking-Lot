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
    char spotType = Enums::SpotType::Motorcycle;
};

#endif // MOTORCYCLESPOT_H
