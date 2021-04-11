// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "deque_eda.h"

template <class T>
class ListaMezcla : public deque<T>
{
    using Nodo = typename deque<T>::Nodo;

public:
    void mezcla(ListaMezcla lista2)
    {

        Nodo *prim1 = this->fantasma->sig;
        Nodo *prim2 = lista2.fantasma->sig;
        Nodo *aux;

        if (prim1 == this->fantasma)
        {
            this->fantasma->sig = prim2;
            this->nelems = lista2.nelems;
        }
        else if (prim2 != lista2.fantasma)
        {
            if (prim1->elem <= prim2->elem)
            {
                aux = prim1;
                prim1 = prim1->sig;
            }
            else
            {
                this->fantasma->sig = prim2;
                aux = prim2;
                prim2 = prim2->sig;
            }

            while (prim1 != this->fantasma && prim2 != lista2.fantasma)
            {
                if (prim1->elem < prim2->elem)
                {
                    aux->sig = prim1;
                    prim1 = prim1->sig;
                    aux = aux->sig;
                }
                else
                {
                    aux->sig = prim2;
                    prim2 = prim2->sig;
                    aux = aux->sig;
                }
            }
            if (prim1 == this->fantasma)
            {
                aux->sig = prim2;
                prim2 = prim2->sig;
            }
            else if (prim2 == lista2.fantasma)
            {
                aux->sig = prim1;
                prim1 = prim1->sig;
            }
            this->nelems += lista2.nelems;
        }

        lista2.fantasma->sig = lista2.fantasma;
        lista2.fantasma->ant = lista2.fantasma;
    }

    void print(std::ostream &o = std::cout) const
    {
        Nodo *prim = this->fantasma->sig;
        Nodo *mostrar = prim;
        for (int i = 0; i < this->nelems; ++i)
        {
            std::cout << mostrar->elem << " ";
            mostrar = mostrar->sig;
        }
    }
};

template <class T>
inline std::ostream &operator<<(std::ostream &o, ListaMezcla<T> const &a)
{
    a.print(o);
    return o;
}

bool resuelveCaso()
{
    ListaMezcla<int> lista1;
    ListaMezcla<int> lista2;

    int n;

    std::cin >> n;

    while (n != 0)
    {
        lista1.push_back(n);
        std::cin >> n;
    }

    std::cin >> n;

    while (n != 0)
    {
        lista2.push_back(n);
        std::cin >> n;
    }

    lista1.mezcla(lista2);

    std::cout << lista1 << "\n";
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

    unsigned int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
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
