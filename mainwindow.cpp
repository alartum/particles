#include "mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <QTime>
#include "particleemitter.h"
#include "particle.h"

MainWindow::MainWindow(QObject *parent) :
    QGraphicsScene(parent)
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    setSceneRect(-350, -350, 700, 700);
    view.setRenderHint(QPainter::Antialiasing);
    view.setScene(this);
    connect (&timer, SIGNAL(timeout()),
                           this, SLOT(advance()));
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    addRect(-7, 40, 14, 150, QPen(QColor()), QBrush (QColor ("peru")));
//    ParticleEmitter *particleEmitter1 = new ParticleEmitter (9, QColor ("lavender"), 140, QPointF (3.2, 4), -0.8, 35);
//    addItem(particleEmitter1);
//    particleEmitter1->setPos(0, 0);
    ParticleEmitter *particleEmitter2 = new ParticleEmitter (14, QColor ("orangered"), 90, QPointF (2, 1), -0.8, 20);
    addItem(particleEmitter2);
    particleEmitter2->setPos(0, 20);
    ParticleEmitter *particleEmitter1 = new ParticleEmitter (18, QColor ("gold"), 60, QPointF (2, 1.8), -0.7, 15);
    addItem(particleEmitter1);
    particleEmitter1->setPos(0, 25);
    ParticleEmitter *particleEmitter3 = new ParticleEmitter (40, QColor ("skyblue"), 40, QPointF (2, 1.6), -0.6, 12);
    addItem(particleEmitter3);
    particleEmitter3->setPos(0, 30);
}
void MainWindow::show()
{
    view.show();
}
void MainWindow::start()
{
    timer.start(UPDATE_FREQUENCY);
}
void MainWindow::stop()
{
    timer.stop();
}
MainWindow::~MainWindow()
{
}
