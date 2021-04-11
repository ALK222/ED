// IMPORTANTE:
// Nombre del alumno: Alejandro Barrachina Argudo
// Usuario del juez de clase: A08
// Usuario que se ha utilizado en esta prueba: A03

#include <iostream>
#include <fstream>
#include <stack>
#include <list>

// Explicaci�n de la soluci�n empleada

/*
* VARIABLES:
* nElem <int>: numero de elementos a seleccionar
* pila <stack<int>>: pila donde guardamos los elementos a comprobar
* cant <list<int>>: lista donde guardamos los resultados para cada numero
* 
* FUNCIONAMIENTO:
* Despues de seleccionar todos los numeros comprobamos cuanto tarda en haber uno mayor.
* Para esto hacemos el siguiente procedimiento nElem veces:
* -Miramos el primer elemento de la pila.
* -Lo eliminamos y copiamos la pila a una auxilar.
* -Comprobamos si el top de la auxiliar es mayor que el numero ya guardado.
* -Si es mayor, ponemos la cantidad de numeros menores hasta entonces en cant.
* Si es menor, seguimos comprobando.
*
*/

// Coste de la soluci�n
/*
* C_0 = Coste de inicio y fin
* C_1 = Coste bucle lectura
* C_2 = Coste for comprobacion
* C_3 = Coste while comprobacion
* 
* En el mejor de los casos la entrada solo tiene 1 elemento y el en la comprobaci�n solo se ejecuta el for,
al while no se entrar�a
*
* En el peor de los casos hay nElem.
* En ese caso: lim_{n -> infinito} C_{0} + nC_{1} + (nC_{2} * (n-1)C_{3}) =
 = lim_{n -> infinito} C_{0} + nC_{1} + n^{2}C_{2}C_{3} - nC_{2}C_{3} =
 = C_{1} - C_{2}C_{3} + nC_{2}C_{3}
* Sacamos un coste O(n)
*/

template <class T>
void print(std::list<T> lista)
{

    for (auto a : lista)
    {
        std::cout << a << " ";
    }
    std::cout << "\n";
}

bool resuelveCaso()
{
    int nElem;
    std::cin >> nElem;
    if (nElem == 0)
        return false;

    // A completar por el alumno

    std::stack<int> pila;
    std::list<int> cant;
    for (int i = 0; i < nElem; ++i)
    {
        int aux;
        std::cin >> aux;
        pila.push(aux);
    }

    for (int i = 0; i < nElem; ++i)
    {
        int comp = pila.top();
        pila.pop();
        std::stack<int> aux;
        int cantidad = 0;
        while (!aux.empty() && comp > aux.top())
        {
            aux.pop();
            cantidad++;
        }
        cant.push_front(cantidad);
    }

    print(cant);

    return true;
}

int main()
{

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
    {
    } //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
