#ifndef IDATABASE_H
#define IDATABASE_H

#include <QString>
#include <QSqlQueryModel>
<<<<<<< HEAD
#include "CarModel.h"
=======
>>>>>>> 7621f5733b019e921c2f7adc17fc3bf11b0eb398

class Idatabase
{
public:
<<<<<<< HEAD
    virtual CarModel* show() = 0;
    virtual CarModel* load(int place, std::string license, std::string type,
              std::string startTime, int parkingTime, long long amount) = 0;
    virtual CarModel* commit(int place, std::string license, std::string type,
              std::string startTime, int parkingTime, long long amount) = 0;
    virtual CarModel* del(int place, std::string license, std::string type,
              std::string startTime, int parkingTime, long long amount) = 0;
    virtual CarModel* delAll() = 0;
    virtual CarModel* add(int place, std::string license, std::string type,
              std::string startTime, int parkingTime, long long amount) = 0;
    virtual void transfer() = 0;
=======
    virtual QSqlQueryModel* show() = 0;
    virtual QSqlQueryModel* load(QString place, QString license, QString type,
              QString startTime, QString parkingTime, QString amount) = 0;
    virtual QSqlQueryModel* commit(QString place, QString license, QString type,
              QString startTime, QString parkingTime, QString amount) = 0;
    virtual QSqlQueryModel* del(QString place, QString license, QString type,
              QString startTime, QString parkingTime, QString amount) = 0;
    virtual QSqlQueryModel* delAll() = 0;
    virtual QSqlQueryModel* add(QString place, QString license, QString type,
              QString startTime, QString parkingTime, QString amount) = 0;
    virtual QSqlQueryModel* getModel() = 0;
>>>>>>> 7621f5733b019e921c2f7adc17fc3bf11b0eb398
    virtual ~Idatabase () {};
};
#endif // IDATABASE_H
