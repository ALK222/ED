// Nombre del alumno: Alejandro Barrachina Argudo
// Usuario del juez de clase: A08
// Usuario del juez de examen que has utilizado hoy: A53

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

template <typename T>
struct tSol
{
    bool esBinario;
    T min, max;
};

template <typename T>
tSol<T> esBinario(bintree<T> const &arbol)
{
    tSol<T> res;

    if (arbol.empty())
    {
        res.esBinario = true;
    }
    else
    {
        tSol<T> iz = esBinario(arbol.left());
        tSol<T> dr = esBinario(arbol.right());

        if (arbol.left().empty())
        {
            res.min = arbol.root();
        }
        else
        {
            res.min = iz.min;
        }

        if (arbol.right().empty())
        {
            res.max = arbol.root();
        }
        else
        {
            res.max = dr.max;
        }

        bool ordenado = (arbol.left().empty() || iz.max < arbol.root()) && (arbol.right().empty() || dr.min > arbol.root());

        res.esBinario = iz.esBinario & dr.esBinario && ordenado;
    }
    return res;
}

void resuelveCaso()
{
    bintree<int> arbol = leerArbol(-1);
    if (esBinario(arbol).esBinario)
    {
        std::cout << "SI" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
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
