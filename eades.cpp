#include "eades.h"

Eades::Eades()
{

}

double Eades::repulsiveForceX(const Vertice *  u, const Vertice *  v)
{
    double denum = std::pow((u->getX()-v->getX()), 2) + std::pow((u->getY() - v->getY()), 2);
    double unitVec = (v->getX() - u->getX())/
            std::sqrt(std::pow((u->getX()-v->getX()), 2) + std::pow((u->getY() - v->getY()), 2));
    return u->getRepConst()/denum * unitVec;
}

double Eades::springForceX(const Vertice *u, const Vertice *v, const Edge *e)
{
    double unitVec = (u->getX() - v->getX())/
            std::sqrt(std::pow((u->getX()-v->getX()), 2) + std::pow((u->getY() - v->getY()), 2));
    double logarithm = std::log2(std::sqrt(std::pow((u->getX()-v->getX()), 2) + std::pow((u->getY() - v->getY()), 2))/
                                 e->getPerfectLength());
    return e->getAttrConst() * logarithm * unitVec;
}

double Eades::repulsiveForceY(const Vertice *u, const Vertice *v)
{
    double denum = std::pow((u->getX()-v->getX()), 2) + std::pow((u->getY() - v->getY()), 2);
    double unitVec = (v->getY() - u->getY())/
            std::sqrt(std::pow((u->getX()-v->getX()), 2) + std::pow((u->getY() - v->getY()), 2));
    return u->getRepConst()/denum * unitVec;
}

double Eades::springForceY(const Vertice *u, const Vertice *v, const Edge *e)
{
    double unitVec = (u->getY() - v->getY())/
            std::sqrt(std::pow((u->getX()-v->getX()), 2) + std::pow((u->getY() - v->getY()), 2));
    double logarithm = std::log2(std::sqrt(std::pow((u->getX()-v->getX()), 2) + std::pow((u->getY() - v->getY()), 2))/
                                 e->getPerfectLength());
    return e->getAttrConst() * logarithm * unitVec;
}
