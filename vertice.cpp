#include "vertice.h"

double Vertice::repulsiveConstant = 1;

Vertice::Vertice()
{

}

Vertice::Vertice(double _x, double _y)
{
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

double Vertice::getRepConst() const
{
    return repulsiveConstant;
}
