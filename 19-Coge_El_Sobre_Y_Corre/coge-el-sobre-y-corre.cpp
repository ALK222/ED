// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <deque>

struct tElem
{
    int elem;
    int pos;
};

bool resuelveCaso()
{
    int sobres;
    int gente;
    int valor;

    std::deque<tElem> cola;
    std::deque<tElem> maxChanchullos;

    tElem max = {0, -1};

    std::cin >> sobres >> gente;

    if (sobres == 0 && gente == 0)
    {
        return false;
    }

    for (int i = 0; i < gente; ++i)
    {
        std::cin >> valor;
        if (valor > max.elem)
        {
            max = {valor, i};
        }
        cola.push_back({valor, i});
    }

    std::deque<tElem> aux = cola;

    int cont = 0;

    while (!aux.empty())
    {
        if (aux.back().elem > cont && aux.back().pos != max.pos)
        {
            cont = aux.back().elem;
            maxChanchullos.push_back(aux.back());
        }
        aux.pop_back();
    }
    std::cout << max.elem;

    if (gente < sobres)
    {
        std::cout << " ";
    }

    for (int i = gente; i < sobres; i++)
    {
        std::cin >> valor;

        if (!maxChanchullos.empty() && maxChanchullos.back().pos == cola.front().pos)
        {
            maxChanchullos.pop_back();
        }

        if (cola.front().elem == max.elem)
        {
            if (!maxChanchullos.empty())
            {
                max = maxChanchullos.back();
                maxChanchullos.pop_back();
            }
            else
            {
                max = {valor, i};
            }
        }

        cola.pop_front();

        if (valor > max.elem)
        {
            max = {valor, i};

            if (!maxChanchullos.empty())
            {
                maxChanchullos.clear();
            }
        }
        else
        {
            if (maxChanchullos.empty())
            {
                maxChanchullos.push_back({valor, i});
            }
            else
            {

                if (valor >= maxChanchullos.front().elem)
                {
                    while (!maxChanchullos.empty() && valor >= maxChanchullos.front().elem)
                    {
                        maxChanchullos.pop_front();
                    }
                }

                maxChanchullos.push_front({valor, i});
            }
        }

        cola.push_back({valor, i});

        std::cout << max.elem;

        if (i < sobres - 1)
        {
            std::cout << " ";
        }
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
