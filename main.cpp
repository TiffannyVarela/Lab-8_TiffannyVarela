#include "Pieza.h"
#include "Partida.h"
#include "Movimiento.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <string>
using namespace std;
#include <cstdlib>
#include <vector>
using std::vector;

int menu();
//Provisionar la matriz de chars

char **provisionarMatriz(int);

//liberar memoria de la matriz
void liberarMatriz(char **&, int);

//imprimir la matriz
void printMatrix(char **, int);

//leer la matriz
char **readMatriz(char **, int, int);

int menu2();

int sacar1(string);
int sacar2(string);
int val(int, int);

int main()
{
    int size = 8;
    int opc = 0;
    char **matriz = NULL;
    string nombre;
    ofstream outfile;
    string coordenada, letra1, coor1, letra2, coor2;
    int opc3 = 0, salir = 0;
    int opc2 = 0;
    int cont = 1;
    Movimiento* mov, mov2;
    vector<Movimiento *> movimientos;
    do
    {
        switch (opc = menu())
        {
        case 1:
            do
            {
                outfile.open("bitacoraPartidas.txt", std::ios::app);
                matriz = provisionarMatriz(size);
                cout << "Nombre de la partida: " << endl;
                cin >> nombre;
                outfile<<nombre<<endl;
                cout << "Pieza para jugar: " << endl;
                opc2 = menu2();
                if (opc2==1)
                {
                    outfile<<"Torre"<<endl;
                }
                if (opc2==2)
                {
                    outfile<<"Alfil"<<endl;
                }
                if (opc2==3)
                {
                    outfile<<"Reina"<<endl;
                }
                if (opc2==4)
                {
                    outfile<<"Caballo"<<endl;
                }
                if (opc2==5)
                {
                    outfile<<"Peon"<<endl;
                }
                readMatriz(matriz, size, opc2);
                printMatrix(matriz, size);
                if (cont%2!= 0)
                {
                    cout << "Ingrese coordenada: " << endl;
                    cin >> coordenada;
                    letra1 = coordenada.substr(1, 1);
                    coor1 = coordenada.substr(2, 1);
                   // mov=new Movimiento(sacar1(letra1), sacar2(coor1));
                    //movimientos.push_back(mov);
                    letra2 = coordenada.substr(4, 1);
                    sacar1(letra2);
                    coor2 = coordenada.substr(5, 1);
                    sacar2(coor2);
                    //mov2=new Movimiento(sacar1(letra2), sacar2(coor2));
                    //movimientos.push_back(mov2);
                    //outfile<<"["<<mov<<","<<mov2<<"]";
                    printMatrix(matriz, size);
                    cont++;
                }

                if (cont %2 == 0)
                {
                    cout << "Ingrese coordenada: " << endl;
                    cin >> coordenada;
                    letra1 = coordenada.substr(1, 1);
                    coor1 = coordenada.substr(2, 1);
                   // mov=new Movimiento(sacar1(letra1), sacar2(coor1));
                    //movimientos.push_back(mov);
                    letra2 = coordenada.substr(4, 1);
                    sacar1(letra2);
                    coor2 = coordenada.substr(5, 1);
                    sacar2(coor2);
                    //mov2=new Movimiento(sacar1(letra2), sacar2(coor2));
                   // movimientos.push_back(mov2);
                    //outfile<<"["<<mov<<","<<mov2<<"]";
                    printMatrix(matriz, size);
                    cout << "Desea salir? [1. Si, 2.No]" << endl;
                    cin >> opc3;
                    if (opc3 == 1)
                    {
                        salir = -4;
                    }
                    else
                    {
                        salir = 0;
                    }
                    cont++;
                }
            } while (salir != -4);
            outfile.close();
            liberarMatriz(matriz, size);
            cont=1;
            break;

        case 2:
            break;

        case 3:
            cout << "Saliendo" << endl;
            break;
        }
    } while (opc != 3);

    return 0;
}

int menu()
{
    while (true)
    {
        cout << "MENU" << endl
             << "1.- Jugar Partida" << endl
             << "2.- Recear Partida" << endl
             << "3.- Salir" << endl;
        cout << "Ingrese una opcion: ";
        int opcion = 0;
        cin >> opcion;
        if (opcion >= 1 && opcion <= 3)
        {
            return opcion;
        }
        else
        {

            cout << "La opcion elegida no es valida, ingrese 1 o 3" << endl;
        }
    } //end del while
    return 0;
}

int menu2()
{
    while (true)
    {
        cout << "MENU" << endl
             << "1.- Torre" << endl
             << "2.- Alfil" << endl
             << "3.- Dama" << endl
             << "4.- Caballo" << endl
             << "5.- Peon" << endl;
        cout << "Ingrese una opcion: ";
        int opcion = 0;
        cin >> opcion;
        if (opcion >= 1 && opcion <= 5)
        {
            return opcion;
        }
        else
        {

            cout << "La opcion elegida no es valida, ingrese 1 o 5" << endl;
        }
    } //end del while
    return 0;
}

char **provisionarMatriz(int size)
{
    char **matrix = new char *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new char[size];
    }
    return matrix;
}

char **readMatriz(char **matriz, int size, int opc2)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matriz[0][4] = 'K';
            matriz[7][4] = 'k';

            if (opc2 == 1)
            {
                matriz[0][7] = 'T';
                matriz[7][0] = 't';
            }
            if (opc2 == 2)
            {
                matriz[0][5] = 'A';
                matriz[7][2] = 'a';
            }
            if (opc2 == 3)
            {
                matriz[0][3] = 'Q';
                matriz[7][3] = 'q';
            }
            if (opc2 == 4)
            {
                matriz[0][6] = 'C';
                matriz[7][1] = 'c';
            }
            if (opc2 == 5)
            {
                matriz[1][4] = 'P';
                matriz[6][4] = 'p';
            }
            else
            {
                matriz[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
        }
    }
    return matriz;
}

void liberarMatriz(char **&matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (matrix[i] != NULL)
        {
            delete[] matrix[i];
            matrix[i] = NULL;
        }
    }

    if (matrix != NULL)
    {
        delete[] matrix;
        matrix = NULL;
    }
}

void printMatrix(char **matriz, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << "[" << matriz[i][j] << "]";

        cout << endl;
    }
}

int sacar1(string coor)
{
    int parte1;
    if (coor == "A" || coor == "a")
    {
        parte1 = 0;
    }
    else if (coor == "B" || coor == "b")
    {
        parte1 = 1;
    }
    else if (coor == "C" || coor == "c")
    {
        parte1 = 2;
    }
    else if (coor == "D" || coor == "d")
    {
        parte1 = 3;
    }
    else if (coor == "E" || coor == "e")
    {
        parte1 = 4;
    }
    else if (coor == "F" || coor == "f")
    {
        parte1 = 5;
    }
    else if (coor == "G" || coor == "g")
    {
        parte1 = 6;
    }
    else if (coor == "H" || coor == "h")
    {
        parte1 = 7;
    }
    else
    {
        parte1 = 20;
    }

    return parte1;
}

int sacar2(string coor)
{
    int parte2;
    if (coor == "1")
    {
        parte2 = 0;
    }
    else if (coor == "2")
    {
        parte2 = 1;
    }
    else if (coor == "3")
    {
        parte2 = 2;
    }
    else if (coor == "4")
    {
        parte2 = 3;
    }
    else if (coor == "5")
    {
        parte2 = 4;
    }
    else if (coor == "6")
    {
        parte2 = 5;
    }
    else if (coor == "7")
    {
        parte2 = 6;
    }
    else if (coor == "8")
    {
        parte2 = 7;
    }
    else
    {
        parte2 = 20;
    }

    return parte2;
}

int val(int x, int y)
{
    if (x == 20)
    {
        return 2;
    }
    if (y == 20)
    {
        return 2;
    }
    return 0;
}