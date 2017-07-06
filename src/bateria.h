#ifndef _BATERIA_H
#define _BATERIA_H

#include "Framework.h"

typedef struct BateriaStruct
{
	int bogus;
}Bateria;

enum EstadosBateria {
	CARGANDO,
	LLENA,
	MEDIA,
	BAJA,
	VACIA,
	CRITICA
};

void Bateria_Init							( Bateria * bateria );
void Bateria_manejadorEventos 				( Bateria * bateria, Evento * evn );

#endif // _BATERIA_H
