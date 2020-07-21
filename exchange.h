#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QTextCodec>
#include <QEventLoop>


class Exchange : public QObject
{
    Q_OBJECT

public:
    Exchange(QWidget *parent = nullptr);
    ~Exchange();
public slots:
    double exchange(int const& arg);
private:
    QUrl url ={};
    QString rate = {};
    QNetworkAccessManager* manager;
};

#endif // EXCHANGE_H
