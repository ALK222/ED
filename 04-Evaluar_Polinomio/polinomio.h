#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

class polinomio
{
public:
    polinomio()
    {
        for (int i = 0; i < 9; ++i)
        {
            pol.push_back(0);
        }
    }

    void insert(int cociente, int grado)
    {
        if (cociente != 0 || grado != 0)
        {
            pol[grado] = cociente;
        }
    }

    int calcular(int valor)
    {
        int result = pol[0];

        for (int i = 1; i < pol.size(); ++i)
        {
            result += pol[i] * pow(valor, i);
        }

        return result;
    }

private:
    std::vector<int> pol;
};

#endif
