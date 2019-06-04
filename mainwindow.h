#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mygraphicsview.h"
#include "eades.h"
#include "vertice.h"
#include "setuptree.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintGraph();

private slots:
    void on_forceButton_clicked();
    void slotResize();
    void slotStartTimer();

    void on_verticalSlider_sliderMoved(int position);

    void on_treeButton_clicked();

private:
    Ui::MainWindow *ui;

    MyGraphicsView *view;
    QGraphicsScene *scene;
    QTimer *timer;
    Graph *graph;

    int sliderPos = 0;
};

#endif // MAINWINDOW_H
