#include "account.h"
#include <QDebug>

Account::Account()
{
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("ParkingDB");
    if(dataBase.open()){
        sqlQuery = QSqlQuery(dataBase);

    } else {
        qDebug()<<"o neet!";
    }
}

QSqlDatabase Account::getDB()const{
    return dataBase;
}
