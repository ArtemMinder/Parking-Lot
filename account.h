#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<QSql>
#include<QSqlQuery>

class Account
{
public:
    Account();
    QSqlDatabase getDB()const;
    bool isAuthorized(QString const& newLogin, QString const& newPassword);
private:
    QString login = "admin";
    QString password = "admin";
    QSqlDatabase dataBase;
    QSqlQuery sqlQuery;
};

#endif // ACCOUNT_H
