// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"

template <class T>
T minimo(bintree<T> bt)
{
    T min;
    if (bt.left().empty() && bt.right().empty())
    {
        return bt.root();
    }
    else
    {
        T m = bt.root();
        if (!bt.left().empty())
        {
            T aux = minimo(bt.left());
            m = std::min(aux, m);
        }
        if (!bt.right().empty())
        {
            T aux = minimo(bt.right());
            m = std::min(aux, m);
        }

        return m;
    }
}

bool resuelveCaso()
{
    if (!std::cin)
    {
        return false;
    }

    char tipo;
    std::cin >> tipo;

    if (tipo == 'N')
    {
        bintree<int> br = leerArbol(-1);
        std::cout << minimo(br) << "\n";
    }
    else if (tipo == 'P')
    {
        bintree<std::string> br = leerArbol(std::string("#"));
        std::cout << minimo(br) << "\n";
    }

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

    while (resuelveCaso())
        ;

        // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
