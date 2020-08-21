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
    std::vector<CarModel> show()override;
    std::vector<CarModel> commit(int place, std::string license, std::string type,
          std::string startTime, int parkingTime, long long amount) override;
    std::vector<CarModel> del(int place, std::string license, std::string type,
          std::string startTime, int parkingTime, long long amount) override;
    std::vector<CarModel> delAll() override;
    std::vector<CarModel> add(int place, std::string license, std::string type,
          std::string startTime, int parkingTime, long long amount) override;
    void transfer() override;
    ~SqliteDB() = default;
private:
    CarModel cmod;
    model *mod;
    QSqlQuery *sqlQuery;
    QSqlDatabase dataBase;
    std::vector<CarModel> notes;
};

#endif // SQLITEDB_H
