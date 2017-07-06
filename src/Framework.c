
/**
 * @file Framework.c
 * @date 28/06/2017
 * @author Ing. Alejandro Celery
 * @brief Framework rudimentario de manejo de eventos
 */

#include "Framework.h"
#include <string.h> //memset

#define MAX_EVENTOS 100
static Evento eventosPublicados[MAX_EVENTOS];
static int idxEventoIn	= 0;
static int idxEventoOut = 0;

void Framework_init							( void )
{
	idxEventoIn = idxEventoOut = 0;
	memset( (void*)&eventosPublicados, 0, MAX_EVENTOS * sizeof(Evento) );
}

int	Framework_publicarEvento				( Evento * evento )
{
	if( idxEventoIn >= MAX_EVENTOS ) {
		return 0; //No hay lugar para mas eventos
	}

	eventosPublicados[idxEventoIn++] = *evento;
	return 1;
}

int Framework_consumirEvento				( Evento * evento )
{
	if( idxEventoOut >= idxEventoIn ) {
		return 0; //No hay eventos por consumir
	}

	*evento = eventosPublicados[idxEventoOut++];
	return 1;
}
