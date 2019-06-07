#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

class Movimiento
{
protected:
    int x, y;

public:
    int getX();
    void setX(int);

    int getY();
    void setY(int);

    Movimiento();
    Movimiento(int, int);
};

#endif