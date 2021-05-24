#include <LiquidCrystal.h>
//#include <DallasTemperature.h>
//#include <OneWire.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);            //Sets pins used by default

  void setup()
{
 lcd.begin(16,2); //Start the LCD
 //pinMode(12,OUTPUT); // sets pin 12 as the output ????
 
}

void loop() {
  lcd.setCursor (3,0); //sets where the print statment apears on the LCD
  lcd.print("SUN!"); // prints "hi" at given location
// lcd.setCursor (3,1); //sets where the print statment apears on the LCD
  //lcd.print("is the goat"); // prints "hi" at given location

}
