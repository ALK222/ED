// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "queue_eda.h"

template <class T>
class ListaInvertida : public queue<T>
{
    using Nodo = typename queue<T>::Nodo;

public:
    void invierte(int pos, int lon)
    {

        Nodo *pre = nullptr;
        Nodo *n = this->prim;

        for (int i = 0; i < pos - 1; i++)
        {
            pre = n;
            n = n->sig;
        }

        Nodo *last = pre;
        Nodo *actual = n;
        Nodo *sig = n->sig;

        for (int i = 0; i < lon - 1; i++)
        {
            last = actual;
            actual = sig;
            sig = sig->sig;
            actual->sig = last;
        }

        if (pre == nullptr)
        {
            this->prim = actual;
        }
        else
        {
            pre->sig = actual;
        }

        if (sig == nullptr)
        {
            this->ult = n;
            n->sig = nullptr;
        }
        else
        {
            n->sig = sig;
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
inline std::ostream &operator<<(std::ostream &o, ListaInvertida<T> const &a)
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

    ListaInvertida<int> lista;
    int lon;
    int pos;
    std::cin >> pos;
    std::cin >> lon;

    int aux;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> aux;
        lista.push(aux);
    }

    lista.invierte(pos, lon);

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
