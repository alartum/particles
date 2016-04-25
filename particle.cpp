#include "particle.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QRectF>
#include <QDebug>

Particle::Particle(QPointF speed, QColor color, double size, double acceleration, int maxAge, QGraphicsItem * parent)
    : QGraphicsItem (parent), mAcceleration (acceleration), mMaxSize (size), mMaxAge (maxAge), mSpeed(speed), mSize(size),
      mColor(color), mAge (0)
{   
}

QRectF Particle::boundingRect() const
{
    qreal adjust = 3;
    return QRectF(- adjust - mSize/2, - adjust - mSize/2,
                  mSize/2 + adjust, mSize/2 + adjust);
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
   if (mAge == 0)
       return;
   QBrush brush (mColor);
   painter->setPen(Qt::NoPen);
   painter->setBrush(brush);
   painter->drawEllipse(boundingRect());
}

void Particle::advance(int step)
{
    if (!step) {
        if (mAge == mMaxAge){
            if (scene())
                scene()->removeItem(this);
            delete this;
        }
    }
    else
    {
        mSpeed.ry() += mAcceleration;
        setPos(pos() + mSpeed);
        mAge ++;
        qreal lifeLength = 1 - (double)mAge / mMaxAge;
        mSize = mMaxSize * lifeLength;
        mColor.setAlpha(120*lifeLength);
    }
}
