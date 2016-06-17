#ifndef ENEMY_H
#define ENEMY_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define ENEMY_DENSITY 8.0f
#define ENEMY_FRICTION 0.4f
#define ENEMY_RESTITUTION 0.3f

class Enemy : public GameItem
{
public:
    Enemy(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // ENEMY_H
