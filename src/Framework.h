#ifndef _FRAMEWORK_H
#define _FRAMEWORK_H

#include <stdlib.h>

enum Seniales {
	SIG_TIMEOUT,
	SIG_ARRANQUE,
	SIG_BATERIA_TENSION_ACTUAL_MV,
	SIG_BATERIA_CRITICA,
	SIG_APAGAR_EQUIPO
};

typedef struct EventoStruct
{
	int senial;
	int valor;
}Evento;

void Framework_init							( void );
int  Framework_publicarEvento				( Evento * evento );
int  Framework_consumirEvento				( Evento * evento );

#endif // _FRAMEWORK_H
