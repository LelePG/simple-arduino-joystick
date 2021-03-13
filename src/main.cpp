#include <Arduino.h>
#include "Keyboard.h"

#define eixoX 9
#define eixoY 10

void movimentaX(int leitura);
void movimentaY(int leitura);

void setup() {
  
  pinMode(eixoX, INPUT);
  pinMode(eixoY,INPUT);
  Serial.begin(9600);
}

int leituraX, leituraY;

void loop() {
  leituraX = map(analogRead(eixoX), 0, 1023, -1, 2);
  leituraY = map(analogRead(eixoY), 0, 1023, -1, 2);

  movimentaX(leituraX);
  movimentaY(leituraY);
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