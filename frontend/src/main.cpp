#include <QApplication>
#include <QQmlEngine>
#include <QQuickView>
#include <QUrl>

#include "FileWatcher.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    const QDir DIRECTORY(QStringLiteral(PROJECT_DIR));

    QQuickView view;

    view.setSource(QUrl("qrc:/QML/StockMarket/frontend/customedModules/Main.qml"));
    view.setWidth(950);
    view.setHeight(700);
    view.show();

    const QUrl SOURCE_URL{QUrl::fromLocalFile(DIRECTORY.filePath("./frontend/customedModules/Main.qml"))};
    FileWatcher watcher([&view, SOURCE_URL]() {
        view.engine()->clearComponentCache();
        view.setSource(SOURCE_URL);
    });

    watcher.set_directory(DIRECTORY.absolutePath());

    return app.exec();
}
