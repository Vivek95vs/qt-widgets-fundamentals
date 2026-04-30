#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "vtkqmlitem.h"
#include <QSurfaceFormat>

#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2)
VTK_MODULE_INIT(vtkRenderingFreeType)

int main(int argc, char *argv[])
{
    // ✅ REQUIRED FOR VTK 8.2
//    qputenv("QT_LOGGING_RULES", "qt.scenegraph.general=true");

    QSurfaceFormat fmt;
    fmt.setRenderableType(QSurfaceFormat::OpenGL);
    fmt.setVersion(3, 3);
    fmt.setProfile(QSurfaceFormat::CompatibilityProfile); // ⚠️ NOT Core
    fmt.setDepthBufferSize(24);
    fmt.setStencilBufferSize(8);
    QSurfaceFormat::setDefaultFormat(fmt);

    QGuiApplication app(argc, argv);

    qmlRegisterType<VTKQmlItem>("VTK", 1, 0, "VTKView");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
