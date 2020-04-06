#ifndef VIEW_H
#define VIEW_H

#include <QDialog>
#include <QLabel>
#include "Types.h"

namespace Ui {
class View;
}

class View : public QDialog
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    void busy(int const& newPlase, Types::VehicleType const& newType);
    void free(int const& newPlase, Types::VehicleType const& newType);
    ~View();
private:
    Ui::View *ui;
    std::vector<QLabel*> Compact = {};
    std::vector<QLabel*> Medium = {};
    std::vector<QLabel*> Large = {};
    std::vector<QLabel*> Motorcycle = {};
    std::vector<QLabel*> Electric = {};
    std::vector<QLabel*> Handicapped = {};
    QPixmap background = QPixmap(":/images/images/Parking Floor HD.png");
    QPixmap isNotFree = QPixmap(":/images/images/isNotFree.png");
    QPixmap online = QPixmap(":/images/images/Online.png");

};

#endif // VIEW_H
