// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"

struct tsol
{
    bool completo;
    int altura;
    int alturaMax;
};

tsol resolver(bintree<char> const &a)
{

    if (a.empty())
    {
        return {false, 0, 0};
    }

    if (a.left().empty() && a.right().empty())
    {
        return {true, 1, 1};
    }

    tsol iz = resolver(a.left());
    tsol dr = resolver(a.right());

    return {true, std::min(dr.altura, iz.altura) + 1, std::max(std::max(iz.alturaMax, dr.alturaMax), std::min(iz.altura, dr.altura) + 1)};
}

void resuelveCaso()
{

    bintree<char> arbol = leerArbol('.');

    tsol sol = resolver(arbol);

    std::cout << sol.alturaMax << "\n";
}

int main()
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;

    for (int i = 0; i < numCasos; i++)
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
