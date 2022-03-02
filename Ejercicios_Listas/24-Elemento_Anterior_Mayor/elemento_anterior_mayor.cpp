// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

struct tSol
{
    int numero;
    int menores;
};

bool resuelveCaso()
{
    int totalCasos;

    std::cin >> totalCasos;

    if (totalCasos == 0)
    {
        return false;
    }

    std::stack<tSol> totalNumeros;

    int numero;
    int numerosMenores = 0;
    int mayorIntervalo = 0;

    for (int i = 0; i < totalCasos; i++)
    {
        tSol numeroAnterior = {0, 0};
        std::cin >> numero;
        while (!totalNumeros.empty() && totalNumeros.top().numero <= numero)
        {
            numeroAnterior = totalNumeros.top();
            totalNumeros.pop();
            numerosMenores += numeroAnterior.menores + 1;
        }

        std::cout << numerosMenores << ' ';

        tSol nuevoElemento = {numero, numerosMenores};
        totalNumeros.push(nuevoElemento);
        numerosMenores = 0;
    }

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

    while (resuelveCaso())
        ;

        // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
