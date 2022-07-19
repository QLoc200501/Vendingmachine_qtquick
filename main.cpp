#include <QGuiApplication>
#include <QQmlApplicationEngine>
// add begin
#include "QNetworkAccessManager"
#include "QNetworkReply"
#include "QNetworkRequest"
#include "QJsonObject"
#include "QJsonDocument"
#include <QQmlContext>
#include "DB.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    DB db;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("DB",&db);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    DB temp;
    return app.exec();
}
