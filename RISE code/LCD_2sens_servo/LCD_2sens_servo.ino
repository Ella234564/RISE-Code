//Include libraries to operate devices
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <SD.h>
#include <Servo.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);            //Sets LCD pins used by default
Servo servo1;                                   //Declare presence of Servo
OneWire oneWire2(2);                            //Sets pin for temperature sensor
OneWire oneWire3(3);                            //Sets pin for temperature sensor
DallasTemperature sensors2(&oneWire2);          //Sends information from OneWire to DallasTemperature
DallasTemperature sensors3(&oneWire3);          //Sends information from OneWire to DallasTemperature
int servmax = 180;                              //Define maximum servo angle
int servmin = 0;                                //Define minimum servo angle
int MaxTemp = 25;                               //Set threshold temperature for servo ventilation

void setup(){                                   //Setup runs 1 time to get things ready
  servo1.attach(0);                             //Servo is initialized to pin 0
  lcd.begin(16, 2);                             //Start the LCD with 16 characters/line and 2 lines
  lcd.setCursor(0,0);                           //Sets the cursor location to character 0, line 0
  lcd.print("Ti:");                             //Prints preliminary inside Temperature text
  lcd.setCursor(8,0);                           //Sets the cursor location to character 8, line 0                         
  lcd.print("To:");                             //Prints preliminary outside Temperature text
  lcd.setCursor(0,1);                           //Moves the cursor to the second line
  lcd.print("SRV:");                            //Prints preliminary Servo text
}
void loop(){                                    //Loop runs over and over again so program continues indefinitely
    lcd.setCursor(3,0);                         //Cursor is moved to 3rd character
    sensors2.requestTemperatures();             //Call temperature from sensor
    lcd.print(sensors2.getTempCByIndex(0));     //Prints temperature
    lcd.setCursor(11,0);                        //Cursor is moved to 11th character
    sensors3.requestTemperatures();             //Call temperature from sensor
    lcd.print(sensors3.getTempCByIndex(0));     //Prints temperature
    
    if (sensors2.getTempCByIndex(0) > MaxTemp){ //Temperature is greater than threshold temperature
      servo1.write(servmax);                    //Move servo to maximum angle
      lcd.setCursor(4,1);                       //Cursor is moved to 4th character on line 1
      lcd.print("OPN");                         //Servo is open
    }
    else {                                      //Temperature is not greater than threshold temperature
      servo1.write(servmin);                    //Move servo to minimum angle
      lcd.setCursor(4,1);                       //Cursor is moved to 4th character on line 1
      lcd.print("CLSD");                        //Servo is closed
    }
    delay(1000);                                //Delays next temperature update by 1 second                           
}
