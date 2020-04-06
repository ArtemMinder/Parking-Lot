#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <iostream>
#include <QStandardItem>
#include "parkingfloor.h"
#include "entrancepanel.h"
#include "vehicle.h"
#include "view.h"
#include "parkingrate.h"

class ParkingLot
{
public:
    ParkingLot(int const& newNumberOfFloors = 1, int const& newNumberOfCompacts = 18,
               int const& newNumberOfMediums = 53, int const& newNumberOfLarges = 14,
               int const& newNumberOfMoto = 10, int const& newNumberOfElectrics = 10,
               int const& newNumberOfHandicapped = 14);
    void simulate();
    void receiveCar(Vehicle const& newVehicle);
    ~ParkingLot();
private:
    int numberOfFloors = 0;
    int numberOfCompactSpots = 0;
    int numberOfMediumSpots = 0;
    int numberOfLargeSpots = 0;
    int numberOfMotorcycleSpots = 0;
    int numberOfElectricSpots = 0;
    int numberOfHandicappedSpots = 0;
    std::vector<ParkingFloor> floors = {};
    EntrancePanel *enterPanel;
    Vehicle *vehicle;
    View *view;
    ParkingRate *rate;
};
#endif // PARKINGLOT_H
