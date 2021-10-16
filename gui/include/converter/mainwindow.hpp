#pragma once

#include <QMainWindow>

#include "ui_mainwindow.h"

namespace rp {

class MainWindow : public QMainWindow {
Q_OBJECT

  Ui::MainWindow ui_;

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void convert_clicked();
};

} // namespace rp
