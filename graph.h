#ifndef GRAPH_H
#define GRAPH_H

#include <QList>
#include <utility>
#include "eades.h"


class Graph
{
public:
    Graph();

    void runEades();
    QList<Vertice*> getVertices();
    QList<QList<Edge*>> getEdges();

private:
    int verticesAmount;
    QList<Vertice*> vertices;

    //Списки смежности. Индекс в списке соотв. номеру вершины
    QList<QList<Edge*>> edges;
};

#endif // GRAPH_H
