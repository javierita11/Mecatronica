#include <Servo.h>
Servo puerta;


int trig = 2;
int echo = 3;
int tiempo;
int distancia;
int angulo = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  puerta.attach(5); // PWM
  puerta.write(0);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo/58.2;
  Serial.println(distancia);
  delay(10);
  if(distancia<=20){
    puerta.write(180);
    delay(1000);
    puerta.write(0);
    delay(1000);
  }
  else{
  //Primera iteración, girar de 0 a 20 grados con incremento 1
  for (angulo = 0; angulo <= 20 or distancia<=20; angulo += 1) {
    //le decimos al servo que vaya al ángulo dado
    puerta.write(angulo);
    Serial.println(angulo); //imprimimos angulo actual
    delay(20); //pequeño delay para evitar problemas
  }
  //Segunda iteración, girar devuelta de 20 a 0 grados con incremento 1
  for (angulo = 20; angulo >= 0 or distancia<=20; angulo -= 1) {
    puerta.write(angulo);
    Serial.println(angulo); //imprimimos angulo actual
    delay(20); //pequeño delay para evitar problemas
  }
   //pausa antes de volver a girar
  }
}