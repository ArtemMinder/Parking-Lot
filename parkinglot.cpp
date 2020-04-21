#include "parkinglot.h"
#include <QDebug>

ParkingLot::ParkingLot(int const& newNumberOfFloors, int const& newNumberOfCompacts,
                       int const& newNumberOfMediums, int const& newNumberOfLarges,
                       int const& newNumberOfMoto, int const& newNumberOfElectrics,
                       int const& newNumberOfHandicapped)
{
    numberOfFloors = newNumberOfFloors;
    for(auto i = 1; i <= newNumberOfFloors;i++){
            floors.push_back(ParkingFloor(i,newNumberOfCompacts,newNumberOfMediums,
                                          newNumberOfLarges,newNumberOfMoto,
                                          newNumberOfElectrics,newNumberOfHandicapped));

    }
    view = new View;
    rate = new ParkingRate;
}

void ParkingLot::receiveCar(Vehicle const& newVehicle){

    std::string startTime = QTime::currentTime().toString().toStdString();
    int place =floors[0].takePlace(newVehicle.getType());
    if(place != -1){
    EntrancePanel enterPanel(newVehicle, place);
    view->loadInfo(place,newVehicle.getLicense(),newVehicle.getType(),startTime,rate->getRate(newVehicle.getType(),
    newVehicle.getParkingTime()), newVehicle.getParkingTime());
    } else {
        std::cout<<"Sorry, all plases for your vehicle is unavailable"<<std::endl;
        newVehicle.~Vehicle();
    }
    view->busy(place, newVehicle.getType());
    //floors[0].releasePlace(newVehicle.getType(),place);
    //view->free(place, newVehicle.getType());
}


ParkingLot::~ParkingLot()
{

}