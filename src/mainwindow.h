#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <button.h>
#include <iostream>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <barrier.h>
#include <enemy.h>
#include <yellowb.h>
#include <whiteb.h>
#include <bigb.h>
#include <egg.h>
//#include "bump.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
//    void deleteBird();

signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void deleteEnemy();
    void tick();
    // For debug slot
    void QUITSLOT();
    void quitslot();
    void restart();
//    void deleteBird();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    QTimer timer2;
    Bird * birdie;
    Bird * bird1;
    Enemy * enemy;
//    QList<Bird *> list;
    egg * eggs;
    int cnt,k;
};

#endif // MAINWINDOW_H
