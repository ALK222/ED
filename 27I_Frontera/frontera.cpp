// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "bintree_eda.h"

template <class T>
class myTree : public bintree<T>
{
    using Link = typename bintree<T>::Link;

public:
    myTree() : bintree<T>() {}
    myTree(myTree<T> const &l, T const &e, myTree<T> const &r) : bintree<T>(l, e, r) {}

    int nodos()
    {
        return numNodos(this->raiz);
    }

    int hojas()
    {
        return numHojas(this->raiz);
    }

    int al()
    {
        return altura(this->raiz);
    }

    void fronteras()
    {
        frontera(this->raiz);
    }

private:
    int numNodos(Link l)
    {
        if (l == nullptr)
        {
            return 0;
        }
        else
        {
            return 1 + (numNodos(l->left) + numNodos(l->right));
        }
    }

    int numHojas(Link l)
    {
        if (l == nullptr)
        {
            return 0;
        }
        else if (l->left == nullptr && l->right == nullptr)
        {
            return 1;
        }
        else
        {
            return (numHojas(l->left) + numHojas(l->right));
        }
    }

    int altura(Link l)
    {
        if (l == nullptr)
        {
            return 0;
        }
        else
        {
            return 1 + std::max(altura(l->left), altura(l->right));
        }
    }

    void frontera(Link l)
    {
        if (l == nullptr)
        {
            return;
        }
        else if (l->left == nullptr && l->right == nullptr)
        {
            std::cout << l->elem << " ";
        }
        else
        {
            frontera(l->left);
            frontera(l->right);
        }
    }
};

template <typename T>
inline myTree<T> leerArbolNew(T vacio)
{
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio)
    { // es un árbol vacío
        return {};
    }
    else
    { // leer recursivamente los hijos
        myTree<T> iz = leerArbolNew(vacio);
        myTree<T> dr = leerArbolNew(vacio);
        return {iz, raiz, dr};
    }
}

bool resuelveCaso()
{
    myTree<int> ar = leerArbolNew(-1);

    ar.fronteras();
    std::cout << "\n";
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
