#ifndef SQLITEDB_H
#define SQLITEDB_H

#include "model.h"
#include <QSqlQuery>
#include "Idatabase.h"
#include <QSqlQueryModel>

class SqliteDB : public Idatabase
{
public:
    SqliteDB();
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
    model *mod;
    QSqlQuery *sqlQuery;
    QSqlDatabase dataBase;
};

#endif // SQLITEDB_H
