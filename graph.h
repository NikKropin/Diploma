#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <utility>
#include "eades.h"


class Graph
{
public:
    Graph();

    void runEades();
    QVector<Vertice*> getVertices();
    QVector<QVector<Edge*>> getEdges();

private:
    int verticesAmount;
    QVector<Vertice*> vertices;

    //Списки смежности. Индекс в списке соотв. номеру вершины
    QVector<QVector<Edge*>> edges;
};

#endif // GRAPH_H
