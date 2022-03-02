/*
NUMERO DE GRUPO:

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/

using namespace std;

#ifndef _SECUENCIA_H_
#define _SECUENCIA_H_

/// Excepción de elemento inexistente
class ElementoInvalido {};


template<class T>
class Secuencia {
public:
	Secuencia() {
		// A IMPLEMENTAR
	}


	void pon(const T& e) {
		// A IMPLEMENTAR
	}

	const T& elem(int i) {
		// A IMPLEMENTAR
	}

	int num_elems() const {
		// A IMPLEMENTAR
	}

     // DEBEN INCLUIRSE E IMPLEMENTARSE 
	 // LAS OPERACIONES ADICIONALES
	 // NECESARIAS PARA GARANTIZAR EL CORRECTO
	 // FUNCIONAMIENTO DEL TAD


private:
  // INCLUIR DETALLES DE REPRESENTACION Y OPERACIONES AUXILIARES

};


#endif


