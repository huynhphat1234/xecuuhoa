#include <Arduino.h>
#include <Servo.h>
Servo myServo;
int8_t in1 =2; 
int8_t ena=3;
int8_t in2=4;
int8_t in3=7;
int8_t in4=6;
int8_t enb=5;
int8_t relay=12;
const int interval=1000;
///////////////////////

int8_t s1 =8;
int8_t s2=9;
int8_t s3=10;
////////////////////////
void setup(){
  Serial.begin(115200);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(relay,OUTPUT);
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(s3,INPUT);
  myServo.attach(11);

  
}
void phai(int ENA,int ENB){
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
  analogWrite(ena,ENA);
  analogWrite(enb,ENB);
}
void trai(int ENA,int ENB){
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  analogWrite(ena,ENA);
  analogWrite(enb,ENB);
}
void max1(int ENA,int ENB){
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  analogWrite(ena,ENA);
  analogWrite(enb,ENB);
}
void stop1(){
  
   analogWrite(ena,0);
  analogWrite(enb,0);
}
int8_t sensor1=0;
int8_t sensor2=0;
int8_t sensor3=0;
void doc_data(){
  sensor1=digitalRead(s1);
  //sensor2=digitalRead(s2);
  //sensor3=digitalRead(s3);
  // Serial.print("sensor1: ");
  // Serial.println(sensor1);
  // Serial.print("sensor2: ");
  // Serial.println(sensor2);
  // Serial.print("sensor3: ");
  // Serial.println(sensor3);
}
int8_t dung;
unsigned long hientai=0;
bool nghia=true;
void chay(){
  
  if (sensor1==0){
    phai(0,0);
    digitalWrite(relay,0);
  }
  else{
    max1(60,60);
    digitalWrite(relay,1);
  }
  
}
unsigned long now=0;

void loop(){
 
    if (nghia){
      max1(100,100);
      delay(50);
      nghia=false;
    }
    
  

  doc_data();
  chay();
  //myServo.write(90);
  
}
