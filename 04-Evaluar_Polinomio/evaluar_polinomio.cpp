// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include "polinomio.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int g, c;

    std::cin >> c;

    if (!std::cin) // fin de la entrada
        return false;

    polinomio p;

    std::cin >> g;
    //lectura del polinomio
    while (c != 0 || g != 0)
    {
        p.insert(c, g);
        std::cin >> c >> g;
    }

    //calculo de los valores que dan
    int n, valor;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> valor;
        std::cout << p.calcular(valor) << " ";
    }
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

    while (resuelveCaso())
        ;

        // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
