import processing.serial.*;

Serial puertoSerie;

int button1X = 100;
int button2X = 200;
int button3X = 300;
int buttonY = 75;
int buttonSize = 40;

void setup() {
  size(400, 200);
  String[] puertos = Serial.list();

  if (puertos.length > 0) {
    String puerto = puertos[0];
    puertoSerie = new Serial(this, puerto, 9600);
  } else {
    println("No se encontraron puertos seriales disponibles.");
  }
}

void draw() {
  background(255);

  fill(250, 50, 0);
  ellipse(button1X, buttonY, buttonSize, buttonSize);
  fill(0);
  textSize(16);
  textAlign(CENTER, CENTER);
  text("1", button1X, buttonY);

  fill(250, 250, 0);
  ellipse(button2X, buttonY, buttonSize, buttonSize);
  fill(0);
  textSize(16);
  textAlign(CENTER, CENTER);
  text("2", button2X, buttonY);

  fill(0, 200, 250);
  ellipse(button3X, buttonY, buttonSize, buttonSize);
  fill(0);
  textSize(16);
  textAlign(CENTER, CENTER);
  text("3", button3X, buttonY);
}

void mousePressed() {
  if (puertoSerie != null) {
    if (dist(mouseX, mouseY, button1X, buttonY) < buttonSize / 2) {
      puertoSerie.write('1');
    } else if (dist(mouseX, mouseY, button2X, buttonY) < buttonSize / 2) {
      puertoSerie.write('2');
    } else if (dist(mouseX, mouseY, button3X, buttonY) < buttonSize / 2) {
      puertoSerie.write('3');
    }
  } else {
    println("No se estableció la conexión serial.");
  }
}
