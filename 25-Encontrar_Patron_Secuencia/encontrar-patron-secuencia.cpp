// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <string>
#include <list>

/**
 * @param ini1 iterador al principio de la secuencia en la que debemos buscar 
 * @param fin1 iterador al final de la secuencia en la que se debe buscar
 * @param ini2 iterador al principio de la secuencia que queremos buscar
 * @param fin2 iterador al final de la secuencia que queremos buscar
*/
std::pair<bool, std::list<int>::iterator> MySearch(std::list<int>::iterator const &ini1, std::list<int>::iterator const &fin1, std::list<int>::iterator const &ini2, std::list<int>::iterator const &fin2)
{
    auto inicio = ini1;
    if (ini2 == fin2)
    {
        return {false, ini1};
    }
    while (inicio != fin1)
    {
        auto it1 = inicio;
        auto it2 = ini2;

        while (*it1 == *it2)
        {

            ++it1;
            ++it2;
            if (it2 == fin2)
            {
                return {true, it1};
            }

            if (it1 == fin1)
            {
                return {false, fin1};
            }
        }
        ++inicio;
    }

    return {false, fin1};
}

bool resuelveCaso()
{
    int sizeFirstSecuence;
    int sizeSecondSecuence;

    std::cin >> sizeFirstSecuence >> sizeSecondSecuence;

    if (sizeFirstSecuence == 0 && sizeSecondSecuence == 0)
    {
        return false;
    }

    std::list<int> lista1;
    std::list<int> lista2;

    for (int i = 0; i < sizeFirstSecuence; ++i)
    {
        int num;
        std::cin >> num;
        lista1.push_back(num);
    }
    for (int i = 0; i < sizeSecondSecuence; ++i)
    {
        int num;
        std::cin >> num;
        lista2.push_back(num);
    }

    std::pair<bool, std::list<int>::iterator> it = MySearch(lista1.begin(), lista1.end(), lista2.begin(), lista2.end());
    while (!lista1.empty() && it.first)
    {

        auto it2 = it.second;
        for (int i = 0; i < sizeSecondSecuence; i++)
        {
            --it2;
        }

        lista1.erase(it2, it.second);
        if (!lista1.empty())
        {
            it = MySearch(lista1.begin(), lista1.end(), lista2.begin(), lista2.end());
        }
    }

    for (auto i : lista1)
    {
        std::cout << i << " ";
    }

    std::cout << '\n';

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
