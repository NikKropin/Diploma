#include "util.h"
#include <QDebug>
std::vector<std::unique_ptr<TreeNode> > readTree()
{
    std::vector<std::unique_ptr<TreeNode> > res;
    QFile file("D:/QtProj/GraphDrawing/tree.txt");
    if (file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        int nodesCount = in.readLine().toInt();
        for (int i = 0; i < nodesCount; ++i){
            std::unique_ptr<TreeNode> p(new TreeNode);
            res.push_back(std::move(p));
        }
        while (!in.atEnd()){
            QString cur = in.readLine();
            QStringList children = cur.split("-").at(1).split(",");
            int parentInd = cur.split("-").at(0).toInt() - 1;
            //для м арного дерева уже не два сына
            int lInd = children.at(0).toInt() - 1;
            if (lInd != parentInd) res[parentInd]->leftSon = res[lInd].get();
            if (children.size() > 1){
                int rInd = children.at(1).toInt() - 1;
                res[parentInd]->rightSon = res[rInd].get();
            }
        }
    } else res.push_back(nullptr);
    return res;
}

Graph *readGraph()
{
    Graph *res = new Graph();
    QVector<QVector<Edge*>> edges;
    QVector<Vertice*> vertices;
    QFile file("D:/QtProj/GraphDrawing/graph.txt");
    if (file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        int nodesCount = in.readLine().toInt();
        vertices.resize(nodesCount);
        edges.resize(nodesCount);
        while (!in.atEnd()){
            QString cur = in.readLine();
            if (cur.startsWith('v')){
                QStringList verticeInfo = cur.section(' ',1,1).split(":");
                double x = verticeInfo.at(1).section(',',0,0).toDouble();
                double y = verticeInfo.at(1).section(',',1,1).toDouble();
                vertices[verticeInfo.at(0).toInt()-1] = new Vertice(x,y);
                //vertices.at(verticeInfo.at(0).toInt()-1)->setCoordinates(x,y);
            } else {
                QVector<Edge*> temp;
                int index = cur.split(':').at(0).toInt() - 1;
                for (QString dest : cur.split(':').at(1).split(',')){
                    temp.push_back(new Edge(dest.toInt() - 1));
                }
                edges[index] = temp;
            }
        }
    } else {
        qDebug() << "Could not read a graph";
    }
    res->setEdges(edges);
    res->setVertices(vertices);
    return res;
}
