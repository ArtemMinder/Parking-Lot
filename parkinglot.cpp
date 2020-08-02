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
   this->newAddress->street = newStreet;
}
void ParkingLot::setBuilding(std::string& newBuilding){
   this->newAddress->building = newBuilding;
}
void ParkingLot::setPostCode(std::string& newPostCode){
   this->newAddress->postCode = newPostCode;
}
void ParkingLot::setParkingID(std::string& newParkingID){
   this->newAddress->parkingID = newParkingID;
}
std::string ParkingLot::getStreet(){
   return this->newAddress->street;
}
std::string ParkingLot::getBuilding(){
    return this->newAddress->building;
}
std::string ParkingLot::getPostCode(){
    return this->newAddress->postCode;
}
std::string ParkingLot::getParkingID(){
    return this->newAddress->parkingID;
}

