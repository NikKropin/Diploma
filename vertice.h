#ifndef VERTICE_H
#define VERTICE_H


class Vertice{
private:
    static double repulsiveConstant;
    int num;
    double x, y;

public:
    Vertice();
    Vertice(double _x, double _y);
    double getX() const;
    double getY() const;
    void setX(double _x);
    void setY(double _y);

    double getRepConst() const;
};

#endif // VERTICE_H
