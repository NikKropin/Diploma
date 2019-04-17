#ifndef EDGE_H
#define EDGE_H


class Edge
{
private:
    double attractiveConstant, perfectLength;
    int destinationVertice;
public:
    Edge();
    explicit Edge(int destVertice);

    double getAttrConst() const;
    void setAttrConst(double x);

    int getDestinationVertice() const;
    void setDestinationVertice(int x);

    double getPerfectLength() const;
    void setPerfectLength(double _pl);
};

#endif // EDGE_H
