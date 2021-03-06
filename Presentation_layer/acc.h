#ifndef ACC_H
#define ACC_H

#include "IAcc.h"

namespace Ui {
class Acc;
}

class Acc : public QDialog, public IAcc
{
    Q_OBJECT

public:
    explicit Acc(QWidget *parent = nullptr);
    bool isAuthorized(QString const& newLogin, QString const& newPassword)override;
    void authentification()override;
    void setStatus(QString const& newStatus)override;
    QString getStatus()override;
    ~Acc();
private slots:
    void on_enterButton_clicked();

private:
    std::unique_ptr<Ui::Acc> ui;
    QString status = {};
    QString adminLogin = "admin";
    QString adminPassword = "admin";
    QString userLogin = "user";
    QString userPassword = "user";
    QSqlDatabase dataBase;
};

#endif // ACC_H
