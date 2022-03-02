// Nombre del alumno: Alejandro Barrachina Argudo
// Usuario del juez de clase: A08
// Usuario del juez de examen que has utilizado hoy: A53

#include <iostream>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

// C�digo del alumno
/*
*COSTE:
* C_1 = Coste de inicio y fin: declaraci�n de variables y veredicto sobre si es pareado o no
* C_2 = Coste de la funci�n pares
*
* En el mejor caso el arbol es vacio, por lo que no entra a la funcion pares y su coste seria 1.
*
* En el peor caso el arbol tiene n nodos: el coste de C_2 se produce por cada nodo del arbol
*
* Lim n-> infinito C_1 + nC_2 = C_2 => Coste lineal en cuanto al numero de nodos
*
*/

struct tSol
{
    bool pareado;
    int numPares;
    int altura;
};

tSol pares(bintree<int> bt)
{
    if (bt.empty())
    {
        return {true, 0, 0};
    }
    else
    {

        tSol resIzq = pares(bt.left());
        tSol resDer = pares(bt.right());

        if (bt.root() % 2 == 0)
        {
            return {abs(resDer.numPares - resIzq.numPares) <= 1, resDer.numPares + resIzq.numPares + 1, 1 + std::max(resIzq.altura, resDer.altura)}; // si es par sumamos 1 al contador
        }
        else
        {
            return {abs(resDer.numPares - resIzq.numPares) <= 1, resDer.numPares + resIzq.numPares, std::max(resIzq.altura, resDer.altura)}; // si es par sumamos 1 al contador
        }
    }
}

void pareados()
{
    bintree<int> bt = leerArbol(-1);
    bool pareado = false;

    if (bt.empty())
    {
        pareado = true;
    }
    else
    {
        pareado = pares(bt).pareado;
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

void resuelveCaso()
{

    // C�digo del alumno

    pareados();
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
