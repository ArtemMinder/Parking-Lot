#include "sqlitedb.h"

SqliteDB::SqliteDB()
{
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("ParkingLot.sqlite");
    dataBase.open();
    mod = new model();
    sqlQuery = new QSqlQuery(dataBase);    
}
QSqlQueryModel* SqliteDB::load(QString place, QString license, QString type,
                    QString startTime, QString parkingTime, QString amount){
    dataBase.open();
    sqlQuery->prepare("insert into Parking (place, license_number, type,"
                      " time_of_coming, parking, amount) values('"+place+"' ,"
                      " '"+license+"' , '"+type+"' , '"+startTime+"' , "
                      "'"+parkingTime+"', '"+amount+"')");
    sqlQuery->exec();
    sqlQuery->prepare("select * from Parking");
    sqlQuery->exec();
    mod->getModel()->setQuery(*sqlQuery);
    return mod->getModel();
}

QSqlQueryModel* SqliteDB::commit(QString place, QString license, QString type,
                                 QString startTime, QString parkingTime, QString amount){
    sqlQuery->prepare("update parking set place = '"+place+"' , license_number = '"+license+"' ,"
                        " type = '"+type+"' , time_of_coming = '"+startTime+"' ,"
                         " parking = '"+parkingTime+"' , amount = '"+amount+"' where license_number = '"+license+"'");
    sqlQuery->exec();
    sqlQuery->prepare("select * from Parking");
    sqlQuery->exec();
    mod->getModel()->setQuery(*sqlQuery);
    return mod->getModel();
}

QSqlQueryModel* SqliteDB::show(){
    dataBase.open();
    sqlQuery->prepare("select * from Parking");
    sqlQuery->exec();
    mod->getModel()->setQuery(*sqlQuery);
    return mod->getModel();
}

QSqlQueryModel* SqliteDB::del(QString place, QString license, QString type,
                              QString startTime, QString parkingTime, QString amount){
    sqlQuery->prepare("delete  from Parking where place = '"+place+"' and license_number = '"+license+"'"
                        "and type = '"+type+"' and time_of_coming = '"+startTime+"' and parking = '"+parkingTime+"'"
                        "and amount = '"+amount+"'");
    sqlQuery->exec();
    sqlQuery->prepare("select * from Parking");
    sqlQuery->exec();
    mod->getModel()->setQuery(*sqlQuery);
    return mod->getModel();
}

QSqlQueryModel* SqliteDB::delAll(){
    sqlQuery->prepare("delete  from Parking");
    sqlQuery->exec();
    sqlQuery->prepare("select * from Parking");
    sqlQuery->exec();
    mod->getModel()->setQuery(*sqlQuery);
    return mod->getModel();
}

QSqlQueryModel* SqliteDB::add(QString place, QString license, QString type,
                              QString startTime, QString parkingTime, QString amount){
    sqlQuery->prepare("insert into Parking (place, license_number, type,"
                      " time_of_coming, parking, amount) values('"+place+"' ,"
                               " '"+license+"' , '"+type+"' , '"+startTime+"' , "
                          "'"+parkingTime+"', '"+amount+"')");
    sqlQuery->exec();
    sqlQuery->prepare("select * from Parking");
    sqlQuery->exec();
    mod->getModel()->setQuery(*sqlQuery);
    return mod->getModel();
}

QSqlQueryModel* SqliteDB::getModel(){
    return mod->getModel();
}
