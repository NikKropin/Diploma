#ifndef NODE_HPP
#define NODE_HPP

//Класс для описания узла дерева
#include <utility>
#include <vector>

struct TreeNode{
    TreeNode(){
        xCoord = yCoord = offset = 0;
        isThread = false;
        leftSon = rightSon = nullptr;
    }
    TreeNode(TreeNode &&n){
        std::swap(this->xCoord, n.xCoord);
        std::swap(this->yCoord, n.yCoord);
        std::swap(this->offset, n.offset);
        std::swap(this->isThread, n.isThread);
        std::swap(this->rightSon, n.rightSon);
        std::swap(this->leftSon, n.leftSon);
    }
    TreeNode& operator=(TreeNode &&n){
        std::swap(this->xCoord, n.xCoord);
        std::swap(this->yCoord, n.yCoord);
        std::swap(this->offset, n.offset);
        std::swap(this->isThread, n.isThread);
        std::swap(this->rightSon, n.rightSon);
        std::swap(this->leftSon, n.leftSon);
        return *this;
    }
    TreeNode *leftSon, *rightSon;
    int xCoord, yCoord;
    int offset;
    bool isThread;
};

#endif // NODE_HPP

