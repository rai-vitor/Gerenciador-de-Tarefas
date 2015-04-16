#ifndef GRAPH_H
#define GRAPH_H
#include <QThread>


class Graph: public QThread{
Q_OBJECT

public:
    Graph();
    void run();
    void finalizar();


signals:
    void updateGUI(int);
};


#endif // GRAPH_H
