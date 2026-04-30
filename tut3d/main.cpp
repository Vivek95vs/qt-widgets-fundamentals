#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "VtkWidgetContainer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    VtkWidgetContainer vtkContainer;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("vtkContainer", &vtkContainer);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
