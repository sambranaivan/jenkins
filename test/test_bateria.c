#include "unity.h"
#include "bateria.h"
#include "Framework.h"
#include "mock_analog.h"

/* Documentacion del modulo, sus entradas y salidas, los requerimientos que se infirieron de ellas y las actividades de validacion resultantes
 *
 * Entradas:
 *
 * Tension de bateria medida en cuentas de 10 bits por el MCU.
 *
 * SIG_TIMEOUT
 * 		Se recibe siempre cada 1 segundo.
 * 		Se debe tomar una medicion de bateria y tomar las acciones correspondientes.
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
 * SIG_APAGAR_ACCESORIOS
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
 * Req.Bat.2.2: El modulo batería tomara los siguientes estados segun los siguientes niveles de tension:
 * 		CARGANDO,	cuando la medicion de bateria sea mayor o igual a 14,0 V
 * 		LLENA,		cuando la medicion de bateria sea menor a 14,0 V y mayor o igual a 12,6 V
 * 		MEDIA,		cuando la medicion de bateria sea menor a 12,6 V y mayor o igual a 12,2 V
 * 		BAJA,		cuando la medicion de bateria sea menor a 12,2 V y mayor o igual a 11,8 V
 * 		VACIA,		cuando la medicion de bateria sea menor a 11,8 V y mayor o igual a 11,4 V
 * 		CRITICA,	cuando la medicion de bateria sea menor a 11,4 V
 * Req.Bat.2.3: El nivel de batería no podrá aumentar sin que el modulo pase por el estado CARGANDO.
 *
 * Req.Bat.3.1: El modulo batería iniciará una cuenta regresiva hasta el apagado de accesorios de 60 segundos
 * 		cada vez que pase a estar vez en estado crítico.
 * Req.Bat.3.2: El modulo batería publicará el pasaje de sucesivos 10 segundos de la cuenta regresiva.
 * Req.Bat.3.3: El modulo batería publicará el fin de la cuenta regresiva para el apagado de accesorios.
 *
 * Req.Bat.5.1: El LED de estado de bateria quedará prendido fijo en los estados sBATERIA_CRITICA y sBATERIA_VACIA
 * Req.Bat.5.2: El LED de estado de bateria cambiará de estado una vez por segundo en el estado sBATERIA_BAJA
 * Req.Bat.5.3: El LED de estado de bateria quedará apagado fijo en los demás estados
 */

/*
 * Dependencias a romper con el hardware:
 *
 * - Medicion de tension
 * - Encendido/apagado del LED del tablero del auto.
 */

Bateria	bateria;
Evento	eventoTimeout, evn;
int		retVal;

static int Bateria_espiarEstado ( Bateria * bateria );
static void valorProximaMedicion	( int valor );
#define PASA_UN_SEGUNDO(e) (Bateria_manejadorEventos(&bateria, &eventoTimeout))
#define CHEQUEAR_ESTADO(e) LONGS_EQUAL(e, bateria->testEspiarEstado())

static
int Bateria_espiarEstado ( Bateria * bateria )
{
	return bateria->estado;
}

static
void valorProximaMedicion	( int valor )
{
	getValorInstantaneoPinBateria_ExpectAndReturn( valor / ESCALA_CUENTAS_MV );
	getValorInstantaneoPinBateria_ExpectAndReturn( valor / ESCALA_CUENTAS_MV );
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
void ignoretest_FrameworkOk						( void )
{
	TEST_ASSERT_EQUAL(1,1);
}














































#if 0
void ignoretest_Ejemplo							( void )
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
#endif

void test_ReqBat_1_1_UnaMedicionCorrecta			( void )
{
	int tensionMV;

	getValorInstantaneoPinBateria_ExpectAndReturn(  8000 / 20 );
	getValorInstantaneoPinBateria_ExpectAndReturn( 12000 / 20 );

	tensionMV = Bateria_tomarUnaMedicion( &bateria );

	TEST_ASSERT_EQUAL( 10000, tensionMV );
}

void test_ReqBat_1_2_UnaMedicionPorSegundo			( void )
{
	getValorInstantaneoPinBateria_ExpectAndReturn(  8000 / 20 );
	getValorInstantaneoPinBateria_ExpectAndReturn( 12000 / 20 );

	PASA_UN_SEGUNDO			( );
}

void test_ReqBat_2_1_EstadoInicialBateria			( void )
{
	TEST_ASSERT_EQUAL		( sBATERIA_LLENA, Bateria_espiarEstado(&bateria) );
}

void test_ReqBat_2_2_a_EstadosBateriaCargando	( void )
{
	valorProximaMedicion	( uBATERIA_CARGANDO );

	PASA_UN_SEGUNDO			( );

	TEST_ASSERT_EQUAL		( sBATERIA_CARGANDO, Bateria_espiarEstado(&bateria) );
}

void test_ReqBat_2_2_b_EstadosBateriaLlena	( void )
{
	valorProximaMedicion	( uBATERIA_CARGANDO - 1 );

	PASA_UN_SEGUNDO			( );

	TEST_ASSERT_EQUAL		( sBATERIA_LLENA, Bateria_espiarEstado(&bateria) );

	valorProximaMedicion	( uBATERIA_LLENA );

	PASA_UN_SEGUNDO			( );

	TEST_ASSERT_EQUAL		( sBATERIA_LLENA, Bateria_espiarEstado(&bateria) );
}

void test_ReqBat_2_2_c_EstadosBateriaLlena	( void )
{
	valorProximaMedicion	( 11599 );

	PASA_UN_SEGUNDO			( );

	TEST_ASSERT_EQUAL		( sBATERIA_MEDIA, Bateria_espiarEstado(&bateria) );

	valorProximaMedicion	( 12200 );

	PASA_UN_SEGUNDO			( );

	TEST_ASSERT_EQUAL		( sBATERIA_MEDIA, Bateria_espiarEstado(&bateria) );
}

void ignoretest_ReqBat_2_3_NivelNoAumentaSinConectarAFuente( void )
{
	valorProximaMedicion	( 12500 );
	PASA_UN_SEGUNDO			( );
	TEST_ASSERT_EQUAL		( sBATERIA_MEDIA, Bateria_espiarEstado(&bateria) );

	valorProximaMedicion	( 13500 );
	PASA_UN_SEGUNDO			( );
	TEST_ASSERT_EQUAL		( sBATERIA_MEDIA, Bateria_espiarEstado(&bateria) );

	valorProximaMedicion	( 14000 );
	PASA_UN_SEGUNDO			( );
	TEST_ASSERT_EQUAL		( sBATERIA_CARGANDO, Bateria_espiarEstado(&bateria) );

	valorProximaMedicion	( 13500 );
	PASA_UN_SEGUNDO			( );
	TEST_ASSERT_EQUAL		( sBATERIA_LLENA, Bateria_espiarEstado(&bateria) );
}

void ignoretest_ReqBat_3_1_InicioCuentaRegresivaApagado	( void )
{
	valorProximaMedicion	( 9000 );

	PASA_UN_SEGUNDO			( );

	retVal = Framework_consumirEvento( &evn );
	TEST_ASSERT_TRUE		( retVal );
	TEST_ASSERT_EQUAL		( SIG_BATERIA_CRITICA, evn.senial );
	TEST_ASSERT_EQUAL		( 60, evn.valor );
}

void ignoretest_ReqBat_3_2_Pasaje10SegundosCuentaRegresivaApagado	( void )
{
	for (int tiempo = 60; tiempo >= 0; --tiempo) {
		valorProximaMedicion	( 9000 );
		PASA_UN_SEGUNDO			( );

		if( tiempo % 10 == 0 ) {
			retVal = Framework_consumirEvento( &evn );
			TEST_ASSERT_TRUE		( retVal );
			TEST_ASSERT_EQUAL		( SIG_BATERIA_CRITICA, evn.senial );
			TEST_ASSERT_EQUAL		( tiempo, evn.valor );
		}
	}
}

void ignoretest_ReqBat_5_1_a_LED_BateriaCritica			( void )
{
	valorProximaMedicion	( 9000 );
	setEstadoLEDPanelFrontal_Expect( 1 );

	PASA_UN_SEGUNDO			( );
}



void ignoretest_ReqBat_1_3_IgnorarMedicionesIncorrectas	( void )
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
