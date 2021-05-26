//Included libraries
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <SD.h>

#define btnSELECT 4                             //Sets value for Select Key defined by the DF Robot keypad

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);            //Sets pins used by default

OneWire oneWire2(2);                            //Sets the pins for temperature sensors
OneWire oneWire3(3);      
DallasTemperature sensors2(&oneWire2);          //Sends information from OneWire to DallasTemperature
DallasTemperature sensors3(&oneWire3);

File tempt;                                     //Sets tempt as a file type
int count;                                      //count is an integer
int record;                                     //record is an integer
//String data = "";

void setup(){
  count = 0;
  lcd.begin(16, 2);                             //Start the LCD
  if (!SD.begin(1)) {                           //Sets the pin for SD card read/write
    lcd.setCursor(0,0);                         //Sets the cursor location
    lcd.print("SD Fail Init");
    exit(0);
  }             
  tempt = SD.open("temps.txt",FILE_WRITE);      //Creates an object that is a created txt file                                         
  if (!tempt) {
    lcd.setCursor(0,0);                         //Sets the cursor location
    lcd.print("File Error");
    exit(0);
  }
  lcd.setCursor(0,0);                           //Sets the cursor location
  lcd.print("Ti:");                             //Prints the beginning message
  lcd.setCursor(0,1);                           
  lcd.print("To:");
  lcd.setCursor(4,1);
  lcd.print("waiting...");
}
 
void loop(){
  if(analogRead(0) < 900){                      //Checks to see if Select Key was pressed
    lcd.setCursor(9,1);
    lcd.print("Ct:    ");
    delay(1000);
    record = 1023;                              //Sets checker so while loop can check if select button was pressed again
    while(record > 900){                        //Checks to see if Select Key was pressed again (Hold the select button until you see finished)
    lcd.setCursor(3,0);                         //4th character, line 0
    sensors2.requestTemperatures();              //Call temperature from sensor
    lcd.print(sensors2.getTempCByIndex(0));      //Prints temperature
    lcd.setCursor(3,1);                        //4th character, line 1
    sensors3.requestTemperatures();             //Call temperature from sensor
    lcd.print(sensors3.getTempCByIndex(0));     //Prints temperature
    lcd.setCursor(12,1);                        //11th character, line 1
    lcd.print(count);                           //Prints the count
    tempt.print(sensors2.getTempCByIndex(0));    //Writes values seperated by newline
    tempt.print(",");
    tempt.println(sensors3.getTempCByIndex(0));
    
    delay(1000);                                //Delays next temperature update by 1 second
    count++;                                    //Increases count variable by 1 (Counts seconds)
    record = analogRead(0);                     //Sets record to the value outputted by the button keys, either NONE or an int
    }
    tempt.close();
    if (tempt) {                                //Closes the temperature file to save it
      lcd.setCursor(0,0);                       //Sets the cursor location
      lcd.print("File Save Error");
      exit(0);
    }
    lcd.setCursor(0,1);                         //Cursor is set to second line
    lcd.print("Finished!  ");                   //Prints the ending message
    exit(0);                                    //Exits the loop
  }
}
