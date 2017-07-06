
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
	switch( evento->senial )
	{
		case SIG_TIMEOUT:
			evn.valor	= getValorInstantaneoPinBateria() * 20;
			evn.senial	= SIG_BATERIA_TENSION_ACTUAL_MV;
			Framework_publicarEvento( &evn );
			setEstadoLEDPanelFrontal( 1 );
			break;

		case SIG_ARRANQUE:
		default:
			break;
	}
}
