#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QObject>

class button :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void clicked();
};

#endif // BUTTON_H
