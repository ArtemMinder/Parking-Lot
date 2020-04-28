#include "view.h"
#include "ui_view.h"
#include "QMessageBox"

View::View(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    setWindowIcon(QIcon(QString::fromUtf8(":/images/images/Logo333.ico")));
    Compact = {ui->label1,ui->label2,ui->label3,ui->label4,ui->label5,ui->label6,ui->label7,
               ui->label8,ui->label9,ui->label10,ui->label11,ui->label12,ui->label13,ui->label14,
               ui->label15,ui->label16,ui->label17,ui->label18};
    Medium = {ui->label2_1,ui->label2_2,ui->label2_3,ui->label2_4,ui->label2_5,ui->label2_6,ui->label2_7,
ui->label2_8,ui->label2_9,ui->label2_10,ui->label2_11,ui->label2_12,ui->label2_13,ui->label2_14,ui->label2_15,
ui->label2_16,ui->label2_17,ui->label2_18,ui->label2_19,ui->label2_20,ui->label2_21,ui->label2_22,ui->label2_23,
ui->label2_24,ui->label2_25,ui->label2_26,ui->label2_27,ui->label2_28,ui->label2_29,ui->label2_30,ui->label2_31,
ui->label2_32,ui->label2_33,ui->label2_34,ui->label2_35,ui->label2_36,ui->label2_37,ui->label2_38,ui->label2_39,
ui->label2_40,ui->label2_41,ui->label2_42,ui->label2_43,ui->label2_44,ui->label2_45,ui->label2_46,ui->label2_47
,ui->label2_48,ui->label2_49,ui->label2_50,ui->label2_51,ui->label2_52,ui->label2_53};
    Large = {ui->label3_1,ui->label3_2,ui->label3_3,ui->label3_4,ui->label3_5,ui->label3_6,ui->label3_7,
             ui->label3_8,ui->label3_9,ui->label3_10,ui->label3_11,ui->label3_12,ui->label3_13,ui->label3_14};
    Motorcycle = {ui->label4_1,ui->label4_2,ui->label4_3,ui->label4_4,ui->label4_5,ui->label4_6,ui->label4_7,
                  ui->label4_8,ui->label4_9,ui->label4_10};
    Electric = {ui->label5_1,ui->label5_2,ui->label5_3,ui->label5_4,ui->label5_5,ui->label5_6,ui->label5_7,
                ui->label5_8,ui->label5_9,ui->label5_10,ui->label5_11,ui->label5_12,ui->label5_13,ui->label5_14,
                ui->label5_15,ui->label5_16,ui->label5_17};
    Handicapped = {ui->label6_1,ui->label6_2,ui->label6_3,ui->label6_4,ui->label6_5,ui->label6_6,ui->label6_7,
                   ui->label6_8,ui->label6_9,ui->label6_10};
    ui->adminLed->setPixmap(isNotFree);

    for(auto i = 0; i < Compact.size(); i++){Compact[i]->setPixmap(online);}
    for(auto i = 0; i < Medium.size(); i++){Medium[i]->setPixmap(online);}
    for(auto i = 0; i < Large.size(); i++){Large[i]->setPixmap(online);}
    for(auto i = 0; i < Motorcycle.size(); i++){Motorcycle[i]->setPixmap(online);}
    for(auto i = 0; i < Electric.size(); i++){Electric[i]->setPixmap(online); }
    for(auto i = 0; i < Handicapped.size(); i++){Handicapped[i]->setPixmap(online);}

    ui->adminBox->setGeometry(1076, 23, 381, 191);
    ui->editBox->hide();
    ui->statBox->hide();
    ui->add->hide();
    ui->delete_all->hide();
    ui->deleteNoteButton->hide();
    ui->tableView->hide();

    acc = new Acc;
    dataBase = acc->getDB();
    dataBase.open();
    model = new QSqlQueryModel();
    sqlQuery = new QSqlQuery(dataBase);
    sqlQuery->prepare("select * from Parking");
    sqlQuery->exec();
    model->setQuery(*sqlQuery);
    ui->tableView->setModel(model);
    this->close();
    ui->tableView->close();
    acc->authentification();
    this->checkStatus();
}

void View::busy(int const& newPlase, Types::VehicleType const& newType){
    switch(newType){
        case Types::VehicleType::MiniCooper:{
            Compact[newPlase-1]->setPixmap(isNotFree);
            break;
        }
        case Types::VehicleType::Car:{
            Medium[newPlase-1]->setPixmap(isNotFree);
            break;
        }
        case Types::VehicleType::Bus:{
            Large[newPlase-1]->setPixmap(isNotFree);
            break;
        }
        case Types::VehicleType::Moto:{
            Motorcycle[newPlase-1]->setPixmap(isNotFree);
            break;
        }
         case Types::VehicleType::ElectroCar:{
            Electric[newPlase-1]->setPixmap(isNotFree);
            break;
        }
        case Types::VehicleType::HandicappedCar:{
            Handicapped[newPlase-1]->setPixmap(isNotFree);
            break;
        }
    }
 this->repaint();
}

void View::free(int const& newPlase, Types::VehicleType const& newType){
    switch(newType){
        case Types::VehicleType::MiniCooper:{
            Compact[newPlase-1]->setPixmap(online);
            break;
        }
        case Types::VehicleType::Car:{
            Medium[newPlase-1]->setPixmap(online);
            break;
        }
        case Types::VehicleType::Bus:{
            Large[newPlase-1]->setPixmap(online);
            break;
        }
        case Types::VehicleType::Moto:{
            Motorcycle[newPlase-1]->setPixmap(online);
            break;
        }
         case Types::VehicleType::ElectroCar:{
            Electric[newPlase-1]->setPixmap(online);
            break;
        }
        case Types::VehicleType::HandicappedCar:{
            Handicapped[newPlase-1]->setPixmap(online);
            break;
        }
    }
 this->repaint();
}

void View::loadInfo(int const& newPlase, std::string const& newLicense, Types::VehicleType const& newType,
                    std::string const& newStartTime, double const& newAmount, int const& newParkingTime){
     this->loot += newAmount;
     QString place = QString::number(newPlase);
     QString parkingTime = QString::number(newParkingTime)+"мин";
     QString license = QString::fromUtf8(newLicense.c_str());
     QString type = QString::number(newType);
     if(type =="0"){type = "Легковой мини";}
     else if(type =="1"){type = "Легковой стандарт";}
     else if(type =="2"){type = "Крупногабаритный";}
     else if(type =="3"){type = "Мотоцикл";}
     else if(type =="4"){type = "Электромобиль";}
     else{type = "Handicapped";}
     QString startTime = QString::fromUtf8(newStartTime.c_str());
     QString amount = QString::number(newAmount)+"$";
     this->noteNumber += 1;


     dataBase.open();
     sqlQuery->prepare("insert into Parking (place, license_number, type,"
                       " time_of_coming, parking, amount) values('"+place+"' ,"
                       " '"+license+"' , '"+type+"' , '"+startTime+"' , "
                       "'"+parkingTime+"', '"+amount+"')");
     sqlQuery->exec();
     sqlQuery->prepare("select * from Parking");
     sqlQuery->exec();
     model->setQuery(*sqlQuery);
     ui->tableView->setModel(model);

     if(maxTime < newParkingTime){
         maxTime = newParkingTime;
     }
     this->cost = (employeeCost + electricCost) * maxTime;
     this->profit = loot - cost;
     QString newLoot = QString::number(loot);
     QString newCost = QString::number(cost);
     QString newProfit = QString::number(profit);
     ui->Loot_label->setText(QString(newLoot)+"$");
     ui->Cost_label->setText(QString(newCost)+"$");
     ui->Profit_label->setText(QString(newProfit)+"$");
}

void View::on_pushButton_clicked()
{
    if(acc->isAuthorized(ui->loginBox->toPlainText(), ui->passwordBox->toPlainText())==true) {
        ui->loginBox->clear();
        ui->passwordBox->clear();
        ui->warningLabel->close();
        ui->label->close();
        ui->adminLed->setPixmap(online);
        ui->tableView->show();
        ui->statBox->show();
        ui->add->show();
        ui->deleteNoteButton->show();
        ui->delete_all->show();
        ui->tableView->setGeometry(1070, 220, 811, 761);
        ui->adminBox->setGeometry(1076, 23, 381, 191);}
    else{
        QMessageBox msgBox;
        msgBox.setText("Password/login was entered incorrectly.");
        msgBox.exec();
    }
}

void View::on_exitButton_clicked()
{
   ui->adminBox->setGeometry(1250, 250, 381, 191);
   ui->tableView->close();
   ui->editBox->hide();
   ui->statBox->hide();
   ui->add->hide();
   ui->deleteNoteButton->hide();
   ui->delete_all->hide();
   ui->adminLed->setPixmap(isNotFree);
   ui->warningLabel->show();
   ui->label->show();
}

void View::checkStatus(){
    if(acc->getStatus() == "admin"){
        ui->adminLed->setPixmap(online);
        ui->tableView->setGeometry(1070, 220, 811, 761);
        ui->adminBox->setGeometry(1076, 23, 381, 191);
        ui->statBox->show();
        ui->delete_all->show();
        ui->deleteNoteButton->show();
        ui->add->show();
        ui->warningLabel->close();
        ui->label->close();
        ui->tableView->show();
        this->open();
    }
    else if(acc->getStatus() == "user"){
        ui->adminLed->setPixmap(isNotFree);
        ui->adminBox->setGeometry(1250, 250, 381, 191);
        ui->tableView->close();
        this->open();
    }
}

void View::on_delete_all_clicked()
{

    QMessageBox msgBox;
    msgBox.setWindowTitle("Delete all notes");
    msgBox.setText("Are you sure, you want to delete all records from the database?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
        sqlQuery->prepare("delete  from Parking");
        sqlQuery->exec();
        sqlQuery->prepare("select * from Parking");
        sqlQuery->exec();
        model->setQuery(*sqlQuery);
        ui->tableView->setModel(model);
    }else {

    }

}

View::~View()
{
    delete ui;
}


void View::on_tableView_activated(const QModelIndex &index)
{
    ui->adminBox->setGeometry(1076, 23, 381, 191);
    ui->editBox->show();
    ui->statBox->show();
    ui->add->show();
    ui->addButton->hide();
    ui->deleteButton->hide();
    ui->commitButton->show();
    ui->delete_all->show();
    ui->tableView->setGeometry(1070, 360, 811, 620);
    QString val = ui->tableView->model()->data(index).toString();
    sqlQuery->prepare("select * from parking where place ='"+val+"' "
                       "or license_number ='"+val+"' or type ='"+val+"' "
                       "or time_of_coming ='"+val+"' or parking ='"+val+"'"
                       "or amount ='"+val+"'");
    exPlace = ui->placeEdit->toPlainText();
    exType = ui->typeEdit->toPlainText();
    exMoney = ui->amountEdit->toPlainText();

    sqlQuery->exec();

    if(sqlQuery-exec()){
        while(sqlQuery->next()){
            ui->placeEdit->setPlainText(sqlQuery->value(0).toString());
            ui->licenseEdit->setPlainText(sqlQuery->value(1).toString());
            ui->typeEdit->setPlainText(sqlQuery->value(2).toString());
            ui->time1Edit->setPlainText(sqlQuery->value(3).toString());
            ui->Time2Edit->setPlainText(sqlQuery->value(4).toString());
            ui->amountEdit->setPlainText(sqlQuery->value(5).toString());
        }
    }
}

void View::on_closeEditButton_clicked()
{
    ui->editBox->hide();
    ui->tableView->setGeometry(1070, 220, 811, 761);
}

void View::on_commitButton_clicked()
{
    QString newPlace, newLicense, newType, newTimeOfComing, newParkingTime, newAmount;
    newPlace = ui->placeEdit->toPlainText();
    newLicense = ui->licenseEdit->toPlainText();
    newType = ui->typeEdit->toPlainText();
    newTimeOfComing = ui->time1Edit->toPlainText();
    newParkingTime= ui->Time2Edit->toPlainText();
    newAmount= ui->amountEdit->toPlainText();
    int place = newPlace.toInt();
    Types::VehicleType type = {};
    if ((newType == "Легковой мини" && newPlace.toInt() <= 17 ) || (newType == "Легковой стандарт" && newPlace.toInt() <= 53) ||
        (newType == "Крупногабаритный" && newPlace.toInt() <= 14) || (newType == "Мотоцикл" && newPlace.toInt() <= 10) ||
        (newType == "Электромобиль" && newPlace.toInt() <= 17 ) || ( newType == "Handicapped" && newPlace.toInt() <= 10) ){

    if(newType == "Легковой мини"){type = Types::VehicleType::MiniCooper;}
    else if(newType == "Легковой стандарт"){type = Types::VehicleType::Car;}
    else if(newType == "Крупногабаритный"){type = Types::VehicleType::Bus;}
    else if(newType == "Мотоцикл"){type = Types::VehicleType::Moto;}
    else if(newType == "Электромобиль"){type = Types::VehicleType::ElectroCar;}
    else if(newType == "Handicapped"){type = Types::VehicleType::HandicappedCar;}
    busy(place, type);
    if(exType == "Легковой мини"){type = Types::VehicleType::MiniCooper;}
    else if(exType == "Легковой стандарт"){type = Types::VehicleType::Car;}
    else if(exType == "Крупногабаритный"){type = Types::VehicleType::Bus;}
    else if(exType == "Мотоцикл"){type = Types::VehicleType::Moto;}
    else if(exType == "Электромобиль"){type = Types::VehicleType::ElectroCar;}
    else if(exType == "Handicapped"){type = Types::VehicleType::HandicappedCar;}
    free (exPlace.toInt(), type);

    sqlQuery->prepare("update parking set place = '"+newPlace+"' , license_number = '"+newLicense+"' ,"
                      " type = '"+newType+"' , time_of_coming = '"+newTimeOfComing+"' ,"
                      " parking = '"+newParkingTime+"' , amount = '"+newAmount+"' where license_number = '"+newLicense+"'");
    sqlQuery->exec();
    sqlQuery->prepare("select * from Parking");
    sqlQuery->exec();
    model->setQuery(*sqlQuery);
    ui->tableView->setModel(model);

    } else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("New data is incorrect");
        msgBox.setText("Incorrect type or number of parking place");
        msgBox.setStandardButtons(QMessageBox::Ok);
        if(msgBox.exec() == QMessageBox::Ok){
            ui->placeEdit->clear();
            ui->typeEdit->clear();
        }
    }
}

void View::on_add_clicked()
{
    ui->tableView->setGeometry(1070, 360, 811, 620);
    ui->adminBox->setGeometry(1076, 23, 381, 191);
    ui->editBox->show();
    ui->commitButton->hide();
    ui->deleteButton->hide();
    ui->addButton->show();
    ui->placeEdit->clear();
    ui->licenseEdit->clear();
    ui->typeEdit->clear();
    ui->time1Edit->clear();
    ui->Time2Edit->clear();
    ui->amountEdit->clear();
}

void View::on_addButton_clicked()
{
    QString newPlace, newLicense, newType, newTimeOfComing, newParkingTime, newAmount;
    newPlace = ui->placeEdit->toPlainText();
    newLicense = ui->licenseEdit->toPlainText();
    newType = ui->typeEdit->toPlainText();
    newTimeOfComing = ui->time1Edit->toPlainText();
    newParkingTime= ui->Time2Edit->toPlainText();
    newAmount= ui->amountEdit->toPlainText();

    if ((newType == "Легковой мини" && newPlace.toInt() <= 17 ) || (newType == "Легковой стандарт" && newPlace.toInt() <= 53) ||
        (newType == "Крупногабаритный" && newPlace.toInt() <= 14) || (newType == "Мотоцикл" && newPlace.toInt() <= 10) ||
        (newType == "Электромобиль" && newPlace.toInt() <= 17 ) || ( newType == "Handicapped" && newPlace.toInt() <= 10) ){

    sqlQuery->prepare("insert into Parking (place, license_number, type,"
                      " time_of_coming, parking, amount) values('"+newPlace+"' ,"
                      " '"+newLicense+"' , '"+newType+"' , '"+newTimeOfComing+"' , "
                      "'"+newParkingTime+"', '"+newAmount+"')");
    sqlQuery->exec();
    sqlQuery->prepare("select * from Parking");
    sqlQuery->exec();
    model->setQuery(*sqlQuery);
    ui->tableView->setModel(model);

    int place = newPlace.toInt();
    Types::VehicleType type = {};
    if(newType == "Легковой мини"){type = Types::VehicleType::MiniCooper;}
    else if(newType == "Легковой стандарт"){type = Types::VehicleType::Car;}
    else if(newType == "Крупногабаритный"){type = Types::VehicleType::Bus;}
    else if(newType == "Мотоцикл"){type = Types::VehicleType::Moto;}
    else if(newType == "Электромобиль"){type = Types::VehicleType::ElectroCar;}
    else if(newType == "Handicapped"){type = Types::VehicleType::HandicappedCar;}
    busy(place, type);
    }
    else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("New data is incorrect");
        msgBox.setText("Incorrect type or number of parking place");
        msgBox.setStandardButtons(QMessageBox::Ok);
        if(msgBox.exec() == QMessageBox::Ok){
            ui->placeEdit->clear();
            ui->typeEdit->clear();
        }
    }
}

void View::on_deleteNoteButton_clicked()
{
    ui->tableView->setGeometry(1070, 360, 811, 620);
    ui->adminBox->setGeometry(1076, 23, 381, 191);
    ui->editBox->show();
    ui->commitButton->hide();
    ui->addButton->hide();
    ui->deleteButton->show();
}

void View::on_deleteButton_clicked()
{
    QString newPlace, newLicense, newType, newTimeOfComing, newParkingTime, newAmount;
    newPlace = ui->placeEdit->toPlainText();
    newLicense = ui->licenseEdit->toPlainText();
    newType = ui->typeEdit->toPlainText();
    newTimeOfComing = ui->time1Edit->toPlainText();
    newParkingTime= ui->Time2Edit->toPlainText();
    newAmount= ui->amountEdit->toPlainText();
    sqlQuery->prepare("delete  from Parking where place = '"+newPlace+"' and license_number = '"+newLicense+"'"
                      "and type = '"+newType+"' and time_of_coming = '"+newTimeOfComing+"' and parking = '"+newParkingTime+"'"
                       "and amount = '"+newAmount+"'");
    sqlQuery->exec();
    sqlQuery->prepare("select * from Parking");
    sqlQuery->exec();
    model->setQuery(*sqlQuery);
    ui->tableView->setModel(model);

    Types::VehicleType type;
    if(newType == "Легковой мини"){type = Types::VehicleType::MiniCooper;}
    else if(newType == "Легковой стандарт"){type = Types::VehicleType::Car;}
    else if(newType == "Крупногабаритный"){type = Types::VehicleType::Bus;}
    else if(newType == "Мотоцикл"){type = Types::VehicleType::Moto;}
    else if(newType == "Электромобиль"){type = Types::VehicleType::ElectroCar;}
    else if(newType == "Handicapped"){type = Types::VehicleType::HandicappedCar;}
    free (newPlace.toInt(), type);
}
