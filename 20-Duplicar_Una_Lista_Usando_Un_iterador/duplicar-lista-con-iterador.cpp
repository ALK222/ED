// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <iterator>

template <class T>
std::list<T> duplicar(std::list<T> list)
{
    std::list<T> aux;
    for (const auto it : list)
    {
        aux.push_back(it);
        aux.push_back(it);
    }

    return aux;
}

template <class T>
void print(std::list<T> list)
{
    std::string aux;

    for (const auto it : list)
    {
        std::cout << it << " ";
    }
    std::cout << "\n";
}

bool resuelveCaso()
{
    int n;
    std::cin >> n;
    if (!std::cin)
    {
        return false;
    }

    std::list<int> lista;
    while (n != 0)
    {
        lista.push_back(n);
        std::cin >> n;
    }

    std::list<int> aux = duplicar(lista);

    print(aux);

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
