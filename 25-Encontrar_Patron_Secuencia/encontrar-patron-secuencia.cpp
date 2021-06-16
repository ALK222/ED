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
                return {true, inicio};
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
    int nElem1, nElem2;
    std::cin >> nElem1 >> nElem2;
    if (nElem1 == 0 && nElem2 == 0)
        return false;
    // Lectura delos datos
    std::list<int> lista1;
    for (int i = 0; i < nElem1; ++i)
    {
        int aux;
        std::cin >> aux;
        lista1.push_back(aux);
    }
    std::list<int> lista2;
    for (int i = 0; i < nElem2; ++i)
    {
        int aux;
        std::cin >> aux;
        lista2.push_back(aux);
    }
    // Elimina todas las apariciones de la lista2 en la lista 1
    // Utilizando la función Mysearch
    auto it1 = lista1.begin();
    while (it1 != lista1.end())
    {
        it1 = MySearch(it1, lista1.end(), lista2.begin(), lista2.end()).second;
        if (it1 != lista1.end())
        {
            for (int i = 0; i < lista2.size(); ++i)
            {
                it1 = lista1.erase(it1);
            }
        }
    }
    // Escribe la lista
    auto it = lista1.begin();
    if (it != lista1.end())
    {
        std::cout << *it;
        ++it;
    }
    for (; it != lista1.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return true;
}

int main()
{

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
    {
    } //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
