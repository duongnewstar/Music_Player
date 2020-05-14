#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "resourceimageprovider.h"
#include "playercontroller.h"
#include "screencontroller.h"
#include "screenmodel.h"
#include "appdefines.h"
#include "appengine.h"
#include "qmltranslator.h"

int main(int argc, char *argv[]){
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
   // ImageProvider
    QQmlApplicationEngine engine;
    engine.addImageProvider(QLatin1String("ImageProvider"), new ResourceImageProvider(QQuickImageProvider::Image));
    const QUrl url(QStringLiteral("qrc:/main.qml"));
   // Controller
    Playercontroller objA;
    engine.rootContext()->setContextProperty("Controller", &objA);
   // SongModel
    SongModel model;
    QObject::connect(&objA,SIGNAL(list_music1(QString)),&model,SLOT(list_music(QString)));
    engine.rootContext()->setContextProperty("SongModel",&model);
    // FilterModel
    FilterProxyModel filterModel;
    filterModel.setSourceModel(&model);
    filterModel.setFilterRole(name);
    filterModel.setSortRole(name);
    engine.rootContext()->setContextProperty("filterModel", &filterModel);
    //Tranlate
    Qmltranslator qmltranslator;
    engine.rootContext()->setContextProperty("QmlTranslator", &qmltranslator);
    // appEnums
    qmlRegisterType<AppEnums>("AppEnums", 1, 0, "AppEnums");
    ScreenController::getInstance();
    ScreenController::getInstance()->initialize(engine.rootContext());
    ScreenController::getInstance()->initializeScreen(&engine);
    return app.exec();
}
