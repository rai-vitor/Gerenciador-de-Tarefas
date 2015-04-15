#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>

//Nossos Includes
#include "thread.h"
#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>

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

    qstr1 = qstr1.remove(-4,3);
    float procTotal = qstr1.toFloat();

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
     //Processadores


     Graph *a = new Graph();
     a->run(ui);
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
