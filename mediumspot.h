#ifndef MEDIUMSPOT_H
#define MEDIUMSPOT_H

#include "parkingspot.h"

class MediumSpot : public ParkingSpot
{
public:
    MediumSpot(int const& newNumberOfSpot);
    int getNumberOfSpot() const;
private:
    int numberOfSpot = 0;
    Types::SpotType type = Types::SpotType::Medium;
};

#endif // MEDIUMSPOT_H
