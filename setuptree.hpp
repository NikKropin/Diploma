#ifndef DRAWTREE_HPP
#define DRAWTREE_HPP

#include <cmath>
#include <stdlib.h>
#include "extreme.hpp"
#include "util.h"

void setup(TreeNode *t, int level, Extreme &rMost, Extreme &lMost);

void petrify(TreeNode *t, int xPos);

#endif // DRAWTREE_HPP
