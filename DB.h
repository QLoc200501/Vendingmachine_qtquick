#ifndef DB_H
#define DB_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
class DB : public QObject
{
    Q_OBJECT
public:
    //DBHandle();
    explicit DB(QObject *parent = nullptr);
    ~DB();
    Q_INVOKABLE QString str;
    Q_INVOKABLE void hello();
    const QString &getStr() const;

private:
    QNetworkAccessManager * m_networkManager;
    QNetworkReply * m_networkReply;

public slots:
    void netWorkReplyReadyRead();
    void ReplyFinished(QNetworkReply *reply);

};

#endif // DB_H
