/**
  NOMBRE Y APELLIDOS:	Rodrigo Sosa Saez
  USUARIO DE DOMJUDGE USADO EN EL EXAMEN:
*/

#include "biblioteca.h"
#include <iostream>
using namespace std;

/*
AVISO
En el ultimo caso de prueba, la ultima linea, la salida no corresponde con lo que tendria que salir,
pero el resto de casos de prueba y el resto de lineas del ultimo caso de prueba van bien
*/

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
	0(1): Orden constante al ser operacion generadora
*/
Biblioteca::Biblioteca() {
	// A IMPLEMENTAR

}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
	O(log n), siendo n el numero de nodos del diccionario
	Este coste se debe al coste de las operaciones inserta y contiene en diccionarios de arboles de busqueda
*/
void Biblioteca::annadir_libro(tSignatura signatura, tNumEjemplares num_ejemplares) {
	// A IMPLEMENTAR
	if (_libros.contiene(signatura)) {					//Si el libro ya existe
		throw ELibroExistente();							//Excepcion
	}
	_libros.inserta(signatura, num_ejemplares);			//Anadimos el libro a la lista de libros
	_esperando.inserta(signatura, Lista<tCodigo>());	//Anadimos el libro a la lista de espera
}
 

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
	O(log n), siendo n el numero de nodos del diccionario
	Este coste se debe a las operacion que se usa: 
	inserta, que tiene coste (O(log n)) en diccionarios de arboles de busqueda
*/
void Biblioteca::annadir_socio(tCodigo id, tNombre nombre) {
	// A IMPLEMENTAR
	if (_socios.contiene(id)) {									//Si ya existe el socio
		throw ESocioExistente();									//Excepcion
	}
	_socios.inserta(id, nombre);								//Anadimos el socio a la lista
	_prestados.inserta(id, Diccionario<tSignatura, tFecha>());	//Anadimos el socio a la lista de prestamos
}

/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
	O(n log n), siendo n el numero de nodos del diccionario
	Este coste se debe a las operaciones que se pueden usar en cada nodo: 
	contiene, valorPara o inserta, que tienen coste (O(log n)) en diccionarios de arboles de busqueda

*/
unsigned int Biblioteca::prestar(tSignatura signatura, tCodigo id, tFecha fecha) {
	// A IMPLEMENTAR

	if (!_libros.contiene(signatura) || !_socios.contiene(id)) {						//Si n hay socio o libro
		throw EPrestamoNoAdmitido();														//Excepcion
	}
	if (_prestados.valorPara(id).contiene(signatura)) {									//Si en la lista de prestamos del socio ya esta libro
		return 0;																			//Devolvemos 0 (no se hace el prestamo)
	}
	if (!_prestados.valorPara(id).contiene(signatura)) {								//Si en la lista de socios no esta el libro
		if (_libros.valorPara(signatura) > 0) {												//Si quedan ejemplares
			Diccionario<tSignatura, tFecha> auxLibros = _prestados.valorPara(id);				//Sacamos la lista de prestamos del socio
			auxLibros.inserta(signatura, fecha);												//Ponemos el libro con la fecha de devolucion
			_libros.inserta(signatura, _libros.valorPara(signatura) - 1);						//Indicamos que hay un ejemplar menos
			_prestados.inserta(id,auxLibros);													//Actualizamos la lista de prestamos
			return 1;																			//Devolvemos 1 (prestamo realizado)
		}
		else {																				//Si no quedan ejemplares
			Lista<tCodigo> auxLectores = _esperando.valorPara(signatura);						//Sacamos la lista de espera del libro
			auxLectores.pon_final(id);															//Ponemos al socio al final de esta
			_esperando.inserta(signatura, auxLectores);											//Actualizamos la lista de espera
			return 2;																			//Devolvemos 2 (en espera)
		}
	}
}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
	O(log n), siendo n el numero de nodos del diccionario
	Este coste se deben a las operaciones que se usan: 
	valorPara o contiene, que tienen coste (O(log n)) en diccionarios de arboles de busqueda
	Las otras operaciones tienen coste O(1)
*/
Codigo_y_Nombre Biblioteca::primeroEnEspera(tSignatura signatura) const {		
	// A IMPLEMENTAR
	if (!_libros.contiene(signatura)) {									//Si no existe el libro
		throw ELibroInexistente();											//Excepcion
	}
	Lista<tCodigo> enEspera = _esperando.valorPara(signatura);			//Sacamos la lista de espera del libro
	if (enEspera.esVacia()) {											//Si la lista esta vacia
		throw ESinEsperas();												//Excepcion
	}
	Codigo_y_Nombre resul;												//Creamos el resul
	auto it = enEspera.cbegin();										//Nos ponemos en el principio de la lista
	resul.id = it.elem();												//Sacamos su codigo
	resul.n = _socios.valorPara(it.elem());							//Sacamos su nombre de la lista de socios
	return resul;														//Devolvemos resul
}


/**
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
	O(n), siendo n el numero de nodos del diccionario
	Este coste se debe a que iteramos, en el peor de los casos, sobre todos los nodos del diccionario de arbol de busqueda y
	en cada iteracion utilizamos operaciones con coste O(1)
	Tambien usamos la funcion valorPara, que tiene coste O(log n)
*/
Lista<Signatura_y_Fecha> Biblioteca::prestados(tCodigo id) const {
	// A IMPLEMENTAR
	if (!_socios.contiene(id)) {										//Si no existe el socio
		throw ESocioInexistente();											//Excepcion
	}
	Lista<Signatura_y_Fecha> resul;										//Creamos la lista resul
	Signatura_y_Fecha elem;												//Creamos una variable elem para la lista
	Diccionario<tSignatura, tFecha> aux = _prestados.valorPara(id);		//Sacamos la lista de prestamos del socio
	if (!aux.esVacio()) {												//Si la lista no esta vacia	(se puede devolver una lista vacia)
		auto it = aux.cbegin();												//Iteramos sobre la lista de prestamos del socio
		while (it != aux.cend()) {											//Mientras queden libros en la lista de prestamos
			elem.signatura = it.clave();										//Sacamos su signatura
			elem.fecha = it.valor();											//Sacamos su fecha
			if (resul.esVacia()) {											//Si la lista resul esta vacia
				resul.pon_ppio(elem);											//Lo ponemos al principio
			}
			else {															//Si no esta vacia
				if (resul.primero().signatura > elem.signatura) {				//Si la signatura es menor al primer elemento de la lista
					resul.pon_ppio(elem);											//Lo ponemos al inicio
				}
				if (resul.ultimo().signatura < elem.signatura) {				//Si la signatura es mayor al ultimo elemento de la lista
					resul.pon_final(elem);											//Lo ponemos al final
				}
			}
			it.next();														//Pasamos al siguiente elemento de la lista de prestamos
		}
	}
	return resul;														//Devolvemos la lista
}


/*
 COMPLEJIDAD: Determina y justifica aqu� la complejidad de la operaci�n
	O(log n), siendo n los nodos del diccionario prestados
	Este coste se debe a las operaciones contiene, valor para e inserta, que tienen coste O(log n) en diccionarios de arboles de busqueda,
	mientras que esVacia tiene coste O(1)
	Las operaciones relativas a la lista (esVacia y quita_ppio) son de orden O(1)
*/
bool Biblioteca::devolver(tSignatura signatura, tCodigo id, tFecha fecha) {
    // A IMPLEMENTAR
	if (!_libros.contiene(signatura) || !_socios.contiene(id)) {									//Si no existe el libro o el socio
		throw EDevolucionNoAdmitida();																	//Excepcion
	}
	Lista<tCodigo> espera = _esperando.valorPara(signatura);										//Sacamos la lista de espera del libro
	Diccionario<tSignatura, tFecha> prestamos = _prestados.valorPara(id);							//Sacamos la lista de libros del socio
	if (!prestamos.contiene(signatura)) {															//Si el socio no tiene el libro
		return false;																					//Devolvemos false
	}
	else {																							//Si el socio tiene el libro
		prestamos.borra(signatura);																		//Borramos el libro de los prestamos
		if (!espera.esVacia()) {																		//Si la lista de espera de libro tiene algun socio
			Diccionario<tSignatura, tFecha> aux = _prestados.valorPara(espera.primero());					//Sacamos la lista de prestamos del socio en espera
			aux.inserta(signatura, fecha);																	//La actualizamos
			espera.quita_ppio();																			//Quitamos al socio de la lista de espera
		}
		else {																							//Si la lista de espera del libre esta vacia
			_libros.inserta(signatura, _libros.valorPara(signatura) + 1);									//Anadimos el ejemlar a la lista de socios
		}
		return true;																					//Devolvemos true
	}
}


