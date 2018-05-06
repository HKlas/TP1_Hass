
#include "sapi.h"       // <= sAPI header

#define TP1_1 (1)
#define TP1_2 (2)
#define TP1_3 (3)
#define TP1_4 (4)
#define TP1_5 (5)
#define TP1_6 (6)
#define TEST (TP1_6)

#define TICKRATE_MS 50
#define LED_TOGGLE_MS 500

#if TEST == TP1_1

int main(void){


   boardConfig();

   while(1) {

      gpioWrite( LEDB, ON );

      delay(500);

      gpioWrite( LEDB, OFF );

      delay(500);

   }

   return 0 ;
}

#elif TEST == TP1_2

int main(void){

   boardConfig();

   gpioConfig( GPIO0, GPIO_INPUT );

   gpioConfig( GPIO1, GPIO_OUTPUT );

   bool_t valor;

   while(1) {

      valor = !gpioRead( TEC1 );
      gpioWrite( LEDB, valor );

      valor = !gpioRead( TEC2 );
      gpioWrite( LED1, valor );

      valor = !gpioRead( TEC3 );
      gpioWrite( LED2, valor );

      valor = !gpioRead( TEC4 );
      gpioWrite( LED3, valor );

      valor = !gpioRead( GPIO0 );
      gpioWrite( GPIO1, valor );

   }

	return 0 ;
}

#elif TEST == TP1_3

void myTickHook( void *ptr ){

   static bool_t ledState = OFF;

   gpioMap_t led = (gpioMap_t)ptr;

   if( ledState ){
      ledState = OFF;
   }
   else{
      ledState = ON;
   }
   gpioWrite( led, ledState );
}


int main(void){

   boardConfig();

   tickConfig( 50 );

   tickCallbackSet( myTickHook, (void*)LEDR );
   delay(1000);

   while(1) {
      tickCallbackSet( myTickHook, (void*)LEDG );
      delay(1000);
      tickCallbackSet( myTickHook, (void*)LEDB );
      delay(1000);
      tickCallbackSet( myTickHook, (void*)LED1 );
      delay(1000);
      tickCallbackSet( myTickHook, (void*)LED2 );
      delay(1000);
      tickCallbackSet( myTickHook, (void*)LED3 );
      delay(1000);
      tickCallbackSet( myTickHook, (void*)LEDR );
      delay(1000);
   }

   return 0 ;
}

#elif TEST == TP1_4

void myTickHook( void *ptr ){

   static bool_t ledState = OFF;

   gpioMap_t led = (gpioMap_t)ptr;

   if( ledState ){
      ledState = OFF;
   }
   else{
      ledState = ON;
   }
   gpioWrite( led, ledState );
}


int main(void){

   boardConfig();

   tickConfig(TICKRATE_MS);

   tickCallbackSet( myTickHook, (void*)LEDR );
   delay(LED_TOGGLE_MS);

   while(1) {
      tickCallbackSet( myTickHook, (void*)LEDG );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LEDG );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LEDB );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LEDB );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LED1 );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LED1 );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LED2 );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LED2 );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LED3 );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LED3 );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LEDR );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LEDR );
      delay(LED_TOGGLE_MS);
   }

   return 0 ;
}

#elif TEST == TP1_5

void myTickHook( void *ptr ){

   static bool_t ledState = OFF;

   gpioMap_t led = (gpioMap_t)ptr;

   if( ledState ){
      ledState = OFF;
   }
   else{
      ledState = ON;
   }
   gpioWrite( led, ledState );
}


int main(void){

   boardConfig();

   tickConfig(TICKRATE_MS);

   tickCallbackSet( myTickHook, (void*)LEDR );
   delay(LED_TOGGLE_MS);

   DEBUG_PRINT_ENABLE;
   debugPrintConfigUart( UART_USB, 115200 );


   while(1) {
      tickCallbackSet( myTickHook, (void*)LEDG );
      debugPrintString( "LED GREEN\n" );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LEDG );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LEDB );
      debugPrintString( "LED BLUE\n" );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LEDB );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LED1 );
      debugPrintString( "LED 1\n" );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LED1 );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LED2 );
      debugPrintString( "LED 2\n" );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LED2 );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LED3 );
      debugPrintString( "LED 3\n" );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LED3 );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LEDR );
      debugPrintString( "LED RED\n" );
      delay(LED_TOGGLE_MS);
      tickCallbackSet( myTickHook, (void*)LEDR );
      delay(LED_TOGGLE_MS);
   }

   return 0 ;
}

#elif TEST == TP1_6

void myTickHook( void *ptr ){

   static bool_t ledState = OFF;

   gpioMap_t led = (gpioMap_t)ptr;

   if( ledState ){
      ledState = OFF;
   }
   else{
      ledState = ON;
   }
   gpioWrite( led, ledState );
}


int main(void){

   boardConfig();


   DEBUG_PRINT_ENABLE;
   debugPrintConfigUart( UART_USB, 115200 );

   bool_t valor;
   size_t counter=0;

   while(1)
   {
	   if (counter == 0)
	   {
		   valor = !gpioRead( TEC1 );
		   if (valor == 1)
		   {
	   		  	  gpioWrite( LEDB, !valor );
	   		  	  gpioWrite( LEDG, !valor );
	   		  	  gpioWrite( LEDR, !valor );
	   		  	  gpioWrite( LED1, !valor );
	   		  	  gpioWrite( LED2, !valor );
	   		  	  gpioWrite( LED3, !valor );
	   			  counter = counter + 1;
		   }
		   else
		   {
			   delay(LED_TOGGLE_MS);
		   }

	   }
	   else if(counter == 1)
	   {
		   valor = !gpioRead( TEC1 );
		   if (valor == 1)
		   {
			   gpioWrite( LEDB, valor );
	   		  /*debugPrintString( "LED Toggle\n" );*/
	   		  delay(LED_TOGGLE_MS);
	   		  counter = counter + 1;
		   }
		   else
		   {
			   delay(LED_TOGGLE_MS);
		   }

	   }
	   else if (counter == 2)
	   {
		   valor = !gpioRead( TEC1 );
		   if (valor == 1)
		   {
			   gpioWrite( LEDG, valor );
			   /*debugPrintString( "LED Toggle\n" );*/
			   delay(LED_TOGGLE_MS);
			   counter = counter + 1;
		   }
		   else
		   {
			   delay(LED_TOGGLE_MS);
		   }

	   }
	   else if (counter == 3)
	   {
		   valor = !gpioRead( TEC1 );
		   if (valor == 1)
		   {
			   gpioWrite( LEDR, valor );
	   		  /*debugPrintString( "LED Toggle\n" );*/
			   delay(LED_TOGGLE_MS);
			   counter = counter + 1;
		   }
		   else
		   {
	   			  delay(LED_TOGGLE_MS);
		   }

	   }
	   else if (counter == 4)
	   {
		   valor = !gpioRead( TEC1 );
		   if (valor == 1)
		   {
			   gpioWrite( LED1, valor );
	   		  /*debugPrintString( "LED Toggle\n" );*/
			   delay(LED_TOGGLE_MS);
			   counter = counter + 1;
		   }
		   else
		   {
			   delay(LED_TOGGLE_MS);
		   }

	   }
	   else if (counter == 5)
	   {
		   valor = !gpioRead( TEC1 );
		   if (valor == 1)
		   {
			   gpioWrite( LED2, valor );
	   		  	  /*debugPrintString( "LED Toggle\n" );*/
	   		  	  delay(LED_TOGGLE_MS);
	   		  	  counter = counter + 1;
		   }
		   else
		   {
			   delay(LED_TOGGLE_MS);
		   }

	   }
	   else
	   {
		   valor = !gpioRead( TEC1 );
		   if (valor == 1)
		   {
			   gpioWrite( LED3, valor );
			   /*debugPrintString( "LED Toggle\n" );*/
			   delay(LED_TOGGLE_MS);
			   counter = 0;
		   }
		   else
		   {
	   			  delay(LED_TOGGLE_MS);
		   }
	   }
   }
   return 0 ;
}

#endif
