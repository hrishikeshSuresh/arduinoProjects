const int trigger1 = 2;    //Trigger pin of 1st Sesnor
const int echo1 = 3;       //Echo pin of 1st Sesnor
const int trigger2 = 4;    //Trigger pin of 2nd Sesnor
const int echo2 = 5;       //Echo pin of 2nd Sesnor
const int trigger3 = 6;
const int echo3 = 7;
const int trigger4 = 8;
const int echo4 = 9;
const int trigger5 = 10;
const int echo5 = 11;

long time_taken;
int dist,distL,distR;
int distMove1, distMoveLeft, distMoveRight;
 
void setup() {
Serial.begin(9600);   
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 
pinMode(trigger3, OUTPUT); 
pinMode(echo3, INPUT); 
pinMode(trigger4, OUTPUT); 
pinMode(echo4, INPUT);
pinMode(trigger5, OUTPUT);
pinMode(echo5, INPUT);
}

/*###Function to calculate distance###*/
void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>50)
dist = 50;
}

void loop() { //infinite loopy
calculate_distance(trigger1,echo1);
distL =dist; //get distance of left sensor

calculate_distance(trigger2,echo2);
distR =dist; //get distance of right sensor

calculate_distance(trigger3,echo3);
distMove1 =dist; //get distance of left sensor

calculate_distance(trigger4,echo4);
distMoveLeft =dist; //get distance of left sensor

calculate_distance(trigger5,echo5);
distMoveRight =dist; //get distance of left sensor


//Comment for perfection
Serial.print("L=");
Serial.println(distL);
Serial.print("R=");
Serial.println(distR);
Serial.print("Move1=");
Serial.println(distMove1);
Serial.print("MoveLeft=");
Serial.println(distMoveLeft);
Serial.print("MoveRight=");
Serial.println(distMoveRight);

//Pause Modes -Hold
if ((distL >40 && distR>40) && (distL <50 && distR<50)) //Detect both hands
{Serial.println("Play/Pause"); delay (500);}

calculate_distance(trigger1,echo1);
distL =dist;

calculate_distance(trigger2,echo2);
distR =dist;

calculate_distance(trigger3,echo3);
distMove1 =dist;

calculate_distance(trigger4,echo4);
distMoveLeft =dist;


calculate_distance(trigger5,echo5);
distMoveRight =dist;

//Control Modes
//Lock Left - Control Mode
if (distL>=13 && distL<=17)
{
  delay(100); //Hand Hold Time
  calculate_distance(trigger1,echo1);
  distL =dist;
  if (distL>=13 && distL<=17)
  {
    Serial.println("Left Locked");
    while(distL<=40)
    {
      calculate_distance(trigger1,echo1);
      distL =dist;
      if (distL<10) //Hand pushed in 
      {Serial.println ("Vup"); delay (300);}
      if (distL>20) //Hand pulled out
      {Serial.println ("Vdown"); delay (300);}
    }
  }
}

//Lock Right - Control Mode
if (distR>=13 && distR<=17)
{
  delay(100); //Hand Hold Time
  calculate_distance(trigger2,echo2);
  distR =dist;
  if (distR>=13 && distR<=17)
  {
    Serial.println("Right Locked");
    while(distR<=40)
    {
      calculate_distance(trigger2,echo2);
      distR =dist;
      if (distR<10) //Right hand pushed in
      {Serial.println ("Rewind"); delay (300);}
      if (distR>20) //Right hand pulled out
      {Serial.println ("Forward"); delay (300);}
  }
}
}

//NS control mode
if (distMove1>=13 && distMove1<=17)
{
  delay(100); //Hand Hold Time
  calculate_distance(trigger3,echo3);
  distMove1 =dist;
  if (distMove1>=13 && distMove1<=17)
  {
    Serial.println("West Locked");
    while(distMove1<=40)
    {
      calculate_distance(trigger3,echo3);
      distMove1 =dist;
      if (distMove1<10) //Right hand pushed in
      {Serial.println ("LeftClick"); delay (300);}
      if (distMove1>20) //Right hand pulled out
      {Serial.println ("MoveLeft"); delay (300);}
  }
}
}

//West control mode
if (distMoveLeft>=13 && distMoveLeft<=17)
{
  delay(100); //Hand Hold Time
  calculate_distance(trigger4,echo4);
  distMoveLeft =dist;
  if (distMoveLeft>=13 && distMoveLeft<=17)
  {
    Serial.println("West Locked");
    while(distMoveLeft<=40)
    {
      calculate_distance(trigger4,echo4);
      distMoveLeft =dist;
      if (distMoveLeft<10) //Right hand pushed in
      {Serial.println ("LeftClick"); delay (300);}
      if (distMoveLeft>20) //Right hand pulled out
      {Serial.println ("MoveLeft"); delay (300);}
  }
}
}

//East control mode
if (distMoveRight>=13 && distMoveRight<=17)
{
  delay(100); //Hand Hold Time
  calculate_distance(trigger5,echo5);
  distMoveRight =dist;
  if (distMoveRight>=13 && distMoveRight<=17)
  {
    Serial.println("East Locked");
    while(distMoveRight<=40)
    {
      calculate_distance(trigger5,echo5);
      distMoveRight =dist;
      if (distMoveRight<10) //Right hand pushed in
      {Serial.println ("RightClick"); delay (300);}
      if (distMoveLeft>20) //Right hand pulled out
      {Serial.println ("MoveRight"); delay (300);}
  }
}
}


delay(200);
}
