#include <utility>
#include <QDebug>
#include "graph.h"

Graph::Graph()
{

    //ЧИСТИТЬ УКАЗАТЕЛИ НА ВЕРШИНЫ
//    vertices.push_back(new Vertice(500, 450));
//    vertices.push_back(new Vertice(400, 300));
//    vertices.push_back(new Vertice(850, 200));
//    vertices.push_back(new Vertice(250, 100));
//    vertices.push_back(new Vertice(70, 70));

//    //НАДО ЗАДАВАТЬ НЕ В ТУПУЮ, JSON?
//    verticesAmount = 5;

//    Edge* temp = new Edge(1), *temp1 = new Edge(2), *temp2 = new Edge(2),
//            *temp3 = new Edge(3), *temp4 = new Edge(4), *temp5 = new Edge(0);

//    edges.push_back({temp});
//    edges.push_back({temp2});
//    edges.push_back({temp3});
//    edges.push_back({temp4});
//    edges.push_back({temp5});

    vertices.push_back(new Vertice(300, 300));
    vertices.push_back(new Vertice(250, 350));
    vertices.push_back(new Vertice(275, 400));
    vertices.push_back(new Vertice(325, 400));
    vertices.push_back(new Vertice(350, 350));
    vertices.push_back(new Vertice(240, 200));
    vertices.push_back(new Vertice(100, 420));
    vertices.push_back(new Vertice(300, 450));
    vertices.push_back(new Vertice(500, 420));
    vertices.push_back(new Vertice(360, 200));

    //НАДО ЗАДАВАТЬ НЕ В ТУПУЮ, JSON?
    verticesAmount = 10;

    Edge* temp = new Edge(1), *temp1 = new Edge(2), *temp2 = new Edge(3),
            *temp3 = new Edge(4), *temp4 = new Edge(5), *temp5 = new Edge(6),
            *temp6 = new Edge(7), *temp7 = new Edge(8), *temp8 = new Edge(9);/*,
            *temp9 = new Edge(5), *temp10 = new Edge(7), *temp11 = new Edge(8),
            *temp12 = new Edge(8), *temp13 = new Edge(8), *temp14 = new Edge(9),
            *temp15 = new Edge(9), *temp16 = new Edge(9);*/

    edges.push_back({temp, temp3, temp6});
    edges.push_back({temp1, temp5, temp6, temp8});
    edges.push_back({temp2, temp5, temp8});
    edges.push_back({temp3, temp4, temp7});
    edges.push_back({temp4, temp6, temp7});
    edges.push_back({temp7});
    edges.push_back({temp8});

}

void Graph::runEades()
{
    QList<std::pair<double, double>> displacements;
    for (int i = 0; i < vertices.size(); ++i){
        displacements.push_back({0,0});
    }

    Eades calc;
    double delta = 0.1, epsilon = 0.5;
    int i = 0;
    double maxDisplacement = 0;
    do {
        maxDisplacement = 0;
        for (int j = 0; j < vertices.size(); ++j){
            double displX = 0, displY = 0;
            for (int k = 0; k < vertices.size(); ++k){
                if (k == j)
                    continue;
                bool isAdjacent = false;
                Edge* curEdge;
                if (j < edges.size()){
                    for (Edge* x : edges.at(j)){
                        if (x->getDestinationVertice() == k){
                            isAdjacent = true;
                            curEdge = x;
                            break;
                        }
                    }
                }         
                if (isAdjacent){
                    displX += calc.springForceX(vertices.at(k), vertices.at(j), curEdge);
                    displY += calc.springForceY(vertices.at(k), vertices.at(j), curEdge);
                } else {
                    displX += calc.repulsiveForceX(vertices.at(k), vertices.at(j));
                    displY += calc.repulsiveForceY(vertices.at(k), vertices.at(j));
                }
            }

            displacements[j].first = displX;
            displacements[j].second = displY;

            double displLength = std::sqrt(std::pow(displX, 2) + std::pow(displY, 2));
            if (displLength > maxDisplacement){
                maxDisplacement = displLength;
            }
        }

        for (int j = 0; j < vertices.size(); ++j){
            vertices.at(j)->setX(vertices.at(j)->getX() + delta*displacements[j].first);
            vertices.at(j)->setY(vertices.at(j)->getY() + delta*displacements[j].second);
        }

        ++i;
    } while(/*i < 100 &&*/ maxDisplacement > epsilon);
    return;
}

QVector<Vertice *> Graph::getVertices()
{
    return vertices;
}

QVector<QVector<Edge *> > Graph::getEdges()
{
    return edges;
}
