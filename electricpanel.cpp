#include "electricpanel.h"

ElectricPanel::ElectricPanel()
{

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
