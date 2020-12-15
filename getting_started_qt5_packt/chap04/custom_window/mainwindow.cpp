#include "mainwindow.h"

MainWindow::MainWindow() {
    setWindowTitle("Main Window");
    resize(700, 400);
    QLabel* mainLabel = new QLabel("Main Widget");
    setCentralWidget(mainLabel);
    mainLabel->setAlignment(Qt::AlignHCenter);
}