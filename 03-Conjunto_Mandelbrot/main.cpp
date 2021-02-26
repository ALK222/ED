// Nombre del alumno Alejandro Barrachina Argudo
// Usuario del Juez A08

#include <iostream>
#include <fstream>
#include <vector>
#include "complejo.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
	complejo c, aux;
	int i = 0;
	bool ok = true;

	std::cin >> c;
	aux = c;
	int n = c.iterNum();

	while (ok && i < n)
	{
		if (c % c > 2)
		{
			ok = false;
		}
		else
		{
			c = (c * c) + aux;
		}

		i++;
	}

	return ok;
}

int main()
{
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; ++i)
	{
		if (resuelveCaso())
		{
			std::cout << "SI\n";
		}
		else
		{
			std::cout << "NO\n";
		}
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
