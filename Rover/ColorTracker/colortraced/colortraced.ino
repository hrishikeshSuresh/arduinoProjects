int x,y,z;
void setup()
{
Serial.begin(9600);
pinMode(LED_BUILTIN,OUTPUT);  
}

void loop() 
{
  if(Serial.available()>0)
  {
    if(Serial.read()=='X')
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
    digitalWrite(LED_BUILTIN,HIGH);
    delay(x);
    digitalWrite(LED_BUILTIN,LOW);
    delay(y);
    while(Serial.available()>0)
    {
      Serial.read();
    }
  }
}

