#include "acc.h"
#include "ui_acc.h"



Acc::Acc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acc)
{
    setWindowIcon(QIcon(QString::fromUtf8(":/images/images/Logo333.ico")));
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
       dataBase.setDatabaseName("database.db3");
       if(dataBase.open()){

       } else {

       }
}

void Acc::authentification(){
    ui->setupUi(this);
    this->show();
    this->exec();
}

bool Acc::isAuthorized(QString const& newLogin, QString const& newPassword){
    if(QString::compare(newLogin,adminLogin)==0 && QString::compare(newPassword, adminPassword)==0 ){return true;}
    else{return false;}
}

QSqlDatabase Acc::getDB()const{
    return dataBase;
}

void Acc::setStatus(QString const& newStatus){
    this->status = newStatus;
}

QString Acc::getStatus(){
    return status;
}

void Acc::on_enterButton_clicked()
{
    if(ui->userButton->isChecked() && ui->loginBox->toPlainText() == userLogin && ui->passwordBox->toPlainText() == userPassword){
    setStatus("user");
    this->hide();
    }
    else if(ui->adminButton->isChecked() && ui->loginBox->toPlainText() == adminLogin && ui->passwordBox->toPlainText() == adminPassword){
    setStatus("admin");
    this->hide();
    }
    else  { QMessageBox msgBox;
    msgBox.setText("Password/login was entered incorrectly or access level is not checked");
    msgBox.exec(); }
}

Acc::~Acc()
{
    delete ui;
}
