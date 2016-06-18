#ifndef YELLOWB_H
#define YELLOWB_H

#include "bird.h"

class yellowb: public Bird{
public:
    yellowb(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual int special();
};

#endif // YELLOWB_H
