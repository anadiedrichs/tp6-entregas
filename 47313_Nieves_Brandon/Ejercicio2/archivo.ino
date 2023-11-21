#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>          //Librerias de shield utilizado
class Programa{
  public:
 bool Led1 = false;
 bool Led2 = false;
 byte button;
 bool PresionarBoton(boolean estado){       //Recibe: Estado del LED. Devuelve: Estado del LED. Funcion: Cambia el estado del LED recibido
  estado = !estado;
  return( estado );
 }
 void EstadoLed1( boolean estado){          //Recibe: Estado del LED. Devuelve: Nada. Funcion: Enciende el LED en Arduino o lo apaga en funcion del estado recibido
  if( estado == true ){
    MFS.writeLeds(LED_1, ON);
  }else{MFS.writeLeds(LED_1, OFF);}
 }
 void EstadoLed2( boolean estado){        //Recibe: Estado del LED. Devuelve: Nada. Funcion: Enciende el LED en Arduino o lo apaga en funcion del estado recibido 
  if( estado == true ){
    MFS.writeLeds(LED_2, ON);
  }else{MFS.writeLeds(LED_2, OFF);}
 }
};
Programa Leds;            //Inicializo el Objeto Leds

void setup() {
 // put your setup code here, to run once:
 Timer1.initialize();
 MFS.initialize(&Timer1);    // initialize multi-function shield library
 Serial.begin(9600);         // Declaro la vel de comunicacion del puerto
 }
void loop() {
  Leds.EstadoLed1( Leds.Led1 );
  Leds.EstadoLed2( Leds.Led2 );
  Leds.button = MFS.getButton();        //Controla si se presiona un boton del shield
  if ( Leds.button ){
    if( Leds.button == BUTTON_1_PRESSED ){    //Si el primer boton del shield es presionado
       Leds.Led1 = Leds.PresionarBoton( Leds.Led1 );    //Cambia el valor del LED 1
       Serial.write("H\n");}     //Envia letra por puerto
     
    if( Leds.button == BUTTON_2_PRESSED ){    //Si el segundo boton del shield es presionado
       Leds.Led2 = Leds.PresionarBoton( Leds.Led2 );    //Cambia el valor del LED 2
       Serial.write("D\n");}     //Envia letra por puerto
  }
}
void serialEvent(){ //Recibe: Nada. Devuelve: Nada. Funcion: Mientras alla valores sin leer en el puerto, los leerá y cambiará el estado del LED respectivo
  while(Serial.available()){
    String Cadena = Serial.readStringUntil('\n');
    if(Cadena == "LED1"){     //Si recibe la cadena "LED1" por puerto cambia el estado del LED1
      Leds.Led1 = !Leds.Led1;}
    if(Cadena == "LED2"){     //Si recibe la cadena "LED2" por puerto cambia el estado del LED2
      Leds.Led2 = !Leds.Led2;}  
  }
}    
