// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"

template <class T>
class dimTree : public bintree<T>
{
    using Link = typename bintree<T>::Link;

public:
    dimTree() : bintree<T>() {}
    dimTree(dimTree<T> const &l, T const &e, dimTree<T> const &r) : bintree<T>(l, e, r) {}

    int dim()
    {
        int altura;
        return diametro(this->raiz, altura);
    }

private:
    int diametro(Link l, int &altura)
    {
        if (l == nullptr)
        {
            altura = 0;
            return 0;
        }
        else
        {
            int altIz, altDr;
            int dimIz = diametro(l->left, altIz);
            int dimDr = diametro(l->right, altDr);

            altura = 1 + std::max(altDr, altIz);

            return std::max(1 + altIz + altDr, std::max(dimDr, dimIz));
        }
    }
};

template <typename T>
inline dimTree<T> leerArbolNew(T vacio)
{
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio)
    { // es un árbol vacío
        return {};
    }
    else
    { // leer recursivamente los hijos
        dimTree<T> iz = leerArbolNew(vacio);
        dimTree<T> dr = leerArbolNew(vacio);
        return {iz, raiz, dr};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    dimTree<char> arbol = leerArbolNew('.');
    std::cout << arbol.dim() << std::endl;
}

int main()
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;

    for (int i = 0; i < numCasos; i++)
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
