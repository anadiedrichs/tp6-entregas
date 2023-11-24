#define led1 9
#define led2 10
#define boton1 13
#define boton2 12
#define boton3 11
int led = led1;
bool b=true;
void setup() {
  // put your setup code here, to run once:
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(boton1)==HIGH){
    delay(20);
    digitalWrite(led,LOW);
    int i=0;
    for(i=0;i<256;i++){
      analogWrite(led,i);
      delay(5);
    }
  }

  if(digitalRead(boton2)==HIGH){
    delay(20);
    digitalWrite(led,HIGH);
    int i = 256;
    for(i=256;i>=0;i--){
      analogWrite(led,i);
      delay(5);
    }
  }
  if(digitalRead(boton3)){
    if(b){
      led = led2;
      b = false;
      delay(200);
    }else{
      led = led1;
      b = true;
      delay(200);
    }
  }
}
