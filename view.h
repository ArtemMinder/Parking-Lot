#ifndef VIEW_H
#define VIEW_H

#include <QDialog>
#include <QLabel>
#include "Types.h"
#include <QtSql>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "acc.h"

namespace Ui {
class View;
}

class View : public QDialog
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    bool showInfo(std::string const& newLogin, std::string const& newPassword);
    void busy(int const& newPlase, Types::VehicleType const& newType);
    void free(int const& newPlase, Types::VehicleType const& newType);
    void loadInfo(int const& newPlase, std::string const& newLicense, Types::VehicleType const& newType,
                  std::string const& newStartTime, double const& newAmount, int const& newParkingTime);
    void checkStatus();
    ~View();
private slots:
    void on_pushButton_clicked();

    void on_exitButton_clicked();

    void on_delete_all_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_closeEditButton_clicked();

    void on_commitButton_clicked();

    void on_add_clicked();

    void on_addButton_clicked();

    void on_deleteNoteButton_clicked();

    void on_deleteButton_clicked();

private:
    QSqlDatabase dataBase;
    QSqlQuery *sqlQuery;
    QSqlQueryModel *model;
    Ui::View *ui;
    Acc *acc;
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
    double employeeCost = 0.04;
    double electricCost = 0.12;
    double loot = 0;
    double cost = 0;
    double profit = 0;
};

#endif // VIEW_H
