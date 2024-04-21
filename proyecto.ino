
#include <Servo.h>
Servo puerta;

int trig = 2;
int echo = 3;
int tiempo;
int distancia;

void setup(){
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  puerta.attach(9);
}

void loop(){
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo/58.2;
  Serial.println(distancia);
  delay(500);
  
  if (distancia <= 15)
  {
    puerta.write(180);
  }
  
  if (distancia > 15)
  {
    puerta.write(0);
  }
}
  
  