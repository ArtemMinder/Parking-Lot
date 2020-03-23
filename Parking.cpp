#include "Parking.h"


void ParkingSpot::setNumber(int const& newNumber) {
	number = newNumber;
}

void ParkingSpot::setAvailability(bool const& available){
	isFree = available;
}

bool ParkingSpot::getAvailability()const{
	return isFree;
}

int ParkingSpot::getNumber()const {
	return number;
}

void ElectricPanel::setPower(bool const& power) {
	isPowerON = power;
}

bool ElectricPanel::getPower()const{
	return isPowerON;
} 

void ElectricPanel::setRate(long long const& rate) {
	payedForMinute = rate;
}

long long ElectricPanel::getRate()const {
	return payedForMinute;
}

void ElectricPanel::setChargingTime(time_t const& startTime) {
	chargingStartTime = startTime;
}

time_t ElectricPanel::getChargingTime() const {
	return chargingStartTime;
}

void ElectricSpot::setCharging(){
	isChargeOn = ePanel.getPower();
}

bool ElectricSpot::getCharging() const {
	return isChargeOn;
}

ParkngLot::ParkingFloor::ParkingFloor(int const& newNumber){
	numberOfFloor = newNumber;
}

void ParkngLot::ParkingFloor::ParkingDisplayBoard::setInfo(std::string const& info) {
	displayInfo = info;
}

std::string ParkngLot::ParkingFloor::ParkingDisplayBoard::getInfo()const {
	return  displayInfo;
}

void ParkngLot::ParkingFloor::updateDisplayBoard(std::string const& info) {
	parkingDisplayBoard.setInfo(info);
}

void ParkngLot::ParkingRate::setRate(long long const& newRate) {
	rate = newRate;
}

long long ParkngLot::ParkingRate::getRate() const{
	return rate;
}

void ParkngLot::setAddress(std::string const& newAddress) {
	address = newAddress;
}

std::string ParkngLot::getAddress()const {
	return address;;
}

void ParkngLot::isFull(bool const& full) {
	isUnavailable = full;
}

bool ParkngLot::getStatus()const {
	return isUnavailable;
}

Vehicle::Vehicle(std::string const& newNumber, VehicleType const& newType) {
	licenseNumber = newNumber;
	vehicleType = newType;
}

void Vehicle::assigneTicket(int const& ticketNumber) {
	numberOfTicket = ticketNumber;
}