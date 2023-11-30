import processing.serial.*;
import controlP5.*;

Serial myPort;
ControlP5 cp5;

int buttonPin1 = 2;
int buttonPin2 = 3;
int buttonPin3 = 4;
int ledPin1 = 5;
int ledPin2 = 6;

void setup() {
  size(400, 300);

  // Configurar la comunicación serial con la placa Arduino
  myPort = new Serial(this, Serial.list()[0], 9600);

  // Crear la interfaz gráfica de usuario
  cp5 = new ControlP5(this);
  cp5.addToggle("button1")
     .setPosition(50, 50)
     .setSize(100, 20)
     .setValue(false)
     .setLabel("Pulsador 1");

  cp5.addToggle("button2")
     .setPosition(50, 100)
     .setSize(100, 20)
     .setValue(false)
     .setLabel("Pulsador 2");

  cp5.addToggle("button3")
     .setPosition(50, 150)
     .setSize(100, 20)
     .setValue(false)
     .setLabel("Pulsador 3");

  cp5.addToggle("led1")
     .setPosition(200, 50)
     .setSize(100, 20)
     .setValue(false)
     .setLabel("LED1");

  cp5.addToggle("led2")
     .setPosition(200, 100)
     .setSize(100, 20)
     .setValue(false)
     .setLabel("LED2");
}

void draw() {
}

void button1(boolean state) {
  if (state) {
    myPort.write('a');
    println("Pulsador 1 activado");
  } else {
    myPort.write('b');
    println("Pulsador 1 desactivado");
  }
}

void button2(boolean state) {
  if (state) {
    myPort.write('c');
    println("Pulsador 2 activado");
  } else {
    myPort.write('d');
    println("Pulsador 2 desactivado");
  }
}

void button3(boolean state) {
  if (state) {
    myPort.write('e');
    println("Pulsador 3 activado");
  } else {
    myPort.write('f');
    println("Pulsador 3 desactivado");
  }
}

void led1(boolean state) {
   if (state) {
      myPort.write('g');
      println("LED1 encendido");
   } else {
      myPort.write('h');
      println("LED1 apagado");
   }
}

void led2(boolean state) {
   if (state) {
      myPort.write('i');
      println("LED2 encendido");
   } else {
      myPort.write('j');
      println("LED2 apagado");
   }
}
