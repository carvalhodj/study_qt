#include <QDateTime>
#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow (parent) {
    setWindowTitle("Locate Window");
    currentDateTimeLabel = new QLabel("Current date and time");
    currentDateTimeLabel->setAlignment(Qt::AlignCenter);
    setCentralWidget(currentDateTimeLabel);
    startTimer(1000);
}

void MainWindow::timerEvent(QTimerEvent *event) {
    Q_UNUSED(event);
    QString dateTime = QDateTime::currentDateTime().toString();
    currentDateTimeLabel->setText(dateTime);
}

void MainWindow::moveEvent(QMoveEvent *event) {
    int xCord = event->pos().x();
    int yCord = event->pos().y();
    QString text = QString::number(xCord) + ", "\
                   + QString::number(yCord);
    statusBar()->showMessage(text);
}