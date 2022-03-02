// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "conjunto.h" // Coso propietario de la Complutense que no puedo subir

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    char letra;
    //leemos si es P o N
    std::cin >> letra;

    if (!std::cin) // fin de la entrada
        return false;

    if (letra == 'P')
    {

        int k;
        set<std::string> serie;
        std::string palabra;
        //leemos el k
        std::cin >> k;
        std::cin >> palabra;
        while (palabra != "FIN")
        {
            serie.insert(palabra);
            std::cin >> palabra;
            if (serie.size() > k)
            {
                serie.borrarMenor();
            }
        }

        serie.print_menores();
    }
    else if (letra == 'N')
    {
        set<int> serie;
        int k, n;

        //leemos el k
        std::cin >> k;
        std::cin >> n;
        while (n != -1)
        {
            serie.insert(n);
            std::cin >> n;
            if (serie.size() > k)
            {
                serie.borrarMenor();
            }
        }

        serie.print_menores();
    }

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
