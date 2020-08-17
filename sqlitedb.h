#ifndef SQLITEDB_H
#define SQLITEDB_H


#include <QSqlQuery>
#include <QSqlQueryModel>
#include "CarModel.h"
#include "QSqlRecord"
#include "model.h"
#include "Idatabase.h"

class SqliteDB : public Idatabase
{
public:
    SqliteDB();
    CarModel* show()override;
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
    model *mod;
    QSqlQuery *sqlQuery;
    QSqlDatabase dataBase;
};

#endif // SQLITEDB_H
