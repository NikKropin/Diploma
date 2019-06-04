#include "vertice.h"

void Vertice::setRepulsiveConstant(double value)
{
    repulsiveConstant = value;
}

Vertice::Vertice()
{
    repulsiveConstant = 500;
}

Vertice::Vertice(double _x, double _y)
{
    repulsiveConstant = 500;
    x = _x;
    y = _y;
}

double Vertice::getX() const
{
    return x;
}

double Vertice::getY() const
{
    return y;
}

void Vertice::setX(double _x)
{
    x = _x;
}

void Vertice::setY(double _y)
{
    y = _y;
}

void Vertice::setCoordinates(double _x, double _y)
{
    x = _x;
    y = _y;
}

double Vertice::getRepConst() const
{
    return repulsiveConstant;
}
