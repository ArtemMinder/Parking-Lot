#ifndef PARKINGDISPLAYBOARD_H
#define PARKINGDISPLAYBOARD_H

#include <QApplication>

class ParkingDisplayBoard
{
public:
    ParkingDisplayBoard();
    void setInfo(std::string const& info);
    std::string getInfo()const;
private:
    int displayNumber = 0;
    std::string displayInfo = {};
};

#endif // PARKINGDISPLAYBOARD_H
