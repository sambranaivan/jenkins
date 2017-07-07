
/**
 * @file bateria.c
 * @date 28/06/2017
 * @author Ing. Alejandro Celery
 * @brief Implementacion de las funciones de la Bateria.
 */

#include "bateria.h"
#include "analog.h"
#include "Framework.h"

/**
 * Inicializa el modulo y lo programa para verificar la condicion de arranque en periodoMedicionBateriaInicial ms.
 * @see verificaCondicionDeArranque
 */

void Bateria_Init							( Bateria * bateria )
{
	bateria->estado = sBATERIA_LLENA;
}

/**
 * Senial | Valor | Evento
 * -------|-------|-------
 * SIG_TIMEOUT (primera ocurrencia) | x | Una vez por segundo. Debe medir la tension y tomar las acciones correspondientes.
 * SIG_ARRANQUE | x | Cuando se esta produciendo un arranque del motor. Debe suspender las mediciones de bateria durante 60 segundos.
 */
void Bateria_manejadorEventos 				( Bateria * bateria, Evento * evento )
{
	Evento evn;
	int tensionMedida;

	switch( evento->senial )
	{
		case SIG_TIMEOUT:
			tensionMedida	= Bateria_tomarUnaMedicion( bateria );
			if( tensionMedida >= uBATERIA_CARGANDO ) {
				bateria->estado	= sBATERIA_CARGANDO;
			}
			else if( tensionMedida >= uBATERIA_LLENA ) {
				bateria->estado	= sBATERIA_LLENA;
			}
			else {
				bateria->estado	= sBATERIA_MEDIA;
			}
			break;

		case SIG_ARRANQUE:
		default:
			break;
	}
}

int  Bateria_tomarUnaMedicion				( Bateria * bateria )
{
	int m1, m2;
	m1 = getValorInstantaneoPinBateria	( ) * ESCALA_CUENTAS_MV;
	m2 = getValorInstantaneoPinBateria	( ) * ESCALA_CUENTAS_MV;
	return (m1+m2) / 2;
}
