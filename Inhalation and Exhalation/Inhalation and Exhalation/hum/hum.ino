/*  DHT11/ DHT22 Sensor Temperature and Humidity Tutorial
 *  Program made by Dejan Nedelkovski,
 *  www.HowToMechatronics.com 
 */
/*
 * You can find the DHT Library from Arduino official website
 * https://playground.arduino.cc/Main/DHTLib
 */
 
#include <dht.h>

#define dataPin 8 // Defines pin number to which the sensor is connected
dht DHT; // Creats a DHT object

void setup() {
  Serial.begin(115200);
}
void loop() {
  int readData = DHT.read22(dataPin); // Reads the data from the sensor
  float t = DHT.temperature; // Gets the values of the temperature
  float h = DHT.humidity; // Gets the values of the humidity
  
  // Printing the results on the serial monitor
  //Serial.print("iuTemperatureiu");
  //Serial.print(":");
  Serial.print(t);
  Serial.print(",");
  //Serial.print("iuHumidityiu");
  //Serial.print(":");
  Serial.print(h);
  delay(1000); // Delays 2 seconds, as the DHT22 sampling rate is 0.5Hz
}
