// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include "bintree_eda.h"

struct tSol
{
    bintree<int> link;
    int nivel;
};

bool es_primo(int num)
{
    int div = 0, i = 1;
    if (num == 1 || num == 0)
    {
        return false;
    }
    while (i <= num)
    {
        if (num % i == 0)
        {
            div++;
        }
        i++;
    }
    if (div <= 2)
    {
        return true;
    }
    return false;
}

void barrera(bintree<int> const &a)
{
    bool encontrado = false;
    int cercano = 0;
    int profundidad = 0;

    if (!a.empty() && !es_primo(a.root()))
    {

        std::queue<struct tSol> cola;
        tSol raiz;

        raiz.link = a;
        raiz.nivel = 1;
        cola.push(raiz);

        while (!encontrado && !cola.empty())
        {

            tSol aux = cola.front();
            cola.pop();

            if (aux.link.root() % 7 == 0)
            {
                encontrado = true;
                cercano = aux.link.root();
                profundidad = aux.nivel;
            }
            else
            {
                tSol iz;
                iz.link = aux.link.left();
                iz.nivel = aux.nivel + 1;
                if (!iz.link.empty() && !es_primo(iz.link.root()))
                {
                    cola.push(iz);
                }

                tSol dr;
                dr.link = aux.link.right();
                dr.nivel = aux.nivel + 1;
                if (!dr.link.empty() && !es_primo(dr.link.root()))
                {
                    cola.push(dr);
                }
            }
        }
    }

    if (encontrado)
    {
        std::cout << cercano << " " << profundidad << std::endl;
    }
    else
    {
        std::cout << "NO HAY" << std::endl;
    }
}

void resuelveCaso()
{
    bintree<int> arbol = leerArbol(-1);
    barrera(arbol);
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
