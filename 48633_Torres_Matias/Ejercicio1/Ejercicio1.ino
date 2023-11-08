const int PULSADOR1 = 2, PULSADOR2 = 4, PULSADOR3 = 7;
int LED1 = 10, LED2 = 11;

class button{
  private:
  bool STATE;
  public:
  void changeState(int BUTTON){
    STATE = digitalRead(BUTTON);
  }
  bool returnState(){
    return STATE;
  }
};
button button1, button2, button3;

class led{
  private:
  int bright = 0;
  bool STATUS1 = true;
  bool STATUS2 = false;
  public:
  void addBright(bool state){
    if(state){
      delay(10);
      bright++;
      bright = constrain(bright,0,255);
    }
  }
  void decreaseBright(){
    for(int i = 255; i >= 0; i--){
      delay(10);
      bright = i;
      bright = constrain(bright, 0 ,255);
      analogWrite(LED1,bright);
    }
  }
  int returnBright(){
    return bright;
  }
  void chooseLed(){
    int aux;
    if(STATUS1){
      aux = LED2;
      LED2 = LED1;
      LED1 = aux;
      STATUS2 = true;
      STATUS1 = false;
    }
    else if(STATUS2){
      aux = LED1;
      LED1 = LED2;
      LED2 = aux;
      STATUS1 = true;
      STATUS2 = false;
    }
  }
};

led led1, led2;
void setup() {
  Serial.begin(9600);
  pinMode(PULSADOR1,INPUT);
  pinMode(PULSADOR2,INPUT);
  pinMode(PULSADOR3,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
}

void loop() {
  analogWrite(LED1,led1.returnBright());
  button1.changeState(PULSADOR1);
  button2.changeState(PULSADOR2);
  button3.changeState(PULSADOR3);
  led1.addBright(button1.returnState());
  if(button2.returnState()){
    led1.decreaseBright();
  }
  if(button3.returnState()){
    delay(500);
    led1.chooseLed();
  }
}
