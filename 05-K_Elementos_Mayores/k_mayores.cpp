// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "set_eda.h" // Coso propietario de la Complutense que no puedo subir

template <class T>
class setMayores
{
public:
    void insert(T element)
    {
        if (serie.count(element) == 0)
        {
            serie.insert(element);
        }
    }

    void kMayores(int k)
    {
        set<T> mayores;
        int count = serie.size();
        for (auto i : serie)
        {
            if (count > k)
            {
                count--;
            }
            else
            {
                mayores.insert(i);
            }
        }

        for (auto j : mayores)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }

private:
    set<T> serie;
};

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
        setMayores<std::string> serie;
        int k;
        std::string palabra;
        //leemos el k
        std::cin >> k;
        std::cin >> palabra;
        while (palabra != "FIN")
        {
            serie.insert(palabra);
            std::cin >> palabra;
        }
        serie.kMayores(k);
    }
    else if (letra == 'N')
    {
        setMayores<int> serie;
        int k, n;

        //leemos el k
        std::cin >> k;
        std::cin >> n;
        while (n != -1)
        {
            serie.insert(n);
            std::cin >> n;
        }
        serie.kMayores(k);
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
