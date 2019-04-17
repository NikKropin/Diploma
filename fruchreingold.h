#ifndef FRUCHREINGOLD_H
#define FRUCHREINGOLD_H

#include <cmath>
#include <stdlib.h>
#include "vertice.h"
#include "edge.h"

class FruchReingold
{
private:
    double repulsiveConstant = 2, attractiveConstant = 1, perfectLength = 1;

public:
    FruchReingold();

    double repulsiveForceX(const Vertice *u, const Vertice *v, const Edge *e);
    double attractiveForceX(const Vertice *u, const Vertice *v, const Edge *e);
    double repulsiveForceY(const Vertice *u, const Vertice *v, const Edge *e);
    double attractiveForceY(const Vertice *u, const Vertice *v, const Edge *e);
};

#endif // FRUCHREINGOLD_H
