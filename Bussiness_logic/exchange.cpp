#include "exchange.h"

Exchange::Exchange(QWidget *parent) :
    QObject(parent)
{
    pManager = std::make_unique<QNetworkAccessManager>(this);


}
double Exchange::exchange(int const & arg)
{
   if(arg == 1) {url = "https://www.nbrb.by/api/exrates/rates/145";}
   else if(arg == 2) {url = "https://www.nbrb.by/api/exrates/rates/145";}
   else if(arg == 3) {url = "https://www.nbrb.by/api/exrates/rates/292";}
   else if(arg == 4) {url = "https://www.nbrb.by/api/exrates/rates/298";}
   QNetworkRequest request(url);
   QNetworkReply* reply =  pManager->get(request);
   QEventLoop loop;
   connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
   loop.exec();
   if (reply->error() == QNetworkReply::NoError)
   {
     QByteArray content= reply->readAll();
     QTextCodec *codec = QTextCodec::codecForName("utf8");
     rate = codec->toUnicode(content.data());
     int x = rate.length();
     rate.remove(0,x-7);
     rate.remove(6,6);
   }
   else
   {
     rate = reply->errorString();
   }
   reply->deleteLater();
   return rate.toDouble();
}


Exchange::~Exchange()
{
    delete this;
}

