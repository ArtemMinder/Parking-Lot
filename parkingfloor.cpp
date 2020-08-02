#include "parkingfloor.h"

ParkingFloor::ParkingFloor(int const& newNumberOfFloor,  int const& newNumberOfCompacts,
                           int const& newNumberOfMediums, int const& newNumberOfLarges,
                           int const& newNumberOfMoto, int const& newNumberOfElectrics,
                           int const& newNumberOfHandicapped)
{
    numberOfFloor= newNumberOfFloor;
    for(int i = 0; i <= newNumberOfCompacts; i++){
        compact.push_back(CompactSpot(i));
   }
    for(int i = 0; i <= newNumberOfMediums; i++){
        medium.push_back(MediumSpot(i));
   }
    for(int i = 0; i <= newNumberOfLarges; i++){
        large.push_back(LargeSpot(i));
   }
    for(int i = 0; i <= newNumberOfMoto; i++){
        motorcycle.push_back(MotorcycleSpot(i));
   }
    for(int i = 0; i <= newNumberOfElectrics; i++){
        electric.push_back(ElectricSpot(i));
   }
    for(int i = 0; i <= newNumberOfHandicapped; i++){
        handicapped.push_back(HandicappedSpot(i));
   }
}


int ParkingFloor::takePlace(Types::VehicleType const& type, int const& newPlase){
    switch(type){
    case Types::VehicleType::MiniCooper:{
        if(compact[newPlase].getAvailability() == true){
            compact[newPlase].setAvailability(false);
        }else{};
        break;
    }
    case Types::VehicleType::Car:{
        if(medium[newPlase].getAvailability() == true){
            medium[newPlase].setAvailability(false);
        } else{};
        break;
    }
    case Types::VehicleType::Bus:{
        if(large[newPlase].getAvailability() == true){
            large[newPlase].setAvailability(false);
        } else{};
        break;
    }
    case Types::VehicleType::Moto:{
        if(motorcycle[newPlase].getAvailability() == true){
            motorcycle[newPlase].setAvailability(false);
        } else{};
        break;
    }
    case Types::VehicleType::ElectroCar:{
        if(electric[newPlase].getAvailability() == true){
            electric[newPlase].setAvailability(false);
        } else{};
        break;
    }
    case Types::VehicleType::HandicappedCar:{
        if(handicapped[newPlase].getAvailability() == true){
            handicapped[newPlase].setAvailability(false);
        } else{};
        break;
    }
    default: return -1;
    }
    return -1;
}

void ParkingFloor::releasePlace(Types::VehicleType const& type, int const& numberOfSpot){
    switch(type){
    case Types::VehicleType::MiniCooper:{
        compact[numberOfSpot].setAvailability(true);
        break;
    }
    case Types::VehicleType::Car:{
        medium[numberOfSpot].setAvailability(true);
        break;
    }
    case Types::VehicleType::Bus:{
        large[numberOfSpot].setAvailability(true);
        break;
    }
    case Types::VehicleType::Moto:{
        motorcycle[numberOfSpot].setAvailability(true);
        break;
    }
    case Types::VehicleType::ElectroCar:{
        electric[numberOfSpot].setAvailability(true);
        break;
    }
    case Types::VehicleType::HandicappedCar:{
        handicapped[numberOfSpot].setAvailability(true);
        break;
    }
    }
}

