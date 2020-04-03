#include "motorcyclespot.h"


MotorcycleSpot::  MotorcycleSpot()
{

}

MotorcycleSpot::MotorcycleSpot(int const& newNumber)
{
    number = newNumber;
}

int MotorcycleSpot::getNumer() const{
    return number;
}
