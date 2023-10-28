

import processing.serial.*;
Serial myPort;



//VARIABLES AUXILIARES//
boolean CambioDeColor1=true;
boolean CambioDeColor2=true;
int Led2;
int Led1;
int MensajeLed1;
int MensajeLed2;



//CONFIGURACION INICIAL//

void setup()
{
  size(300,300);
  background(190);
  frameRate(60);
  
  
   //RECTANGULO ENTRADAS//
  fill(255); 
  rect(20,50,100,30); //dibujo un rectangulo en (x,y,ancho,alto)
  stroke(0);//contorno negro
  textSize(18);//tamaño del texto
  fill(255,0,0); //color de la letra
  text("ENTRADAS",25,70); //texto y posicion en x,y
  
  
  //RECTANGULO SALIDAS//
  fill(255);
  rect(20,200,100,30);
  stroke(0);
  textSize(18);
  fill(255,0,0);
  text("SALIDAS",28,220);
  
  
  //RECTANGULO E1//
  fill(255); 
  rect(width/2,50,50,30); 
  stroke(0);
  textSize(18);
  fill(255,0,0); 
  text("E1",9+width/2,70); 
  
  
   //RECTANGULO E2//
  fill(255); 
  rect(70+width/2,50,50,30); 
  stroke(0);
  textSize(18);
  fill(255,0,0); 
  text("E2",80+width/2,70); 
  
  
  //CIRCUNFERENCIA LED1 //
  fill(255);
  ellipse(15+width/2,215,50,50);
  stroke(0);
  textSize(18);
  fill(255,0,0);
  text("L1",5+width/2,219);
  
  
  //CIRCUNFERENCIA LED2//
  fill(255);
  ellipse(90+width/2,215,50,50);
  stroke(0);
  textSize(18);
  fill(255,0,0);
  text("L2",80+width/2,219);
  
  //PARTE COMUNICACION//
  //String portName = Serial.list()[1];
  
  myPort = new Serial(this, "COM3", 9600);
} //FIN VOID SETUP()//



//PROGRAMA PRINCIPAL QUE ENTRA DENTRO DE UN LOOP//



void draw()
{
  //CONFIGURACION SI ME APRETAN E1//
  
 if(enRect(width/2,50,50,30)==true && mousePressed)
 {
  //Pinto el fondo de E1, como que se prsiono//
  if(CambioDeColor1==true)
  {
    fill(0,230,0); 
    rect(width/2,50,50,30); 
    stroke(0);
    textSize(18);
    fill(255,0,0); 
    text("E1",9+width/2,70); 
  }else  { 
    
          fill(255); 
          rect(width/2,50,50,30);  //si no lo dejo blanco al fondo como que no se presiono//
          stroke(0);
          textSize(18);
          fill(255,0,0); 
          text("E1",9+width/2,70); 
        }
  
  //Pinto el fondo de encendido del led 1, porque se prendio//
  
  if(CambioDeColor1==true) //si esta encendido pongo el fndo de L1 en verde//
  {
    fill(0,230,0);
    ellipse(15+width/2,215,50,50); 
    stroke(0);
    textSize(18);
    fill(255,0,0);
    text("L1",5+width/2,219);
    
    //Envio el dato al arduino para que encienda el Led 1//
    MensajeLed1=1;
    myPort.write(MensajeLed1);
  }else {
    
        fill(255);
        ellipse(15+width/2,215,50,50);  //sino, pongo el fondo del led L1 en blanco, como apagado//
        stroke(0);
        textSize(18);
        fill(255,0,0);
        text("L1",5+width/2,219);
        
        //Como lo voy a apagar, pinto blanco el fondo de L1 en la pantalla y mando un 0 a arduino para apagarlo//
        MensajeLed1=0;
        myPort.write(MensajeLed1);
        }
 
  //Actualizacion de la variable que maneja el color en la interfaz//
  CambioDeColor1=!CambioDeColor1;
  delay(150);
 }
 
 //Una vez verificado si se presiono para el led 1, verifico si me lo apagaron desde arduino//
 
 Led1=myPort.read();
 if(Led1==1) //¿me lo prendieron desde arduino?
 {
    fill(0,230,0); 
    rect(width/2,50,50,30);  //fondo de E1 en verde//
    stroke(0);
    textSize(18);
    fill(255,0,0); 
    text("E1",9+width/2,70); 
    
    fill(0,230,0);
    ellipse(15+width/2,215,50,50); //fonde de L1 en verde//
    stroke(0);
    textSize(18);
    fill(255,0,0);
    text("L1",5+width/2,219);
    
   
      if(CambioDeColor1==true)
      {
         CambioDeColor1=!CambioDeColor1;
      }
 }
 
  if(Led1==0) //¿me lo apagaron desde arduino?
 {
    fill(255); 
    rect(width/2,50,50,30); 
    stroke(0);
    textSize(18);
    fill(255,0,0); 
    text("E1",9+width/2,70);
    
    fill(255);
    ellipse(15+width/2,215,50,50);
    stroke(0);
    textSize(18);
    fill(255,0,0);
    text("L1",5+width/2,219);
    if(CambioDeColor1==false)
    {
       CambioDeColor1=!CambioDeColor1;
    }
 }
 
 //CONFIGURACION SI ME PRESIONAN E2//
 
 //Realizo exactamente los mismo para el boton E2//
 
 if(enRect(70+width/2,50,50,30)==true && mousePressed)
 {
   
 //Pinto el fondo de E2, como que se prsiono//
     if (CambioDeColor2==true) 
     {
      
        fill(10,190,10); //Color verde
        rect(70+width/2,50,50,30); 
        stroke(0);
        textSize(18);
        fill(255,0,0); 
        text("E2",80+width/2,70); 
     }else
       {
          fill(255); 
          rect(70+width/2,50,50,30); 
          stroke(0);
          textSize(18);
          fill(255,0,0); 
          text("E2",80+width/2,70);  
       }
    if (CambioDeColor2==true)
      {
        fill(10,190,10);
        ellipse(90+width/2,215,50,50);
        stroke(0);
        textSize(18);
        fill(255,0,0);
        text("L2",80+width/2,219);
        MensajeLed2=2;
        myPort.write(MensajeLed2);
      }else 
          {  
            fill(255);
            ellipse(90+width/2,215,50,50);
            stroke(0);
            textSize(18);
            fill(255,0,0);
            text("L2",80+width/2,219);
            MensajeLed2=3;
            myPort.write(MensajeLed2);
          }
 CambioDeColor2=!CambioDeColor2;
 delay(150);

//Chequeo si me han enviado datos para el LED 2 desde arduino//
 
}

 
  if(Led1==2)
     {
            fill(10,190,10);
            ellipse(90+width/2,215,50,50);
            stroke(0);
            textSize(18);
            fill(255,0,0);
            text("L2",80+width/2,219);
            
            fill(10,190,10); //Color verde
            rect(70+width/2,50,50,30); 
            stroke(0);
            textSize(18);
            fill(255,0,0); 
            text("E2",80+width/2,70); 
            
             if(CambioDeColor2==true)
             {
                CambioDeColor2=!CambioDeColor2;
             }
     }
     
  if(Led1==3)
    {
            fill(255);
            ellipse(90+width/2,215,50,50);
            stroke(0);
            textSize(18);
            fill(255,0,0);
            text("L2",80+width/2,219);
            fill(255); 
            rect(70+width/2,50,50,30); 
            stroke(0);
            textSize(18);
            fill(255,0,0); 
            text("E2",80+width/2,70);  
            
            if(CambioDeColor2==false)
            {
               CambioDeColor2=!CambioDeColor2;
            }
    }  
    
} //FIN VOID DRAW()//



//FUNCIONES USADAS EN PROGRAMA CREADAS POR NOSOTROS//

//FUNCION PARA DETECTAR SI ESTOY DENTRO DE UN RECTANGULO//

boolean enRect(int x, int y, int ancho, int alto)  
{
  if (mouseX >= x && mouseX <= x+ancho &&  mouseY >= y && mouseY <= y+alto) 
      {
        return true;
      } 
      else 
      {
        return false;
      }
}
