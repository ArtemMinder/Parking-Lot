#ifndef PARKINGRATE_H
#define PARKINGRATE_H

#include <Types.h>

class ParkingRate
{
public:
    ParkingRate();
    double getRate(Types::VehicleType const& newType, int const& elapsedMinuts);

private:
    const double fullPriceForMinute = 0.12;
    Types::VehicleType type ={};
};

#endif // PARKINGRATE_H
