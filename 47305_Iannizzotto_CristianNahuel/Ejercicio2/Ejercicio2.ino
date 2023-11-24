#include "Led.h"

#define led1 9
#define led2 10
#define boton1 13
#define boton2 12
#define boton3 11

LED led(led1,led2);

void setup() {
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if(digitalRead(boton1)){
    Serial.write(1);
    led.slowUpLed();
  }

  if(digitalRead(boton2)){
    Serial.write(2);
    led.slowDownLed();
  }
  if(digitalRead(boton3)){
    Serial.write(3);
    led.changeLed();
  }

  if(Serial.available()>0){
    int valorRecibido = Serial.read();
    switch(valorRecibido){
      case 1:
        led.slowUpLed();
        break;
      case 2:
        led.slowDownLed();
        break;
      case 3:
        led.changeLed();
    }
  }
}