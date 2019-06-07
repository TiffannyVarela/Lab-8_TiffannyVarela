
#include "Pieza.h"
#include "Movimiento.h"
#ifndef PARTIDA_H
#define PARTIDA_H
#include <string>

#include <vector>
using std::vector;
using std::string;

class Partida
{
protected:
    string nombre;
    string pieza;
    vector <Movimiento*> movimientos;
public:
    Partida();
    Partida(string, vector<Movimiento*>, string);
};

#endif