#include "build/temp/_test_bateria.c"
#include "mock_analog.h"
#include "Framework.h"
#include "bateria.h"
#include "unity.h"
Bateria bateria;

Evento eventoTimeout, evn;

int retVal;



static int Bateria_espiarEstado ( Bateria * bateria );

static void valorProximaMedicion ( int valor );







static

int Bateria_espiarEstado ( Bateria * bateria )

{

 return bateria->estado;

}



static

void valorProximaMedicion ( int valor )

{

 getValorInstantaneoPinBateria_CMockExpectAndReturn(83, valor / 20);

 getValorInstantaneoPinBateria_CMockExpectAndReturn(84, valor / 20);

}



void setUp(void)

{

 Framework_init ( );

 Bateria_Init ( &bateria );

 eventoTimeout.senial = SIG_TIMEOUT;

 eventoTimeout.valor = 0;

}



void tearDown(void)

{



}





void ignoretest_FrameworkOk ( void )

{

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((1)), (

((void *)0)

), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_INT);

}

void test_ReqBat_1_1_UnaMedicionCorrecta ( void )

{

 int tensionMV;



 getValorInstantaneoPinBateria_CMockExpectAndReturn(171, 8000 / 20);

 getValorInstantaneoPinBateria_CMockExpectAndReturn(172, 12000 / 20);



 tensionMV = Bateria_tomarUnaMedicion( &bateria );



 UnityAssertEqualNumber((UNITY_INT)((10000)), (UNITY_INT)((tensionMV)), (

((void *)0)

), (UNITY_UINT)(176), UNITY_DISPLAY_STYLE_INT);

}



void test_ReqBat_1_2_UnaMedicionPorSegundo ( void )

{

 getValorInstantaneoPinBateria_CMockExpectAndReturn(181, 8000 / 20);

 getValorInstantaneoPinBateria_CMockExpectAndReturn(182, 12000 / 20);



 (Bateria_manejadorEventos(&bateria, &eventoTimeout));

}



void test_ReqBat_2_1_EstadoInicialBateria ( void )

{

 UnityAssertEqualNumber((UNITY_INT)((sBATERIA_LLENA)), (UNITY_INT)((Bateria_espiarEstado(&bateria))), (

((void *)0)

), (UNITY_UINT)(189), UNITY_DISPLAY_STYLE_INT);

}



void test_ReqBat_2_2_a_EstadosBateriaCargando ( void )

{

 valorProximaMedicion ( uBATERIA_CARGANDO );



 (Bateria_manejadorEventos(&bateria, &eventoTimeout));



 UnityAssertEqualNumber((UNITY_INT)((sBATERIA_CARGANDO)), (UNITY_INT)((Bateria_espiarEstado(&bateria))), (

((void *)0)

), (UNITY_UINT)(198), UNITY_DISPLAY_STYLE_INT);

}



void test_ReqBat_2_2_b_EstadosBateriaLlena ( void )

{

 valorProximaMedicion ( uBATERIA_CARGANDO - 1 );



 (Bateria_manejadorEventos(&bateria, &eventoTimeout));



 UnityAssertEqualNumber((UNITY_INT)((sBATERIA_LLENA)), (UNITY_INT)((Bateria_espiarEstado(&bateria))), (

((void *)0)

), (UNITY_UINT)(207), UNITY_DISPLAY_STYLE_INT);



 valorProximaMedicion ( uBATERIA_LLENA );



 (Bateria_manejadorEventos(&bateria, &eventoTimeout));



 UnityAssertEqualNumber((UNITY_INT)((sBATERIA_LLENA)), (UNITY_INT)((Bateria_espiarEstado(&bateria))), (

((void *)0)

), (UNITY_UINT)(213), UNITY_DISPLAY_STYLE_INT);

}



void test_ReqBat_2_2_c_EstadosBateriaLlena ( void )

{

 valorProximaMedicion ( 11599 );



 (Bateria_manejadorEventos(&bateria, &eventoTimeout));



 UnityAssertEqualNumber((UNITY_INT)((sBATERIA_MEDIA)), (UNITY_INT)((Bateria_espiarEstado(&bateria))), (

((void *)0)

), (UNITY_UINT)(222), UNITY_DISPLAY_STYLE_INT);



 valorProximaMedicion ( 12200 );



 (Bateria_manejadorEventos(&bateria, &eventoTimeout));



 UnityAssertEqualNumber((UNITY_INT)((sBATERIA_MEDIA)), (UNITY_INT)((Bateria_espiarEstado(&bateria))), (

((void *)0)

), (UNITY_UINT)(228), UNITY_DISPLAY_STYLE_INT);

}



void ignoretest_ReqBat_2_3_NivelNoAumentaSinConectarAFuente( void )

{

 valorProximaMedicion ( 12500 );

 (Bateria_manejadorEventos(&bateria, &eventoTimeout));

 UnityAssertEqualNumber((UNITY_INT)((sBATERIA_MEDIA)), (UNITY_INT)((Bateria_espiarEstado(&bateria))), (

((void *)0)

), (UNITY_UINT)(235), UNITY_DISPLAY_STYLE_INT);



 valorProximaMedicion ( 13500 );

 (Bateria_manejadorEventos(&bateria, &eventoTimeout));

 UnityAssertEqualNumber((UNITY_INT)((sBATERIA_MEDIA)), (UNITY_INT)((Bateria_espiarEstado(&bateria))), (

((void *)0)

), (UNITY_UINT)(239), UNITY_DISPLAY_STYLE_INT);



 valorProximaMedicion ( 14000 );

 (Bateria_manejadorEventos(&bateria, &eventoTimeout));

 UnityAssertEqualNumber((UNITY_INT)((sBATERIA_CARGANDO)), (UNITY_INT)((Bateria_espiarEstado(&bateria))), (

((void *)0)

), (UNITY_UINT)(243), UNITY_DISPLAY_STYLE_INT);



 valorProximaMedicion ( 13500 );

 (Bateria_manejadorEventos(&bateria, &eventoTimeout));

 UnityAssertEqualNumber((UNITY_INT)((sBATERIA_LLENA)), (UNITY_INT)((Bateria_espiarEstado(&bateria))), (

((void *)0)

), (UNITY_UINT)(247), UNITY_DISPLAY_STYLE_INT);

}



void ignoretest_ReqBat_3_1_InicioCuentaRegresivaApagado ( void )

{

 valorProximaMedicion ( 9000 );



 (Bateria_manejadorEventos(&bateria, &eventoTimeout));



 retVal = Framework_consumirEvento( &evn );

 if ((retVal)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(257)));};

 UnityAssertEqualNumber((UNITY_INT)((SIG_BATERIA_CRITICA)), (UNITY_INT)((evn.senial)), (

((void *)0)

), (UNITY_UINT)(258), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((60)), (UNITY_INT)((evn.valor)), (

((void *)0)

), (UNITY_UINT)(259), UNITY_DISPLAY_STYLE_INT);

}



void ignoretest_ReqBat_3_2_Pasaje10SegundosCuentaRegresivaApagado ( void )

{

 for (int tiempo = 60; tiempo >= 0; --tiempo) {

  valorProximaMedicion ( 9000 );

  (Bateria_manejadorEventos(&bateria, &eventoTimeout));



  if( tiempo % 10 == 0 ) {

   retVal = Framework_consumirEvento( &evn );

   if ((retVal)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(270)));};

   UnityAssertEqualNumber((UNITY_INT)((SIG_BATERIA_CRITICA)), (UNITY_INT)((evn.senial)), (

  ((void *)0)

  ), (UNITY_UINT)(271), UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((UNITY_INT)((tiempo)), (UNITY_INT)((evn.valor)), (

  ((void *)0)

  ), (UNITY_UINT)(272), UNITY_DISPLAY_STYLE_INT);

  }

 }

}



void ignoretest_ReqBat_5_1_a_LED_BateriaCritica ( void )

{

 valorProximaMedicion ( 9000 );

 setEstadoLEDPanelFrontal_CMockExpect(280, 1);



 (Bateria_manejadorEventos(&bateria, &eventoTimeout));

}







void ignoretest_ReqBat_1_3_IgnorarMedicionesIncorrectas ( void )

{



}



void ignoretest_ReqBat_5_1_b_LED_BateriaVacia ( void )

{



}



void ignoretest_ReqBat_5_2_LED_BateriaBaja ( void )

{



}



void ignoretest_ReqBat_5_3_LED_EstadosLEDApagado ( void )

{



}
