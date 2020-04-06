#include "view.h"
#include "ui_view.h"
#include <QDebug>

View::View(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    QWidget::showMaximized();
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
}

void View::busy(int const& newPlase, Types::VehicleType const& newType){
    qDebug()<<newType;
    switch(newType){
        case Types::VehicleType::MiniCooper:{
            Compact[newPlase-1]->setPixmap(isNotFree);
        }
        case Types::VehicleType::Car:{
            Medium[newPlase-1]->setPixmap(isNotFree);
        }
        case Types::VehicleType::Bus:{
            Large[newPlase-1]->setPixmap(isNotFree);
        }
        case Types::VehicleType::Moto:{
            Motorcycle[newPlase-1]->setPixmap(isNotFree);
        }
         case Types::VehicleType::ElectroCar:{
            Electric[newPlase-1]->setPixmap(isNotFree);
        }
        case Types::VehicleType::HandicappedCar:{
            Handicapped[newPlase-1]->setPixmap(isNotFree);
        }
    }
 this->repaint();
}

void View::free(int const& newPlase, Types::VehicleType const& newType){
    qDebug()<<newType;
    switch(newType){
        case Types::VehicleType::MiniCooper:{
            Compact[newPlase-1]->setPixmap(online);
        }
        case Types::VehicleType::Car:{
            Medium[newPlase-1]->setPixmap(online);
        }
        case Types::VehicleType::Bus:{
            Large[newPlase-1]->setPixmap(online);
        }
        case Types::VehicleType::Moto:{
            Motorcycle[newPlase-1]->setPixmap(online);
        }
         case Types::VehicleType::ElectroCar:{
            Electric[newPlase-1]->setPixmap(online);
        }
        case Types::VehicleType::HandicappedCar:{
            Handicapped[newPlase-1]->setPixmap(online);
        }
    }
 this->repaint();
}

View::~View()
{
    delete ui;
}
