#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow (parent) {
    setWindowTitle("Locate Window with timer");
    mainWidget = new QWidget();
    label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    layout = new QHBoxLayout;
    layout->addWidget(label);
    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);
}

void MainWindow::moveEvent(QMoveEvent *event) {
    int xCord = event->pos().x();
    int yCord = event->pos().y();
    QString text = QString::number(xCord) + ", "\
                   + QString::number(yCord);
    statusBar()->showMessage(text);
}