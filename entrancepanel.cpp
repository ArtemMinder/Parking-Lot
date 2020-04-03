#include "entrancepanel.h"
#include <iostream>

EntrancePanel::EntrancePanel()
{
 floor = new ParkingFloor;
 ticket = new ParkingTicket;
}

void EntrancePanel::printTicket(std::string newLicense, Enums::VehicleType type){
    if(floor->checkAvaibility(type) == true){
    ticket->setInfo(newLicense,type,1,1,takePlace(type));
    std::cout<<"License - "<<ticket->getLicenseNumber()<<std::endl;
    std::cout<<"Type - "<<ticket->getTicketType()<<std::endl;
    std::cout<<"s_time - "<<ticket->getStartTime()<<std::endl;
    std::cout<<"numberT - "<<ticket->getNumberOfTicket()<<std::endl;
    std::cout<<"numberPlace - "<<ticket->getNumberOfPlace()<<std::endl;
    } else{
         std::cout<<"Sorry, all places for your vehicle is unavailable"<<std::endl;
    }

}


int EntrancePanel::takePlace(Enums::VehicleType type){
    return  floor->takePlace(type);
}
