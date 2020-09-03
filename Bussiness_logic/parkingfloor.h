#ifndef PARKINGFLOOR_H
#define PARKINGFLOOR_H

#include "compactspot.h"
#include "electricspot.h"
#include "handicappedspot.h"
#include "largespot.h"
#include "mediumspot.h"
#include "motorcyclespot.h"
#include "parkingspot.h"

class ParkingFloor
{
public:
    ParkingFloor(int const& newNumberOfFloor,  int const& newNumberOfCompacts,
                 int const& newNumberOfMediums, int const& newNumberOfLarges,
                 int const& newNumberOfMoto, int const& newNumberOfElectrics,
                 int const& newNumberOfHandicapped);
    int takePlace(Types::VehicleType const& type, int const& newPlase);
    void releasePlace(Types::VehicleType const& type, int const& numberOfSpot);
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
