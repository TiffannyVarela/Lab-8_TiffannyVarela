#include "Peon.h"
#include "Movimiento.h"
#include <typeinfo>
#include <string>
using std::string;

Peon::Peon():Pieza(){

}


bool Peon::validarMovimiento (Movimiento* mov,Movimiento* mov2, char** matriz){
    bool retval = false;
    if(mov->getY()==7 || mov -> getY()==2){
        if(mov2->getY()==(mov->getY()+2) || mov2->getY()==(mov->getY()-2)){
            retval=true;
        }
    }
    else if (mov2->getY()==(mov->getY()+1))
    {
        retval=true;
    }
    else{
        retval=false;
    }
    
    return retval;
}