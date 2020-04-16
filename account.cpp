#include "account.h"
Account::Account()
{
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("database.db3");
    if(dataBase.open()){

    } else {

    }
}

bool Account::isAuthorized(QString const& newLogin, QString const& newPassword){
    if(QString::compare(newLogin,login)==0 && QString::compare(newPassword,password)==0 ){return true;}
    else{return false;}
}

QSqlDatabase Account::getDB()const{
    return dataBase;
}
