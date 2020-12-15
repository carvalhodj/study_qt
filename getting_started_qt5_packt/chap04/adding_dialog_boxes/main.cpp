#include <QApplication>
#include "mainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}