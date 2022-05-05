#ifndef _CARNET_POR_PUNTOS_H
#define _CARNET_POR_PUNTOS_H

#include "lista.h"
#include <string>
#include "diccionario.h"
using namespace std;

class EConductorDuplicado
{
};
class EConductorNoExiste
{
};
class EPuntosNoValidos
{
};

class CarnetPorPuntos
{
public:
	CarnetPorPuntos();
	void nuevo(const string &dni);
	void quitar(const string &dni, unsigned int puntos);
	void recuperar(const string &dni, unsigned int puntos);
	unsigned int consultar(const string &dni) const;
	unsigned int cuantos_con_puntos(unsigned int puntos) const;
	const Lista<string> &lista_por_puntos(unsigned int puntos) const;

private:
	// A COMPLETAR
	const static unsigned int MAX_PUNT = 15;
	const static unsigned int MIN_PUNT = 0;
	using conductor = string;
	using puntos = unsigned int;
	Diccionario<conductor, puntos> conductores;
	Lista<string> ordenPuntosObtenidos[MAX_PUNT + 1];
};

#endif
