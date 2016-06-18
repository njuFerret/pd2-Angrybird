#include "bigb.h"

bigb::bigb(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x, y,radius,timer,pixmap,world,scene){}

int bigb::special(){return 3;}
