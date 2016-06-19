#include "barrier.h"

Barrier::Barrier(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(w,h);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);

    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/2.0f,h/2.0f);
//    g_body->CreateFixture(&bodyBox,9.0f);

//    b2CircleShape bodyshape;
//    bodyshape.m_radius = w;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyBox;
    fixturedef.density = BARRIER_DENSITY;
    fixturedef.friction = BARRIER_FRICTION;
    fixturedef.restitution = BARRIER_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->SetLinearVelocity(b2Vec2(0,0));
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
    paint();

}

//void Barrier::setLinearVelocity(b2Vec2 velocity)
//{
//    g_body->SetLinearVelocity(velocity);
//}
