// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "queue_eda.h"
#include "horas.h" // Ejercicio 2

class propSerPar
{
public:
    bool operator()(horas h)
    {
        horas aux = horas(12, 00, 00);
        return h > aux;
    }
};

template <class T>
class ListaAmpliada : public queue<T>
{
    using Nodo = typename queue<T>::Nodo;

public:
    template <class comp>
    int contarElementos(comp propiedad) const
    {

        // Aqui el código del alumno

        // Para comprobar que un elemento a cumple una propiedad
        // se utiliza la función recibida como parámetro
        // if (propiedad(a)) ...

        Nodo *nodo = this->prim;
        int n = this->nelems;
        int total = 0;

        for (int i = 0; i < n; i++)
        {
            if (propiedad(nodo->elem))
            {
                total++;
            }
            nodo = nodo->sig;
        }
        return total;
    }
};

bool resuelveCaso()
{
    int numElem;
    std::cin >> numElem;
    if (numElem == 0)
        return false;

    ListaAmpliada<horas> lista;
    for (size_t i = 0; i < numElem; ++i)
    {
        horas n;
        std::cin >> n;
        lista.push(n);
    }
    int cont = lista.contarElementos(propSerPar());

    std::cout << cont << '\n';

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
