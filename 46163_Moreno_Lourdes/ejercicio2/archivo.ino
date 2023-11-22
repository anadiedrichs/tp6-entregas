// Definir los pines utilizados
const int PULSADOR1 = 2;
const int PULSADOR2 = 3;
const int PULSADOR3 = 4;
const int LED1 = 5;
const int LED2 = 6;

// Definir los estados de la máquina de estados
enum Estado {
  ESPERANDO,
  INCREMENTANDO,
  DECREMENTANDO,
  CAMBIANDO_LED
};

// Inicializar la máquina de estados en el estado ESPERANDO
Estado estado_actual = ESPERANDO;

// Inicializar los valores del brillo y del LED actual
int brillo = 0;
int led_actual = LED1;

void setup() {
  // Configurar los pines como entrada o salida
  pinMode(PULSADOR1, INPUT);
  pinMode(PULSADOR2, INPUT);
  pinMode(PULSADOR3, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  // Inicializar el puerto serie a una velocidad de 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Leer los pulsadores
  int pulsador1 = digitalRead(PULSADOR1);
  int pulsador2 = digitalRead(PULSADOR2);
  int pulsador3 = digitalRead(PULSADOR3);

  // Actualizar la máquina de estados según los pulsadores
  switch (estado_actual) {
    case ESPERANDO:
      if (pulsador1 == HIGH) {
        estado_actual = INCREMENTANDO;
      } else if (pulsador2 == HIGH) {
        estado_actual = DECREMENTANDO;
        brillo = 255; // Iniciar con el brillo máximo
      } else if (pulsador3 == HIGH) {
        estado_actual = CAMBIANDO_LED;
        led_actual = (led_actual == LED1) ? LED2 : LED1; // Cambiar al otro LED
      }
      break;

    case INCREMENTANDO:
      analogWrite(led_actual, brillo);
      brillo++;
      if (brillo > 255) {
        brillo = 0;
        estado_actual = ESPERANDO;
      }
      break;

    case DECREMENTANDO:
      analogWrite(led_actual, brillo);
      brillo--;
      if (brillo < 0) {
        brillo = 0;
        estado_actual = ESPERANDO;
      }
      break;

    case CAMBIANDO_LED:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      analogWrite(led_actual, brillo);
      if (pulsador3 == HIGH) {
        led_actual = (led_actual == LED1) ? LED2 : LED1; // Cambiar al otro LED
        delay(100); // Esperar para evitar rebotes del pulsador
      } else {
        estado_actual = ESPERANDO;
      }
      break;
  }

  // Enviar el estado actual de la máquina de estados por el puerto serie
  Serial.println(estado_actual);//Este código utiliza una variable estado_actual para almacenar el estado actual de la máquina de estados. En cada iteración del bucle principal (loop()), se leen los pulsadores y se actualiza la máquina de estados según su valor. Luego, se ejecuta la acción correspondiente a cada estado.

//Además, este código envía el estado actual de la máquina de estados por el puerto serie en cada iteración. Esto puede ser útil para depurar el programa o para sincronizar el estado del programa con una interfaz gráfica en Processing.
}
