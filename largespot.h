#ifndef LARGESPOT_H
#define LARGESPOT_H

#include "parkingspot.h"

class LargeSpot : public ParkingSpot
{
public:
    LargeSpot(int const& newNumberOfSpot);
    int getNumberOfSpot() const;
private:
    int numberOfSpot = 0;
    Types::SpotType type = Types::SpotType::Large;
};

#endif // LARGESPOT_H
