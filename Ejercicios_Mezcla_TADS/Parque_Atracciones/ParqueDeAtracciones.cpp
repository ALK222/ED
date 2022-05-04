
#include "ParqueDeAtracciones.h"

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.
    coste constante: la creación de diccionarios y listas vacias es la misma en todos los casos
*/

ParqueDeAtracciones::ParqueDeAtracciones()
{
    // A IMPLEMENTAR
    colaAtracciones = Diccionario<std::string, Lista<std::string>>();
    visitantes = Diccionario<std::string, Diccionario<std::string, int>>();
    colaVisitante = Diccionario<std::string, std::string>();
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.
    coste lineal O(N), siendo n el número de claves "menores" en orden alfabético a la atracción a insertar.
*/
void ParqueDeAtracciones::an_atraccion(const string &nombre_atraccion)
{
    // A IMPLEMENTAR
    if (colaAtracciones.contiene(nombre_atraccion))
    {
        throw EAtraccionYaExiste();
    }

    colaAtracciones.inserta(nombre_atraccion, Lista<std::string>());
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.
    coste lineal O(N), siendo n el número de claves "menores" en orden alfabético al visitante a insertar.
*/
void ParqueDeAtracciones::an_ninio(const string &nombre_ninio)
{
    // A IMPLEMENTAR
    if (visitantes.contiene(nombre_ninio))
    {
        throw ENinioYaRegistrado();
    }

    visitantes.inserta(nombre_ninio, Diccionario<std::string, int>());
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
void ParqueDeAtracciones::poner_en_fila(const string &nombre_ninio, const string &nombre_atraccion)
{
    // A IMPLEMENTAR
    if (!visitantes.contiene(nombre_ninio) || !colaAtracciones.contiene(nombre_atraccion))
    {
        throw EAccesoAtraccion();
    }

    if (colaVisitante.contiene(nombre_ninio))
    {
        throw EAccesoAtraccion();
    }

    auto colaAtraccion = colaAtracciones.busca(nombre_atraccion);
    colaAtraccion.valor().pon_final(nombre_ninio);

    colaVisitante.inserta(nombre_ninio, nombre_atraccion);
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
void ParqueDeAtracciones::avanzar(const string &nombre_atraccion)
{
    // A IMPLEMENTAR
    if (!colaAtracciones.contiene(nombre_atraccion))
    {
        throw EAtraccionNoExiste();
    }

    auto listaAux = colaAtracciones.busca(nombre_atraccion);
    if (!listaAux.valor().esVacia()) // Comprobamos que la atracción tenga alguien esperando
    {
        // Quitamos de la cola
        std::string visitanteEnAtraccion = listaAux.valor().primero();
        listaAux.valor().quita_ppio();
        colaVisitante.borra(visitanteEnAtraccion);

        // Actualizamos las veces que el visitante se ha montado en la atracción
        auto atraccionesUsadas = visitantes.busca(visitanteEnAtraccion);

        if (atraccionesUsadas.valor().contiene(nombre_atraccion))
        {
            atraccionesUsadas.valor().busca(nombre_atraccion).valor() += 1;
        }
        else
        {
            atraccionesUsadas.valor().inserta(nombre_atraccion, 1);
        }
    }
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
Lista<string> ParqueDeAtracciones::atracciones_visitadas(const string &nombre_ninio) const
{
    // A IMPLEMENTAR
    if (!visitantes.contiene(nombre_ninio))
    {
        throw ENinioNoRegistrado();
    }

    auto atraccionesVisitante = visitantes.valorPara(nombre_ninio);

    auto atraccionesIt = atraccionesVisitante.begin();

    Lista<std::string> atraccionesVisitadas = Lista<std::string>();

    while (atraccionesIt != atraccionesVisitante.end())
    {
        atraccionesVisitadas.pon_final(atraccionesIt.clave());
        atraccionesIt.next();
    }

    return atraccionesVisitadas;
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
int ParqueDeAtracciones::numero_visitas(const string &nombre_ninio, const string &nombre_atraccion) const
{
    // A IMPLEMENTAR
    if (!visitantes.contiene(nombre_ninio) || !colaAtracciones.contiene(nombre_atraccion))
    {
        throw EConsultaNumViajes();
    }

    return visitantes.valorPara(nombre_ninio).contiene(nombre_atraccion) ? visitantes.valorPara(nombre_ninio).valorPara(nombre_atraccion) : 0;
}
