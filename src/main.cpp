#include <Arduino.h>

#define eixoX 9
#define eixoY 10

void setup() {
  
  pinMode(eixoX, INPUT);
  pinMode(eixoY,INPUT);
  Serial.begin(9600);
}

int leituraX, leituraY;

void loop() {
  leituraX = map(analogRead(eixoX), 0, 1023, -1, 2);
  leituraY = map(analogRead(eixoY), 0, 1023, -1, 2);

  //Movimentação em X
  if(leituraX < 0){
    Serial.println("direita");
  }
  else if (leituraX > 0){
    Serial.println("Esquerda");
  }

  //Movimentação em Y
  if(leituraY < 0){
    Serial.println("cima");
  }
  else if (leituraY > 0){
    Serial.println("Baixo");
  }
  
  delay(100);
}

