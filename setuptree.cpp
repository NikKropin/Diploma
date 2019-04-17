#include "setuptree.hpp"

//Минимальное расстояние между узлами(расстояние в чем?)
int minSep = 20;

void setup(TreeNode *t, int level, Extreme &rMost, Extreme &lMost)
{
    TreeNode *l, *r;
    Extreme lr, ll, rr, rl;
    int curSep, rootSep, loffSum, roffSum;
    if (t == nullptr){
        rMost.level = lMost.level = -1;
    } else {
        t->yCoord = level;
        l = t->leftSon;
        r = t->rightSon;
        setup(l, level + 1, lr, ll);
        setup(r, level + 1, rr, rl);
        if (r == nullptr && l == nullptr){
            rMost.node = lMost.node = t;
            rMost.level = lMost.level = level;
            rMost.offset = lMost.offset = t->offset = 0;
        } else {
            curSep = rootSep = minSep;
            loffSum = roffSum = 0;
            while (l != nullptr && r != nullptr){
                if (curSep < minSep){
                    rootSep = rootSep + (minSep - curSep);
                    curSep = minSep;
                }
                if (l->rightSon != nullptr){
                    loffSum += l->offset;
                    curSep -= l->offset;
                    l = l->rightSon;
                } else {
                    loffSum -= l->offset;
                    curSep += l->offset;
                    l = l->leftSon;
                }
                if (r->leftSon != nullptr){
                    roffSum -= r->offset;
                    curSep -= r->offset;
                    r = r->leftSon;
                } else {
                    roffSum += r->offset;
                    curSep += r->offset;
                    r = r->rightSon;
                }
            }
            t->offset = (rootSep + 1)/2;
            loffSum -= t->offset;
            roffSum += t->offset;
            if (rl.level > ll.level || t->leftSon == nullptr){
                lMost = rl;
                lMost.offset += t->offset;
            } else {
                lMost = ll;
                lMost.offset -= t->offset;
            }
            if (lr.level > rr.level || t->rightSon == nullptr){
                rMost = lr;
                rMost.offset -= t->offset;
            } else {
                rMost = rr;
                rMost.offset += t->offset;
            }
            if (l != nullptr && l != t->leftSon){
                rr.node->isThread = true;
                rr.node->offset = std::abs(rr.offset + t->offset - loffSum);
                if ((loffSum - t->offset) <= rr.offset){
                    rr.node->leftSon = l;
                } else {
                    rr.node->rightSon = l;
                }
            } else if (r != nullptr && r != t->rightSon){
                ll.node->isThread = true;
                ll.node->offset = std::abs(ll.offset - t->offset - roffSum);
                if ((roffSum + t->offset) >= ll.offset){
                    ll.node->rightSon = r;
                } else {
                    ll.node->leftSon = r;
                }
            }
        }
    }
}

void petrify(TreeNode *t, int xPos)
{
    if (t != nullptr){
        t->xCoord = xPos;
        if (t->isThread){
            t->isThread = false;
            t->rightSon = t->leftSon = nullptr;
        }
        petrify(t->leftSon, xPos - t->offset);
        petrify(t->rightSon, xPos + t->offset);
    }
}
