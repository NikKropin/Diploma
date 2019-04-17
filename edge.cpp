#include "edge.h"

Edge::Edge()
{
    attractiveConstant = 1;
    perfectLength = 50;
}

Edge::Edge(int destVertice)
{
    destinationVertice = destVertice;
    attractiveConstant = 1;
    perfectLength = 50;
}

double Edge::getAttrConst() const
{
    return attractiveConstant;
}

void Edge::setAttrConst(double x)
{
    attractiveConstant = x;
}

int Edge::getDestinationVertice() const
{
    return destinationVertice;
}

void Edge::setDestinationVertice(int x)
{
    destinationVertice = x;
}

double Edge::getPerfectLength() const
{
    return perfectLength;
}

void Edge::setPerfectLength(double _pl)
{
    perfectLength = _pl;
}
