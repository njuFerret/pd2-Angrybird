#ifndef BARRIER_H
#define BARRIER_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BARRIER_DENSITY 20.0f
#define BARRIER_FRICTION 0.8f
#define BARRIER_RESTITUTION 0.3f

class Barrier : public GameItem
{
public:
    Barrier(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
//    void setLinearVelocity(b2Vec2 velocity);
};

#endif // BARRIER_H
