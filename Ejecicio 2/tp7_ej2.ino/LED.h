class LED{
private:
 int all_led,led1,led2;
 int contador;
 bool flag;
public:
  LED(int,int);
  ~LED(){};
  void SlowUpLed();
  void SlowDownLed();
  void ChangeLed();
};

LED::LED(int Led1,int Led2){
  all_led = Led1;
  led1 = Led1;
  led2 = Led2;
  contador = 0;
  flag = true;
}

void LED::SlowUpLed(){
     digitalWrite(all_led,LOW);
    int contador = 0;
    for(contador = 0; contador < 256; contador++){
      analogWrite(all_led,contador);
      delay(5);
    }
}

void LED::SlowDownLed(){
  digitalWrite(all_led,HIGH);
  int contador = 256;
  for(contador = 256; contador >= 0; contador--){
    analogWrite(all_led,contador);
    delay(5);
  }
}

void LED::ChangeLed(){
   if(flag){
     all_led = led2;
     flag = false;
     delay(200);
   }else{
     all_led = led1;
     flag = true;
     delay(200);
   }
}
