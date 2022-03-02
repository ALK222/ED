// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "horas.h"
#include "pelicula.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    int numPeliculas;
    std::cin >> numPeliculas;

    if (numPeliculas == 0) {
        return false;
    }

    std::vector<pelicula> filmList(numPeliculas);

    for (int i = 0; i < numPeliculas; i++)
    {
        horas ini, dur;
        std::string tit = "";
        std::cin >> ini >> dur;
        std::getline(std::cin, tit);
        filmList[i] = pelicula(ini, dur, tit);
    }
    std::sort(filmList.begin(), filmList.end());

    for(pelicula film : filmList)
    {
        std::cout << film << "\n";
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


	while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
