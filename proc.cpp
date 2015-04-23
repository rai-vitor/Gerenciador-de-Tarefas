#include "proc.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <QDir>
#include <QStandardItem>
using namespace std;
proc::proc()
{

}

void proc::run(){
    QList<QStandardItem *> listaItem;
    QStringList list, list_proc, list0;
    QString qstr, qstr1, qstr_nome, qstr_pid, qstr_ppid, qstr_state, qstr_user, qstr_thread, qstr_cnt, display, nome_sistema;
    string linha, str, path, _system, username;
    const char * c ;
    int count = 0, count_thread = 0;

    QStandardItemModel *model;

    model = new QStandardItemModel();
    QStringList headers;
    headers << tr("Nome") << tr("Status") << tr("PID") << tr("PPID") << tr("Usuário") << tr("Threads") << tr("Trocas de Contexto");
    model->setHorizontalHeaderLabels(headers);
    cout<<"entrei";
    while(true){


        model->clear();
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

                            }
                        }

                    //total de processos
        /*
                    display = QString::number(count);
                    ui->lcdNumber->display(display);
                    display = QString::number(count_thread);
                    ui->lcdNumber_2->display(display);
        */
                    }
                }
            emit updateTable1(model);
            proc.close();
            user.close();


    }
}

void proc::finalizar(){

}

