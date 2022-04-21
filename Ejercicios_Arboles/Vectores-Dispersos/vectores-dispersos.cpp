#include "lista.h"
#include "diccionario.h"
#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    int x;
    double val;
} tEntrada;

typedef Lista<tEntrada> tVector;

double producto_escalar(const tVector &u, const tVector &v)
{
    // A IMPLEMENTAR

    Diccionario<int, double> primero = Diccionario<int, double>();
    Diccionario<int, double> sol = Diccionario<int, double>();
    auto i = u.cbegin();

    while (i != u.cend())
    {
        primero.inserta(i.elem().x, i.elem().val);
        i.next();
    }

    auto j = v.cbegin();

    bool notZero = false;

    while (j != v.cend())
    {
        if (primero.contiene(j.elem().x))
        {
            notZero = true;
            sol.inserta(j.elem().x, primero.valorPara(j.elem().x) * j.elem().val);
            primero.borra(j.elem().x);
        }
        else
        {
            sol.inserta(j.elem().x, 0);
        }
        j.next();
    }

    auto dIt1 = primero.cbegin();

    while (dIt1 != primero.cend())
    {
        sol.inserta(dIt1.clave(), 0);
        dIt1.next();
    }

    if (notZero)
    {
        auto dIt = sol.cbegin();

        double suma = 0;

        while (dIt != sol.cend())
        {
            suma += dIt.valor();

            dIt.next();
        }

        return suma;
    }

    return 0;
}

bool leeVector(tVector &v)
{
    if (cin.peek() == '(')
    {
        char sep;
        cin >> sep;
        while (cin.peek() != ')')
        {
            tEntrada e;
            unsigned int i;
            double val;
            cin >> e.x >> sep >> e.val;
            if (cin.peek() != ')')
            {
                cin >> sep;
            }
            v.pon_final(e);
        }
        cin >> sep;
        return true;
    }
    else
        return false;
}
void saltaLinea()
{
    string s;
    getline(cin, s);
}

int main()
{
    bool fin = false;
    while (!fin)
    {
        tVector u;
        tVector v;
        if (leeVector(u))
        {
            leeVector(v);
            saltaLinea();
            cout << producto_escalar(u, v) << endl;
        }
        else
        {
            fin = true;
        }
    }
}
