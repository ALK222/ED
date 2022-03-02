// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

bool resuelveCaso()
{
    std::queue<int> positivos;
    std::stack<int> negativos;
    std::queue<int> final;

    int num;

    std::cin >> num;

    if (num == 0)
    {
        return false;
    }

    for (int i = 0; i < num; ++i)
    {
        int aux;
        std::cin >> aux;

        aux > 0 ? positivos.push(aux) : negativos.push(aux);
    }

    while (!negativos.empty())
    {
        final.push(negativos.top());
        negativos.pop();
    }

    while (!positivos.empty())
    {
        final.push(positivos.front());
        positivos.pop();
    }

    while (!final.empty())
    {
        std::cout << final.front() << " ";
        final.pop();
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
