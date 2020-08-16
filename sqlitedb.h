#ifndef SQLITEDB_H
#define SQLITEDB_H

<<<<<<< HEAD

#include <QSqlQuery>
#include <QSqlQueryModel>
#include "CarModel.h"
#include "QSqlRecord"
#include "model.h"
#include "Idatabase.h"
=======
#include "model.h"
#include <QSqlQuery>
#include "Idatabase.h"
#include <QSqlQueryModel>
>>>>>>> 7621f5733b019e921c2f7adc17fc3bf11b0eb398

class SqliteDB : public Idatabase
{
public:
    SqliteDB();
<<<<<<< HEAD
    CarModel* show()override;
    CarModel* load(int place, std::string license, std::string type,
          std::string startTime, int parkingTime, long long amount) override;
    CarModel* commit(int place, std::string license, std::string type,
          std::string startTime, int parkingTime, long long amount) override;
    CarModel* del(int place, std::string license, std::string type,
          std::string startTime, int parkingTime, long long amount) override;
    CarModel* delAll() override;
    CarModel* add(int place, std::string license, std::string type,
          std::string startTime, int parkingTime, long long amount) override;
    void transfer() override;
    ~SqliteDB() = default;
private:
    CarModel *cmod;
=======
    QSqlQueryModel* show()override;
    QSqlQueryModel* load(QString place, QString license, QString type,
              QString startTime, QString parkingTime, QString amount) override;
    QSqlQueryModel* commit(QString place, QString license, QString type,
              QString startTime, QString parkingTime, QString amount) override;
    QSqlQueryModel* del(QString place, QString license, QString type,
              QString startTime, QString parkingTime, QString amount) override;
    QSqlQueryModel* delAll() override;
    QSqlQueryModel* add(QString place, QString license, QString type,
              QString startTime, QString parkingTime, QString amount) override;
    QSqlQueryModel* getModel() override;
private:
>>>>>>> 7621f5733b019e921c2f7adc17fc3bf11b0eb398
    model *mod;
    QSqlQuery *sqlQuery;
    QSqlDatabase dataBase;
};

#endif // SQLITEDB_H
