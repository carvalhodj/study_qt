#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMoveEvent>
#include <QStatusBar>
#include <QLabel>
#include <QHBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);
    protected:
        void moveEvent(QMoveEvent *event);
    private:
        QWidget *mainWidget;
        QLabel *label;
        QHBoxLayout *layout;
};

#endif