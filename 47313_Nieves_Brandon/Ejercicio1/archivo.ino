// Código para subir y bajar brillo de 2 LEDS usando 3 pulsadores; uno aumenta brillo, otro disminuye
//el brillo y el último cambia de LED.
#define MAX 255
class Arduino{
  public:
  int brilloPulsador1 = 0, brilloPulsador2 = MAX;
  int pulsador1 = 0; 	  //cable de color amarillo
  int pulsador2 = 0;	  //cable de color verde
  int pulsador3 = 0;    //cable de color azul
  bool bandera = true;
  
  void CambioLED1(int pin){		//Recibe un pin entero y cambia booleano a true
  	pulsador3 = digitalRead(pin);
    if( pulsador3 == HIGH ){
    	bandera = true;
      	delay(1000);
    }
  }
  void CambioLED2(int pin){     //Recibe un pin entero y cambia booleano a false
  	pulsador3 = digitalRead(pin);
    if( pulsador3 == HIGH ){
    	bandera = false;
      	delay(1000);}
    }
  void subirBrillo(int analogoPin){  	//Recibe en valor del pin correspondiente al pulsador y sube el brillo del LED
    if( pulsador1 == HIGH ){
            analogWrite(analogoPin, brilloPulsador1);
            if( brilloPulsador1 < MAX ){
                brilloPulsador1 += 5;
                delay(30);}
            else{brilloPulsador1 = 0;}
        }   
   }
  void bajarBrillo(int analogoPin){		//Recibe en valor del pin correspondiente al pulsador y baja el brillo del LED
    if( pulsador2 == HIGH ){
          analogWrite(analogoPin, brilloPulsador2);
          if( brilloPulsador2 > 0 ){
              brilloPulsador2 -= 5;
              delay(30);} // Esperar 30 milisegundos
          else{brilloPulsador2 = MAX;}
        }
   }
};
Arduino led;				//creo objeto de la clase arduino
void setup()
{
  pinMode(8, INPUT);		//entradas digitales
  pinMode(7, INPUT);
  pinMode(12, INPUT);
  pinMode(3, OUTPUT);		//salidas análogas
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
    {while( led.bandera == true ){ 		//Los cambios se realizan en LED1 (blanco)
      	led.CambioLED2( 7 );
        led.pulsador1 = digitalRead(12);
        led.subirBrillo( 11 ); 

        led.pulsador2 = digitalRead(8);
      	led.bajarBrillo( 9 );
    }
     while( led.bandera == false ){		//Los cambios se realizan en LED2 (rojo)
   		led.CambioLED1( 7 );
        led.pulsador1 = digitalRead(12);
        led.subirBrillo( 6 );

        led.pulsador2 = digitalRead(8);
        led.bajarBrillo( 3 );
    }  
}