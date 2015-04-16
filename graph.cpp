#include "graph.h"
#include <iostream>
#include <QtCore>

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

Graph::Graph(){

}

void Graph::run(){


    int i = 0;
    while(true){
        emit updateGUI(i);
       // std::cout<<i;
        i++;
        if(i == 100){
            i = 0;
        }
        sleep(1);
    }

    QStringList list;
    char buff[512];
    FILE *proc = popen("cat /proc/cpuinfo | grep 'MHz'","r");

    QString qstr = " ";
    list.clear();
    while ( fgets( buff, 256, proc ) != NULL ) {
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



    float procTotal = 2.2; // Depois vou pegar o valor real, isso aqui foi uma gambiarra, pq o valor real to outro arquivo
    procTotal = procTotal * 10000.0;
    /*ui->progressBar_1->setValue((proc1*100)/procTotal);
    ui->progressBar_2->setValue((proc2*100)/procTotal);
    ui->progressBar_3->setValue((proc3*100)/procTotal);
    ui->progressBar_4->setValue((proc4*100)/procTotal);*/

}

void Graph::finalizar(){

}
