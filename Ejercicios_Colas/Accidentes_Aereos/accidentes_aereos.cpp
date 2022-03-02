// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

typedef struct
{
    std::string date;
    int victims;
} tAccident;
bool resuelveCaso()
{
    int n;

    std::cin >> n;
    if (!std::cin)
    {
        return false;
    }

    std::stack<tAccident> pila;
    tAccident aux;

    for (int i = 0; i < n; i++)
    {
        std::cin >> aux.date >> aux.victims;

        while (!pila.empty() && pila.top().victims <= aux.victims)
        {
            pila.pop();
        }

        if (pila.empty())
        {
            std::cout << "NO HAY\n";
        }
        else
        {
            std::cout << pila.top().date << '\n';
        }

        pila.push(aux);
    }

    std::cout << "---\n";
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
