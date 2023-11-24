class LED{
private:
 int allLed,led1,led2;
 int contador;
 bool flag;
public:
  LED(int,int);
  ~LED(){};
  void slowUpLed();
  void slowDownLed();
  void changeLed();
};

LED::LED(int Led1,int Led2){
  allLed = Led1;
  led1 = Led1;
  led2 = Led2;
  contador = 0;
  flag = true;
}

void LED::slowUpLed(){
     digitalWrite(allLed,LOW);
    int contador = 0;
    for(contador = 0; contador < 256; contador++){
      analogWrite(allLed,contador);
      delay(5);
    }
}

void LED::slowDownLed(){
  digitalWrite(allLed,HIGH);
  int contador = 256;
  for(contador = 256; contador >= 0; contador--){
    analogWrite(allLed,contador);
    delay(5);
  }
}

void LED::changeLed(){
   if(flag){
     allLed = led2;
     flag = false;
     delay(200);
   }else{
     allLed = led1;
     flag = true;
     delay(200);
   }
}