#ifndef ENUMS_H
#define ENUMS_H

#include <QObject>

class Enums : public QObject
{
    Q_OBJECT
public:
    explicit Enums(QObject *parent = nullptr);

    enum class SpotSize: char {
            Compact, Medium, Large, Motorcycle, Electric, Handicapped
        };
    enum class VeicleType: char {
            MiniCooper, Car, Bus, Moto, ElectroCar
        };

};

#endif // ENUMS_H
