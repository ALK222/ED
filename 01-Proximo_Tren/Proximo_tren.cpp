// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "horas.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int numTrains, numConsults;
    std::cin >> numTrains >> numConsults;
    if (numTrains == 0 && numConsults == 0)
        return false;

    std::vector<horas> trenes(numTrains);
    for (horas &h : trenes)
    {
        std::cin >> h;
    }

    for (int i = 0; i < numConsults; ++i)
    {
        horas h;
        try
        {
            std::cin >> h;
            auto pos = lower_bound(trenes.begin(), trenes.end(), h);
            if (pos != trenes.end())
                std::cout << *pos << '\n';
            else
                std::cout << "NO\n";
        }
        catch (std::invalid_argument &e)
        {
            std::cout << e.what();
        }
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
