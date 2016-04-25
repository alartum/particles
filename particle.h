#ifndef PARTICLE_H
#define PARTICLE_H

#include <QGraphicsItem>
#include <QPointF>
#include <QColor>

class Particle : public QGraphicsItem
{
public:
    Particle(QPointF speed = QPointF(3, -2), QColor color = Qt::darkYellow, double size = 10,
             double acceleration = -0.2, int maxAge = 50, QGraphicsItem * parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
protected:
    void advance(int step);
private:
    QPointF mSpeed;
    double mAcceleration;
    double mMaxSize;
    int mMaxAge;
    QColor mColor;
    double mSize;
    int mAge;
};

#endif // PARTICLE_H
