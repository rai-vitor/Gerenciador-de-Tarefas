#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>

//Nossos Includes

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
    listaItem << new QStandardItem("firefox");
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

    /* ------------------------------------------------------------------------- */

    //Sistema

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
    FILE *kernel = popen("uname -r","r");
    FILE *Name = popen("cat /etc/*-release | grep 'PRETTY_NAME'", "r");

    while ( fgets( buff, 256, kernel ) != NULL ) {
      cout << "Kernel Version: " << buff << endl;
    }

    qstr = QString::fromStdString(buff);
    ui->label_8->setText("Versão do Kernel: " + qstr);

    while ( fgets( buff, 256, Name ) != NULL ) {
    //  cout << buff << endl;
    }

    //Dividindo a string do nome do sistema

    qstr = " ";
    qstr = QString::fromStdString(buff);
    list = qstr.split("=");
    qstr = list[1];

   // cout << list[0] << endl;
    ui->label_11->setText("Sistema Operacional: " + qstr);

    pclose(kernel);
    pclose(Name);

    /* ------------------------------------------------------------------------- */

    //CPU model name


    FILE *cpu = popen("cat /proc/cpuinfo | grep -m 1 'model name'","r");
    FILE *cores = popen("cat /proc/cpuinfo | grep processor | wc -l","r");

    while ( fgets( buff, 256, cpu ) != NULL ) {
     // cout << buff << endl;
    }

    //Dividindo a string do nome do sistema

    qstr = " ";
    qstr = QString::fromStdString(buff);
    list = qstr.split(":");
    qstr = list[1];
    list = qstr.split(" ");
    qstr1 = list[list.size()-1];

    //string t = qstr1;

   // float a = qstr1.toFloat();
    //cout<<"Aque: "<<t.substr(0, strlen(pch)-3)<<endl;
    //float a = std::stof (t.substr(0, strlen(t)-3)) ; // Converti pra float
    cout<<"Aqui: ";
    qstr1 = qstr1.remove(-4,3);

    float procTotal = qstr1.toFloat();
    cout<<procTotal;

    //Quantidade de Cores

    while ( fgets( buff, 256, cores ) != NULL ) {
     // cout << buff << endl;
    }



    qstr1 = QString::fromStdString(buff);

    ui->label_12->setText(qstr + "x" + qstr1);

    pclose(cpu);
    pclose(cores);

 /* ------------------------------------------------------------------------- */

     //Memória

     FILE *memram = popen("cat /proc/meminfo | grep 'MemTotal'","r");
     FILE *memswap = popen("cat /proc/meminfo | grep 'MemTotal'","r");

     while ( fgets( buff, 256, memram ) != NULL ) {
       //cout << buff << endl;
     }

     qstr = " ";
     qstr = QString::fromStdString(buff);
     list = qstr.split(":");
     qstr = list[1];
     list = qstr.split(" ");
     qstr = list[0];

     ui->label_13->setText(qstr);

     pclose(memram);
     pclose(memswap);

     /***************************************************************************/
     while(true){

     }
     //Processadores
     FILE *proc = popen("cat /proc/cpuinfo | grep 'MHz'","r");

     qstr = " ";
     list.clear();
     while ( fgets( buff, 256, memram ) != NULL ) {
         list.push_back(buff); // Cada linha tem um processador
     }

     float proc1 = 0;
     float proc2 = 0;
     float proc3 = 0;
     float proc4 = 0;

     QStringList processadores;
     for(int i = 0; i<list.size(); i++){
         qstr = list[i];
         processadores = qstr.split(" ");
         qstr = processadores[2];
         if(i == 0) proc1 = qstr.toFloat();
         if(i == 1) proc2 = qstr.toFloat();
         if(i == 2) proc3 = qstr.toFloat();
         if(i == 3) proc4 = qstr.toFloat();
     }


     procTotal = procTotal * 10000.0;
     cout<<"Proc 1:"<<(proc1*100)/procTotal<<endl;
     ui->progressBar_1->setValue((proc1*100)/procTotal);
     ui->progressBar_2->setValue((proc2*100)/procTotal);
     ui->progressBar_3->setValue((proc3*100)/procTotal);
     ui->progressBar_4->setValue((proc4*100)/procTotal);
 }

MainWindow::~MainWindow()
{
    delete ui;
}
