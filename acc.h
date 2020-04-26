#ifndef ACC_H
#define ACC_H

#include <QDialog>
#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class Acc;
}

class Acc : public QDialog
{
    Q_OBJECT

public:
    explicit Acc(QWidget *parent = nullptr);
    QSqlDatabase getDB()const;
    bool isAuthorized(QString const& newLogin, QString const& newPassword);
    void authentification();
    void setStatus(QString const& newStatus);
    QString getStatus();

    ~Acc();
private slots:
    void on_enterButton_clicked();

private:
    Ui::Acc *ui;
    QString status = {};
    QString adminLogin = "admin";
    QString adminPassword = "admin";
    QString userLogin = "user";
    QString userPassword = "user";
    QSqlDatabase dataBase;
};

#endif // ACC_H
