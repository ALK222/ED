#include <iostream>
#include "Cola.h"
using namespace std;

unsigned int escoge(Cola<int> &colaAlumnos, const int &salto, int total)
{
    int n = 1;
    unsigned int seleccionado = colaAlumnos.primero();

    while (total > 1) // Solo queda 1 alumno
    {
        seleccionado = colaAlumnos.primero();
        colaAlumnos.quita();

        if (n % salto != 0) // Si no hay que "salvarlo" lo volvemos a meter
        {
            colaAlumnos.pon(seleccionado);
        }
        else
        {
            total--; // Si está salvado tenemos un alumno menos
        }

        ++n;
    }

    return colaAlumnos.primero();
}

unsigned int afortunado(unsigned int n, unsigned int m)
{ // n>=1  m>=2
    // A IMPLEMENTAR
    Cola<int> colaAlumnos;

    if (n == 0 && m == 0)
    {
        return false;
    }

    for (int i = 1; i < n + 1; i++)
    {
        colaAlumnos.pon(i);
    }

    return escoge(colaAlumnos, m, n);
}

int main()
{
    int n, m;
    while ((cin >> n))
    {
        cin >> m;
        cout << afortunado(n, m) << endl;
    }
    return 0;
}
