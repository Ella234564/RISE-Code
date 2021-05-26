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
int steps=5;

void setup(){
  count = 0;                                    //count starts at 0
  lcd.begin(16, 2);                             //Start the LCD
 SD.begin(0);
  if (!SD.begin(0)) {                           //Pin 1 will be used for SD card read/write
    lcd.setCursor(0,0);                         //Sets the cursor location
    lcd.print("SD Fail Init");                  //SD begin failed to initialize so write error message
    exit(0);                                    //Exit
  }   

  lcd.clear(); 
  lcd.setCursor(0,0);                           //Sets the cursor location
  lcd.print("Ti:");                             //Tin
  lcd.setCursor(0,1);                           //Set cursor
  lcd.print("To:");                             //Tout
  lcd.setCursor(4,1);                           //Set cursor
  lcd.print("waiting...");                      //Wait for Select button
}
 
void loop(){
  if(analogRead(0) < 900){                      //If Select key was pressed, proceed.  If not, keep waiting.
    lcd.setCursor(9,1);                         //Set cursor
    lcd.print(" Ct:    ");                       //Count
    delay(1000);                                //Delay 1 second
    record = 1023;                              //Sets checker so while loop can check if select button was pressed again
    while(record > 900){                        //Checks to see if Select Key was pressed again (Hold the select button until you see "Finished!")
      tempt = SD.open("temps.txt",FILE_WRITE);      //Creates an object that is a created txt file                                         
      if (!tempt) {                                 //If SD card failed to open
        lcd.setCursor(0,0);                         //Sets the cursor location
        lcd.print("File Error");                    //Write error message
        exit(0);                                    //Exit
      }
      for(int i=0; i<steps; i++){                   //Runs inner loop multiple times and then saves file. (prevents progress loss)
        lcd.setCursor(3,0);                         //3rd character, line 0
        sensors2.requestTemperatures();             //Call temperature from sensor
        lcd.print(sensors2.getTempCByIndex(0));     //Prints temperature
        lcd.setCursor(3,1);                         //3rd character, line 1
        sensors3.requestTemperatures();             //Call temperature from sensor
        lcd.print(sensors3.getTempCByIndex(0));     //Prints temperature
        lcd.setCursor(12,1);                        //12th character, line 1
        lcd.print(count);                           //Prints the count
        tempt.print(count);
        tempt.print(",");
        tempt.print(sensors2.getTempCByIndex(0));   //Writes first Temp to file
        tempt.print(",");                           //A comma will separate the 2 temperatures
        tempt.println(sensors3.getTempCByIndex(0)); //Writes second Temp to file and starts a new line

        delay(1000);                                //Delays next temperature update by 1 second
        count++;                                    //Increases count variable by 1 (so counts = seconds)
        record = analogRead(0);                     //Sets record to the value on the Select button, either NONE or an int
        if (record<900) {                           //Checks every inner loop to see if the select buton was pressed
          break;                                    //Exits inner loop so the program will stop collecting data
        }
      }
      tempt.close();                              //Closes the tempt file to save it
      if (tempt) {                                //If tempt fails to close
        lcd.setCursor(0,0);                       //Sets the cursor location
        lcd.print("File Save Error");             //Write error message
        exit(0);                                  //Exit the loop
      }
    }
    lcd.setCursor(0,1);                         //Cursor is set to second line
    lcd.print("Finished!  ");                   //Prints the final message
    exit(0);                                    //Exits the loop
  }
}
