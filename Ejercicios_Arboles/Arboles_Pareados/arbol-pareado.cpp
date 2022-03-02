// Nombre del alumno: Alejandro Barrachina Argudo
// Usuario del juez de clase: A08
// Usuario del juez de examen que has utilizado hoy: A53

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

struct tSol
{
    bool pareado;
    int numPares;
    int altura;
};

template <class T>
class myTree : public bintree<T>
{
    using Link = typename bintree<T>::Link;

public:
    myTree<T>() : bintree<T>(){};
    myTree<T>(myTree const &l, T const &e, myTree const &r) : bintree<T>(l, e, r){};

    void pareados()
    {
        bool pareado = false;
        int paresDer = 0;
        int paresIzq = 0;

        if (this->raiz == nullptr)
        {
            pareado = true;
        }
        else
        {
            pareado = pares(this->raiz).pareado;
        }

        if (pareado)
        {
            std::cout << "SI\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

private:
    tSol pares(Link l)
    {
        if (l == nullptr)
        {
            return {true, 0, 0};
        }
        else
        {

            tSol resIzq = pares(l->left);
            tSol resDer = pares(l->right);

            if (l->elem % 2 == 0)
            {
                return {abs(resDer.numPares - resIzq.numPares) <= 1, resDer.numPares + resIzq.numPares + 1, 1 + std::max(resIzq.altura, resDer.altura)}; // si es par sumamos 1 al contador
            }
            else
            {
                return {abs(resDer.numPares - resIzq.numPares) <= 1, resDer.numPares + resIzq.numPares, std::max(resIzq.altura, resDer.altura)}; // si es par sumamos 1 al contador
            }
        }
    }
};

template <typename T>
inline myTree<T> leerArbolNew(T vacio)
{
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio)
    { // es un �rbol vac�o
        return {};
    }
    else
    { // leer recursivamente los hijos
        auto iz = leerArbolNew(vacio);
        auto dr = leerArbolNew(vacio);
        return {iz, raiz, dr};
    }
}

void resuelveCaso()
{

    // C�digo del alumno
    myTree<int> bt = leerArbolNew(-1);

    bt.pareados();
}

int main()
{
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos = 1;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
