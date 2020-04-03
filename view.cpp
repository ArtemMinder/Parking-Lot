#include "view.h"
#include "ui_view.h"
#include <QLabel>

View::View(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    QPixmap background(":/images/images/Parking Floor HD.png");
    QPixmap isNotFree(":/images/images/isNotFree.png");
    QPixmap online(":/images/images/Online.png");
    ui->Electric1->setPixmap(isNotFree);
    std::vector<QLabel*> Electric = {ui->Electric1,ui->Electric2};
    Electric[0]->setPixmap(isNotFree);
    Electric[1]->setPixmap(online);
    QWidget::showMaximized();
    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("my_db.sqlite");
    if (!dbase.open()) {
        qDebug() << "Что-то не так с соединением!";
    }
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

View::~View()
{
    delete ui;
}
