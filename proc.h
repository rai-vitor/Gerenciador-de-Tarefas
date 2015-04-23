#ifndef PROC_H
#define PROC_H
#include <QThread>
#include <QStandardItem>

class proc: public QThread{
Q_OBJECT

public:
    proc();
    void run();
    void finalizar();


signals:
    void updateTable1(QStandardItemModel*);
};

#endif // PROC_H

