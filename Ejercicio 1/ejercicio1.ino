/**PULSADOR1, PULSADOR2, PULSADOR3 y LED1, LED2

a) Al presionar el PULSADOR1, se debe empezar a incrementar el brillo del
LED1 de forma muy tenue o lentamente.

b) Si el PULSADOR2 es presionado, se debe iniciar el LED1 en su brillo
máximo, e irlo decrementando.

c) El botón PULSADOR3 cambiaría el led a ser utilizado por el LED2, para
ejecutar a) y b) sobre LED2. Si nuevamente es presionado, cambiaría el led
a ser utilizado por LED1, y así sucesivamente.**/

int LED1 = 11 , LED2 = 9;
int PULSADOR1 = 0 , PULSADOR2 = 2 , PULSADOR3 = 3;
int estado1 = LOW , estado2 = LOW;
int brillo=0;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  
  pinMode(PULSADOR1, INPUT);
  pinMode(PULSADOR2, INPUT);
  pinMode(PULSADOR3, INPUT);
  
  Serial.begin(9600);
};

void loop()
{
 estado1 = analogRead(PULSADOR1);
 estado2 = analogRead(PULSADOR2);
  
  if(estado1 != LOW && brillo < 120){
    analogWrite(LED1, brillo); 
    brillo++;
    delay(1000);
  }
  
 
  
}
