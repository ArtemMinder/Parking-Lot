#ifndef ENUMS_H
#define ENUMS_H

#include <QObject>

class Enums : public QObject
{
    Q_OBJECT
public:
public:
    enum SpotType: char {
        Compact, Medium, Large, Motorcycle, Electric, Handicapped
    };
    Q_ENUM(SpotType)
    enum VehicleType: char {
         MiniCooper, Car, Bus, Moto, ElectroCar, HandicappedCar
    };
    Q_ENUM(VehicleType)
    Enums() = delete;

};

#endif // ENUMS_H
