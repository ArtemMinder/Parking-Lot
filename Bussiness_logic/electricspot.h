#ifndef ELECTRICSPOT_H
#define ELECTRICSPOT_H

#include "parkingspot.h"

class ElectricSpot : public ParkingSpot
{
public:
    ElectricSpot(int const& newNumberOfSpot);
    int getNumberOfSpot() const;
private:
    int numberOfSpot = 0;
    Types::SpotType type = Types::SpotType::Electric;
};

#endif // ELECTRICSPOT_H
