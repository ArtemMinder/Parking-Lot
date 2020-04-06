#ifndef PARKINGFLOOR_H
#define PARKINGFLOOR_H

#include <QStandardItem>
#include "parkingspot.h"
#include "compactspot.h"
#include "mediumspot.h"
#include "largespot.h"
#include "motorcyclespot.h"
#include "electricspot.h"
#include "handicappedspot.h"

class ParkingFloor
{
public:
    ParkingFloor(int const& newNumberOfFloor,  int const& newNumberOfCompacts,
                 int const& newNumberOfMediums, int const& newNumberOfLarges,
                 int const& newNumberOfMoto, int const& newNumberOfElectrics,
                 int const& newNumberOfHandicapped);
    int takePlace(Types::VehicleType const& type);
    void releasePlace(Types::VehicleType const& type, int const& numberOfSpot);
private:
    int numberOfFloor = 0;
    int NumberOfCompactSpots = 0;
    std::vector <CompactSpot> compact = {};
    std::vector <MediumSpot> medium = {};
    std::vector <LargeSpot> large = {};
    std::vector <HandicappedSpot> handicapped = {};
    std::vector <MotorcycleSpot> motorcycle = {};
    std::vector <ElectricSpot> electric = {};
};

#endif // PARKINGFLOOR_H
