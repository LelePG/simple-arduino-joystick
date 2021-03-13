#include <Arduino.h>
#include "Keyboard.h"

#define eixoX 9
#define eixoY 10
#define btn1 4
#define btn2 5
#define btn3 6
#define btn4 7

void movimentaX(int leitura);
void movimentaY(int leitura);

void setup() {
  pinMode(eixoX, INPUT);
  pinMode(eixoY,INPUT);
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  pinMode(btn3,INPUT);
  pinMode(btn4,INPUT);
  Keyboard.begin();
  Serial.begin(9600);
}

int leituraX, leituraY;

void loop() {
  leituraX = map(analogRead(eixoX), 0, 1023, -1, 2);
  leituraY = map(analogRead(eixoY), 0, 1023, -1, 2);

 // movimentaX(leituraX);
 // movimentaY(leituraY);
  if(digitalRead(btn1)){
  /* Keyboard.press('n');
   delay(50);
   Keyboard.release('n');*/
   Serial.println("A");
  }
  else if(digitalRead(btn2)){
   /*Keyboard.press('v');
   delay(50);
   Keyboard.release('v');*/
   Serial.println("B");
  }
  else if(digitalRead(btn3)){
  /* Keyboard.press(' ');
   delay(50);
   Keyboard.release(' ');*/
   Serial.println("C");
  }
  else if(digitalRead(btn4)){
   // Keyboard.write(KEY_ESC);
   Serial.println("d");
  }
  delay(50);

}

void movimentaX(int leitura){
  if(leitura < 0){
    Keyboard.press(KEY_RIGHT_ARROW);
  }
  else if (leitura > 0){
    Keyboard.press(KEY_LEFT_ARROW);
  }
  else{
    Keyboard.release(KEY_RIGHT_ARROW);
    Keyboard.release(KEY_LEFT_ARROW);
  }
}

void movimentaY(int leitura){
 if(leitura < 0){
    Keyboard.press(KEY_UP_ARROW);
  }
  else if (leitura > 0){
    Keyboard.press(KEY_DOWN_ARROW);
  }
  else{
    Keyboard.release(KEY_UP_ARROW);
    Keyboard.release(KEY_DOWN_ARROW);
  }
}


/*
nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
*/