#ifndef ELECTRICSPOT_H
#define ELECTRICSPOT_H

#include "parkingspot.h"
#include "electricpanel.h"

class ElectricSpot : public ParkingSpot
{
public:
    ElectricSpot();
    void setCharging();
    bool getCharging() const;
private:
    bool isChargeOn = false;
    bool isFree = true;
    int number = 0;
    char spotType = Enums::SpotType::Electric;
    ElectricPanel *ePanel;
};

#endif // ELECTRICSPOT_H
