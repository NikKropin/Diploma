#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showMaximized();

    scene = new QGraphicsScene(this);

    graph = readGraph();
    paintGraph();

    view = new MyGraphicsView();
    view->setScene(scene);
    connect(view, &MyGraphicsView::resized, this, &MainWindow::slotStartTimer);

    ui->viewLayout->addWidget(view);

    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &MainWindow::slotResize);
    timer->start(50);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete view;
}

void MainWindow::paintGraph()
{
    scene->clear();

    auto vertices = graph->getVertices();
    auto edges = graph->getEdges();
    for (auto x : vertices){
        scene->addEllipse(x->getX() - 5, x->getY() - 5, 10, 10, QPen(Qt::black), QBrush(Qt::black));
    }
    for (int i = 0; i < edges.size(); ++i){
        for (int j = 0; j < edges.at(i).size(); ++j){
            auto startVertice = vertices.at(i);
            auto endVertice = vertices.at(edges.at(i).at(j)->getDestinationVertice());
            scene->addLine(startVertice->getX(), startVertice->getY(), endVertice->getX(), endVertice->getY(), QPen(Qt::black));
        }
    }
}

void MainWindow::on_forceButton_clicked()
{
    //НАДО ВЕРНУТЬ ЦИКЛ ПО КОЛИЧЕСТВУ ИТЕРАЦИЙ В ГРАФЕ
    graph->runEades();
    paintGraph();
}

void MainWindow::slotResize()
{
    scene->setSceneRect(0, 0, this->width(), this->height());
}

void MainWindow::slotStartTimer()
{
    timer->start(50);
}

void MainWindow::on_verticalSlider_sliderMoved(int position)
{
    view->scale(1 + (position - sliderPos)*0.01, 1 + (position - sliderPos)*0.01);
    sliderPos = position;
}

void MainWindow::on_treeButton_clicked()
{
    std::vector<std::unique_ptr<TreeNode>> tree = readTree();
    scene->clear();

    Extreme rMost, lMost;
    setup(tree[0].get(), 3, rMost, lMost);
    petrify(tree[0].get(), 500);
    for (auto &x : tree){
        scene->addEllipse(x->xCoord - 2, x->yCoord*50 - 2, 5, 5, QPen(Qt::black), QBrush(Qt::black));
        if (x->leftSon != nullptr){
            scene->addEllipse(x->leftSon->xCoord - 2, x->leftSon->yCoord*50 - 2, 5, 5, QPen(Qt::black), QBrush(Qt::black));
            scene->addLine(x->xCoord, x->yCoord*50, x->leftSon->xCoord, x->leftSon->yCoord*50, QPen(Qt::black));
        }
        if (x->rightSon != nullptr){
            scene->addEllipse(x->rightSon->xCoord - 2, x->rightSon->yCoord*50 - 2, 5, 5, QPen(Qt::black), QBrush(Qt::black));
            scene->addLine(x->xCoord, x->yCoord*50, x->rightSon->xCoord, x->rightSon->yCoord*50, QPen(Qt::black));
        }
    }
}
