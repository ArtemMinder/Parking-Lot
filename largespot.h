#ifndef LARGESPOT_H
#define LARGESPOT_H

#include "parkingspot.h"

class LargeSpot : public ParkingSpot
{
public:
    LargeSpot();
    LargeSpot(int const& newNumber);
    int getNumer() const;
private:
    bool isFree = true;
    int number = 0;
    char spotType = Enums::SpotType::Large;
};

#endif // LARGESPOT_H
