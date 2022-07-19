#include "DB.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "qjsonvalue.h"
#include "QJsonArray"
#include <QNetworkRequest>
#include <QDebug>
#include <QUrlQuery>


//DBHandle::DBHandle(){}

DB::DB(QObject *parent)
    : QObject(parent)
{
    qDebug() << "hello";
    m_networkManager = new QNetworkAccessManager(this);

    //m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("https://demodb-abddc-default-rtdb.asia-southeast1.firebasedatabase.app/Staff.json")));
    //connect(m_networkReply, &QNetworkReply::readyRead, this, &DBHandle::netWorkReplyReadyRead);

    //auto status = connect(m_networkManager, &QNetworkAccessManager::finished, this, &DBHandle::ReplyFinished);
    //qDebug() << "Connection status:" << status;
    //m_networkManager->get(QNetworkRequest(QUrl("https://appsalesphone.000webhostapp.com/getdata.php")));

    //    QUrl url("https://appsalesphone.000webhostapp.com/update.php");
    //    QNetworkRequest request(url);

    //    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    //    QUrlQuery params;
    //    params.addQueryItem("nID", "13");
    //    params.addQueryItem("nUSER", "13");
    //    params.addQueryItem("nPASSWORD", "13");
    //    params.addQueryItem("nMAIL", "13");
    //    params.addQueryItem("nPHONE", "13");
    //    params.addQueryItem("nADDRESS", "13");
    //    // etc

    //    connect(m_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));

    //    m_networkManager->post(request, params.query().toUtf8());

    connect(m_networkManager, &QNetworkAccessManager::finished, this, &DB::ReplyFinished);
    m_networkManager->get(QNetworkRequest(QUrl("http://localhost/db/api/question/read.php")));
}

DB::~DB(){
    m_networkManager->deleteLater();
}

void DB::hello()
{
    connect(m_networkManager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply){

    QByteArray result = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(result);
    QJsonObject obj = jsonResponse.object();
    QJsonArray array = obj.value("data").toArray();
    qDebug() << array.count();

    for(const QJsonValue & value : array) {
        qDebug()<< "Thumbnail: " <<value.toObject().value("thumbnail").toString();
    }
    QJsonValue value = array[0];
    str = value.toObject().value("thumbnail").toString();
     qDebug() << str;
    });
    m_networkManager->get(QNetworkRequest(QUrl("http://localhost/db/api/question/read.php")));

//    return "Duc" ;
}

const QString &DB::getStr() const
{
    return str;
}

void DB::netWorkReplyReadyRead()
{
    qDebug() << "11111";
    qDebug() << m_networkReply->readAll();
}

void DB::ReplyFinished(QNetworkReply *reply) {
    QByteArray result = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(result);
    QJsonObject obj = jsonResponse.object();
    QJsonArray array = obj.value("data").toArray();
    qDebug() << array.count();

    for(const QJsonValue & value : array) {
        qDebug()<< "Thumbnail: " <<value.toObject().value("thumbnail").toString();
    }
    QJsonValue value = array[0];

}
