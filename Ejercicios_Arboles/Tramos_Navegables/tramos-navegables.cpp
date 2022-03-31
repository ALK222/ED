
#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool esHoja(const Arbin<int> &cuenca)
{
    return cuenca.hijoDer().esVacio() && cuenca.hijoIz().esVacio();
}

void numeroTramosNavegablesAux(const Arbin<int> &cuenca, int &tramos, int &caudal)
{
    if (cuenca.esVacio()) // final del arbol
    {
        caudal = 0;
    }
    else if (esHoja(cuenca))
    {
        caudal = 1 + cuenca.raiz();
    }
    else
    {
        int caudalDer;
        int caudalIzq;

        numeroTramosNavegablesAux(cuenca.hijoDer(), tramos, caudalDer);
        numeroTramosNavegablesAux(cuenca.hijoIz(), tramos, caudalIzq);

        caudal = caudalDer + caudalIzq + cuenca.raiz();

        if (caudal >= 3)
        {
            tramos++;
        }
        else if (caudal < 0)
        {
            caudal = 0;
        }
    }
}

int numeroTramosNavegables(const Arbin<int> &cuenca)
{
    // A IMPLEMENTAR
    if (cuenca.esVacio())
    {
        return 0;
    }
    int totalTramos = 0;
    int caudal = 0;
    numeroTramosNavegablesAux(cuenca, totalTramos, caudal);
    if (caudal >= 3)
    {
        totalTramos--;
    }
    return totalTramos;
}

Arbin<int> leeArbol(istream &in)
{
    char c;
    in >> c;
    switch (c)
    {
    case '#':
        return Arbin<int>();
    case '[':
    {
        int raiz;
        in >> raiz;
        in >> c;
        return Arbin<int>(raiz);
    }
    case '(':
    {
        Arbin<int> iz = leeArbol(in);
        int raiz;
        in >> raiz;
        Arbin<int> dr = leeArbol(in);
        in >> c;
        return Arbin<int>(iz, raiz, dr);
    }
    default:
        return Arbin<int>();
    }
}

int main()
{
    Arbin<int> cuenca;
    while (cin.peek() != EOF)
    {
        cout << numeroTramosNavegables(leeArbol(cin));
        string restoLinea;
        getline(cin, restoLinea);
        if (cin.peek() != EOF)
            cout << endl;
    }
    return 0;
}
