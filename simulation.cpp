#include "simulation.h"
#include "ui_simulation.h"

Simulation::Simulation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Simulation)
{
    ui->setupUi(this);
}

QString Simulation::generateNumber(){
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    QString first = QString::number(static_cast<int>(rand() * fraction * (9 - 0 + 1) + 0));
    QString second = QString::number(static_cast<int>(rand() * fraction * (9 - 0 + 1) + 0));
    QString third = QString::number(static_cast<int>(rand() * fraction * (9 - 0 + 1) + 0));
    QString fourth = QString::number(static_cast<int>(rand() * fraction * (9 - 0 + 1) + 0));
    QString fifth = QString::number(static_cast<int>(rand() * fraction * (7 - 1 + 1) + 1));

    QString fullNumber = first + second + third + fourth + "AB-" + fifth;
    return fullNumber;
}

Types::VehicleType Simulation::generateType(){
    Types::VehicleType type;
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    int randType = static_cast<int>(rand() * fraction * (6 - 0 + 0) + 0);
    switch(randType){
    case 0:{
        type = Types::VehicleType::Car;
        return type;
        break;
    }
    case 1:{
        type = Types::VehicleType::Moto;
        return type;
        break;
    }
    case 2:{
        type = Types::VehicleType::ElectroCar;
        return type;
        break;
    }
    case 3:{
        type = Types::VehicleType::MiniCooper;
        return type;
        break;
    }
    case 4:{
        type = Types::VehicleType::Bus;
        return type;
        break;
    }
    case 5:{
        type = Types::VehicleType::HandicappedCar;
        return type;
        break;
    }
    default : type = Types::VehicleType::Car;
    }
    return Types::VehicleType::Car;
}

int Simulation::generateTime(){
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    int time = static_cast<int>(rand() * fraction * (300 - 30 + 1) + 30);
    return time;
}

Simulation::~Simulation()
{
    delete ui;
}
