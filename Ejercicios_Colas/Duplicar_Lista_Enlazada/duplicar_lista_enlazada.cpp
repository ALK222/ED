// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "queue_eda.h"

template <class T>
class ListaDuplicada : public queue<T>
{
    using Nodo = typename queue<T>::Nodo;

public:
    void duplica()
    {
        Nodo *nodo = this->prim;
        int n = this->nelems;

        for (int i = 0; i < n; i++)
        {
            Nodo *sig = nodo->sig;
            nodo->sig = new Nodo(nodo->elem, sig);
            nodo = sig;
            this->nelems++;
        }
    }

    void print(std::ostream &o = std::cout) const
    {
        if (!this->empty())
        {
            Nodo *n = this->prim;
            for (int i = 0; i < this->nelems; ++i)
            {
                std::cout << n->elem << " ";
                n = n->sig;
            }
        }
    }
};

template <class T>
inline std::ostream &operator<<(std::ostream &o, ListaDuplicada<T> const &a)
{
    a.print(o);
    return o;
}

bool resuelveCaso()
{
    int n;
    std::cin >> n;
    if (!std::cin)
    {
        return false;
    }

    ListaDuplicada<int> lista;

    while (n != 0)
    {
        lista.push(n);
        std::cin >> n;
    }

    lista.duplica();

    std::cout << lista << "\n";

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
