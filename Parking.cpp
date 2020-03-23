#include <iostream>
#include <ctime>

enum  SpotType {
    Compact, Medium, Large, Motorcycle, Electric, Handicapped
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

class ExitingPanel {

};

class ParkingSpot {
public:
    void setAvailability();
    bool getAvailability() const;
    void setNumber();
    int getNumber() const;
private:
    bool isFree = true;
    int number = 0;
    SpotType type = Medium;
};

class ParkngLot {
public:
    bool isFull() const;
private:
    bool isUnavailable = false;
    std::string address = {};
    class ParkingFloor {
    public:
        void updateDisplayBoard();
    private:
        int numberOfFloor = 0;
        class ParkingDisplayBoard {
        public:
            void showInfo();
        private:
            int displayNumber = 0;
        };
        ParkingDisplayBoard parkingDisplayBoard;
        ParkingSpot parkingSpot;
    };
    class ParkingRate {
        void setRate();
        long long getRate()const;
    private:
        long long rate;
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
    void setPowerON();
    bool getPower() const;
private:
    bool isPowerON = false;
    std::time_t chargingStartTime = {};
    long long payedForMinute = 0;
};

class ElectricSpot : public ParkingSpot {
public:
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

class Account {

};

class Admin : public Account {

};






int main()
{
    std::cout << "Hello World!\n";
    return 0;
}


