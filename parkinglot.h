#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <QMainWindow>
#include "parkingrate.h"
#include "parkingfloor.h"

#include "QStandardItemModel"
#include "QStandardItem"
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class ParkingLot; }
QT_END_NAMESPACE

class ParkingLot : public QMainWindow
{
    Q_OBJECT

public:
    ParkingLot(QWidget *parent = nullptr);
    void setAddress(std::string const& newAddress);
    std::string getAddress()const;
    void isFull(bool const& full);
    bool getStatus()const;
    ~ParkingLot();

private:
    std::string address;
    bool isUnavailable = false;
    Ui::ParkingLot *ui;
    ParkingRate *rate;
    ParkingFloor *floor;
};
#endif // PARKINGLOT_H
