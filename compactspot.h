#ifndef COMPACTSPOT_H
#define COMPACTSPOT_H

#include "parkingspot.h"
#include "Types.h"

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
