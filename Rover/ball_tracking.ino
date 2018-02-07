//Made by Master Hrishikesh ,the Handsome Devil of PES
 // incoming serial byte
 char inbyte;
#include <Servo.h>
int count=1;
Servo myservo; 
void setup()
{
 // start serial port at 9600 bps;
 Serial.begin(9600);
  myservo.attach(8);
  myservo.write(0); 
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(3, OUTPUT);

}
void loop()
{
 //if we get a valid byte,read analog ins:
 
  // get incoming byte:
  //delay(2000);
     inbyte = Serial.read();
     //Serial.println(inbyte);
     //Serial.println("HI");


if (inbyte == 'R') {
 // delay(100);
 
 Serial.println("HI");
 analogWrite(9,255);
 digitalWrite(10,LOW);
 digitalWrite(6,LOW);
 analogWrite(3,255);
 digitalWrite(11,HIGH);
 digitalWrite(5,LOW); 
// delay(50);
 }

 
else if (inbyte == 'L') 
{
 // delay(100);

 Serial.println("HI");
 analogWrite(9,255);
 digitalWrite(6,HIGH);
 digitalWrite(10,LOW);
 analogWrite(3,255);
 digitalWrite(5,LOW);
 digitalWrite(11,LOW); 
// delay(100);
 }

 
else if (inbyte == 'F')
{
  //delay(100);
  Serial.println("HI");
 analogWrite(9,255);
 digitalWrite(6,HIGH);
 digitalWrite(10,LOW);
 analogWrite(3,255);
 digitalWrite(11,HIGH);
 digitalWrite(5,LOW); 
 //delay(100);
 }

 
else if (inbyte == 'S') 
 {
 
analogWrite(9,255);
analogWrite(3,255);
digitalWrite(6,LOW);
digitalWrite(5,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
  
  
  delay(1000);
  myservo.write(60);
  delay(2000);

analogWrite(9,255);
analogWrite(3,255);
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
delay(3000);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
delay(500);
count=0;
myservo.write(60);
delay(3000);

 }
}
