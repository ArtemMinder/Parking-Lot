#include "account.h"
#include <QDebug>

Account::Account()
{
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("database.db3");
    if(dataBase.open()){

    } else {

    }
}

QSqlDatabase Account::getDB()const{
    return dataBase;
}
