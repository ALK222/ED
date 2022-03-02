// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "bintree_eda.h"

template <class T>
int numNodos(bintree<T> ar)
{
    if (ar.empty())
    {
        return 0;
    }
    else
    {
        return 1 + (numNodos(ar.left()) + numNodos(ar.right()));
    }
}

template <class T>
int numHojas(bintree<T> ar)
{
    if (ar.empty())
    {
        return 0;
    }
    else if (ar.left().empty() && ar.right().empty())
    {
        return 1;
    }
    else
    {
        return (numHojas(ar.left()) + numHojas(ar.right()));
    }
}

template <class T>
int altura(bintree<T> ar)
{
    if (ar.empty())
    {
        return 0;
    }
    else
    {
        return 1 + std::max(altura(ar.left()), altura(ar.right()));
    }
}

bool resuelveCaso()
{
    bintree<char> ar = leerArbol('.');

    std::cout << numNodos(ar) << " " << numHojas(ar) << " " << altura(ar) << "\n";
    return true;
}

int main()
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    unsigned int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
    {
        resuelveCaso();
    }

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
