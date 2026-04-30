#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "vtkquickitem.h"

int main(int argc, char *argv[])
{
//    // Set OpenGL requirements for VTK
//    QSurfaceFormat format;
//    format.setRenderableType(QSurfaceFormat::OpenGL);
//    format.setProfile(QSurfaceFormat::CoreProfile);
//    format.setVersion(3, 2);
//    format.setSamples(0);  // Disable multisampling for VTK compatibility
//    QSurfaceFormat::setDefaultFormat(format);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // Register VTKQuickItem as a QML type
    qmlRegisterType<VTKQuickItem>("VTK3D", 1, 0, "VTKQuickItem");

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
