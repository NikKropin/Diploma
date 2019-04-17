#ifndef EADES_H
#define EADES_H

#include <cmath>
#include <stdlib.h>
#include "vertice.h"
#include "edge.h"

class Eades
{
public:
    Eades();

    double repulsiveForceX(const Vertice *u, const Vertice *v);
    double attractiveForceX(const Vertice *u, const Vertice *v, const Edge *e);
    double repulsiveForceY(const Vertice *u, const Vertice *v);
    double attractiveForceY(const Vertice *u, const Vertice *v, const Edge *e);
};

#endif // EADES_H
