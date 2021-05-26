//Included libraries
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <SD.h>

#define btnSELECT 4                             //Sets value for Select Key defined by the DF Robot keypad

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);            //Sets pins used by default

OneWire oneWire2(2);                             //Sets the pin for temperature sensor      
OneWire oneWire3(3);
DallasTemperature sensors2(&oneWire2);            //Sends information from OneWire to DallasTemperature
DallasTemperature sensors3(&oneWire3);

File intemp;                                    //Sets temperature as a file type
int count;                                      //count is an integer
int record;                                     //record is an integer
String data ="";
 
void setup(){ 
  count = 0;                                    //count starts at 0
  SD.begin(1);                                  //Pin 1 will be used for SD card read/write
                                    
  intemp = SD.open("intemp.txt",FILE_WRITE);    //Creates an object that is a created txt file
  lcd.begin(16, 2);                             //Start the LCD
  lcd.setCursor(0,0);                           //Sets the cursor location
  lcd.print("Tin:");               //Prints the current temp
  lcd.setCursor(0,1);
  lcd.print("Tout:");
  lcd.setCursor (6,1);
  lcd.print("Waiting...");
}
 
void loop(){
  if(analogRead(0) < 1000){                     //Checks to see if Select Key was pressed
    record = 1001;                              //Sets checker so while loop can check if select button was pressed again
    while(record > 1000){                       //Checks to see if Select Key was pressed again (Hold the selct button until you see "Finished!")
    
    lcd.setCursor(5,0);                         //Cursor is moved to 3rd character
    sensors2.requestTemperatures();             //Call temperature from sensor
    lcd.print(sensors2.getTempCByIndex(0));     //Prints temperature
    lcd.setCursor(5,1);                        //Cursor is moved to 11th character
    sensors3.requestTemperatures();             //Call temperature from sensor
    lcd.print(sensors3.getTempCByIndex(0));     //Prints temperature
    lcd.setCursor(10,1);                         //Cursor is moved to character 8
    lcd.print(" ct:");
    lcd.setCursor(14,1);
    lcd.print(count);                           //Prints the count (the number of temperature readings)
    
    intemp.println(sensors2.getTempCByIndex(0)); //Writes temperature to SD card file
    intemp.println(",");                         // puts comma between temepratures in SD file
    intemp.println(sensors3.getTempCByIndex(0)); //Writes temperature to SD card file delay(1000);                                //Delays next temperature update by 1 second
    count++;                                    //Increases count variable by 1 (count = seconds)
    record = analogRead(0);                     //Sets record to the value outputted by the button keys, either NONE or an int
    delay(1000);
    }
    intemp.close();                             //Closes the temperature file to save it
    lcd.setCursor(0,1);                         //Cursor is set to second line
    lcd.print("Finished!  ");                   //Prints the ending message
    exit(0);                                    //Exits the loop
  }
}
