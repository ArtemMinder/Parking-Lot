#ifndef COMPACTSPOT_H
#define COMPACTSPOT_H

#include "parkingspot.h"

class CompactSpot : public ParkingSpot
{
public:
    CompactSpot();
    CompactSpot(int const& newNumber);
    int getNumer() const;
private:
    bool isFree = true;
    int number = 0;
    char spotType = Enums::SpotType::Compact;
};

#endif // COMPACTSPOT_H
