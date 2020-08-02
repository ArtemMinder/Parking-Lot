#ifndef SIMULATION_H
#define SIMULATION_H
#include <QWidget>
#include <random>
#include "vehicle.h"
#include "Types.h"

class Simulation
{
public:
    QString generateNumber();
    Types::VehicleType generateType();
    int generateTime();   
};

#endif // SIMULATION_H
