#include "parkinglot.h"
#include "ui_parkinglot.h"

ParkingLot::ParkingLot(int const& newNumberOfFloors, int const& newNumberOfCompacts,
                       int const& newNumberOfMediums, int const& newNumberOfLarges,
                       int const& newNumberOfMoto, int const& newNumberOfElectrics,
                       int const& newNumberOfHandicapped)
{
    for(auto i = 0; i <= newNumberOfFloors; i++){
            floors.push_back(ParkingFloor(i,newNumberOfCompacts,newNumberOfMediums,
                                          newNumberOfLarges,newNumberOfMoto,
                                          newNumberOfElectrics,newNumberOfHandicapped));
    }
}

void ParkingLot::receiveCar(int const& newPlase, Types::VehicleType const& newType, Vehicle& newVehicle){
    EntrancePanel enterPanel(newVehicle, newPlase);
    floors.front().takePlace(newType, newPlase);
}

void ParkingLot::deleteCar(int const& newPlace, Types::VehicleType const& newType){
    floors.front().releasePlace(newType, newPlace);
}

void ParkingLot::setStreet(std::string& newStreet){
   this->pAddress->street = newStreet;
}
void ParkingLot::setBuilding(std::string& newBuilding){
   this->pAddress->building = newBuilding;
}
void ParkingLot::setPostCode(std::string& newPostCode){
   this->pAddress->postCode = newPostCode;
}
void ParkingLot::setParkingID(std::string& newParkingID){
   this->pAddress->parkingID = newParkingID;
}
std::string ParkingLot::getStreet(){
   return this->pAddress->street;
}
std::string ParkingLot::getBuilding(){
    return this->pAddress->building;
}
std::string ParkingLot::getPostCode(){
    return this->pAddress->postCode;
}
std::string ParkingLot::getParkingID(){
    return this->pAddress->parkingID;
}

