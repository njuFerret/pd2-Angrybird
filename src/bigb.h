#ifndef BIGB_H
#define BIGB_H

#include "bird.h"

class bigb: public Bird{
public:
    bigb(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual int special();
};

#endif // BIGB_H
