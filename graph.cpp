#include <utility>
#include <QDebug>
#include "graph.h"

Graph::Graph()
{

}

void Graph::runEades()
{
    QVector<std::pair<double, double>> displacements;
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

void Graph::setVertices(QVector<Vertice *> vertices_)
{
    vertices = vertices_;
}

void Graph::setEdges(QVector<QVector<Edge *> > edges_)
{
    edges = edges_;
}
