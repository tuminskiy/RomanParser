#include <QApplication>

#include "converter/mainwindow.hpp"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  rp::MainWindow w;
  w.show();
  
  return a.exec();
}
