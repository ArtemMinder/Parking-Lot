#include "parkingrate.h"

ParkingRate::ParkingRate()
{

}

void ParkingRate::setRate(long long const& newRate){
   rate = newRate;
}

long long ParkingRate::getRate()const{
   return rate;
}
