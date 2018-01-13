void setup() 
{
 pinMode(8,OUTPUT);
 pinMode(LED_BUILTIN,OUTPUT);
 pinMode(9,OUTPUT);
}

void loop() 
{
 digitalWrite(8,HIGH);
 delay(100);
 digitalWrite(8,LOW);
 delay(100);
 digitalWrite(LED_BUILTIN,HIGH);
 delay(100);
 digitalWrite(LED_BUILTIN,LOW);
 delay(100);
}
