const int ledPin = 9;
const int ledPin2 = 10;  
const int buttonPin = 2; 
const int buttonPin2 = 3;
const int buttonPin3 = 5;  
int brightness2 = 0;
int fadeAmount = 1;
int activeLed = 1; 

void setup()
{
  pinMode(ledPin, OUTPUT); 
  pinMode(buttonPin, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}
void loop()
{
  int alternar = digitalRead(buttonPin3);
  if (alternar == HIGH)
  {
    activeLed=cambiarLed(activeLed);
    Serial.println(activeLed);
    delay(100);
  }
  int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    subirBrillo(activeLed);
  }
  if (digitalRead(buttonPin2)==HIGH)
  {
    bajarBrillo(activeLed);
  }
}
void subirBrillo(int activeLed)
{
  if (activeLed==1)
  {
    brightness = brightness + fadeAmount;
    brightness = constrain(brightness, 0, 255);
    analogWrite(ledPin, brightness);  
    delay(10);  
  }
  else
  {
    brightness2 = brightness2 + fadeAmount;
    brightness2 = constrain(brightness2, 0, 255);
    analogWrite(ledPin2, brightness2);  
    delay(10);  
    Serial.print(brightness);
  }
}
void bajarBrillo(int activeLed)
{
  if(activeLed==1)
  {
    brightness = brightness - fadeAmount;
    brightness = constrain(brightness, 0, 255);
    analogWrite(ledPin, brightness); 
    delay(10); 
    Serial.println(brightness);
  }
  else
  {
    brightness2 = brightness2 - fadeAmount;
    brightness2 = constrain(brightness2, 0, 255);
    analogWrite(ledPin2, brightness2); 
    delay(10);  
    Serial.println(brightness2);
  }
}
int cambiarLed (int activeLed)
{
  if (activeLed == 1)
  {
    (activeLed)=0;
  }
  else
  {
    (activeLed)=1;
  }
  return activeLed;
}