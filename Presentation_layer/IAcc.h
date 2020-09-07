#ifndef IACC_H
#define IACC_H

#include <QDialog>
#include <QDialog>
#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>

class IAcc
{
 public:
    virtual void authentification() = 0;
    virtual void setStatus(QString const& newStatus) = 0;
    virtual bool isAuthorized(QString const& newLogin, QString const& newPassword) = 0;
    virtual QString getStatus() = 0;
    virtual ~IAcc () {};
};

#endif // IACC_H
