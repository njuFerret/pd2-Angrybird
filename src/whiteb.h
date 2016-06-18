#ifndef WHITEB_H
#define WHITEB_H

#include "bird.h"

class whiteb: public Bird{
public:
    whiteb(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual int special();
};

#endif // WHITEB_H
