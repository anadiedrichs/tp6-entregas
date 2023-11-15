boolean Entrada1Presionada = false; //<>//
boolean Entrada2Presionada = false;
color colorSalida1 = color(255); 
color colorSalida2 = color(255);
color colorEntrada1 = color(255); 
color colorEntrada2 = color(255);
import processing.serial.*;
Serial puertoSerie;
void setup()
{
size(290, 200);
background(0);
print(Serial.list());
puertoSerie = new Serial(this, Serial.list()[1], 9600);
}
void mousePressed()
{
// Puedes agregar acciones específicas cuando se presionan los botones
if (mouseX > 10 && mouseX < 140 && mouseY > 10 && mouseY < 60)
 {
   Entrada1Presionada=true;
   colorSalida1 = color(255,0,0);
   colorEntrada1 = color(0,255,0);
   puertoSerie.write("ON1\n");
   print("ON1\n");
   
 }
 if (mouseX > 150 && mouseX < 280 && mouseY > 10 && mouseY < 60)
 {
   Entrada2Presionada=true;
   colorSalida2 = color(255,255,0);
   colorEntrada2 = color(0,255,0);
   puertoSerie.write("ON2\n");
   print("ON2\n");
 }
}
void draw()
{

fill(colorEntrada1);
rect(10, 10, 130, 50); // Botón 1
fill(0, 0, 0);
textAlign(CENTER, CENTER);
textSize(25);
text("Entrada 1", 75, 35); // texto del botón rectangular 1
fill(colorEntrada2);
rect(150, 10, 130, 50); // Botón 2
fill(0,0,0);
textSize(25);
text("Entrada 2", 215, 35);//texto del boton rectangular 2
fill(colorSalida1);
ellipse(75, 150, 50,50); // Salida 1
fill(0);
textSize(40);
text("S1", 75, 150);//texto del boton circular 1
fill(colorSalida2);
ellipse(215, 150, 50, 50);//Salida 2
fill(0);
textSize(40);
text("S2", 215, 150);//texto del boton circular 2
if(Entrada1Presionada == false && Entrada2Presionada == false)
{
if (puertoSerie.available() > 0)
{
    String datos = puertoSerie.readStringUntil('\n');
    if (datos != null)
    {
      String[] estados = split(datos,',');
      if (estados.length !=0)
      {
        int estadoBoton1 = int(trim(estados[0]));
        int estadoBoton2 = int(trim(estados[1]));
        boton1(estadoBoton1);
        boton2(estadoBoton2);
      }
    }
  }
}
}
void boton1(int estadoBoton1)
{
  if(estadoBoton1 ==1)
  {
    colorSalida1 = color(255,0,0);
    colorEntrada1 = color(178, 214, 63);
  }
  else
  {
    colorSalida1 = color(255);
    colorEntrada1 = color(255);
  }
}
void boton2 (int estadoBoton2)
{
  if(estadoBoton2 ==1)
  {
    colorSalida2 = color(255,255,0);
    colorEntrada2 = color(178, 214, 63);
  }
  else
  {
    colorSalida2 = color(255);
    colorEntrada2 = color(255);
  }
}
void mouseReleased()
{
  Entrada1Presionada=false;
  Entrada2Presionada=false;
  puertoSerie.write("OFF1\n");
  print("OFF1\n");
  puertoSerie.write("OFF2\n");
  print("OFF2\n");
  colorSalida1 = color (92,51,10);
  colorEntrada1 = color (255);
  colorSalida2 = color (92,51,10);
  colorEntrada2 = color (255);
}
