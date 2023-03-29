#include <MPU6050_tockn.h>
#include <Wire.h>

#define pinLedX 12
#define pinLedY 11
#define pinLedZ 10

#define MPU6050_ADDR 0x68

#define DEBUG
MPU6050 mpu6050(Wire);

float anguloX;
float anguloY;
float anguloZ;

unsigned long controleTempo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu.6050.calcGyroOffsets(false);

  pinMode(pinLedX,OUTPUT);
  pinMode(pinLedY,OUTPUT);
  pinMode(pinLedZ,OUTPUT);
  digitalWrite(pinLedX,HIGH);
  digitalWrite(pinLedY,HIGH);
  digitalWrite(pinLedZ,HIGH);
  delay(500);
  digitalWrite(pinLedX,LOW);
  digitalWrite(pinLedY,LOW);
  digitalWrite(pinLedZ,LOW);
  #ifdef DEBUG
  Serial.print("fim setup");
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
  mpu6050.update();
  anguloX = mpu6050.getAngleX();
  anguloY = mpu6050.getAngleY();
  anguloZ = mpu6050.getAngleZ();

  if (anguloX >=25){
    digitalWrite(pinLedX,HIGH);
  }else if(anguloX <= -25){
    digitalWrite(pinLedX,HIGH);
  }else{
    digitalWrite(pinLedX,LOW);
  }
  if (anguloY >=25){
    digitalWrite(pinLedY,HIGH);
  }else if(anguloY <= -25){
    digitalWrite(pinLedY,HIGH);
  }else{
    digitalWrite(pinLedY,LOW);
  }
  if (anguloZ >=25){
    digitalWrite(pinLedZ,HIGH);
  }else if(anguloZ <= -25){
    digitalWrite(pinLedZ,HIGH);
  }else{
    digitalWrite(pinLedZ,LOW);
  }
}
