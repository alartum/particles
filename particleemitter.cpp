#include "particleemitter.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QPointF>
#include <QDebug>

ParticleEmitter::ParticleEmitter(int spawnPeriod, QColor color, double size, QPointF speed, double acceleration, int maxAge, QGraphicsItem * parent) :
    QGraphicsItem (parent), mSpawnPeriod (spawnPeriod), mParticleSize (size), mMaxAge (maxAge),
    mParticleColor (color), mParticleSpeed (speed), mParticleAcceleration (acceleration)
{
    mSpawningTimer.start(mSpawnPeriod);
    connect(&mSpawningTimer, SIGNAL(timeout()), this, SLOT(spawnParticle()));
}
QRectF ParticleEmitter::boundingRect() const
{
    qreal adjust = 3;
    return QRectF(- adjust - 2, - adjust - 2,
        2 + adjust, 2 + adjust);
}

void ParticleEmitter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
//   painter->setBrush(Qt::darkGreen);
//   painter->drawEllipse(boundingRect());
}

void ParticleEmitter::spawnParticle()
{
    double y = (2 * (double) qrand() / (RAND_MAX) - 1) * mParticleSpeed.y(),
           x = (2 * (double) qrand() / (RAND_MAX) - 1) * mParticleSpeed.x();
    QPointF speed (x, y);
//    qDebug()<<speed;
    Particle *particle = new Particle (speed, mParticleColor, mParticleSize, mParticleAcceleration, mMaxAge);
    particle->setParentItem(this);
    particle->setPos(mParticleSize/4, mParticleSize/4);
}

