#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "enums.h"

class ParkingSpot
{
public:
    ParkingSpot();
    void setAvailability(bool const& available);
    bool getAvailability() const;
    void setNumber(int const& newNumber);
    int getNumber() const;
private:
    bool isFree = true;
    int number = 0;
   // SpotType type = Medium;
};

#endif // PARKINGSPOT_H
