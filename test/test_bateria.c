#include "unity.h"
#include "bateria.h"
#include "Framework.h"
#include "mock_analog.h"

/* Documentacion del modulo, sus entradas y salidas, los requerimientos que se infirieron de ellas y las actividades de validacion resultantes
 *
 * Entradas:
 *
 * Tension de bateria medida en cuentas de 12 bits por el MCU.
 *
 * SIG_TIMEOUT
 * 		Se recibe siempre cada 1 segundo.
 * 		Se debe tomar una medicion de bateria y tomar las acciones correspondientes.
 *
 * SIG_ARRANQUE
 * 		Se recibe cuando se esta produciendo un arranque del motor.
 * 		Se deben suspender las mediciones de bateria durante 60 segundos.
 *
 * Salidas:
 *
 * LED indicador de estado en el panel frontal
 *
 * SIG_BATERIA_TENSION_ACTUAL_MV
 * 		Se publica cada vez que hay una medicion tomada del nivel de bateria.
 * 		Valor: Tension medida en mV.
 *
 * SIG_BATERIA_CRITICA
 * 		Se publica cada 10 segundos mientras se este produciendo la cuenta regresiva hacia el apagado de los accesorios.
 * 		Valor: segundos restantes hasta el apagado (60,50,40,30,20,10).
 *
 * SIG_APAGAR_EQUIPO
 * 		Se publica cuando se deben apagar los accesorios del auto por nivel de bateria critica.
 * 		Valor: no se usa.
 *
 * Requerimientos del modulo:
 *
 * Req.Bat.1.1: La bateria se medirá tomando 2 muestras seguidas de la tensión en el pin VBAT, escalándolo a la tensión en batería y haciendo un promedio aritmético de las mismas.
 * Req.Bat.1.2: Se hara una medicion de bateria por segundo.
 * Req.Bat.1.3: Se ignorarán las mediciones por debajo de 6,0 V y por encima de 18,0V.
 *
 * Req.Bat.2.1: El modulo se inicializara en el estado sBATERIA_LLENA y permanecera en el hasta que tome la primera medicion.
 * Req.Bat.2.2: El modulo batería publicará el estado de la batería en los siguientes niveles:
 * 		CARGANDO,	cuando la medicion de bateria sea mayor o igual a 14,0 V
 * 		LLENA,		cuando la medicion de bateria sea menor a 14,0 V y mayor o igual a 12,6 V
 * 		MEDIA,		cuando la medicion de bateria sea menor a 12,6 V y mayor o igual a 12,2 V
 * 		BAJA,		cuando la medicion de bateria sea menor a 12,2 V y mayor o igual a 11,8 V
 * 		VACIA,		cuando la medicion de bateria sea menor a 11,8 V y mayor o igual a 11,4 V
 * 		CRITICA,	cuando la medicion de bateria sea menor a 11,4 V
 * Req.Bat.2.3: El nivel de batería no podrá aumentar sin que el modulo pase por el estado CARGANDO.
 *
 * Req.Bat.3.1: El modulo batería iniciará una cuenta regresiva hasta el apagado de accesorios de 60 segundos cada vez que pase a estar vez en estado crítico.
 * Req.Bat.3.2: El modulo batería publicará el pasaje de sucesivos 10 segundos de la cuenta regresiva.
 * Req.Bat.3.3: El modulo batería publicará el fin de la cuenta regresiva para el apagado de accesorios.
 *
 * Req.Bat.4.1: No se medirá la bateria en los 60 segundos siguientes al arranque.
 *
 * Req.Bat.5.1: El LED de estado de bateria quedará prendido fijo en los estados sBATERIA_CRITICA y sBATERIA_VACIA
 * Req.Bat.5.2: El LED de estado de bateria cambiará de estado una vez por segundo en el estado sBATERIA_BAJA
 * Req.Bat.5.3: El LED de estado de bateria quedará apagado fijo en los demás estados
 */

/*
 * Dependencias a romper con el hardware:
 *
 * - Medicion de tension
 * - Encendido/apgado del LED del tablero del auto.
 */

Bateria	bateria;
Evento	eventoTimeout, evn;
int		retVal;

static int Bateria_espiarEstado ( Bateria * bateria );
#define PASA_UN_SEGUNDO(e) (Bateria_manejadorEventos(&bateria, &eventoTimeout))
#define CHEQUEAR_ESTADO(e) LONGS_EQUAL(e, bateria->testEspiarEstado())

static
int Bateria_espiarEstado ( Bateria * bateria )
{
	return bateria->estado;
}

void setUp(void)
{
	Framework_init	( );
	Bateria_Init	( &bateria ); //Para que todos los tests inicien con un controlador limpio
	eventoTimeout.senial = SIG_TIMEOUT;
	eventoTimeout.valor = 0;
}

void tearDown(void)
{

}

//Para enviar un evento al modulo se llama al manejador de eventos del mismo con el evento como argumento.
void test_FrameworkOk						( void )
{
	TEST_ASSERT_EQUAL(1,1);
}















































void test_Ejemplo							( void )
{
	getValorInstantaneoPinBateria_ExpectAndReturn( 14400 / 20 );
	setEstadoLEDPanelFrontal_Expect( 1 );
	PASA_UN_SEGUNDO			( );

	retVal = Framework_consumirEvento( &evn );

	TEST_ASSERT_EQUAL		( sBATERIA_VACIA, Bateria_espiarEstado(&bateria) );
	TEST_ASSERT_TRUE		( retVal );
	TEST_ASSERT_EQUAL		( SIG_BATERIA_TENSION_ACTUAL_MV, evn.senial );
	TEST_ASSERT_EQUAL		( 14400, evn.valor );
}












void ignoretest_ReqBat_1_1_UnaMedicionCorrecta			( void )
{

}

void ignoretest_ReqBat_1_2_UnaMedicionPorSegundo		( void )
{

}

void ignoretest_ReqBat_1_3_IgnorarMedicionesIncorrectas	( void )
{

}

void ignoretest_ReqBat_2_1_EstadoInicialBateria			( void )
{

}

void ignoretest_ReqBat_2_2_EstadosBateria				( void )
{

}

void ignoretest_ReqBat_2_3_NivelNoAumentaSinConectarARed( void )
{

}

void ignoretest_ReqBat_3__1_2_3_CuentaRegresivaApagado	( void )
{

}

void ignoretest_ReqBat_4_1_NoMedirLuegoDeArranque		( void )
{

}

void ignoretest_ReqBat_5_1_a_LED_BateriaCritica			( void )
{

}

void ignoretest_ReqBat_5_1_b_LED_BateriaVacia			( void )
{

}

void ignoretest_ReqBat_5_2_LED_BateriaBaja				( void )
{

}

void ignoretest_ReqBat_5_3_LED_EstadosLEDApagado		( void )
{

}
