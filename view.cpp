#include "view.h"
#include "ui_view.h"
#include <QDebug>

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

    for(auto i = 0; i < Compact.size(); i++){Compact[i]->setPixmap(online);}
    for(auto i = 0; i < Medium.size(); i++){Medium[i]->setPixmap(online);}
    for(auto i = 0; i < Large.size(); i++){Large[i]->setPixmap(online);}
    for(auto i = 0; i < Motorcycle.size(); i++){Motorcycle[i]->setPixmap(online);}
    for(auto i = 0; i < Electric.size(); i++){Electric[i]->setPixmap(online); }
    for(auto i = 0; i < Handicapped.size(); i++){Handicapped[i]->setPixmap(online);}

    model = new QStandardItemModel(122, 6, this);
    item = new QStandardItem;
    account = new Account;
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
    QStringList horizontalHeader;
    horizontalHeader.append("Место");
    horizontalHeader.append("Номер ТС");
    horizontalHeader.append("Тип ТС");
    horizontalHeader.append("Время прибытия");
     horizontalHeader.append("Время стоянки");
    horizontalHeader.append("Стоимость услуг");
    horizontalHeader.append("Оплачено");


     this->loot += newAmount;
     QString place = QString::number(newPlase);
     QString parkingTime = QString::number(newParkingTime);
     QString license = QString::fromUtf8(newLicense.c_str());
     QString type = QString::number(newType);
     if(type =="0"){type = "Легковой мини";}
     else if(type =="1"){type = "Легковой стандарт";}
     else if(type =="2"){type = "Крупногабаритный";}
     else if(type =="3"){type = "Мотоцикл";}
     else if(type =="4"){type = "Электромобиль";}
     else{type = "Handicapped";}
     QString startTime = QString::fromUtf8(newStartTime.c_str());
     QString amount = QString::number(newAmount);

    model->setHorizontalHeaderLabels(horizontalHeader);

    this->noteNumber += 1;

    dataBase = account->getDB();


    item = new QStandardItem(QString(place));
    model->setItem(noteNumber, 0, item);
    item = new QStandardItem(QString(license));
    model->setItem(noteNumber, 1, item);
    item = new QStandardItem(QString(type));
    model->setItem(noteNumber, 2, item);
    item = new QStandardItem(QString(startTime));
    model->setItem(noteNumber, 3, item);
    item = new QStandardItem(QString(parkingTime)+" минут");
    model->setItem(noteNumber, 4, item);
    item = new QStandardItem(QString(amount)+"$");
    model->setItem(noteNumber, 5, item);
    item = new QStandardItem(QString("+"));
    model->setItem(noteNumber, 6, item);

    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();

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

View::~View()
{
    delete ui;
}
