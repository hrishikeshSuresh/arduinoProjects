const int trigPin=2;
const int echoPin=4;
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  long duration,inches;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration=pulseIn(echoPin, HIGH);
  inches=duration/58.2;
  Serial.print(inches);
  Serial.println();
  delay(100);
}
