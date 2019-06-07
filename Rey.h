#include "Pieza.h"
#include "Movimiento.h"
#include <string>
using std::string;
#ifndef Rey_H
#define Rey_H

class Rey:public Pieza
{
public:
    Rey();
    
    virtual bool validarMovimiento(Movimiento*, Movimiento*,char **);
};

#endif