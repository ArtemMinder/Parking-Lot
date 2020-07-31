#include "parkingrate.h"

ParkingRate::ParkingRate()
{

}

double ParkingRate::getRate(Types::VehicleType const& newType, int const& elapsedMinuts){
    switch(newType){
    case Types::VehicleType::MiniCooper:{
        return fullPriceForMinute * 0.7 * elapsedMinuts;
    }
    case Types::VehicleType::Car:{
        return fullPriceForMinute * 0.9 * elapsedMinuts;
    }
    case Types::VehicleType::Bus:{
        return fullPriceForMinute * 1.2 * elapsedMinuts;
    }
    case Types::VehicleType::Moto:{
        return fullPriceForMinute * 0.7 * elapsedMinuts;
    }
     case Types::VehicleType::ElectroCar:{
        return fullPriceForMinute * 0.8 * elapsedMinuts;
    }
    case Types::VehicleType::HandicappedCar:{
        return fullPriceForMinute * 0.5 * elapsedMinuts;
    }
    default: return -1;
    }
}
