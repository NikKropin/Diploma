#ifndef EXTREME_HPP
#define EXTREME_HPP

#include "node.hpp"

//Класс для описания Extreme из алгоритма RT
//Хранит информацию о крайних узлах поддерева (самый левый и правый)

struct Extreme{
    Extreme(){
        node = nullptr;
        offset = level = 0;
    }

    TreeNode *node;
    //offset - расстояние от корня дерева (по Х?)
    //level - на какой глубине в дереве расположен узел
    int offset, level;
};

#endif // EXTREME_HPP
