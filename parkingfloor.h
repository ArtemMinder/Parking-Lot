#ifndef PARKINGFLOOR_H
#define PARKINGFLOOR_H

#include <QApplication>
#include "parkingspot.h"
#include "parkingdisplayboard.h"

class ParkingFloor
{
public:
    ParkingFloor(int const& newNumber);
    int getNumberOfFloor()const;
    void updateDisplayBoard(std::string const& newInfo);
private:
   int numberOfFloor = 0;
   ParkingSpot *parkingSpot;
   ParkingDisplayBoard *board;
};

#endif // PARKINGFLOOR_H
