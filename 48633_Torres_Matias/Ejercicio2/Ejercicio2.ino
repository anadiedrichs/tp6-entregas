int BUTTON1 = 2, BUTTON2 = 4, LED1 = 10, LED2 = 11;

class button{
  private:
  bool STATE;
  public:
  void changeState(int BUTTON){
    STATE = digitalRead(BUTTON);
  }
  void changeStateP(bool PROCESSING, int LED){
    if(PROCESSING){
      digitalWrite(LED,HIGH);
    }
    else digitalWrite(LED,LOW);
    delay(50);
  }
  bool returnState(){
    return STATE;
  }
}BUTTON_1, BUTTON_2;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON1,INPUT);
  pinMode(BUTTON2,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);

}

void loop() {

  BUTTON_1.changeState(BUTTON1);
  BUTTON_2.changeState(BUTTON2);

  if(BUTTON_1.returnState()){
    digitalWrite(LED1,HIGH);
    delay(50);
  }
  else digitalWrite(LED1,LOW);

  if(BUTTON_2.returnState()){
    digitalWrite(LED2,HIGH);
    delay(50);
  }
  else digitalWrite(LED2,LOW);
  Serial.print(BUTTON_1.returnState());
  Serial.print(',');
  Serial.println(BUTTON_2.returnState());

  /******************************************************************************************/
  //Leer los mensajes recibidos por Serial

  String mensaje = ""; // Inicializa una cadena vacía

    // Lee caracteres hasta que se reciba un salto de línea ('\n') o hasta que se alcance un límite máximo
    char caracter;
    int maxLongitud = 64; // Establece un límite máximo de longitud del mensaje
    int tiempoMaximoEspera = 5; // Establece un tiempo máximo de espera en milisegundos

    unsigned long inicioTiempo = millis();
    while (millis() - inicioTiempo < tiempoMaximoEspera) {
      if (Serial.available() > 0) {
        caracter = Serial.read();
        mensaje += caracter;
        if (caracter == '\n' || mensaje.length() >= maxLongitud) {
          // Se encontró un salto de línea o se alcanzó el límite máximo
          break;
        }
      }
    }

    // Procesa el mensaje si no está vacío
    if (mensaje.length() > 0) {
      // Verifica si el mensaje recibido es igual a "reinicio"
      if (mensaje.equals("encendido1\n")) {
        BUTTON_1.changeStateP(true,LED1);
      }
      if (mensaje.equals("encendido2\n")) {
        BUTTON_2.changeStateP(true,LED2);
      }
      if (mensaje.equals("apagado1\n")) {
        BUTTON_1.changeStateP(false,LED1);
      }
      if (mensaje.equals("apagado2\n")) {
        BUTTON_2.changeStateP(false,LED2);
      }
    }
    /**************************************************************************************************/

  delay(200);
}
