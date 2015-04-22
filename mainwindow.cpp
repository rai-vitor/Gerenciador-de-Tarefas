#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>

//Nossos Includes
#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <QDir>

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
    QStringList list, list_proc, list0;
    QString qstr, qstr1, qstr_nome, qstr_pid, qstr_ppid, qstr_state, qstr_user, qstr_thread, qstr_cnt, display;
    string linha, str, path, _system, username;
    const char * c ;
    int count = 0, count_thread = 0;



    system("ps -A -o pid > proc.txt && ps -A -o user > users.txt");
    ifstream proc, file, user;
    proc.open("proc.txt");
    user.open("users.txt");
    if(proc.is_open() && user.is_open()) {
        while (proc && user) {
            for (int k = 0; getline(proc, str) && getline(user, username); ++k) {

                str.erase(std::remove(str.begin(),str.end(),' '),str.end());

                if(str != "PID") {                                      //pula a primeira linha

                    count = k;

                    qstr = QString::fromStdString(str);
                    path = "/proc/" + str + "/status";
                    _system = "grep -w 'Name\\|State\\|Pid\\|PPid\\|Uid\\|Threads\\|voluntary_ctxt_switches' " + path + " > processos/" + str + ".txt";
                   // cout << _system << endl;
                    c = _system.c_str();
                    system(c);

                    //Nome
                    file.open("processos/" + str + ".txt");
                    if(file.is_open()) {
                        getline(file, linha);
                        qstr_nome = QString::fromStdString(linha);
                        qstr_nome.replace("Name:", "");
                        qstr_nome = qstr_nome.trimmed();
                        file.close();
                    }

                    //State
                    file.open("processos/" + str + ".txt");
                    if(file.is_open()) {
                        for(int j = 0; j < 2; ++j ) {
                            getline(file, linha);
                        }
                        qstr_state = QString::fromStdString(linha);
                        qstr_state.replace("State:", "");
                        qstr_state = qstr_state.trimmed();
                        file.close();
                    }

                    //PPID

                    file.open("processos/" + str + ".txt");
                    if(file.is_open()) {
                        for(int j = 0; j < 4; ++j ) {
                            getline(file, linha);
                        }
                        qstr_ppid = QString::fromStdString(linha);
                        qstr_ppid.replace("PPid:", "");
                        qstr_ppid = qstr_ppid.trimmed();
                        file.close();
                    }


/*
                    //User
                    file.open("users.txt");
                    if(file.is_open()) {
                        //for(int j = 0; j < 5; ++j ) {
                            getline(file, linha);
                        //}
                        qstr_user = QString::fromStdString(linha);
                        //qstr_user.replace("Uid:", "");
                        //list0 = qstr_user.split("\t");
                       // qstr_user.replace("\t","");
                        qstr_user = qstr_user.trimmed();
                        file.close();
                    }

*/
                    qstr_user = QString::fromStdString(username);

                    //Threads

                    file.open("processos/" + str + ".txt");
                    if(file.is_open()) {
                        for(int j = 0; j < 6; ++j ) {
                            getline(file, linha);
                        }
                        qstr_thread = QString::fromStdString(linha);
                        qstr_thread.replace("Threads:", "");
                        qstr_thread = qstr_thread.trimmed();
                        count_thread += qstr_thread.toInt();
                        file.close();
                    }

                    //Troca de contexto

                    file.open("processos/" + str + ".txt");
                    if(file.is_open()) {
                        for(int j = 0; j < 7; ++j ) {
                            getline(file, linha);
                        }
                        qstr_cnt = QString::fromStdString(linha);
                        qstr_cnt.replace("voluntary_ctxt_switches:", "");
                        qstr_cnt = qstr_cnt.trimmed();
                        file.close();
                    }

                    //process.open(path);

                    list_proc.append(qstr);
                    listaItem << new QStandardItem(qstr_nome);             //nome
                    listaItem << new QStandardItem(qstr_state);           //status
                    listaItem << new QStandardItem(list_proc[k-1]);     //pid
                    listaItem << new QStandardItem(qstr_ppid);               //ppid
                    listaItem << new QStandardItem(qstr_user);       //usuário
                    listaItem << new QStandardItem(qstr_thread);                //threads
                    listaItem << new QStandardItem(qstr_cnt);             //troca de contexto ?
                    model->appendRow(listaItem);
                    listaItem.clear();

                   // process.close();

                    ui->tableView->setModel(model);
                    ui->tableView->setShowGrid(false);
                    ui->tableView->setAlternatingRowColors(true);
                    ui->tableView->verticalHeader()->setVisible(false);
                    ui->tableView->setSortingEnabled(true);
                    ui->tableView->sortByColumn(4, Qt::AscendingOrder);

                    }
                }

            //total de processos

            display = QString::number(count);
            ui->lcdNumber->display(display);
            display = QString::number(count_thread);
            ui->lcdNumber_2->display(display);

            }
        }
    proc.close();
    user.close();


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
    char buff[256];
    //FILE *kernel = popen("uname -r","r");
    //FILE *Name = popen("cat /etc/*-release | grep 'PRETTY_NAME'", "r");

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

        ui ->label_6->setPixmap(QPixmap("/usr/share/pixmaps/ubuntu-logo.png", 0, Qt::AutoColor));

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

void MainWindow::on_pushButton_clicked()
{
    graph->run();
}
