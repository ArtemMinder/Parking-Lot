#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <QEventLoop>
#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QUrl>
#include "IExchange.h"


class Exchange : public QObject, public IExchange
{
    Q_OBJECT
public:
    Exchange(QWidget *parent = nullptr);
    double exchange(int const& arg)override;
    ~Exchange();
private:
    QUrl url ={};
    QString rate = {};
    std::unique_ptr<QNetworkAccessManager> pManager;
};

#endif // EXCHANGE_H
