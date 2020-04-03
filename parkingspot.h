#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "enums.h"

class ParkingSpot
{
public:
    ParkingSpot();
    void setAvailability(bool const& available);
    bool getAvailability() const;
    int checkAvaibility(char const& type);
private:
    bool isFree = true;
    int number = 0;
};

#endif // PARKINGSPOT_H
