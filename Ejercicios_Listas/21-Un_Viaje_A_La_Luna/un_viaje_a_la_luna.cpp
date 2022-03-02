// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <iterator>
#include "Persona.h"

bool resuelveCaso()
{
    int numIns;
    int inf;
    int sup;

    std::cin >> numIns >> inf >> sup;

    if (numIns == 0 && inf == 0 && sup == 0)
    {
        return false;
    }
    std::list<persona> peopleList;
    for (int i = 0; i < numIns; i++)
    {
        persona aux;
        std::cin >> aux;
        peopleList.push_back(aux);
    }
    peopleList.remove_if(condition(inf, sup));

    for (persona p : peopleList)
    {
        std::cout << p << "\n";
    }

    std::cout << "---\n";

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
