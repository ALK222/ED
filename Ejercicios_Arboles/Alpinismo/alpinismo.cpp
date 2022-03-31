#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void tiempoAyudaAux(const Arbin<char> &falda, int tramos, int &total)
{
    if (!falda.esVacio())
    {
        if (falda.raiz() == 'X')
        {
            total += tramos;
        }
        tramos += 2;
        tiempoAyudaAux(falda.hijoDer(), tramos, total);
        tiempoAyudaAux(falda.hijoIz(), tramos, total);
    }
}

int tiempoAyuda(const Arbin<char> &falda)
{
    // A IMPLEMENTAR
    int total = 0;
    tiempoAyudaAux(falda, 0, total);
    return total;
}

Arbin<char> leeArbol(istream &in)
{
    char c;
    in >> c;
    switch (c)
    {
    case '#':
        return Arbin<char>();
    case '[':
    {
        char raiz;
        in >> raiz;
        in >> c;
        return Arbin<char>(raiz);
    }
    case '(':
    {
        Arbin<char> iz = leeArbol(in);
        char raiz;
        in >> raiz;
        Arbin<char> dr = leeArbol(in);
        in >> c;
        return Arbin<char>(iz, raiz, dr);
    }
    default:
        return Arbin<char>();
    }
}

int main()
{
    Arbin<char> falda;
    while (cin.peek() != EOF)
    {
        cout << tiempoAyuda(leeArbol(cin));
        string restoLinea;
        getline(cin, restoLinea);
        if (cin.peek() != EOF)
            cout << endl;
    }
    return 0;
}
