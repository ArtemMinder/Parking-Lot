#include "parkinglot.h"
#include "ui_parkinglot.h"

ParkingLot::ParkingLot(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ParkingLot)
{
    ui->setupUi(this);
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("my_db.sqlite");
    if (!dbase.open()) {
        qDebug() << "Что-то не так с соединением!";
    }
    QWidget::showMaximized();
    QStandardItemModel *model = new QStandardItemModel;
        QStandardItem *item;

        //Заголовки столбцов
        QStringList horizontalHeader;
        horizontalHeader.append("Номер места");
        horizontalHeader.append("Номер транспортного средства");
        horizontalHeader.append("Тип транспортного средства");
        horizontalHeader.append("Время");
        horizontalHeader.append("Стоимость услуг");
        horizontalHeader.append("Оплачено");

        //Заголовки строк
        QStringList verticalHeader;
        QString numberOfString;
        for(int i = 1;i <= 122;i++){
        numberOfString = QString::number(i);
        verticalHeader.append(numberOfString);
        }

        model->setHorizontalHeaderLabels(horizontalHeader);
        model->setVerticalHeaderLabels(verticalHeader);

        //Первый ряд
        item = new QStandardItem(QString("0"));
        model->setItem(0, 0, item);

        item = new QStandardItem(QString("1"));
        model->setItem(0, 1, item);

        item = new QStandardItem(QString("2"));
        model->setItem(0, 2, item);

        item = new QStandardItem(QString("3"));
        model->setItem(0, 3, item);

        //Второй ряд
        item = new QStandardItem(QString("4"));
        model->setItem(1, 0, item);

        item = new QStandardItem(QString("5"));
        model->setItem(1, 1, item);

        item = new QStandardItem(QString("6"));
        model->setItem(1, 2, item);

        item = new QStandardItem(QString("7"));
        model->setItem(1, 3, item);

        ui->tableView->setModel(model);

                ui->tableView->resizeRowsToContents();
                ui->tableView->resizeColumnsToContents();
}

void ParkingLot::setAddress(std::string const& newAddress) {
    address = newAddress;
}

std::string ParkingLot::getAddress()const {
    return address;;
}

void ParkingLot::isFull(bool const& full) {
    isUnavailable = full;
}

bool ParkingLot::getStatus()const {
    return isUnavailable;
}

ParkingLot::~ParkingLot()
{
    delete ui;
}



