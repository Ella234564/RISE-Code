//Include libraries
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //Sets pins used by default

OneWire oneWire2(2);                  //Sets the pin for temperature sensor

DallasTemperature sensors2(&oneWire2); //Sends information from OneWire to DallasTemperature

void setup(){
  lcd.begin(16, 2);               //Start the LCD
  lcd.setCursor(0,0);             //Sets the cursor location 
  lcd.print("Temp:");//Prints temperature
pinMode(10,OUTPUT);
digitalWrite(10,LOW);
 lcd.setCursor(0,1);
}
 
void loop(){
  lcd.setCursor(6,0);             //Cursor is moved to second line
  sensors2.requestTemperatures();  //Call temperature from sensor
  lcd.print(sensors2.getTempCByIndex(0)); //Prints temperature
  
  delay(5000);                    //Delays next temperature update by one second
}
