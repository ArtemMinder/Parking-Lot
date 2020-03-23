#include <iostream>
#include <ctime>

enum  SpotType {
    Compact, Medium, Large, Motorcycle, Electric, Handicapped
};

enum  VehicleType {
    MiniCooper, Car, Bus, Moto, ElectroCar
};

class Vehicle {
public:
    Vehicle(std::string const& newNumber, VehicleType const& newType);
    void assigneTicket(int const& ticketNumber);
private:
    std::string licenseNumber = {};
    VehicleType vehicleType = {};
    int numberOfTicket= 0;
};

class ParkingTicket {
private:
    int number = 0;
    time_t startTime = {};
    long long amount = 0;
};

class EntrancePanel {
public:
    void printTicket();
};

class ParkingSpot {
public:
    void setAvailability(bool const& available);
    bool getAvailability() const;
    void setNumber(int const& newNumber);
    int getNumber() const;
private:
    bool isFree = true;
    int number = 0;
    SpotType type = Medium;
};

class ParkngLot {
public:
    void setAddress(std::string const& newAddress);
    std::string getAddress()const;
    void isFull(bool const& full);
    bool getStatus()const;
private:
    bool isUnavailable = false;
    std::string address = {};
    class ParkingFloor {
    public:
        ParkingFloor(int const& newNumber);
        void updateDisplayBoard(std::string const& info);
    private:
        int numberOfFloor = 0;
        class ParkingDisplayBoard {
        public:
            void setInfo(std::string const& info);
            std::string getInfo()const;
        private:
            int displayNumber = 0;
            std::string displayInfo = {};
        };
        ParkingDisplayBoard parkingDisplayBoard;
        ParkingSpot parkingSpot;
    };
    class ParkingRate {
        void setRate(long long const& newRate);
        long long getRate()const;
    private:
        long long rate = 0;
    };
    ParkingRate parkingRate;
    ParkingFloor parkingFloor;
    ParkingTicket parkingTicket;
};

class CompactSpot : public ParkingSpot {
private:
    bool isFree = true;
    int number = 0;
    SpotType type = Compact;
};

class MediumSpot : public ParkingSpot {
private:
    bool isFree = true;
    int number = 0;
    SpotType type = Medium;
};

class LargeSpot : public ParkingSpot {
private:
    bool isFree = true;
    int number = 0;
    SpotType type = Large;
};

class MotorcycleSpot : public ParkingSpot {
private:
    bool isFree = true;
    int number = 0;
    SpotType type = Medium;
};

class ElectricPanel {
public:
    void setPower(bool const& power);
    bool getPower() const;
    void setRate(long long const& rate);
    long long getRate() const;
    void setChargingTime(time_t const& startTime);
    time_t getChargingTime() const;
private:
    bool isPowerON = false;
    std::time_t chargingStartTime = {};
    long long payedForMinute = 0;
};

class ElectricSpot : public ParkingSpot {
public:
    void setCharging();
    bool getCharging() const;
private:
    bool isChargeOn = false;
    bool isFree = true;
    int number = 0;
    SpotType type = Electric;
    ElectricPanel ePanel;
};

class HandicappedSpot : public ParkingSpot {

private:
    bool isFree = true;
    int number = 0;
    SpotType type = Handicapped;
};

/*class Payment {
public:
private:
};

class PaymentByCach : Payment {
public:
private:
};

class PaymentByCreditCard : Payment {
public:
private:
};*/

/*class Account {

};

class Admin : public Account {

};*/

int main()
{
    std::cout << "done" << std::endl;
    return 0;
}



