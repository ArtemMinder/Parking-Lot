#ifndef PARKINGFLOOR_H
#define PARKINGFLOOR_H

#include <QApplication>
#include "parkingspot.h"
#include "parkingdisplayboard.h"
#include "compactspot.h"
#include "mediumspot.h"
#include "largespot.h"
#include "handicappedspot.h"
#include "electricspot.h"
#include "motorcyclespot.h"


class ParkingFloor
{
public:
    ParkingFloor(int newNumberOfCompactPlases = 18, int newNumberOfMediumPlases = 53,
    int newNumberOfLargePlases = 14, int newNumberOfHandicappedPlases = 10, int newNumberOfMotorcyclePlases = 10,
    int newNumberOfElectricPlases = 17);
    void setNumberOfFloor(int const& newNumber);
    int getNumberOfFloor()const;
    void updateDisplayBoard(std::string const& newInfo);
    bool checkAvaibility(Enums::VehicleType type);
    int takePlace(Enums::VehicleType type);
private:
   int numberOfFloor = 0;
   std::vector <CompactSpot> compact = {};
   std::vector <MediumSpot> medium = {};
   std::vector <LargeSpot> large = {};
   std::vector <HandicappedSpot> handicapped = {};
   std::vector <MotorcycleSpot> motorcycle = {};
   std::vector <ElectricSpot> electric = {};
};

#endif // PARKINGFLOOR_H
