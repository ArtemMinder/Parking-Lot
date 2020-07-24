#include "parkinglot.h"
#include "ui_parkinglot.h"

ParkingLot::ParkingLot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParkingLot)
{
    ui->setupUi(this);
}

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
    sim = new Simulation;
    rate = new ParkingRate;
}

void ParkingLot::receiveCar(){
    Vehicle newVehicle(sim->generateNumber().toStdString(), sim->generateType(), sim->generateTime());
    std::string startTime = QTime::currentTime().toString().toStdString();
    int place = 0;
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    if(newVehicle.getType()==Types::MiniCooper){
        place = static_cast<int>(rand() * fraction * (17 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::Car){
        place = static_cast<int>(rand() * fraction * (53 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::Bus){
        place = static_cast<int>(rand() * fraction * (14 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::Moto){
        place = static_cast<int>(rand() * fraction * (10 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::HandicappedCar){
        place = static_cast<int>(rand() * fraction * (10 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::ElectroCar){
        place = static_cast<int>(rand() * fraction * (17 - 1 + 1) + 1);
    }
    if(place != -1){
    EntrancePanel enterPanel(newVehicle, place);
    view->loadInfo(place,newVehicle.getLicense(),newVehicle.getType(),startTime,rate->getRate(newVehicle.getType(),
    newVehicle.getParkingTime()), newVehicle.getParkingTime());
    view->busy(place, newVehicle.getType());
    }else {
        std::cout<<"Sorry, all plases for your vehicle is unavailable"<<std::endl;
    }
}


void ParkingLot::deleteCar(){
   Vehicle newVehicle(sim->generateNumber().toStdString(), sim->generateType(), sim->generateTime());
   int place = 0;
   static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
   if(newVehicle.getType()==Types::MiniCooper){
       place = static_cast<int>(rand() * fraction * (17 - 1 + 1) + 1);
   }
   else if(newVehicle.getType()==Types::Car){
       place = static_cast<int>(rand() * fraction * (53 - 1 + 1) + 1);
   }
   else if(newVehicle.getType()==Types::Bus){
       place = static_cast<int>(rand() * fraction * (14 - 1 + 1) + 1);
   }
   else if(newVehicle.getType()==Types::Moto){
       place = static_cast<int>(rand() * fraction * (10 - 1 + 1) + 1);
   }
   else if(newVehicle.getType()==Types::HandicappedCar){
       place = static_cast<int>(rand() * fraction * (10 - 1 + 1) + 1);
   }
   else if(newVehicle.getType()==Types::ElectroCar){
       place = static_cast<int>(rand() * fraction * (17 - 1 + 1) + 1);
   }
   floors[0].releasePlace(newVehicle.getType(),place);
   view->free(place, newVehicle.getType());
}

void ParkingLot::simulate(){
    add = new QTimer;
    del = new QTimer;
    del->setInterval(450);
    add->setInterval(500);
    connect(add, SIGNAL(timeout()), this, SLOT(receiveCar()));
    connect(del, SIGNAL(timeout()), this, SLOT(deleteCar()));
    del->start();
    add->start();
}

ParkingLot::~ParkingLot()
{
    delete ui;
}
