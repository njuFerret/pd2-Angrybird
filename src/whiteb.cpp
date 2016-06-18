#include "whiteb.h"

whiteb::whiteb(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x, y,radius,timer,pixmap,world,scene)
{}

int whiteb::special(){return 2;}
