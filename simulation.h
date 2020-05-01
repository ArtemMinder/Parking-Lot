#ifndef SIMULATION_H
#define SIMULATION_H
#include <QWidget>
#include "vehicle.h"
#include "Types.h"
#include <random>

namespace Ui {
class Simulation;
}

class Simulation : public QWidget
{
    Q_OBJECT

public:
    explicit Simulation(QWidget *parent = nullptr);
    QString generateNumber();
    Types::VehicleType generateType();
    int generateTime();
    ~Simulation();

private:
    Ui::Simulation *ui;
};

#endif // SIMULATION_H
