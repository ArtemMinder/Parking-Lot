#ifndef VIEW_H
#define VIEW_H

#include <QDialog>
#include "QStandardItemModel"
#include "QStandardItem"
#include <QtSql>

namespace Ui {
class View;
}

class View : public QDialog
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    ~View();

private:
    Ui::View *ui;
};

#endif // VIEW_H
