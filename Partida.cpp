#include "Partida.h"
#include "Movimiento.h"
#include <string>
using std::string;
#include <vector>
using std::vector;

Partida::Partida(){

}

Partida::Partida(string pnombre, vector<Movimiento*> pmovimientos, string ppieza){
    this -> nombre = pnombre;
    this -> movimientos = pmovimientos;
    this -> pieza = ppieza;
}