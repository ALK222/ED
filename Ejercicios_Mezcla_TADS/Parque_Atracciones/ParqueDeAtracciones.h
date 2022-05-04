#ifndef _PARQUE_ATRACCIONES_H
#define _PARQUE_ATRACCIONES_H
#include <string>

#include "diccionario.h"
#include "lista.h"
// Realizar los 'include' adicionales
// que se estimen oportunos.

using namespace std;

class EAtraccionYaExiste
{
};

class ENinioYaRegistrado
{
};

class EAtraccionNoExiste
{
};

class ENinioNoRegistrado
{
};

class EAccesoAtraccion
{
};

class EConsultaNumViajes
{
};

class ParqueDeAtracciones
{
public:
    ParqueDeAtracciones();
    void an_atraccion(const string &nombre_atraccion);
    void an_ninio(const string &nombre_ninio);
    void poner_en_fila(const string &nombre_ninio, const string &nombre_atraccion);
    void avanzar(const string &nombre_atraccion);
    Lista<string> atracciones_visitadas(const string &nombre_ninio) const;
    int numero_visitas(const string &nombre_ninio, const string &nombre_atraccion) const;

private:
    // Definir la representación que se estime oportuna, así como declarar los métodos
    // auxiliares que se consideren oportunos (si se estima necesario).
    using visitante = std::string;
    using atraccion = std::string;
    Diccionario<atraccion, Lista<visitante>> colaAtracciones;
    Diccionario<visitante, Diccionario<atraccion, int>> visitantes;
    Diccionario<visitante, atraccion> colaVisitante;
};

#endif
