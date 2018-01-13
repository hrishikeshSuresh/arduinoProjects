int x,y,z;
void setup()
{ 
 Serial.begin(9600);
 pinMode(13,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 
 }
void loop()
{
 if(Serial.available()>0)
   {  if(Serial.read()=='X')
      { 
        x=Serial.parseInt();
         if(Serial.read()=='Y')
          {
            y=Serial.parseInt();
             if(Serial.read()=='Z')
              {
                z=Serial.parseInt();
              }
          }
      }
  digitalWrite(13,HIGH);
  delay(x);
  digitalWrite(13,LOW);
  delay(z);
  analogWrite(3,400);
  analogWrite(9,400);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  delay(x);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  delay(z);
   
   while(Serial.available()>0)
    {
      Serial.read();
    }
   }
}

