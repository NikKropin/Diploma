#ifndef UTIL_H
#define UTIL_H

#include "node.hpp"
#include "graph.h"
#include <QFile>
#include <QTextStream>
#include <vector>
#include <memory>

std::vector<std::unique_ptr<TreeNode>> readTree();

Graph* readGraph();

#endif // UTIL_H
