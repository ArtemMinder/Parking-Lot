#ifndef IDATABASE_H
#define IDATABASE_H

#include <QString>
#include <QSqlQueryModel>
#include "CarModel.h"

class Idatabase
{
public:
    virtual CarModel* show() = 0;
    virtual CarModel* commit(int place, std::string license, std::string type,
              std::string startTime, int parkingTime, long long amount) = 0;
    virtual CarModel* del(int place, std::string license, std::string type,
              std::string startTime, int parkingTime, long long amount) = 0;
    virtual CarModel* delAll() = 0;
    virtual CarModel* add(int place, std::string license, std::string type,
              std::string startTime, int parkingTime, long long amount) = 0;
    virtual void transfer() = 0;
    virtual ~Idatabase () {};
};
#endif // IDATABASE_H
