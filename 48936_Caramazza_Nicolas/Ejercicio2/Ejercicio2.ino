const int ENTRADA1 = 2;
const int ENTRADA2 = 3;
const int SALIDA1 = 9;
const int SALIDA2 = 10;
int boton1Presionado=0;
int boton2Presionado=0;
String comando;
void setup()
{
  pinMode(ENTRADA1, INPUT);
  pinMode(ENTRADA2, INPUT);
  pinMode(SALIDA1, OUTPUT);
  pinMode(SALIDA2, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
if (Serial.available() > 0)
{
   comando = Serial.readStringUntil('\n');
   if(comando=="ON1")
  {
   analogWrite(SALIDA1, 255);
  }
  if(comando=="OFF1")
  {
  analogWrite(SALIDA1, 0);
  }
if(comando=="ON2")
  {
   analogWrite(SALIDA2, 255);
  }
  if(comando=="OFF2")
  {
  analogWrite(SALIDA2, 0);
  }
}

//Botones fisicos
  if(digitalRead(ENTRADA1)==HIGH)
  {
    digitalWrite(SALIDA1,HIGH);
    boton1Presionado=1;
  }
  if(digitalRead(ENTRADA1)==LOW && boton1Presionado==1)
  {
    digitalWrite(SALIDA1,LOW);
    boton1Presionado=0;
  }
  if(digitalRead(ENTRADA2)==HIGH)
  {
    digitalWrite(SALIDA2,HIGH);
    boton2Presionado=1;
  }
  if(digitalRead(ENTRADA2)==LOW && boton2Presionado==1)
  {
    digitalWrite(SALIDA2,LOW);
    boton2Presionado=0;
  }
  Serial.print(boton1Presionado);
  Serial.print(",");
  Serial.println(boton2Presionado);
  delay(50);
  }
