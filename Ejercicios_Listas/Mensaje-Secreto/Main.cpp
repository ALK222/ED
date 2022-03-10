/*
NUMERO DE GRUPO:

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/


#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
#include "pila.h"
// Incluir otros TADs que se consideren necesarios,
// asi como el resto de definiciones auxiliares que
// se considere oportuno.

bool esVocal(const char& c)
{
	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
	{
		return true;
	}
	return false;
}

void invierteSecuenciasNoVocales(Lista<char>& mensaje) {
	// A IMPLEMENTAR
	if (!mensaje.esVacia())
	{
		Lista<char>::Iterator it = mensaje.begin();
		Pila<char> pila;

		while (it != mensaje.end())
		{
			if (!esVocal(it.elem()))
			{
				pila.apila(it.elem());
				it = mensaje.eliminar(it);
			}
			else
			{
				
				while (!pila.esVacia()) {				
					mensaje.insertar(pila.cima(), it);	
					pila.desapila();					
				}
				it.next();
			}
		}
		if (!pila.esVacia()) {
			while (!pila.esVacia()) {
				mensaje.insertar(pila.cima(), it);
				pila.desapila();
			}
		}
	}
}

// CODIGO ADICIONAL: NO MODIFICAR

  // Imprime la lista por la salida estandar,
  // tanto leída desde el principio hasta el final
  // como leída desde el final hasta el principio.
void imprime(Lista<char>& l) {
	l.imprime(cout);
	cout << "#";
	l.imprime_invertida(cout);
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();
}

// Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for (unsigned int i = 0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);
}

int main() {
	string linea;
	while (getline(cin, linea)) {
		Lista<char> mensaje;
		construyeMensaje(linea, mensaje);
		codifica(mensaje);
		imprime(mensaje);
	}
	return 0;
}
