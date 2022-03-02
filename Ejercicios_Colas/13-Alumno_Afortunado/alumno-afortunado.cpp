// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "queue_eda.h"

template <class T>
class ListaAlumnos : public queue<T>
{
    using Nodo = typename queue<T>::Nodo;

public:
    T choose(int salto)
    {

        Nodo *n = this->prim;
        Nodo *ant = this->prim;
        int afortunado;
        int i = this->nelems;
        this->ult->sig = this->prim; //hacemos que la cola sea circular

        while (i > 1)
        {
            for (int j = 0; j < salto; j++)
            {
                ant = n;
                n = n->sig;
            }
            ant->sig = n->sig;
            n = n->sig;
            --i;
        }
        this->nelems = 0;
        this->prim = this->ult = NULL;
        return n->elem;
    }
};

bool resuelveCaso()
{
    ListaAlumnos<int> list;

    int max;
    int salto;

    std::cin >> max >> salto;

    if (max == 0 && salto == 0)
    {
        return false;
    }

    for (int i = 1; i < max + 1; i++)
    {
        list.push(i);
    }

    std::cout << list.choose(salto) << "\n";

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
