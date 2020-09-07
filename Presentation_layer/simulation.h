#ifndef SIMULATION_H
#define SIMULATION_H

#include <QWidget>
#include <random>
#include "Types.h"
#include "vehicle.h"

class Simulation
{
public:
    int generateTime();
    QString generateNumber();
    Types::VehicleType generateType();
};

#endif // SIMULATION_H
