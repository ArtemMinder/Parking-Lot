#include "sqlitedb.h"

SqliteDB::SqliteDB()
{
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("ParkingLot.sqlite");
    dataBase.open();
    mod = new model();
    sqlQuery = new QSqlQuery(dataBase);
}

std::vector<CarModel> SqliteDB::commit(int place, std::string license, std::string type,
                                 std::string startTime, int parkingTime, long long amount){
    QString newPlace = QString::number(place);
    QString newLicense = QString::fromStdString(license);
    QString newType = QString::fromStdString(type);
    QString newStartTime = QString::fromStdString(startTime);
    QString newParkingTime = QString::number(parkingTime);
    QString newAmount = QString::number(amount);
    sqlQuery->prepare("UPDATE parking set place = '"+newPlace+"' , license_number = '"+newLicense+"' ,"
                        " type = '"+newType+"' , time_of_coming = '"+newStartTime+"' ,"
                        " parking = '"+newParkingTime+"' , amount = '"+newAmount+"' where license_number = '"+newLicense+"'");
    sqlQuery->exec();
    mod->getModel()->setQuery(*sqlQuery);
    transfer();
    return notes;
}

std::vector<CarModel> SqliteDB::show(){
    sqlQuery->prepare("SELECT * from Parking");
    sqlQuery->exec();
    mod->getModel()->setQuery(*sqlQuery);
    transfer();
    return notes;
}

std::vector<CarModel> SqliteDB::del(int place, std::string license, std::string type,
                              std::string startTime, int parkingTime, long long amount){
    QString newPlace = QString::number(place);
    QString newLicense = QString::fromStdString(license);
    QString newType = QString::fromStdString(type);
    QString newStartTime = QString::fromStdString(startTime);
     QString newParkingTime = QString::number(parkingTime);
    QString newAmount = QString::number(amount);
    sqlQuery->prepare("DELETE  from Parking where place = '"+newPlace+"' and license_number = '"+newLicense+"'"
                        "and type = '"+newType+"' and time_of_coming = '"+newStartTime+"' and parking = '"+newParkingTime+"'"
                        "and amount = '"+newAmount+"'");
    sqlQuery->exec();
    mod->getModel()->setQuery(*sqlQuery);
    transfer();
    return notes;
}

std::vector<CarModel> SqliteDB::delAll(){
    sqlQuery->prepare("DELETE  from Parking");
    sqlQuery->exec();
    mod->getModel()->setQuery(*sqlQuery);
    transfer();
    return notes;
}

std::vector<CarModel> SqliteDB::add(int place, std::string license, std::string type,
                              std::string startTime, int parkingTime, long long amount){
    QString newPlace = QString::number(place);
    QString newLicense = QString::fromStdString(license);
    QString newType = QString::fromStdString(type);
    QString newStartTime = QString::fromStdString(startTime);
    QString newParkingTime = QString::number(parkingTime);
    QString newAmount = QString::number(amount);
    sqlQuery->prepare("INSERT into Parking (place, license_number, type,"
                      " time_of_coming, parking, amount) values('"+newPlace+"' ,"
                               " '"+newLicense+"' , '"+newType+"' , '"+newStartTime+"' , "
                          "'"+newParkingTime+"', '"+newAmount+"')");
    sqlQuery->exec();
    mod->getModel()->setQuery(*sqlQuery);
    transfer();
    return notes;
}

void SqliteDB::transfer(){
    notes.clear();
    for (int i = 0; i < mod->getModel()->rowCount(); ++i) {
        QSqlRecord record = mod->getModel()->record(i);
        int place = record.value("place").toInt();
        std::string license_number = record.value("license_number").toString().toStdString();
        std::string type = record.value("type").toString().toStdString();
        std::string time_of_coming = record.value("time_of_coming").toString().toStdString();
        std::string parking = record.value("parking").toString().toStdString();
        long long amount = record.value("amount").toLongLong();
        cmod.place = place;
        cmod.license = license_number;
        cmod.type = type;
        cmod.startTime = time_of_coming;
        cmod.parkingTime = parking;
        cmod.amount = amount;
        notes.push_back(cmod);
    }
}
