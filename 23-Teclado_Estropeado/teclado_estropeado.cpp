// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>

bool resuelveCaso()
{
    std::string entrada;
    getline(std::cin, entrada);

    if (!std::cin)
    {
        return false;
    }

    std::list<char> fraseFinal;
    auto cursor = fraseFinal.begin();

    for (auto a : entrada)
    {
        switch (a)
        {
        case '+':
            cursor = fraseFinal.end();
            break;
        case '-':
            cursor = fraseFinal.begin();
            break;
        case '*':
            if (!fraseFinal.empty() && cursor != fraseFinal.end())
            {
                cursor++;
            }
            break;
        case '3':
            if (!fraseFinal.empty() && cursor != fraseFinal.end())
            {
                fraseFinal.erase(cursor++);
            }
            break;
        default:
            cursor = fraseFinal.insert(cursor, a);
            cursor++;
            break;
        }
    }

    for (auto a : fraseFinal)
    {
        std::cout << a;
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
