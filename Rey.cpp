#include "Rey.h"
#include "Movimiento.h"
#include <typeinfo>
#include <string>
using std::string;

Rey::Rey()
{
}

bool Rey::validarMovimiento(Movimiento *mov, Movimiento *mov2, char **matriz)
{
    bool retval = false;

    if (mov2->getY() == (mov->getY() + 1) || mov2->getX() == (mov->getX() + 1) || mov2->getY() == (mov->getY() - 1) || mov2->getX() == (mov->getX() - 1))
    {
        retval = true;
    }
    else
    {
        retval = false;
    }

    return retval;
}