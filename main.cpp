#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "memomodel.h"

static QObject *memoModelProvider(QQmlEngine*, QJSEngine*)
{
    MemoModel *model = new MemoModel();
    return model;
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    app.setOrganizationName("Sebbia");
    app.setOrganizationDomain("www.sebbia.com");
    app.setApplicationName("24 years");
    app.setApplicationVersion("1.0");

    MemoModel::initDb();

    qmlRegisterSingletonType<MemoModel>("com.sebbia.memomodel", 1, 0, "MemoModel", memoModelProvider);

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
