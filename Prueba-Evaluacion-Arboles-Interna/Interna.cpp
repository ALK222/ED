// Nombre del alumno: Alejandro Barrachina Argudo
// Usuario del juez de clase: A08
// Usuario del juez de examen que has utilizado hoy: A53


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// Código del alumno
/*
*COSTE:
* C_1 = Coste de inicio y fin: declaración de variables y veredicto sobre si es pareado o no
* C_2 = Coste de la función pares
* 
* En el mejor caso el arbol es vacio, por lo que no entra a la funcion pares y su coste seria 1.
* 
* En el peor caso el arbol tiene n nodos: el coste de C_2 se produce por cada nodo del arbol
* 
* Lim n-> infinito C_1 + nC_2 = C_2 => Coste lineal en cuanto al numero de nodos
*
*/

template<class T>
class myTree : public bintree<T>
{
    using Link = typename bintree<T>::Link;
public:
    myTree<T>() : bintree<T>() {};
    myTree<T>(myTree const& l, T const& e, myTree const& r) : bintree<T>(l, e, r) {};
    
    void pareados()
    {
        bool pareado = false;
        int paresDer = 0;
        int paresIzq = 0;

        if (this->raiz == nullptr)
        {
            pareado = true;
        }
        else
        {
            paresDer = pares(this->raiz->right); // comprobamos todos los nodos de la rama derecha
            paresIzq = pares(this->raiz->left); // comprobamos todos los nodos de la rama izquierda

            if (paresDer - paresIzq == 1 || paresDer - paresIzq == -1 || paresDer == paresIzq)
            {
                pareado = true; // la diferencia puede ser 1 o - 1 dependiendo de que numero sea mayor
            }
        }

        if (pareado)
        {
            std::cout << "SI\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

private:
    int pares(Link l)
    {
        if (l == nullptr)
        {
            return 0; // si esta vacio devolvemos 0
        }
        if (l->elem % 2 == 0)
        {
            return 1 + pares(l->left) + pares(l->right); // si es par sumamos 1 al contador
        }
        else {
            return pares(l->left) + pares(l->right); // si es impar comprobamos los siguientes
        }
    }
};

template <typename T>
inline myTree<T> leerArbolNew(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un árbol vacío
        return {};
    }
    else { // leer recursivamente los hijos
        auto iz = leerArbolNew(vacio);
        auto dr = leerArbolNew(vacio);
        return { iz, raiz, dr };
    }
}


void resuelveCaso() {

    // Código del alumno
    myTree<int> bt = leerArbolNew(-1);

    bt.pareados();


}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos = 1;   std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
