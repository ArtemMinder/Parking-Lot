#include "parkingfloor.h"
#include <QDebug>

ParkingFloor::ParkingFloor(int const& newNumberOfFloor,  int const& newNumberOfCompacts,
                           int const& newNumberOfMediums, int const& newNumberOfLarges,
                           int const& newNumberOfMoto, int const& newNumberOfElectrics,
                           int const& newNumberOfHandicapped)
{
    numberOfFloor= newNumberOfFloor;
    NumberOfCompactSpots = newNumberOfCompacts;
    for(int i = 1; i <= newNumberOfCompacts; i++){
        compact.push_back(CompactSpot(i));
   }
    for(int i = 1; i <= newNumberOfMediums; i++){
        medium.push_back(MediumSpot(i));
   }
    for(int i = 1; i <= newNumberOfLarges; i++){
        large.push_back(LargeSpot(i));
   }
    for(int i = 1; i <= newNumberOfMoto; i++){
        motorcycle.push_back(MotorcycleSpot(i));
   }
    for(int i = 1; i <= newNumberOfElectrics; i++){
        electric.push_back(ElectricSpot(i));
   }
    for(int i = 1; i <= newNumberOfHandicapped; i++){
        handicapped.push_back(HandicappedSpot(i));
   }
}

int ParkingFloor::takePlace(Types::VehicleType const& type){
    switch(type){
    case Types::VehicleType::MiniCooper: {
        int size = compact.size();
        int free = 0;
        for(int i = 0; i < size; i++){
            if(compact[i].getAvailability() == true){
                free++;
            }
        }
        if(free > 0){
            std::vector <int> available = {};
           for(auto i =0; i<compact.size();i++){
               if(compact[i].getAvailability() == true){
                   available.push_back(i);
               }
           }
           compact[available[0]].setAvailability(false);
         return  compact[available[0]].getNumberOfSpot();
        }
       return -1;
    }
    case Types::VehicleType::Car: {
        int size = medium.size();
        int free = 0;
        for(int i = 0; i < size; i++){
            if(medium[i].getAvailability() == true){
                free++;
            }
        }
        if(free > 0){
            std::vector <int> available = {};
           for(auto i =0; i<medium.size();i++){
               if(medium[i].getAvailability() == true){
                   available.push_back(i);
               }
           }
           medium[available[0]].setAvailability(false);
         return  medium[available[0]].getNumberOfSpot();
        }
       return -1;
    }
    case Types::VehicleType::Bus: {
        int size = large.size();
        int free = 0;
        for(int i = 0; i < size; i++){
            if(large[i].getAvailability() == true){
                free++;
            }
        }
        if(free > 0){
            std::vector <int> available = {};
           for(auto i =0; i<large.size();i++){
               if(large[i].getAvailability() == true){
                   available.push_back(i);
               }
           }
           large[available[0]].setAvailability(false);
         return  large[available[0]].getNumberOfSpot();
        }
       return -1;
    }
    case Types::VehicleType::Moto: {
        int size = motorcycle.size();
        int free = 0;
        for(int i = 0; i < size; i++){
            if(motorcycle[i].getAvailability() == true){
                free++;
            }
        }
        if(free > 0){
            std::vector <int> available = {};
           for(auto i =0; i<motorcycle.size();i++){
               if(motorcycle[i].getAvailability() == true){
                   available.push_back(i);
               }
           }
           motorcycle[available[0]].setAvailability(false);
         return  motorcycle[available[0]].getNumberOfSpot();
        }
       return -1;
    }
    case Types::VehicleType::ElectroCar: {
        int size = electric.size();
        int free = 0;
        for(int i = 0; i < size; i++){
            if(electric[i].getAvailability() == true){
                free++;
            }
        }
        if(free > 0){
            std::vector <int> available = {};
           for(auto i =0; i<electric.size();i++){
               if(electric[i].getAvailability() == true){
                   available.push_back(i);
               }
           }
           electric[available[0]].setAvailability(false);
         return  electric[available[0]].getNumberOfSpot();
        }
       return -1;
    }
    case Types::VehicleType::HandicappedCar: {
        int size = handicapped.size();
        int free = 0;
        for(int i = 0; i < size; i++){
            if(handicapped[i].getAvailability() == true){
                free++;
            }
        }
        if(free > 0){
            std::vector <int> available = {};
           for(auto i =0; i<handicapped.size();i++){
               if(handicapped[i].getAvailability() == true){
                   available.push_back(i);
               }
           }
           handicapped[available[0]].setAvailability(false);
         return handicapped[available[0]].getNumberOfSpot();
        }
       return -1;
    }
   }
    return -1;
}

void ParkingFloor::releasePlace(Types::VehicleType const& type, int const& numberOfSpot){
    switch(type){
    case Types::VehicleType::MiniCooper:{
        compact[numberOfSpot-1].setAvailability(true);
    }
    case Types::VehicleType::Car:{
        medium[numberOfSpot-1].setAvailability(true);
    }
    case Types::VehicleType::Bus:{
        large[numberOfSpot-1].setAvailability(true);
    }
    case Types::VehicleType::Moto:{
        motorcycle[numberOfSpot-1].setAvailability(true);
    }
     case Types::VehicleType::ElectroCar:{
        electric[numberOfSpot-1].setAvailability(true);
    }
    case Types::VehicleType::HandicappedCar:{
        handicapped[numberOfSpot-1].setAvailability(true);
    }
   }
}

