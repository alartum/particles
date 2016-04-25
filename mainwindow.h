#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

class MainWindow : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent = 0);
    ~MainWindow();
    void show();
    void start();
    QGraphicsView view;
private:
    QTimer timer;
    static const int UPDATE_FREQUENCY = 33;
private slots:
    void stop();
};

#endif // MAINWINDOW_H
