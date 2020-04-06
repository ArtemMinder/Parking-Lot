#ifndef TYPES_H
#define TYPES_H

#include <QObject>

class Types : public QObject
{
    Q_OBJECT
public:
    enum SpotType: int {
        Compact, Medium, Large, Motorcycle, Electric, Handicapped
    };
    Q_ENUM(SpotType)
    enum VehicleType: int {
         MiniCooper, Car, Bus, Moto, ElectroCar, HandicappedCar
    };
    Q_ENUM(VehicleType)
   Types() = delete;
};
#endif // TYPES_H
