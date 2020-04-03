#include "parkingrate.h"

ParkingRate::ParkingRate()
{
}
void ParkingRate::setRate(long long const& newRate){
   rate = newRate;
}

long long ParkingRate::getRate(char const& type)const{
    switch(type){
    case Enums::VehicleType::MiniCooper:{return compactPlaceRate;}
    case Enums::VehicleType::Car:{return mediumPlaceRate;}
    case Enums::VehicleType::Bus:{return largePlaceRate;}
    case Enums::VehicleType::Moto:{return motorcyclePlaceRate;}
    case Enums::VehicleType::ElectroCar:{return electricPlaceRate;}
    }
   return rate;
}
