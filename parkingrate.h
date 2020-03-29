#ifndef PARKINGRATE_H
#define PARKINGRATE_H

class ParkingRate
{
public:
    ParkingRate();
    void setRate(long long const& newRate);
    long long getRate()const;
private:
    long long rate = 0;
};

#endif // PARKINGRATE_H
