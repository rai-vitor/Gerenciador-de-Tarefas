#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>

//Nossos Includes
#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

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
    listaItem << new QStandardItem("fire");
    listaItem << new QStandardItem("Parado");
    listaItem << new QStandardItem("1234");
    listaItem << new QStandardItem("20");
    listaItem << new QStandardItem("Ivanovitch");
    listaItem << new QStandardItem("5");
    listaItem << new QStandardItem("2345");

    model->appendRow(listaItem);
    listaItem.clear();

    listaItem << new QStandardItem("word");
    listaItem << new QStandardItem("Executando");
    listaItem << new QStandardItem("345");
    listaItem << new QStandardItem("1");
    listaItem << new QStandardItem("IMD");
    listaItem << new QStandardItem("6");
    listaItem << new QStandardItem("12345");

    model->appendRow(listaItem);

    ui->tableView->setModel(model);
    ui->tableView->setShowGrid(false);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(4, Qt::AscendingOrder);

/* ----------------------------------------------------------------------------------------------------------- */

/********************************************** Sistema ********************************************************/

    string linha;
    QStringList list;
    QString qstr, qstr1;

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
    char buff[256];
    //FILE *kernel = popen("uname -r","r");
    //FILE *Name = popen("cat /etc/*-release | grep 'PRETTY_NAME'", "r");

    ifstream kernel;
    system("uname -r > kernel.txt");
    kernel.open("kernel.txt");
    if(kernel.is_open()) {
        getline(kernel, linha);
        qstr = QString::fromStdString(linha);
        ui->label_8->setText("Nome do Computador: " + qstr);
        kernel.close();
    }

    ifstream name;
    system("cat /etc/*-release | grep 'PRETTY_NAME' > name.txt");
    name.open("name.txt");
    if(name.is_open()) {
        getline(name, linha);
        qstr = QString::fromStdString(linha);
        list = qstr.split("=");
        qstr = list[1];
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

     //FILE *memram = popen("cat /proc/meminfo | grep 'MemTotal'","r");
     //FILE *memswap = popen("cat /proc/meminfo | grep 'MemTotal'","r");

    double val;

    ifstream memram;
    system("cat /proc/meminfo | grep 'MemTotal' > memram.txt");
    memram.open("memram.txt");

    ifstream memswap;
    system("cat /proc/meminfo | grep 'SwapTotal' > memswap.txt");
    memswap.open("memswap.txt");

    string str;

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

     //Processadores


     graph = new Graph();
     connect(graph,SIGNAL(updateGUI(int)),SLOT(updateInterface(int)));
    // graph->run();
     //pclose(proc); // Não sei se devo fechar pq a thread vai ficar lendo o tempo todo

     /*****************************************************************/
     // Processos

     FILE *ListaProcessos = popen("ps aux","r");

     qstr = " ";
     list.clear();
     while ( fgets( buff, 256, ListaProcessos ) != NULL ) {
         list.push_back(buff); // Cada linha tem um processo
     }
     cout<<endl;

    QStringList processo; // Cada linha tem 1 proccesso do 'ps aux'
    QVector<int> pid; //No final deste for, essa variavel terá todos os PID dos processos
    for(int j = 0; j<list.size(); j++){
        processo = list[j].split(" ");
        int cont = 0;
        for(int i = 0; i<processo.size(); i++){
            if(processo[i].toStdString().length() != 0){ // Testo para saber se o valor é diferente de expaço
                cont++;
                if(cont == 2){// cont 1 = USER, cont 2 = PID
                    if(processo[i].toInt()>0){
                        pid.push_back(processo[i].toInt());
                    }
                    break;
                }
            }
        }
    }


 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInterface(int porcent){
    ui->progressBar_1->setValue(porcent);
    //cout<<porcent<<endl;
}

void MainWindow::on_pushButton_clicked()
{
    graph->run();
}
