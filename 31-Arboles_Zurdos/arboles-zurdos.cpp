// Nombre del alumno: Alejandro Barrachina Argudo
// Usuario del juez de clase: A08
// Usuario del juez de examen que has utilizado hoy: A53

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

void zurdo(bintree<char> const &bt, bool &isLeft, int &numLeftSons, int &numRightSons)
{
    if (!bt.empty())
    {
        if (!bt.left().empty())
        {
            ++numLeftSons;
            zurdo(bt.left(), isLeft, numLeftSons, numRightSons);
        }

        if (!bt.right().empty())
        {
            ++numRightSons;
            zurdo(bt.right(), isLeft, numLeftSons, numRightSons);

            const int nSons = numLeftSons + numRightSons;

            isLeft = numLeftSons <= (nSons / 2) ? false : true;
        }
    }
}

void resuelveCaso()
{

    // C�digo del alumno
    bintree<char> bt = leerArbol('.');

    if (bt.empty() || (bt.left().empty() && bt.right().empty()))
    {
        std::cout << "SI\n";
    }
    else
    {
        bool isLefty = true;
        int numLeftSons = 0;
        int numRightSons = 0;

        zurdo(bt, isLefty, numLeftSons, numRightSons);

        std::cout << (isLefty ? "SI\n" : "NO\n");
    }
}

int main()
{
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos = 1;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
