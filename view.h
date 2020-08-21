#ifndef VIEW_H
#define VIEW_H

#include <QDialog>
#include <QLabel>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include "Types.h"
#include "parkinglot.h"
#include "acc.h"
#include "exchange.h"
#include "simulation.h"
#include "parkingrate.h"
#include "sqlitedb.h"
#include "Idatabase.h"
#include "CarModel.h"
#include "QStandardItemModel"
#include <memory>

namespace Ui {
class View;
}
class View : public QDialog
{
    Q_OBJECT
public:
    View(QWidget *parent = nullptr, IExchange *exh = nullptr, ParkingLot *new_p_lot = nullptr, Idatabase *newdat = nullptr);
    void simulateTraffic();
    bool showInfo(std::string const& newLogin, std::string const& newPassword);
    void busy(int const& newPlase, Types::VehicleType const& newType);
    void free(int const& newPlase, Types::VehicleType const& newType);
    void loadInfo(int const& newPlase, std::string const& newLicense, Types::VehicleType const& newType,
                  std::string const& newStartTime, double const& newAmount, int const& newParkingTime);
    void checkStatus();
    void transfer();
    ~View();
public slots:
    void coming();
    void depart();
private slots:
    void on_pushButton_clicked();
    void on_exitButton_clicked();
    void on_delete_all_clicked();
    void on_closeEditButton_clicked();
    void on_commitButton_clicked();
    void on_add_clicked();
    void on_addButton_clicked();
    void on_deleteNoteButton_clicked();
    void on_deleteButton_clicked();
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    std::vector<CarModel> cm;
    Idatabase *dat;
    Ui::View *ui;
    Acc *acc;
    Simulation *sim;
    ParkingLot *p_lot;
    IExchange *ex;
    ParkingRate *rate;
    QTimer *add;
    QTimer *del;
    std::vector<QLabel*> Compact = {};
    std::vector<QLabel*> Medium = {};
    std::vector<QLabel*> Large = {};
    std::vector<QLabel*> Motorcycle = {};
    std::vector<QLabel*> Electric = {};
    std::vector<QLabel*> Handicapped = {};
    QPixmap background = QPixmap(":/images/images/Parking Floor HD.png");
    QPixmap isNotFree = QPixmap(":/images/images/isNotFree.png");
    QPixmap online = QPixmap(":/images/images/Online.png");
    std::string startTime = {};
    int noteNumber = -1;
    int maxTime = 0;
    double employeeCost = 0.096;
    double electricCost = 0.29;
    double percent = 0;
    double loot = 0;
    double cost = 0;
    double profit = 0;
    QString exType = {};
    QString exPlace = {};
    QString exMoney = {};
    double rateCoeff = 1;
    QString moneyName = "BYN";
    QStandardItemModel *m;
};

#endif // VIEW_H
