// Nombre del alumno: Alejandro Barrachina Argudo
// Usuario del juez de clase: A08
// Usuario del juez de examen que has utilizado hoy: A53

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

struct tSol
{
    int longitud;
    int maxLong;
};

tSol caminoPares(bintree<int> arbol)
{
    tSol sol;

    if (arbol.empty())
    {
        sol = {0, 0};
    }
    else
    {
        tSol solIzq = caminoPares(arbol.left());
        tSol solDer = caminoPares(arbol.right());

        sol.maxLong = solIzq.maxLong > solDer.maxLong ? solIzq.maxLong : solDer.maxLong;

        if (arbol.root() % 2 == 0)
        {
            if (solIzq.longitud + solDer.longitud + 1 > sol.maxLong)
            {
                sol.maxLong = solIzq.longitud + solDer.longitud + 1;
            }

            sol.longitud = solIzq.longitud > solDer.longitud ? solIzq.longitud + 1 : solDer.longitud + 1;
        }
        else
        {
            sol.longitud = 0;
        }
    }

    return sol;
}

void resuelveCaso()
{

    // C�digo del alumno
    bintree<int> bt = leerArbol(-1);

    std::cout << caminoPares(bt).maxLong << '\n';
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
