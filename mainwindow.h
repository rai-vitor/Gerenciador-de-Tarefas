#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include <QSplitter>
#include <string>
#include "graph.h"
#include "proc.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    std::string kill_process;
    ~MainWindow();

public slots:
    void updateInterface(QVector<float>);
    void updateTable(QStandardItemModel*);

private slots:
    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QSplitter *splitter;
    float procTotal;
    Graph *graph;
    proc *proc1;

};

#endif // MAINWINDOW_H
