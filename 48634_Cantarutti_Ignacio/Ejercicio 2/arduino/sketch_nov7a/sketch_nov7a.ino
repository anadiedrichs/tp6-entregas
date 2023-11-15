const int PULSADOR1 = 2;
const int PULSADOR2 = 4;
const int PULSADOR3 = 6;
const int LED1 = 3;
const int LED2 = 5;
int ledActual = 1; // Iniciar con el LED1
int brilloLED1 = 0;
int brilloLED2 = 0;
int incremento = 1;
bool led1Encendido = false;
bool led2Encendido = false;

void setup() {
  pinMode(PULSADOR1, INPUT_PULLUP);
  pinMode(PULSADOR2, INPUT_PULLUP);
  pinMode(PULSADOR3, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600); // Inicializa la comunicación serial
}

void loop() {
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n'); // Lee el comando desde Processing
    if (comando == "ON1") {
      brilloLED1 = 255; // Establece el brillo al máximo
      led1Encendido = true;
    } else if (comando == "OFF1") {
      brilloLED1 = 0; // Apaga el LED1
      led1Encendido = false;
    } else if (comando == "ON2") {
      brilloLED2 = 255; // Establece el brillo al máximo
      led2Encendido = true;
    } else if (comando == "OFF2") {
      brilloLED2 = 0; // Apaga el LED2
      led2Encendido = false;
    }
  }

  // Maneja los botones físicos
  if (digitalRead(PULSADOR1) == LOW) {
    if (!led1Encendido) {
      brilloLED1 = 255; // Activa el LED1 al presionar el botón 1
      led1Encendido = true;
    } else {
      brilloLED1 = 0; // Apaga el LED1 si ya estaba encendido y se presiona el botón 1 nuevamente
      led1Encendido = false;
    }
  }
  if (digitalRead(PULSADOR2) == LOW) {
    if (!led2Encendido) {
      brilloLED2 = 255; // Activa el LED2 al presionar el botón 2
      led2Encendido = true;
    } else {
      brilloLED2 = 0; // Apaga el LED2 si ya estaba encendido y se presiona el botón 2 nuevamente
      led2Encendido = false;
    }
  }
  if (digitalRead(PULSADOR3) == LOW) {
    ledActual = (ledActual == 1) ? 2 : 1; // Cambia el LED actual al presionar el botón 3
    brilloLED1 = 0;
    brilloLED2 = 0;
    led1Encendido = false;
    led2Encendido = false;
  }

  // Aplica el brillo a los LEDs correspondientes
  analogWrite(LED1, brilloLED1);
  analogWrite(LED2, brilloLED2);
}
