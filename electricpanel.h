#ifndef ELECTRICPANEL_H
#define ELECTRICPANEL_H

#include <QApplication>

class ElectricPanel
{
public:
    ElectricPanel();
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

#endif // ELECTRICPANEL_H
