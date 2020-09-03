#ifndef MODEL_H
#define MODEL_H

#include <QSqlQueryModel>

class model
{
public:
    model(){mod = new QSqlQueryModel();};
    QSqlQueryModel* getModel(){
        return mod;
    }
private:
    QSqlQueryModel *mod;
};

#endif // MODEL_H
