#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include <QTimer>
#include <QGraphicsItem>
#include <QObject>
#include <QPointF>
#include <QColor>
#include "particle.h"

class ParticleEmitter : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    ParticleEmitter(int spawnPeriod = 50, QColor color = Qt::gray, double size = 10,
                    QPointF speed = QPointF (3, 2), double acceleration = -0.3, int maxAge = 50, QGraphicsItem * parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
private:
    int mSpawnPeriod;
    double mParticleSize;
    QTimer mSpawningTimer;
    QColor mParticleColor;
    QPointF mParticleSpeed;
    double mParticleAcceleration;
    int mMaxAge;
public slots:
    void spawnParticle ();
};

#endif // PARTICLEEMITTER_H
