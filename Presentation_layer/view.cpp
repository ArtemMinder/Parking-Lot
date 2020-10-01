#include "view.h"
#include "ui_view.h"
#include <QDebug>

View::View(QWidget *parent, IExchange *exh, ParkingLot *new_p_lot, Idatabase *newdat) :
    QDialog(parent),
    pDat(newdat),
    ui(new Ui::View),
    pPLot(new_p_lot),
    pEx(exh)
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

    for(size_t i = 0; i < Compact.size(); i++){Compact[i]->setPixmap(online);}
    for(size_t i = 0; i < Medium.size(); i++){Medium[i]->setPixmap(online);}
    for(size_t i = 0; i < Large.size(); i++){Large[i]->setPixmap(online);}
    for(size_t i = 0; i < Motorcycle.size(); i++){Motorcycle[i]->setPixmap(online);}
    for(size_t i = 0; i < Electric.size(); i++){Electric[i]->setPixmap(online); }
    for(size_t i = 0; i < Handicapped.size(); i++){Handicapped[i]->setPixmap(online);}

    ui->adminBox->setGeometry(1076, 23, 381, 191);
    ui->editBox->hide();
    ui->statBox->hide();
    ui->analytics->hide();
    ui->comboBox->hide();
    ui->open_analitics->hide();
    ui->add->hide();
    ui->delete_all->hide();
    ui->deleteNoteButton->hide();
    ui->tableView->hide();
    pPLot = std::make_unique<ParkingLot>(1,17,53,14,10,10,17);
    pDat = std::make_unique <SqliteDB>();
    this->cm = pDat->show();
    transfer();
    ui->tableView->setModel(pM.get());
    this->close();
    ui->tableView->close();
    acc->authentification();
    this->checkStatus();
    this->simulateTraffic();
}

void View::simulateTraffic(){

    pAddTimer = std::make_unique<QTimer>();
    pDelTimer = std::make_unique<QTimer>();
    pDelTimer->setInterval(450);
    pAddTimer->setInterval(500);
    connect(pAddTimer.get(), SIGNAL(timeout()), this, SLOT(coming()));
    connect(pDelTimer.get(), SIGNAL(timeout()), this, SLOT(depart()));
    pDelTimer->start();
    pAddTimer->start();
}

void View::coming(){
    Vehicle newVehicle(sim->generateNumber().toStdString(), sim->generateType(), sim->generateTime());
    std::string startTime = QTime::currentTime().toString().toStdString();
    int place = 0;
    all+=1;
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    if(newVehicle.getType()==Types::MiniCooper){
        place = static_cast<int>(rand() * fraction * (17 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::Car){
        place = static_cast<int>(rand() * fraction * (53 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::Bus){
        place = static_cast<int>(rand() * fraction * (14 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::Moto){
        place = static_cast<int>(rand() * fraction * (10 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::HandicappedCar){
        place = static_cast<int>(rand() * fraction * (10 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::ElectroCar){
        place = static_cast<int>(rand() * fraction * (17 - 1 + 1) + 1);
    }
    if(place != -1){
   loadInfo(place,newVehicle.getLicense(),newVehicle.getType(),startTime,rate->getRate(newVehicle.getType(),
   newVehicle.getParkingTime()), newVehicle.getParkingTime());
   busy(place, newVehicle.getType());
    }else {
        std::cout<<"Sorry, all plases for your vehicle is unavailable"<<std::endl;
    }
    pPLot->receiveCar(place, newVehicle.getType(), newVehicle);
}

void View::depart(){
    Vehicle newVehicle(sim->generateNumber().toStdString(), sim->generateType(), sim->generateTime());
    int place = 0;
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    if(newVehicle.getType()==Types::MiniCooper){
        place = static_cast<int>(rand() * fraction * (17 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::Car){
        place = static_cast<int>(rand() * fraction * (53 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::Bus){
        place = static_cast<int>(rand() * fraction * (14 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::Moto){
        place = static_cast<int>(rand() * fraction * (10 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::HandicappedCar){
        place = static_cast<int>(rand() * fraction * (10 - 1 + 1) + 1);
    }
    else if(newVehicle.getType()==Types::ElectroCar){
        place = static_cast<int>(rand() * fraction * (17 - 1 + 1) + 1);
    }
    free(place, newVehicle.getType());
    pPLot->deleteCar(place, newVehicle.getType());
}

void View::busy(int const& newPlase, Types::VehicleType const& newType){
    switch(newType){
        case Types::VehicleType::MiniCooper:{
            Compact[newPlase-1]->setPixmap(isNotFree);
            com += 1;
            break;
        }
        case Types::VehicleType::Car:{
            Medium[newPlase-1]->setPixmap(isNotFree);
            med += 1;
            break;
        }
        case Types::VehicleType::Bus:{
            Large[newPlase-1]->setPixmap(isNotFree);
            lrg += 1;
            break;
        }
        case Types::VehicleType::Moto:{
            Motorcycle[newPlase-1]->setPixmap(isNotFree);
            mot += 1;
            break;
        }
         case Types::VehicleType::ElectroCar:{
            Electric[newPlase-1]->setPixmap(isNotFree);
            elc += 1;
            break;
        }
        case Types::VehicleType::HandicappedCar:{
            Handicapped[newPlase-1]->setPixmap(isNotFree);
            hnd += 1;
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
     QString type = QString::number(newType);
     std::string nType = {};
     if(type =="0"){nType = "Легковой мини";}
     else if(type =="1"){nType = "Легковой стандарт";}
     else if(type =="2"){nType = "Крупногабаритный";}
     else if(type =="3"){nType = "Мотоцикл";}
     else if(type =="4"){nType = "Электромобиль";}
     else{nType = "Handicapped";}
     this->noteNumber += 1;

     this->cm = pDat->add(newPlase, newLicense, nType, newStartTime+"мин", newParkingTime, newAmount);
     this->cm = pDat->show();
     transfer();
     ui->tableView->setModel(pM.get());
     if(maxTime < newParkingTime){
         maxTime = newParkingTime;
     }
     percent = (newAmount/(100*0.035) + (employeeCost + electricCost));
     this->cost += percent;
     this->profit = loot - cost;
     loot /= rateCoeff;
     cost /= rateCoeff;
     profit /= rateCoeff;
     QString newLoot = QString::number(loot);
     QString newCost = QString::number(cost);
     QString newProfit = QString::number(profit);
     ui->Loot_label->setText(QString(newLoot)+moneyName);
     ui->Cost_label->setText(QString(newCost)+moneyName);
     ui->Profit_label->setText(QString(newProfit)+moneyName);
}

void View::on_pushButton_clicked()
{
    if(acc->isAuthorized(ui->loginBox->toPlainText(), ui->passwordBox->toPlainText())==true) {
        ui->loginBox->clear();
        ui->passwordBox->clear();
        ui->warningLabel->close();
        ui->label->close();
        ui->adminLed->setPixmap(online);
        ui->comboBox->show();
        ui->open_analitics->show();
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
        ui->comboBox->show();
        ui->open_analitics->show();
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
        this->cm = pDat->delAll();
        this->cm = pDat->show();
        transfer();
        ui->tableView->setModel(pM.get());
    }else {

    }

}

void View::on_tableView_doubleClicked(const QModelIndex &index)
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
    exPlace = ui->placeEdit->toPlainText();
    exType = ui->typeEdit->toPlainText();
    exMoney = ui->amountEdit->toPlainText();
    QString val = ui->tableView->model()->data(index).toString();
    ui->placeEdit->setPlainText(pM->data(pM->index(ui->tableView->currentIndex().row(), 0)).toString());
    ui->licenseEdit->setPlainText(pM->data(pM->index(ui->tableView->currentIndex().row(), 1)).toString());
    ui->typeEdit->setPlainText(pM->data(pM->index(ui->tableView->currentIndex().row(), 2)).toString());
    ui->time1Edit->setPlainText(pM->data(pM->index(ui->tableView->currentIndex().row(), 3)).toString());
    ui->Time2Edit->setPlainText(pM->data(pM->index(ui->tableView->currentIndex().row(), 4)).toString());
    ui->amountEdit->setPlainText(pM->data(pM->index(ui->tableView->currentIndex().row(), 5)).toString());
}

void View::on_closeEditButton_clicked()
{
    ui->editBox->hide();
    ui->tableView->setGeometry(1070, 220, 811, 761);
}

void View::on_commitButton_clicked()
{
    int newPlace = {};
    std::string newLicense = {};
    std::string newType={};
    std::string newTimeOfComing = {};
    int newParkingTime = {};
    long long newAmount = {};
    newPlace = ui->placeEdit->toPlainText().toInt();
    newLicense = ui->licenseEdit->toPlainText().toStdString();
    newType = ui->typeEdit->toPlainText().toStdString();
    newTimeOfComing = ui->time1Edit->toPlainText().toStdString();
    newParkingTime= ui->Time2Edit->toPlainText().toInt();
    newAmount= ui->amountEdit->toPlainText().toLongLong();
    Types::VehicleType type = {};
    if ((newType == "Легковой мини" && newPlace <= 17 ) || (newType == "Легковой стандарт" && newPlace <= 53) ||
        (newType == "Крупногабаритный" && newPlace <= 14) || (newType == "Мотоцикл" && newPlace <= 10) ||
        (newType == "Электромобиль" && newPlace <= 17 ) || ( newType == "Handicapped" && newPlace <= 10) ){

    if(newType == "Легковой мини"){type = Types::VehicleType::MiniCooper;}
    else if(newType == "Легковой стандарт"){type = Types::VehicleType::Car;}
    else if(newType == "Крупногабаритный"){type = Types::VehicleType::Bus;}
    else if(newType == "Мотоцикл"){type = Types::VehicleType::Moto;}
    else if(newType == "Электромобиль"){type = Types::VehicleType::ElectroCar;}
    else if(newType == "Handicapped"){type = Types::VehicleType::HandicappedCar;}
    busy(newPlace, type);
    if(exType == "Легковой мини"){type = Types::VehicleType::MiniCooper;}
    else if(exType == "Легковой стандарт"){type = Types::VehicleType::Car;}
    else if(exType == "Крупногабаритный"){type = Types::VehicleType::Bus;}
    else if(exType == "Мотоцикл"){type = Types::VehicleType::Moto;}
    else if(exType == "Электромобиль"){type = Types::VehicleType::ElectroCar;}
    else if(exType == "Handicapped"){type = Types::VehicleType::HandicappedCar;}
    free (exPlace.toInt(), type);

    this->cm = pDat->commit(newPlace,newLicense,newType,newTimeOfComing,newParkingTime,newAmount);
    this->cm = pDat->show();
    transfer();
    ui->tableView->setModel(pM.get());
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
    int newPlace = {};
    std::string newLicense = {};
    std::string newType={};
    std::string newTimeOfComing = {};
    int newParkingTime = {};
    long long newAmount = {};
    newPlace = ui->placeEdit->toPlainText().toInt();
    newLicense = ui->licenseEdit->toPlainText().toStdString();
    newType = ui->typeEdit->toPlainText().toStdString();
    newTimeOfComing = ui->time1Edit->toPlainText().toStdString();
    newParkingTime= ui->Time2Edit->toPlainText().toInt();
    newAmount= ui->amountEdit->toPlainText().toLongLong();

    if ((newType == "Легковой мини" && newPlace <= 17 ) || (newType == "Легковой стандарт" && newPlace <= 53) ||
            (newType == "Крупногабаритный" && newPlace <= 14) || (newType == "Мотоцикл" && newPlace <= 10) ||
            (newType == "Электромобиль" && newPlace <= 17 ) || ( newType == "Handicapped" && newPlace <= 10) ){

        this->cm = pDat->add(newPlace, newLicense, newType, newTimeOfComing, newParkingTime, newAmount);
        this->cm = pDat->show();
        transfer();
        ui->tableView->setModel(pM.get());

    int place = newPlace;
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
    int newPlace = {};
    std::string newLicense = {};
    std::string newType={};
    std::string newTimeOfComing = {};
    int newParkingTime = {};
    long long newAmount = {};
    newPlace = ui->placeEdit->toPlainText().toInt();
    newLicense = ui->licenseEdit->toPlainText().toStdString();
    newType = ui->typeEdit->toPlainText().toStdString();
    newTimeOfComing = ui->time1Edit->toPlainText().toStdString();
    newParkingTime= ui->Time2Edit->toPlainText().toInt();
    newAmount= ui->amountEdit->toPlainText().toLongLong();

    this->cm = pDat->del(newPlace,newLicense,newType,newTimeOfComing,newParkingTime,newAmount);
    this->cm = pDat->show();
    transfer();
    ui->tableView->setModel(pM.get());

    Types::VehicleType type;
    if(newType == "Легковой мини"){type = Types::VehicleType::MiniCooper;}
    else if(newType == "Легковой стандарт"){type = Types::VehicleType::Car;}
    else if(newType == "Крупногабаритный"){type = Types::VehicleType::Bus;}
    else if(newType == "Мотоцикл"){type = Types::VehicleType::Moto;}
    else if(newType == "Электромобиль"){type = Types::VehicleType::ElectroCar;}
    else if(newType == "Handicapped"){type = Types::VehicleType::HandicappedCar;}
    free (newPlace, type);
}

void View::on_comboBox_currentTextChanged(const QString &arg1)
{
    IExchange *ex = new Exchange();
    if (arg1 == "BYN"){rateCoeff = 1;
    moneyName = "BYN";}
    else if (arg1 == "USD"){rateCoeff = ex->exchange(2);
    moneyName = "USD";}
    else if (arg1 == "EUR"){rateCoeff = ex->exchange(3);
    moneyName = "EUR";}
    else if (arg1 == "RUB"){rateCoeff = (ex->exchange(4))/100;
    moneyName = "RUB";}
}

void View::transfer(){
    int rows = cm.size();
    for(int i = 1; i < rows; i++){
       pM = std::make_unique<QStandardItemModel>(rows,6,this);
    }
    for(int i = 0; i < rows; i++){
        pM->insertRow( pM->rowCount(QModelIndex()));
        pM->setData(pM->index(i,0), cm[i].place);
        pM->setData(pM->index(i,1), QString::fromStdString(cm[i].license));
        pM->setData(pM->index(i,2), QString::fromStdString(cm[i].type));
        pM->setData(pM->index(i,3), QString::fromStdString(cm[i].startTime));
        pM->setData(pM->index(i,4), QString::fromStdString(cm[i].parkingTime));
        pM->setData(pM->index(i,5), cm[i].amount);
        money.push_back(cm[i].amount);
        time.push_back((QString::fromStdString(cm[i].parkingTime)).toInt());
        QString st = QString::fromStdString(cm[i].startTime);
        st.remove(0,3);
        st.remove(4,4);
        st.remove(2,1);
        times.push_back(st.toInt());
        all_percentage.push_back(all);
    }
}

View::~View()
{
    delete ui.get();
}

void View::on_open_analitics_clicked()
{
    ui->analytics->show();

    pSeries = std::make_unique<QtCharts::QPieSeries>();
    pSeries->append("Compact", com);
    pSeries->append("Medium", med);
    pSeries->append("Large", lrg);
    pSeries->append("Motorcycle", mot);
    pSeries->append("Handicapped", hnd);
    pSeries->append("Electric", elc);

    pChart = std::make_unique<QtCharts::QChart>();
    pChart->setScale(1);
    pChart->addSeries(pSeries.get());
    pChart->setTitle("Types frequency");
    pChart->legend()->setAlignment(Qt::AlignBottom);
    QtCharts::QPieSlice *slice = pSeries->slices().at(5);
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);
    slice->setLabel(QString("%1% Electric").arg(100*slice->percentage(), 0, 'f', 1));

    QtCharts::QPieSlice *slice_4 = pSeries->slices().at(4);
    slice_4->setLabelVisible();
    slice_4->setPen(QPen(Qt::darkMagenta, 2));
    slice_4->setBrush(Qt::magenta);
    slice_4->setLabel(QString("%1% Handicapped").arg(100*slice_4->percentage(), 0, 'f', 1));

    QtCharts::QPieSlice *slice_3 = pSeries->slices().at(3);
    slice_3->setLabelVisible();
    slice_3->setColor(QColor(253,156,31));
    slice_3->setBrush(QColor(253,156,0));
    slice_3->setLabel(QString("%1% Motorcycle").arg(100*slice_3->percentage(), 0, 'f', 1));

    QtCharts::QPieSlice *slice_2 = pSeries->slices().at(2);
    slice_2->setLabelVisible();
    slice_2->setPen(QPen(Qt::darkRed, 2));
    slice_2->setBrush(Qt::red);
    slice_2->setLabel(QString("%1% Large").arg(100*slice_2->percentage(), 0, 'f', 1));

    QtCharts::QPieSlice *slice_1 = pSeries->slices().at(1);
    slice_1->setLabelVisible();
    slice_1->setPen(QPen(Qt::darkBlue, 2));
    slice_1->setBrush(Qt::blue);
    slice_1->setLabel(QString("%1% Medium").arg(100*slice_1->percentage(), 0, 'f', 1));

    QtCharts::QPieSlice *slice_0 = pSeries->slices().at(0);
    slice_0->setLabelVisible();
    slice_0->setPen(QPen(Qt::darkYellow, 2));
    slice_0->setBrush(Qt::yellow);
    slice_0->setLabel(QString("%1% Compact").arg(100*slice_0->percentage(), 0, 'f', 1));

    pChartView = std::make_unique<QtCharts::QChartView>(pChart.get());
    pChartView->setRenderHint(QPainter::Antialiasing);

    ui->frequency->addWidget(pChartView.get());

    pSpSeries = std::make_unique<QtCharts::QSplineSeries>();
    pSpSeries->setName("spline");
    for(size_t i = 0; i < all_percentage.size(); i++){
        pSpSeries->append(times[i], all);
    }
    pSpChart = std::make_unique<QtCharts::QChart>();

    pSpChart->addSeries(pSpSeries.get());
    pSpChart->legend()->hide();
    pSpChart->setTitle("Visit Frequency");
    pSpChart->createDefaultAxes();
    pSpChart->axes(Qt::Vertical).first()->setRange(0, 100);
    pSpChart->axes(Qt::Horizontal).first()->setRange(0, 500);

    pSpChartView = std::make_unique<QtCharts::QChartView>(pSpChart.get());
    pChartView->setRenderHint(QPainter::Antialiasing);
    ui->Visit->addWidget(pSpChartView.get());

    double maxMoney = *std::max_element(money.begin(), money.end());
    double minMoney = *std::min_element(money.begin(), money.end());
    double average_money = accumulate(money.begin(), money.end(), 0.0)/money.size();
    ui->high_money->setText(QString::number(maxMoney));
    ui->ave_money->setText(QString::number(average_money));
    ui->min_money->setText(QString::number(minMoney));
    int maxTime = *std::max_element(time.begin(), time.end());
    int minTime = *std::min_element(time.begin(), time.end());
    float average = accumulate(time.begin(), time.end(), 0.0)/time.size();
    ui->high_time->setText(QString::number(maxTime));
    ui->ave_time->setText(QString::number(average));
    ui->min_time->setText(QString::number(minTime));
}

void View::on_hide_analitics_clicked()
{
    ui->analytics->hide();
}

void View::on_refresh_stat_clicked()
{
    on_hide_analitics_clicked();
    pSeries->clear();
    pChart->destroyed();
    pChartView->close();
    pSpSeries->clear();
    pSpChart->destroyed();
    pSpChartView->close();
    on_open_analitics_clicked();
}
