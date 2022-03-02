// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"

using nivel = int;
using nodo = int;

std::vector<std::pair<int, int>> levelorder(bintree<int> const &a)
{
    std::vector<std::pair<nodo, nivel>> levels;

    if (!a.empty())
    {
        std::queue<std::pair<bintree<int>, nivel>> pendientes;

        pendientes.push({a, 1});

        while (!pendientes.empty())
        {

            //vamos sacando los arboles que hemos ido metiendo para ir analizandolos
            bintree<int> sig_arb = pendientes.front().first;
            int nivel = pendientes.front().second;

            pendientes.pop();

            // si somos la raiz añadimos al vector
            if (nivel == 1)
            {
                levels.push_back({sig_arb.root(), nivel});
            }
            else
            {
                // si en el vector todavia no hay ningun elemento de ese nivel, lo metemos en el vector
                if (levels.back().second != nivel)
                {
                    levels.push_back({sig_arb.root(), nivel});
                }
            }

            // si el hijo izquierdo o el hijo derecho no son vacion los añadimos para analizalos a la vuelta siguiente
            // e incrementeamos el nivel

            if (!sig_arb.left().empty())
            {
                pendientes.push({sig_arb.left(), nivel + 1});
            }

            if (!sig_arb.right().empty())
            {
                pendientes.push({sig_arb.right(), nivel + 1});
            }
        }
    }

    return levels;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{

    bintree<int> arbol = leerArbol(-1);

    auto v = levelorder(arbol);

    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i].first << ' ';
    }

    std::cout << "\n";
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
