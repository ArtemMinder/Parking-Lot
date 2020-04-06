#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "Types.h"
#include <QStandardItem>

class ParkingSpot
{
public:
    ParkingSpot();
    ParkingSpot(int const& newNumberOfSpot);
    Types::SpotType getTypeOfSpot() const;
    void setAvailability(bool const& availability);
    bool getAvailability() const;
private:
    bool isFree = true;
    int numberOfSpot = 0;
    Types::SpotType typeOfSpot = {};
};

#endif // PARKINGSPOT_H
