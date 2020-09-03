#ifndef COMPACTSPOT_H
#define COMPACTSPOT_H

#include "Types.h"
#include "parkingspot.h"

class CompactSpot : public ParkingSpot
{
public:
    CompactSpot(int const& newNumberOfSpot);
    int getNumberOfSpot() const;
private:
    int numberOfSpot = 0;
    Types::SpotType type = Types::SpotType::Compact;
};

#endif // COMPACTSPOT_H
