#include "graph.h"
#include <iostream>
#include <QtCore>

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;
Graph::Graph(){

}

void Graph::run(){

    while(true){
        string linha;
        QString qstr1 = " ";
        QStringList lista;
        ifstream proc1;
        system("cat /proc/cpuinfo | grep 'MHz' > processadores.txt");
        proc1.open("processadores.txt");
        int cont = 0;
        if(proc1.is_open()) {
            while(getline(proc1, linha)){
                cont++;
                qstr1 = QString::fromStdString(linha);
                lista.push_back(qstr1);
            }
            proc1.close();
        }

        float procTotal = 2.2;
        procTotal = procTotal * 1000.0;

        QVector<float> processadores(cont);
        QStringList Lprocessadores;

        for(int i = 0; i<lista.size(); i++){
            qstr1 = lista[i];
            Lprocessadores = qstr1.split(" ");
            qstr1 = Lprocessadores[2];
            processadores[i] = qstr1.toFloat();
            processadores[i] = (processadores[i]*100)/procTotal;
        }
        emit updateGUI(processadores);
        sleep(1);
    }

}

void Graph::finalizar(){

}
