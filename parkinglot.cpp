#include "parkinglot.h"
#include "ui_parkinglot.h"

ParkingLot::ParkingLot(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ParkingLot)
{
    ui->setupUi(this);
}

void ParkingLot::setAddress(std::string const& newAddress) {
    address = newAddress;
}

std::string ParkingLot::getAddress()const {
    return address;;
}

void ParkingLot::isFull(bool const& full) {
    isUnavailable = full;
}

bool ParkingLot::getStatus()const {
    return isUnavailable;
}

ParkingLot::~ParkingLot()
{
    delete ui;
}



