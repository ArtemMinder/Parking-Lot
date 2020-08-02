#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <QDialog>
#include <QObject>
#include "iostream"
#include "parkingfloor.h"
#include "entrancepanel.h"
#include "vehicle.h"

namespace Ui {
class ParkingLot;
}

class ParkingLot
{
public:
    ParkingLot (int const& newNumberOfFloors = 1, int const& newNumberOfCompacts = 18,
               int const& newNumberOfMediums = 53, int const& newNumberOfLarges = 14,
               int const& newNumberOfMoto = 10, int const& newNumberOfElectrics = 10,
               int const& newNumberOfHandicapped = 14);
    void receiveCar(int const& newPlase, Types::VehicleType const& newType, Vehicle& newVehicle);
    void deleteCar(int const& newPlase, Types::VehicleType const& newType);
    void setStreet(std::string& newStreet);
    void setBuilding(std::string& newBuilding);
    void setPostCode(std::string& newPostCode);
    void setParkingID(std::string& newParkingID);
    std::string getStreet();
    std::string getBuilding();
    std::string getPostCode();
    std::string getParkingID();
private:
    std::vector<ParkingFloor> floors = {};
    EntrancePanel *enterPanel;
    struct address {
        std::string street = {};
        std::string building = {};
        std::string postCode = {};
        std::string parkingID = {};
    };
    address *newAddress;
};

#endif // PARKINGLOT_H
