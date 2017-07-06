#ifndef _BATERIA_H
#define _BATERIA_H

#include "Framework.h"

typedef struct BateriaStruct
{
	int estado;
}Bateria;

enum EstadosBateria {
	sBATERIA_CARGANDO,
	sBATERIA_LLENA,
	sBATERIA_MEDIA,
	sBATERIA_BAJA,
	sBATERIA_VACIA,
	sBATERIA_CRITICA
};

void Bateria_Init							( Bateria * bateria );
void Bateria_manejadorEventos 				( Bateria * bateria, Evento * evn );

#endif // _BATERIA_H
