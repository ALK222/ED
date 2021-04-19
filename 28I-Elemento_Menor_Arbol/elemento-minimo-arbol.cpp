// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"

template <class T>
class minTree : public bintree<T>
{
    using Link = typename bintree<T>::Link;

public:
    minTree() : bintree<T>() {}
    minTree(minTree<T> const &l, T const &e, minTree<T> const &r) : bintree<T>(l, e, r) {}

    void minimo()
    {
        std::cout << this->getMin(this->raiz) << "\n";
    }

private:
    T getMin(Link l)
    {

        if (l->left == nullptr && l->right == nullptr)
        {
            return l->elem;
        }
        else
        {
            T m = l->elem;
            if (l->left != nullptr)
            {
                T aux = getMin(l->left);
                m = std::min(aux, m);
            }
            if (l->right != nullptr)
            {
                T aux = getMin(l->right);
                m = std::min(aux, m);
            }

            return m;
        }
    }
};

template <typename T>
inline minTree<T> leerArbolNew(T vacio)
{
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio)
    { // es un árbol vacío
        return {};
    }
    else
    { // leer recursivamente los hijos
        minTree<T> iz = leerArbolNew(vacio);
        minTree<T> dr = leerArbolNew(vacio);
        return {iz, raiz, dr};
    }
}

bool resuelveCaso()
{
    char tipo;
    std::cin >> tipo;

    if (!std::cin)
    {
        return false;
    }

    if (tipo == 'N')
    {
        minTree<int> br = leerArbolNew(-1);
        br.minimo();
    }
    else if (tipo == 'P')
    {
        minTree<std::string> br = leerArbolNew(std::string("#"));
        br.minimo();
    }

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
