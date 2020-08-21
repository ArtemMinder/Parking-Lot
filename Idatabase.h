#ifndef IDATABASE_H
#define IDATABASE_H

#include <QString>
#include <QSqlQueryModel>
#include "CarModel.h"

class Idatabase
{
public:
    virtual std::vector<CarModel> show() = 0;
    virtual std::vector<CarModel> commit(int place, std::string license, std::string type,
              std::string startTime, int parkingTime, long long amount) = 0;
    virtual std::vector<CarModel> del(int place, std::string license, std::string type,
              std::string startTime, int parkingTime, long long amount) = 0;
    virtual std::vector<CarModel> delAll() = 0;
    virtual std::vector<CarModel> add(int place, std::string license, std::string type,
              std::string startTime, int parkingTime, long long amount) = 0;
    virtual void transfer() = 0;
    virtual ~Idatabase () {};
};
#endif // IDATABASE_H
