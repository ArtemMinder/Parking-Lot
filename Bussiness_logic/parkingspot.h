#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "Types.h"

class ParkingSpot
{
public:
    ParkingSpot();
    ParkingSpot(int const& newNumberOfSpot); 
    void setAvailability(bool const& availability);
    bool getAvailability() const;
    Types::SpotType getTypeOfSpot() const;
private:
    bool isFree = true;
    int numberOfSpot = 0;
    Types::SpotType typeOfSpot = {};
};

#endif // PARKINGSPOT_H
