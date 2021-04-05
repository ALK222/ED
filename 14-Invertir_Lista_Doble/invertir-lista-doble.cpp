// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "deque_eda.h"

template <class T>
class ListaInvertida : public deque<T>
{
    using Nodo = typename deque<T>::Nodo;

public:
    void invierte()
    {

        Nodo *prim = this->fantasma->sig;
        Nodo *ult = this->fantasma;

        Nodo *act = prim;
        Nodo *ant = nullptr;
        while (act != nullptr && act != ult)
        {
            ant = act->ant;
            Nodo *sig = act->sig;
            act->ant = act->sig;
            act->sig = ant;
            act = sig;
        }
        this->fantasma->sig = act->ant;
    }

    void print(std::ostream &o = std::cout) const
    {
        Nodo *prim = this->fantasma->sig;
        Nodo *ult = this->fantasma;
        Nodo *mostrar = prim;
        while (mostrar != ult)
        {
            std::cout << mostrar->elem << " ";
            mostrar = mostrar->sig;
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
        lista.push_back(n);
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
