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
            res[parentInd]->leftSon = res[lInd].get();
            if (children.size() > 1){
                int rInd = children.at(1).toInt() - 1;
                res[parentInd]->rightSon = res[rInd].get();
            }
        }
    } else res.push_back(nullptr);
    return res;
}
