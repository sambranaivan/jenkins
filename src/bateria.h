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

enum UmbralesBateria {
	uBATERIA_CARGANDO = 14000,
	uBATERIA_LLENA = 12600,
	uBATERIA_MEDIA = 12200,
	uBATERIA_BAJA = 11800,
	uBATERIA_VACIA = 11400
};

#define ESCALA_CUENTAS_MV 20

void Bateria_Init							( Bateria * bateria );
void Bateria_manejadorEventos 				( Bateria * bateria, Evento * evn );
int  Bateria_tomarUnaMedicion				( Bateria * bateria );

#endif // _BATERIA_H
