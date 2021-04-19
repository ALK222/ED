// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"

template <class T>
void fronteras(bintree<T> bt)
{
    if (bt.empty())
    {
        return;
    }
    else if (bt.left().empty() && bt.right().empty())
    {
        std::cout << bt.root() << " ";
    }
    else
    {
        fronteras(bt.left());
        fronteras(bt.right());
    }
}

bool resuelveCaso()
{
    bintree<int> bt = leerArbol(-1);

    fronteras(bt);
    std::cout << "\n";
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
