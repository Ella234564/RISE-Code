//Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire2(2);                  //Sets the pin for temperature sensor
DallasTemperature sensors2(&oneWire2); //Sends information from OneWire to DallasTemperature

void setup(){
  
}
 
void loop(){
  sensors2.requestTemperatures();  //Call temperature from sensor
  delay(5000);                    //Delays next temperature update by one second
}
