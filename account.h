#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<QSql>
#include<QSqlQuery>

class Account
{
public:
    Account();
    QSqlDatabase getDB()const;
private:
    QSqlDatabase dataBase;
    QSqlQuery sqlQuery;
};

#endif // ACCOUNT_H
