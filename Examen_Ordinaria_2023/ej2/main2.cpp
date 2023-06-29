/**
  NOMBRE Y APELLIDOS:	Rodrigo Sosa Saez
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/


#include "Arbin.h"
#include <iostream>
#include <string>
using namespace std;

void es_rebuscado_aux(const Arbin<int>& a, bool& resul, int& min) {
	/*
		Un árbol de enteros es rebuscado cuando,
			A) es vacío
			B) bien no es vacío y cumple las siguientes condiciones:
				1. El mínimo de todos sus valores ocurre una única vez en el árbol.
				2. Tanto el hijo izquierdo como el hijo derecho son, a su vez, rebuscados.
	*/
	if (resul) {												//Si es rebuscado
		if (!a.hijoIz().esVacio() && a.hijoDer().esVacio()) {		//Si tiene hijo izquierdo
			int izq = a.hijoIz().raiz();								//El minimo del subarbol izquierdo es el valor del hijo izquierdo del nodo
			es_rebuscado_aux(a.hijoIz(), resul, izq);					//Comprobamos el subarbol izquierdo
			if (resul) {												//Si el subarbol es rebuscado
				if (izq < min) {											//Si el minimo del subarbol es menor que el minimo del arbol
					min = izq;													//Actualizamos el minimo del arbol
				}
				if (izq == min) {											//Si el minimo del subarbol es igual que el minimo del arbol
					resul = false;												//Ya no es rebuscado
				}
			}
		}
		if (a.hijoIz().esVacio() && !a.hijoDer().esVacio()) {		//Si tiene hijo derecho
			int der = a.hijoDer().raiz();								//El minimo del subarbol derecho es el valor del hijo derecho del nodo
			es_rebuscado_aux(a.hijoDer(), resul, der);					//Comprobamos el subarbol derecho
			if (resul) {												//Si el subarbol es rebuscado
				if (der < min) {											//Si el minimo del subarbol es menor que el minimo del arbol
					min = der;													//Actualizamos el minimo del arbol
				}
				if (der == min) {											//Si el minimo del subarbol es igual que el minimo del arbol
					resul = false;												//Ya no es rebuscado
				}
			}
		}
		if (!a.hijoIz().esVacio() && !a.hijoDer().esVacio()) {		//Si tiene hijos izquierdo y derecho
			int izq = a.hijoIz().raiz();								//El minimo del subarbol izquerdo es el valor del hijo izquierdo del nodo
			int der = a.hijoDer().raiz();								//El minimo del subarbol derecho es el valor del hijo derecho del nodo
			es_rebuscado_aux(a.hijoIz(), resul, izq);					//Comprobamos el hijo izquierdo
			es_rebuscado_aux(a.hijoDer(), resul, der);					//Comprobamos el hijo derecho (si el izquierdo no es rebuscado, no comprobara dentro)
			if (resul) {												//Si los dos son rebuscados
				if (izq < der) {											//Si el minimo izquierdo es menor que el minimo derecho
					if (izq == min) {											//Si el minimo del subarbol izquierdo es igual que el minimo del arbol
						resul = false;												//Ya no es rebuscado
					}
					if (izq < min) {											//Si el minimo del subarbol izquierdo es menor que el minimo del arbol
						min = izq;													//Actualizamos el minimo del arbol
					}
				}
				else if (izq == der) {										//Si los minimos izquierdo y derecho son iguales
					if (izq <= min) {											//Si son menores o iguales que el minimo del arbol
						resul = false;												//Ya no es rebuscado
					}
				}
				else {/*(izq > der)*/										//Si el minimo izquierdo es mayor que el minimo derecho
					if (der == min) {											//Si el minimo del subarbol derecho es igual que el minimo del arbol
						resul = false;												//Ya no es rebuscado
					}
					if (der < min) {											//Si el minimo del subarbol derecho es menor que el minimo del arbol
						min = der;													//Actualizamos el minimo del arbol
					}
				}
			}
		}
	}
}
/*
*  COMPLEJIDAD: Determina justificadamente la complejidad 
*	O(n), siendo n el numero de nodos del arbol,
*	ya que recorremos todos los nodos del arbol al completo
*	y las operaciones por cada nodo son O(1)
*/
bool es_rebuscado(const Arbin<int>& a) {
	 // A IMPLEMENTAR

	if (a.esVacio()) {				//Si el arbol es vacio
		return true;					//Es rebuscado
	}
	bool ok = true;					//Bool de control
	int min = a.raiz();				//El valor minimo es la raiz del arbol (de momento)
	es_rebuscado_aux(a, ok, min);	//Llamamos a la funcion auxiliar
	return ok;						//Devolvemos el arbol de control
}


/*
*  NO MODIFICAR EL CODIGO QUE SIGUE
*
*/

Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
  		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

void muestra_solucion(bool rebuscado) {
  if (rebuscado) {
	 cout << "SI" << endl; 
  }	
  else {
	 cout << "NO" << endl; 
  }
}

int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		Arbin<int> a = lee_arbol(cin);
		muestra_solucion(es_rebuscado(a));
		string resto_linea;
		getline(cin, resto_linea);
	}
    return 0;       
}