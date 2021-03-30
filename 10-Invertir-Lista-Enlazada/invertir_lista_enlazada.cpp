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
    void invierte()
    {
        if (this->empty())
            return;
        Nodo *i;
        Nodo *siguiente;
        Nodo *aux;

        i = this->prim;
        siguiente = i->sig;
        while (siguiente != nullptr)
        {
            aux = siguiente->sig;
            siguiente->sig = i;
            i = siguiente;
            siguiente = aux;
        }
        aux = this->ult;
        this->ult = this->prim;
        this->prim = aux;
        this->ult->sig = nullptr;
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

    while (n != 0)
    {
        lista.push(n);
        std::cin >> n;
    }

    lista.invierte();

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
