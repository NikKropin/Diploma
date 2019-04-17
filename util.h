#ifndef UTIL_H
#define UTIL_H

#include "node.hpp"
#include <QFile>
#include <QTextStream>
#include <vector>
#include <memory>

std::vector<std::unique_ptr<TreeNode>> readTree();

#endif // UTIL_H
