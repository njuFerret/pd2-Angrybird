#include "button.h"


void button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}
