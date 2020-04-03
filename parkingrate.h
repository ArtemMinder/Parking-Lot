#ifndef PARKINGRATE_H
#define PARKINGRATE_H

#include "enums.h"

class ParkingRate
{
public:
    ParkingRate();
    void setRate(long long const& newRate);
    long long getRate(char const& type)const;
private:
    long long rate = 0;
    long long compactPlaceRate = 0;
    long long mediumPlaceRate = 0;
    long long largePlaceRate = 0;
    long long handicappedPlaceRate = 0;
    long long motorcyclePlaceRate = 0;
    long long electricPlaceRate = 0;
};

#endif // PARKINGRATE_H
