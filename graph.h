#include "thread.h"
#include <iostream>
#include "ui_mainwindow.h"
#include <QMainWindow>


class Graph{

public:
    Ui::MainWindow *ui;

    void run(Ui::MainWindow *ui);
};
