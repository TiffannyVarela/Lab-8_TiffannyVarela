#include "Pieza.h"
#include "Movimiento.h"
#include <string>
#include <typeinfo>
using std::string;
#ifndef PEON_H
#define PEON_H

class Peon:public Pieza
{
public:
    Peon(/* args */);
    virtual bool validarMovimiento(Movimiento*, Movimiento*,char **);
};

#endif