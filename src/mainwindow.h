#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QList>
#include <QMainWindow>
// #include <QDesktopWidget>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <QTimer>
// #include <iostream>
#include <button.h>
// #include <iostream>

#include <barrier.h>
#include <bigb.h>
#include <bird.h>
#include <egg.h>
#include <enemy.h>
#include <gameitem.h>
#include <land.h>
#include <whiteb.h>
#include <yellowb.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void showEvent(QShowEvent *);
  bool eventFilter(QObject *, QEvent *event);
  void closeEvent(QCloseEvent *);
  //    void deleteBird();
  static int const Exit;

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
  Bird *birdie;
  Enemy *enemy;
  egg *eggs;
  int cnt, k, tmp;
};

#endif        // MAINWINDOW_H
