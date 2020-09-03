#ifndef MOTORCYCLESPOT_H
#define MOTORCYCLESPOT_H

#include "parkingspot.h"

class MotorcycleSpot : public ParkingSpot
{
public:
    MotorcycleSpot(int const& newNumberOfSpot);
    int getNumberOfSpot() const;
private:
    int numberOfSpot = 0;
    Types::SpotType type = Types::SpotType::Motorcycle;
};

#endif // MOTORCYCLESPOT_H
