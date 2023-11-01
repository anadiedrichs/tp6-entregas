const int PULSADOR1 = 2;
const int PULSADOR2 = 3;
const int PULSADOR3 = 4;
const int LED1 = 5;
const int LED2 = 6;
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
}

void loop() {
  // Si el LED actual es el 1
  if (ledActual == 1) {
    // Si PULSADOR1 está presionado y LED2 no está encendido, incrementa el brillo de LED1
    if (digitalRead(PULSADOR1) == LOW && !led2Encendido) {
      if (brilloLED1 < 255) {
        brilloLED1 += incremento;
        led1Encendido = true;
      }
    }
    // Si PULSADOR2 está presionado y LED2 no está encendido, inicia LED1 en su brillo máximo y disminuye
    if (digitalRead(PULSADOR2) == LOW && !led2Encendido) {
      analogWrite(LED1, 255);
      if (brilloLED1 > 0) {
        brilloLED1 -= incremento;
      }
    }
  }
  // Si el LED actual es el 2
  else if (ledActual == 2) {
    // Si PULSADOR1 está presionado y LED1 no está encendido, incrementa el brillo de LED2
    if (digitalRead(PULSADOR1) == LOW && !led1Encendido) {
      if (brilloLED2 < 255) {
        brilloLED2 += incremento;
        led2Encendido = true;
      }
    }
    // Si PULSADOR2 está presionado y LED1 no está encendido, inicia LED2 en su brillo máximo y disminuye
    if (digitalRead(PULSADOR2) == LOW && !led1Encendido) {
      analogWrite(LED2, 255);
      if (brilloLED2 > 0) {
        brilloLED2 -= incremento;
      }
    }
  }

  // Si PULSADOR3 está presionado, cambia el LED actual y reinicia las variables
  if (digitalRead(PULSADOR3) == LOW) {
    ledActual = (ledActual == 1) ? 2 : 1;
    led1Encendido = false;
    led2Encendido = false;
  }

  // Aplica el brillo a los LEDs correspondientes
  analogWrite(LED1, brilloLED1);
  analogWrite(LED2, brilloLED2);
}
