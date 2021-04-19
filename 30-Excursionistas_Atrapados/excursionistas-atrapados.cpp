// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"

struct tSol
{
    int equipos;
    int rescates;
    bool hayEnRama;
};

tSol rescatados(bintree<int> const &bt)
{
    if (bt.empty())
    {
        return {0, 0, false};
    }

    tSol l = rescatados(bt.left());
    tSol r = rescatados(bt.right());

    if (bt.root() == 0)
    {
        if (l.hayEnRama || r.hayEnRama)
        {
            return {l.equipos + r.equipos, std::max(l.rescates, r.rescates), true};
        }
        else
        {
            return {0, 0, false};
        }
    }

    if (l.hayEnRama || r.hayEnRama)
    {
        return {l.equipos + r.equipos, std::max(l.rescates + bt.root(), r.rescates + bt.root()), true};
    }

    return {1, std::max(l.rescates + bt.root(), r.rescates + bt.root()), true};
}

void resuelveCaso()
{
    bintree<int> arbol = leerArbol(-1);
    tSol sol = rescatados(arbol);
    std::cout << sol.equipos << " " << sol.rescates << std::endl;
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
