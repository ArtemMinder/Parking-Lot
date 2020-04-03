#include "parkingfloor.h"
#include <QDebug>

ParkingFloor::ParkingFloor(int newNumberOfCompactPlases, int newNumberOfMediumPlases,
                           int newNumberOfLargePlases, int newNumberOfHandicappedPlases, int newNumberOfMotorcyclePlases,
                           int newNumberOfElectricPlases){

    for(int i = 1; i <= newNumberOfCompactPlases; i++){
        compact.push_back(CompactSpot(i));
   }
    for(int i = 1; i <= newNumberOfMediumPlases; i++){
         medium.push_back(MediumSpot(i));
   }
    for(int i = 1; i <= newNumberOfLargePlases; i++){
         large.push_back(LargeSpot(i));
   }
    for(int i = 1; i<= newNumberOfHandicappedPlases; i++){
        handicapped.push_back(HandicappedSpot(i));
   }
    for(int i = 1; i<= newNumberOfMotorcyclePlases; i++){
       motorcycle.push_back(MotorcycleSpot(i));
   }
    for(int i = 1; i<= newNumberOfElectricPlases; i++){
        electric.push_back(ElectricSpot(i));
   }
    for(auto i = 0; i < compact.size();i++){
      qDebug()<<"++++"<<compact[i].getNumer();
    }
}

void ParkingFloor::setNumberOfFloor(int const& newNumber){
    numberOfFloor = newNumber;
}

int ParkingFloor::getNumberOfFloor()const{
    return numberOfFloor;
}

//void ParkingFloor::updateDisplayBoard(const std::string &newInfo){
//////////////////////////
//}

bool ParkingFloor::checkAvaibility(Enums::VehicleType type){
    switch(type){
    case Enums::VehicleType::MiniCooper: {
        int size = sizeof(compact)/sizeof(compact[0]);
        int free = 0;
        for(int i = 0; i < size; i++){
            if(compact[i].getAvailability() == true){
                free++;
            }
        }
        if(free > 0){
            return true;
        }
       return false;
    }
    case Enums::VehicleType::Car: {
        int size = sizeof(medium)/sizeof(medium[0]);
        int free = 0;
        for(int i = 0; i < size; i++){
            if(medium[i].getAvailability() == true){
                free++;
            }
        }
        if(free > 0){
            return true;
        }
       return false;
    }
    case Enums::VehicleType::Bus: {
        int size = sizeof(large)/sizeof(large[0]);
        int free = 0;
        for(int i = 0; i < size; i++){
            if(large[i].getAvailability() == true){
                free++;
            }
        }
        if(free > 0){
            return true;
        }
       return false;
    }
    case Enums::VehicleType::HandicappedCar: {
        int size = sizeof(handicapped)/sizeof(handicapped[0]);
        int free = 0;
        for(int i = 0; i < size; i++){
            if(handicapped[i].getAvailability() == true){
                free++;
            }
        }
        if(free > 0){
            return true;
        }
       return false;
    }
    case Enums::VehicleType::Moto: {
        int size = sizeof(motorcycle)/sizeof(motorcycle[0]);
        int free = 0;
        for(int i = 0; i < size; i++){
            if(motorcycle[i].getAvailability() == true){
                free++;
            }
        }
        if(free > 0){
            return true;
        }
       return false;
    }
    case Enums::VehicleType::ElectroCar: {
        int size = electric.size();
        int free = 0;
        for(int i = 0; i < size; i++){
            if(motorcycle[i].getAvailability() == true){
                free++;
            }
        }
        if(free > 0){
            return true;
        }
       return false;
    }
   }
    return false;
}


int ParkingFloor::takePlace(Enums::VehicleType type){
    switch(type){
    case Enums::VehicleType::MiniCooper:{
        std::vector <int> available = {};
       for(auto i =0; i<compact.size();i++){
           if(compact[i].getAvailability() == true){
               available.push_back(i);
           }
       }
       compact[available[0]].setAvailability(false);
     return  compact[available[0]].getNumer();
    }
    case Enums::VehicleType::Car:{
        std::vector <int> available = {};
       for(auto i =0; i<medium.size();i++){
           if(medium[i].getAvailability() == true){
               available.push_back(i);
           }
       }
       medium[available[0]].setAvailability(false);
     return  medium[available[0]].getNumer();
    }
    case Enums::VehicleType::Bus:{
        std::vector <int> available = {};
       for(auto i =0; i<large.size();i++){
           if(large[i].getAvailability() == true){
               available.push_back(i);
           }
       }
      large[available[0]].setAvailability(false);
     return  large[available[0]].getNumer();
    }
    case Enums::VehicleType::HandicappedCar:{
        std::vector <int> available = {};
       for(auto i =0; i<handicapped.size();i++){
           if(handicapped[i].getAvailability() == true){
               available.push_back(i);
           }
       }
      handicapped[available[0]].setAvailability(false);
     return  handicapped[available[0]].getNumer();
    }
    case Enums::VehicleType::Moto:{
        std::vector <int> available = {};
       for(auto i =0; i<motorcycle.size();i++){
           if(motorcycle[i].getAvailability() == true){
               available.push_back(i);
           }
       }
       motorcycle[available[0]].setAvailability(false);
     return  motorcycle[available[0]].getNumer();
    }
    case Enums::VehicleType::ElectroCar:{
        std::vector <int> available = {};
       for(auto i =0; i<electric.size();i++){
           if(electric[i].getAvailability() == true){
               available.push_back(i);
           }
       }
      electric[available[0]].setAvailability(false);
     return  electric[available[0]].getNumer();
    }
    }
    return 0;
}
