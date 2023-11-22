/**PULSADOR1, PULSADOR2, PULSADOR3 y LED1, LED2

a) Al presionar el PULSADOR1, se debe empezar a incrementar el brillo del
LED1 de forma muy tenue o lentamente.

b) Si el PULSADOR2 es presionado, se debe iniciar el LED1 en su brillo
máximo, e irlo decrementando.

c) El botón PULSADOR3 cambiaría el led a ser utilizado por el LED2, para
ejecutar a) y b) sobre LED2. Si nuevamente es presionado, cambiaría el led
a ser utilizado por LED1, y así sucesivamente.**/

int LED1 = 11 , LED2 = 9;
int PULSADOR1 = 6 , PULSADOR2 = 3, PULSADOR3 = 5;
int brillo=0;
int estado1, estado2, estado3, condicion, condicionLED;//condicion es una bandera

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  pinMode(PULSADOR1, INPUT);
  pinMode(PULSADOR2, INPUT);
  Serial.begin(9600);
  brillo = 0;
  condicionLED = LED1;
};//SETUP

void loop()
{
 	
   estado1 = digitalRead(PULSADOR1);
   estado2 = digitalRead(PULSADOR2);
   estado3 = digitalRead(PULSADOR3);
  
 Serial.print("Pulsador 1: ");
 Serial.println(estado1);
 Serial.print("Pulsador 2: ");
 Serial.println(estado2);
 Serial.print("Pulsador 3: ");
 Serial.println(estado3);
 Serial.print("Brillo: ");
 Serial.println(brillo);
 Serial.print("LED: ");
 Serial.println(condicionLED);
  
    
  if(estado1 == HIGH && brillo <= 50){
    condicion = 0;
    analogWrite(condicionLED, brillo); 
    brillo+=5;
  
  }//if
  
  if(estado2 == HIGH){
    condicion = 1;
	}//if

 if(condicion == 1){
   digitalWrite(condicionLED, HIGH);
  
   for(brillo = 90 ; brillo > 0 ; brillo--){
     analogWrite(condicionLED, brillo);
     delay(5);
   }//for
   
    condicion = 0;
}//if
  
 if(estado3 == HIGH && condicionLED == LED1){
   condicionLED = LED2;
   
 }//if
  
 else if(estado3 == HIGH && condicionLED == LED2){
    condicionLED = LED1;
    
  }//if

}//LOOP
  
  delay(1000);
  
}//LOOP
