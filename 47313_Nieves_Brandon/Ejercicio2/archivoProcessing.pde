import processing.serial.*;
Processing Objeto;
Serial MiPuerto;

class Processing{
  color ColorFondo, ColorRectangulo, ColorApagado, ColorEncendido;
  float posicionX, posicionY, radio;
  boolean EstadoLed1, EstadoLed2;
  Processing(){
    ColorFondo = color(0);
    ColorRectangulo = color(#FAFAFA);
    ColorApagado = color(#FAFAFA);
    ColorEncendido = color(#FF0505);
    posicionX = 0;
    posicionY = 0;
    radio = 0;
    EstadoLed1 = false;
    EstadoLed2 = false;}
    
  void ColorLed( boolean Estado, int x ){  //Recibe: Estado del LED y la posicion del eje x. Devuelve: Nada. Funcion: Dibuja el circulo representativo del LED con un color en funcion de su estado (encendido o apagado)
    if( Estado == false ){
    fill(ColorApagado);
    circle(x, 400, 100);
    }else{
    fill(ColorEncendido);
    circle(x, 400, 100);} }
    
  boolean PresionarRectangulo( float PosicionX, float PosicionY, boolean Estado, int Rectangulo ){ //Recibe: Estado de LED, Coordenadas del mouse y distancia del eje x del rectangulo . Devuelve: El Estado (booleano) del LED cambiado. Funcion: Cambia el estado del LED si el rectangulo es presionado
    if( ( PosicionX <= (150/2) ) && ( PosicionY <= (100/2) ) ){
      fill(ColorEncendido);
      rect(Rectangulo,200,150,100);
      Estado = !Estado;
      switch( Rectangulo ){              //Envia por puero serial 
        case 200:{MiPuerto.write("LED1\n");}
          break;
        case 500:{MiPuerto.write("LED2\n");}
          break;
      }
    }
    return (Estado);}
    
  boolean PresionarCirculo( float radio, boolean Estado, int Circulo ){    //Recibe: Estado de LED, coordenadas del mouse y distancia del eje x del circulo. Devuelve: El Estado (booleano) del LED cambiado. Funcion: Cambia el Estado del LED si es presionado el circulo del mismo
    if( radio <= 50 ){
      Estado = !Estado;
      switch( Circulo ){                  //Envia por puerto serial
        case 200:{MiPuerto.write("LED1\n");}
          break;
        case 500:{MiPuerto.write("LED2\n");}
          break;
      }
    }  
    return (Estado);}  
};

void setup() {
  //printArray(Serial.list());
  MiPuerto = new Serial(this, Serial.list()[2], 9600);    //Declaro el puerto a utilizar
  size(700, 600);                                         //Declaro el tamaño de patalla
  Objeto = new Processing();                              //Inicializo el objeto
  rectMode(CENTER);                                       //Dibuja un rectangulo con coordenadas centralizadas
  ellipseMode(CENTER);
}
void draw(){
  background(Objeto.ColorFondo);
  fill(Objeto.ColorRectangulo);
  rect(200,200,150,100);
  rect(500,200,150,100);
  Objeto.ColorLed( Objeto.EstadoLed1, 200 );              //Dibujo LED 1
  Objeto.ColorLed( Objeto.EstadoLed2, 500 );              //Dibujo LED 2
}
void mousePressed() {                                     //Funcion: Al presionar el click del mouse, dependiendo de la posicion, se encienden o apagan los LEDs
  Objeto.EstadoLed1 = Objeto.PresionarRectangulo( dist(mouseX, 0, 200, 0), dist(0, mouseY, 0, 200), Objeto.EstadoLed1, 200 );
  Objeto.EstadoLed2 = Objeto.PresionarRectangulo( dist(mouseX, 0, 500, 0), dist(0, mouseY, 0, 200), Objeto.EstadoLed2, 500 );
  Objeto.EstadoLed1 = Objeto.PresionarCirculo( dist(mouseX, mouseY, 200, 400), Objeto.EstadoLed1, 200 );
  Objeto.EstadoLed2 = Objeto.PresionarCirculo( dist(mouseX, mouseY, 500, 400), Objeto.EstadoLed2, 500 );
}
void serialEvent (Serial  MiPuerto){               //Recibe: Valores del puesto serie. Devuelve: Nada. Funcion: Cambia el estado del LED si recibe la letra H o D.
  char dato = MiPuerto.readChar();
    if( dato == 'H' ){
      Objeto.EstadoLed1 = !Objeto.EstadoLed1;}
     if( dato == 'D' ){
      Objeto.EstadoLed2 = !Objeto.EstadoLed2;}
  }   
