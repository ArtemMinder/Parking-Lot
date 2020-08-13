#ifndef IDATABASE_H
#define IDATABASE_H

#include <QString>
#include <QSqlQueryModel>

class Idatabase
{
public:
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
    virtual ~Idatabase () {};
};
#endif // IDATABASE_H
