// Nombre del alumno: Alejandro Barrachina Argudo
// Usuario del juez de clase: A08
// Usuario del juez de examen que has utilizado hoy: A53

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

struct tSol
{
    int altura;
    bool completo;
    bool semicompleto;
};

tSol esCompleto(bintree<char> arbol)
{
    tSol sol;

    if (arbol.empty())
    {
        return {0, true, true};
    }
    else
    {
        tSol solIzq = esCompleto(arbol.left());
        tSol solDer = esCompleto(arbol.right());

        if (solIzq.completo && solDer.completo && solIzq.altura == solDer.altura)
        {
            return {solIzq.altura + 1, true, true};
        }
        else if (solIzq.semicompleto && solDer.completo && solIzq.altura == solDer.altura + 1)
        {
            return {solIzq.altura + 1, false, true};
        }
        else if (solIzq.completo && solDer.semicompleto && solIzq.altura == solDer.altura)
        {
            return {solIzq.altura + 1, false, true};
        }
        else
        {
            return {solIzq.altura, false, false};
        }
    }
}

void resuelveCaso()
{

    // C�digo del alumno
    bintree<char> bt = leerArbol('.');

    tSol solucion = esCompleto(bt);

    if (solucion.completo)
    {
        std::cout << "COMPLETO\n";
    }
    else if (solucion.semicompleto)
    {
        std::cout << "SEMICOMPLETO\n";
    }
    else
    {
        std::cout << "NADA\n";
    }
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
