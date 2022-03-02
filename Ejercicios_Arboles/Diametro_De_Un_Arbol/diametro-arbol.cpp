// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"

int diametro(bintree<char> const &a, int &altura)
{
    if (a.empty())
    {
        altura = 0;
        return 0;
    }
    else
    {
        int altIz, altDr;
        int dimIz = diametro(a.left(), altIz);
        int dimDr = diametro(a.right(), altDr);

        altura = 1 + std::max(altDr, altIz);

        return std::max(1 + altIz + altDr, std::max(dimDr, dimIz));
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    bintree<char> arbol = leerArbol('.');
    int altura;
    std::cout << diametro(arbol, altura) << std::endl;
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
