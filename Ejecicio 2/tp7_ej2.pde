import processing.serial.*;
Serial MiPuerto;


boolean boton=true,boton3=true,led1 = true,led2 = true;
int Lectura=0;

void setup(){
  printArray(Serial.list());
  background(255);
  fullScreen();
  //size(800,700);
  MiPuerto = new Serial(this,Serial.list()[1],9600);
  MiPuerto.clear();
  print(MiPuerto);
}

void draw(){
  background(255);
  fill(255);
  strokeWeight(4);
  stroke(0);
  //Circulos que representan los leds.
  if(!boton3){ 
    fill(#73E44B);
    circle(width/2+124,height/2-310,50);
    if(!boton){
      fill(#73E44B);
      circle(width/2+124,height/2-200,150);
      led2 = false;
    }else{
      fill(255);
      circle(width/2+124,height/2-200,150);
      led2 = true;
    }
    
    if(led1){
      fill(255);
      circle(width/2+350,height/2-200,150);
    }else{
      fill(#73E44B);
      circle(width/2+350,height/2-200,150);
    }
    
  }else{
    fill(#73E44B);
    circle(width/2+350,height/2-310,50);
    if(!boton){
      fill(#73E44B);
      circle(width/2+350,height/2-200,150);
      led1 = false;
    }else{
      fill(255);
      circle(width/2+350,height/2-200,150);
      led1 = true;
    }
    
    if(led2){
      fill(255);
      circle(width/2+124,height/2-200,150);
    }else{
      fill(#73E44B);
      circle(width/2+124,height/2-200,150);
    }
    
  }
  
  //Botones que generan acciones.
  fill(#FF0000);
  square(width/2-75,height/2+100,150);
  square(width/2+150,height/2+100,150);
  square(width/2+375,height/2+100,150);
  //texto que indica que significal cada cosa.
  fill(#5BF26A);
  textSize(100);
  text("Botones:",width/2-550,height/2+180);
  text("LEDs:",width/2-550,height/2-180);
  
  //Partr de lectura pos usb-seria
  if(MiPuerto.available()>0){
    Lectura = MiPuerto.read();
    delay(100);
    if(Lectura == 1){
       boton = false; 
    }
    if(Lectura == 2){
       boton = true; 
    }
    if(Lectura == 3){
      if(boton3){
         boton3 = false; 
     
        if(led2){
          boton = true;
        }else{
          boton = false;
        }
     
        }else{
          boton3 = true;
           
          if(led1){
            boton = true;
          }else{
            boton = false;
          } 
       }
    }
  }
}

void mousePressed(){

 if((width/2-75)<mouseX && (height/2+100)<mouseY && (width/2+75)>mouseX && (height/2+250)>mouseY){
   MiPuerto.write(1);
   boton = false;
 }
 
 if((width/2+150)<mouseX && (height/2+100)<mouseY && (width/2+300)>mouseX && (height/2+250)>mouseY){
   MiPuerto.write(2);
   boton = true;
 }
 
 if((width/2+375)<mouseX && (height/2+100)<mouseY && (width/2+525)>mouseX && (height/2+250)>mouseY){
   MiPuerto.write(3);
   if(boton3){
     boton3 = false; 
     
     if(led2){
       boton = true;
     }else{
       boton = false;
     }
     
   }else{
     boton3 = true;
     
     if(led1){
       boton = true;
     }else{
       boton = false;
     }
     
   }
   
 }
 
delay(100);
}
