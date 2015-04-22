#ifndef GRAPH_H
#define GRAPH_H
#include <QThread>
#include <fstream>
#include <string>

class Graph: public QThread{
Q_OBJECT

public:
    Graph();
    void run();
    void finalizar();


signals:
    void updateGUI(QVector<float>);
};


#endif // GRAPH_H
