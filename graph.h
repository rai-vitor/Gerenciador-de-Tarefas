#include "thread.h"
#include <iostream>
#include <QMainWindow>
#include "ui_mainwindow.h"


class Graph : public Thread{

public:
    Ui::MainWindow *ui;
    void run(){
        //ui->progressBar_5->setValue(80); Aqui onde ta o erro
        std::cout<<"Teste";
    }
};
