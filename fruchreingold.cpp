#include "fruchreingold.h"

FruchReingold::FruchReingold()
{

}

double FruchReingold::repulsiveForceX(const Vertice *u, const Vertice *v, const Edge *e)
{
    double eucLength = std::sqrt(std::pow((u->getX()-v->getX()), 2) + std::pow((u->getY() - v->getY()), 2));
    double unitVec = (v->getX() - u->getX())/eucLength;
    return std::pow(e->getPerfectLength(), 2) * unitVec / std::pow(eucLength, 2);
}

double FruchReingold::attractiveForceX(const Vertice *u, const Vertice *v, const Edge *e)
{
    double unitVec = (u->getX() - v->getX());
    double eucLength = std::sqrt(std::pow((u->getX()-v->getX()), 2) + std::pow((u->getY() - v->getY()), 2));
    return unitVec*eucLength/e->getPerfectLength();
}

double FruchReingold::repulsiveForceY(const Vertice *u, const Vertice *v, const Edge *e)
{
    double eucLength = std::sqrt(std::pow((u->getX()-v->getX()), 2) + std::pow((u->getY() - v->getY()), 2));
    double unitVec = (v->getY() - u->getY())/eucLength;
    return std::pow(e->getPerfectLength(), 2) * unitVec / std::pow(eucLength, 2);
}

double FruchReingold::attractiveForceY(const Vertice *u, const Vertice *v, const Edge *e)
{
    double unitVec = (u->getY() - v->getY());
    double eucLength = std::sqrt(std::pow((u->getX()-v->getX()), 2) + std::pow((u->getY() - v->getY()), 2));
    return unitVec*eucLength/e->getPerfectLength();
}
