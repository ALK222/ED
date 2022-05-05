#include "CarnetPorPuntos.h"
/*
nuevo 1234
nuevo 1234
consultar 1234
consultar 1235
nuevo 1235
consultar 1235
cuantos_con_puntos 15
cuantos_con_puntos 8
cuantos_con_puntos 16
cuantos_con_puntos 15
cuantos_con_puntos 14
lista_por_puntos 15
lista_por_puntos 16
recuperar 1234 1
cuantos_con_puntos 15
lista_por_puntos 15
quitar 1234 1
cuantos_con_puntos 15
cuantos_con_puntos 14
lista_por_puntos 15
lista_por_puntos 14
recuperar 1234 10
lista_por_puntos 15
recuperar 1456 5
quitar 1456 5
*/

/**
Implementa aquí los métodos de las clases adicionales
*/

CarnetPorPuntos::CarnetPorPuntos()
{
	conductores = Diccionario<string, unsigned int>();
}

/**
Debes completar la implementación de las operaciones de CarnetPorPuntos,
y justificar la complejidad de las mismas.
*/

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::nuevo(const string &dni)
{
	// A IMPLEMENTAR
	if (conductores.contiene(dni))
	{
		throw EConductorDuplicado();
	}

	conductores.inserta(dni, 15);

	ordenPuntosObtenidos[15].pon_ppio(dni);
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::quitar(const string &dni, unsigned int puntos)
{
	// A IMPLEMENTAR
	if (!conductores.contiene(dni))
	{
		throw EConductorNoExiste();
	}

	auto conductor = conductores.busca(dni);
	int puntosAnt = conductor.valor();

	int puntosAct = conductor.valor() - puntos;
	if (puntosAct < 0)
	{
		puntosAct = 0;
	}

	if (puntosAct != puntosAnt)
	{
		// Eliminar del listado del antiguo valor de puntos
		auto conductorEnLista = ordenPuntosObtenidos[conductor.valor()].begin();
		bool encontrado = false;
		while (conductorEnLista != ordenPuntosObtenidos[conductor.valor()].end() && !encontrado)
		{
			if (conductorEnLista.elem() == dni)
			{
				encontrado = true;
			}
			else
			{
				conductorEnLista.next();
			}
		}
		ordenPuntosObtenidos[conductor.valor()].eliminar(conductorEnLista);
		conductor.valor() = puntosAct;
		// poner al final del listado actual de puntos
		ordenPuntosObtenidos[conductor.valor()].pon_ppio(dni);
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::recuperar(const string &dni, unsigned int puntos)
{
	// A IMPLEMENTAR
	if (!conductores.contiene(dni))
	{
		throw EConductorNoExiste();
	}

	// buscamos al conductor
	auto conductor = conductores.busca(dni);
	int puntosAnt = conductor.valor();

	int puntosAct = conductor.valor() + puntos;
	if (puntosAct > 15)
	{
		puntosAct = 15;
	}

	if (puntosAct != puntosAnt)
	{
		// Eliminar del listado del antiguo valor de puntos
		auto conductorEnLista = ordenPuntosObtenidos[conductor.valor()].begin();
		bool encontrado = false;
		while (conductorEnLista != ordenPuntosObtenidos[conductor.valor()].end() && !encontrado)
		{
			if (conductorEnLista.elem() == dni)
			{
				encontrado = true;
			}
			else
			{
				conductorEnLista.next();
			}
		}
		ordenPuntosObtenidos[conductor.valor()].eliminar(conductorEnLista);
		conductor.valor() = puntosAct;
		// poner al final del listado actual de puntos
		ordenPuntosObtenidos[conductor.valor()].pon_ppio(dni);
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
unsigned int CarnetPorPuntos::consultar(const string &dni) const
{
	// A IMPLEMENTAR
	if (!conductores.contiene(dni))
	{
		throw EConductorNoExiste();
	}
	unsigned int puntos = conductores.cbusca(dni).valor();
	return puntos;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
unsigned int CarnetPorPuntos::cuantos_con_puntos(unsigned int puntos) const
{
	// A IMPLEMENTAR

	if (puntos < 0 || puntos > 15)
	{
		throw EPuntosNoValidos();
	}

	auto conductoresIt = conductores.cbegin();

	unsigned int total = 0;

	while (conductoresIt != conductores.cend())
	{
		if (conductoresIt.valor() == puntos)
		{
			total++;
		}

		conductoresIt.next();
	}

	return total;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
const Lista<string> &CarnetPorPuntos::lista_por_puntos(unsigned int puntos) const
{
	// A IMPLEMENTAR
	if (puntos < 0 || puntos > 15)
	{
		throw EPuntosNoValidos();
	}

	return ordenPuntosObtenidos[puntos];
}
