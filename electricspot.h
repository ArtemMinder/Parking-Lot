#ifndef ELECTRICSPOT_H
#define ELECTRICSPOT_H

#include "parkingspot.h"
#include "electricpanel.h"

class ElectricSpot : public ParkingSpot
{
public:
    ElectricSpot();
    ElectricSpot(int const& newNumber);
    void setCharging();
    bool getCharging() const;
    int getNumer() const;
private:
    bool isChargeOn = false;
    bool isFree = true;
    int number = 0;
    char spotType = Enums::SpotType::Electric;
    ElectricPanel *ePanel;
};

#endif // ELECTRICSPOT_H
