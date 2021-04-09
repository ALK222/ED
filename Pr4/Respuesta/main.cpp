/*
NUMERO DE GRUPO: 

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:
	Tomas Turbao
	Solomeo Paredes

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/
#include <iostream>
using namespace std;
#include "cola.h"
#include "dcola.h"
#include "pila.h"


bool palindroma(const Cola<char>& cola) {
	// A IMPLEMENTAR
	bool esPalindroma = true;

	Cola<char> original(cola);	//O(n)
	DCola<char> aux;

	while (!original.esVacia()) {
		aux.pon_ppio(original.primero());
		original.quita();
	}
	while (!aux.esVacia() && esPalindroma) {
		if (aux.primero() == aux.ultimo()) {
			aux.quita_ppio();
			if (!aux.esVacia()) {
				aux.quita_final();
			}
		}
		else {
			esPalindroma = false;
		}
	}
	return esPalindroma;
}	
	
	//SE PUEDE HACER CON PILA DE LA SIGUIENTE FORMA
	/*bool palindroma(const Cola<char>& cola) {
	// A IMPLEMENTAR
	bool esPalindroma = true;

	Cola<char> original(cola);	//O(n)
	Cola<char> aux(cola);
	Pila<char> pila;

	while (!original.esVacia()) {
		pila.apila(original.primero());
		original.quita();
	}
	while (!aux.esVacia() && esPalindroma) {
		if (aux.primero() == pila.cima()) {
			aux.quita();
			pila.desapila();
		}
		else {
			esPalindroma = false;
		}
	}
	return esPalindroma;
}	*/
	
	
// Codigo de lectura y ejecuci�n de caso: no modificar

bool lee_caso(Cola<char>& cola) {
	char ch;
	cin.get(ch);
	if (ch == '*') {
		return false;
	}
	else {
		while (ch != '\n') {
			if (ch != ' ')
				cola.pon(ch);
			cin.get(ch);
		}
		return true;
	}
}

int main() {
	Cola<char> cola;

	while (lee_caso(cola)) {
		bool es_palindroma = palindroma(cola);
		while (!cola.esVacia()) {
			cout << cola.primero();
			cola.quita();
		}
		cout << " = ";
		if (es_palindroma)
			cout << "SI\n";
		else
			cout << "NO\n";
	}
	return 0;
}

