// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <deque>
#include <stack>

bool esVocal(char c)
{

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;

    return false;
}

bool resuelveCaso()
{
    std::deque<char> cola1;
    std::deque<char> cola2;
    std::stack<char> pila;
    std::string frase;

    getline(std::cin, frase);

    if (!std::cin)
        return false;

    int i = 0;

    for (auto c : frase)
    {

        if (i % 2 == 0)
            cola1.push_back(c);

        else
            pila.push(c);

        i++;
    }

    while (!pila.empty())
    {
        cola2.push_back(pila.top());
        pila.pop();
    }

    while (!cola2.empty())
    {
        cola1.push_back(cola2.front());
        cola2.pop_front();
    }

    while (!cola1.empty())
    {

        if (!esVocal(cola1.front()))
        {
            pila.push(cola1.front());
            cola1.pop_front();
        }

        else
        {
            while (!pila.empty())
            {
                cola2.push_back(pila.top());
                pila.pop();
            }
            cola2.push_back(cola1.front());
            cola1.pop_front();
        }
    }

    while (!pila.empty())
    {
        cola2.push_back(pila.top());
        pila.pop();
    }

    for (int i = 0; i < cola2.size(); i++)
    {
        std::cout << cola2[i];
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
