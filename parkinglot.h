#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <QDialog>
#include "iostream"
#include "parkingfloor.h"
#include "entrancepanel.h"
#include "vehicle.h"
#include "view.h"
#include "parkingrate.h"
#include "simulation.h"
#include <QObject>
#include <QTime>
#include <QTimer>

namespace Ui {
class ParkingLot;
}

class ParkingLot : public QDialog
{
    Q_OBJECT

public:
    explicit ParkingLot(QWidget *parent = nullptr);
    ParkingLot (int const& newNumberOfFloors = 1, int const& newNumberOfCompacts = 18,
               int const& newNumberOfMediums = 53, int const& newNumberOfLarges = 14,
               int const& newNumberOfMoto = 10, int const& newNumberOfElectrics = 10,
               int const& newNumberOfHandicapped = 14);
    ~ParkingLot();
private:
private slots:
    void receiveCar();
    void deleteCar();
public slots:
    void simulate();
private:
    int mode = {};
    int numberOfFloors = 0;
    int numberOfCompactSpots = 0;
    int numberOfMediumSpots = 0;
    int numberOfLargeSpots = 0;
    int numberOfMotorcycleSpots = 0;
    int numberOfElectricSpots = 0;
    int numberOfHandicappedSpots = 0;
    std::vector<ParkingFloor> floors = {};
    EntrancePanel *enterPanel;
    Vehicle *vehicle;
    View *view;
    ParkingRate *rate;
    Simulation *sim;
    QTimer *add;
    QTimer *del;
    Ui::ParkingLot *ui;
};

#endif // PARKINGLOT_H
