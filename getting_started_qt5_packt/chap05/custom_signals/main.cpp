#include <QApplication>
#include <Qt>
#include "mainWindow.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.resize(400, 400);
    mainWindow.setWindowTitle("Hover events");
    mainWindow.show();

    return app.exec();
}