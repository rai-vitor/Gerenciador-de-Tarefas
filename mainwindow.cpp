#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>

//Nossos Includes
#include "graph.h"
#include "proc.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <QDir>

using namespace std;

string kill_process;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel();
    QStringList headers;
    headers << tr("Nome") << tr("Status") << tr("PID") << tr("PPID") << tr("Usuário") << tr("Threads") << tr("Trocas de Contexto");
    model->setHorizontalHeaderLabels(headers);


    // model->setHorizontalHeaderItem( 0, new QStandardItem( "Nome" ) );
    // model->setHorizontalHeaderItem( 1, new QStandardItem( "Status" ) );
    // model->setHorizontalHeaderItem( 2, new QStandardItem( "PID" ) );


    QList<QStandardItem *> listaItem;
    QStringList list, list_proc, list0;
    QString qstr, qstr1, qstr_nome, qstr_pid, qstr_ppid, qstr_state, qstr_user, qstr_thread, qstr_cnt, display, nome_sistema;
    string linha, str, path, _system, username;
    const char * c ;
    int count = 0, count_thread = 0;

    proc1 = new proc();
    connect(proc1, SIGNAL(updateTable1(QStandardItemModel*)), SLOT(updateTable(QStandardItemModel*)));
    proc1->start();
   /*

    listaItem << new QStandardItem("word");
    listaItem << new QStandardItem("Executando");
    listaItem << new QStandardItem("345");
    listaItem << new QStandardItem("1");
    listaItem << new QStandardItem("IMD");
    listaItem << new QStandardItem("6");
    listaItem << new QStandardItem("12345");

    model->appendRow(listaItem);
*/


/* ----------------------------------------------------------------------------------------------------------- */

/********************************************** Sistema ********************************************************/



    //Nome do Computador
    ifstream hostname;
    hostname.open("/etc/hostname");
    if(hostname.is_open()) {
        getline(hostname, linha);
        qstr = QString::fromStdString(linha);
        ui->label_7->setText("Nome do Computador: " + qstr);
        hostname.close();
    }
    else {
    //    cout << "Não foi possível abrir o arquivo" << endl;
    }

    /* ------------------------------------------------------------------------- */

    //Informações do SO: Nome e Kernel

    ifstream kernel;
    system("uname -r > kernel.txt");
    kernel.open("kernel.txt");
    if(kernel.is_open()) {
        getline(kernel, linha);
        qstr = QString::fromStdString(linha);
        ui->label_8->setText("Versão do Kernel: " + qstr);
        kernel.close();
    }

    ifstream name;
    system("cat /etc/*-release | grep 'PRETTY_NAME' > name.txt");
    name.open("name.txt");
    if(name.is_open()) {
        getline(name, linha);
        qstr = QString::fromStdString(linha);
        qstr = qstr.remove("\"");
        list = qstr.split("=");
        qstr = list[1];
        nome_sistema = qstr;
        ui->label_11->setText("Sistema Operacional: " + qstr);
        name.close();
    }


    /* ------------------------------------------------------------------------- */

    //CPU


    ifstream cpu;
    system("cat /proc/cpuinfo | grep -m 1 'model name' > cpu.txt");
    cpu.open("cpu.txt");

    ifstream cores;
    system("cat /proc/cpuinfo | grep processor | wc -l > cores.txt");
    cores.open("cores.txt");

    if(cpu.is_open()) {
        getline(cpu, linha);
        qstr = QString::fromStdString(linha);
        list = qstr.split(":");
        qstr = list[1];
        //list = qstr.split(" ");
        //qstr = list[0];
        cpu.close();
    }

    if(cores.is_open()) {
        getline(cores, linha);
        qstr1 = QString::fromStdString(linha);
        cores.close();
    }

    //float procTotal = qstr1.toFloat();

    ui->label_12->setText("Processador: " + qstr1 + "x " + qstr);



 /* ------------------------------------------------------------------------- */

     //Memória

    double val;

    ifstream memram;
    system("cat /proc/meminfo | grep 'MemTotal' > memram.txt");
    memram.open("memram.txt");

    ifstream memswap;
    system("cat /proc/meminfo | grep 'SwapTotal' > memswap.txt");
    memswap.open("memswap.txt");

     if(memram.is_open()) {
         getline(memram, linha);
         qstr = QString::fromStdString(linha);
         list = qstr.split(":");
         qstr = list[1];
         list = qstr.split(" ");
         qstr = list[8];
         val = qstr.toDouble();
         val /= 1000000;
         val = floorf(val*100)/100;
         qstr = QString::number(val);
         memram.close();
         ui->label_13->setText("Memória Primária: " + qstr + "GB");
     }

     if(memswap.is_open()) {
         getline(memswap, linha);
         qstr = QString::fromStdString(linha);
         list = qstr.split(":");
         qstr = list[1];
         list = qstr.split(" ");
         qstr = list[7];
         val = qstr.toDouble();
         val /= 1000000;
         val = floorf(val*100)/100;
         qstr = QString::number(val);
         memswap.close();
         ui->label_14->setText("Memória Secundária: " + qstr + "GB");
     }

/* ----------------------------------------------------------------------------------------------------------- */

     //logo

        QString match = "Ubuntu", match1 = "ubuntu";
        bool test1 = nome_sistema.contains(match);
        bool test2 = nome_sistema.contains(match1);
        if(test1 || test2) {
            ui ->label_6->setPixmap(QPixmap("logos/ubuntu.png", 0, Qt::AutoColor));
        }

/* ----------------------------------------------------------------------------------------------------------- */

     //Processadores

     qRegisterMetaType<QVector<float> >("QVector<float>");
     graph = new Graph();
     connect(graph,SIGNAL(updateGUI(QVector<float>)),SLOT(updateInterface(QVector<float>)));
     graph->start();
 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInterface(QVector<float> processadores){
    ui->progressBar_1->setValue(processadores[0]);
    ui->progressBar_2->setValue(processadores[1]);
    ui->progressBar_3->setValue(processadores[2]);
    ui->progressBar_4->setValue(processadores[3]);
}

void MainWindow::updateTable(QStandardItemModel *model){
    ui->tableView->setModel(model);
    ui->tableView->setShowGrid(false);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(4, Qt::AscendingOrder);
}

void MainWindow::on_pushButton_clicked()
{
    kill_process = "kill -9 " + kill_process;
    const char * command = kill_process.c_str();
    //cout << command << endl;
    system(command);
}

//Obtém valores do tableView

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    //cout << index.row() << endl;
    QString valor = ui->tableView->model()->data(index).toString();
    kill_process = valor.toStdString();
    cout << kill_process << endl;
}
