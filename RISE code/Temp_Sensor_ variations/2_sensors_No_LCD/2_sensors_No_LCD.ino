//Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire2(2);                  //Sets the pin for temperature sensor
OneWire oneWire3(3);
DallasTemperature sensors2(&oneWire2); //Sends information from OneWire to DallasTemperature
DallasTemperature sensors3(&oneWire3);
//Serial.println();
void setup(){
  
}
 
void loop(){
 
  sensors2.requestTemperatures();  //Call temperature from sensor
  sensors3.requestTemperatures();
  delay(5000);                    //Delays next temperature update by one second
}
