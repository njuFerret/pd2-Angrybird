#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  qSetMessagePattern("[%{file}:%{line}] %{message}");
  int tmp = 0;
  //    do{
  QApplication a(argc, argv);
  do {
    MainWindow w;
    w.show();
    tmp = a.exec();
  } while (tmp == MainWindow::Exit);

  //    return a.exec();
  return tmp;
}
