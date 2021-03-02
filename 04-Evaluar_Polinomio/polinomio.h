#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <fstream>
#include <vector>

class polinomio
{
public:
    polinomio()
    {
    }

    int binarySearch(int ini, int fin, const std::pair<int, int> &mon)
    {
        if (ini == fin)
            return ini;
        else
        {
            int mitad = (ini + fin) / 2;
            if (pol[mitad].second > mon.second)
                return binarySearch(ini, mitad, mon);
            else if (pol[mitad].second < mon.second)
                return binarySearch(mitad + 1, fin, mon);
            else
            { //igual exponente, sumo coeficientes
                pol[mitad].first += mon.first;
                return -1;
            }
        }
    }

    void insert(int cociente, int grado)
    {
        if (cociente != 0 || grado != 0)
        {
            int pos = binarySearch(0, pol.size(), std::make_pair(cociente, grado));
            if (pos != -1)
            {
                pol.insert(pol.begin() + pos, std::make_pair(cociente, grado));
            }
        }
    }

    int calcular(int valor)
    {
        int resul = 0;
        int pow = 1;
        int pow_counter = 0;
        for (auto i : pol)
        {
            while (pow_counter < i.second)
            {
                pow *= valor;
                pow_counter++;
            }
            resul += i.first * pow;
        }
        return resul;
    }

private:
    std::vector<std::pair<int, int>> pol;
};

#endif
