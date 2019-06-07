#include "Movimiento.h"
#include <typeinfo>
#ifndef PIEZA_H
#define PIEZA_H
#include <string>
using std::string;
class Pieza
{
private:
    char **matriz;
    Movimiento* mov1, mov2;

public:
    Pieza();
   // Pieza(Movimiento*, Movimiento* );

    virtual bool validarMovimiento(Movimiento*, Movimiento*,char **);
};

#endif