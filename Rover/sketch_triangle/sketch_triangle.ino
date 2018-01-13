void setup()
{
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
}

void loop() 
{
 
  analogWrite(3,255);
  analogWrite(9,255);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  delay(100);
 
 }
