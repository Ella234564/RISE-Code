#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);            //Sets pins used by default

  void setup()
{
   lcd.begin(16,2); //Start the LCD
 pinMode(10,OUTPUT); // sets pin 12 as the output ????
digitalWrite(10,LOW);
}

void loop() {
  lcd.setCursor (0,0); //sets where the print statment apears on the LCD
  lcd.print("Backlight is off"); // prints " " at given location

}
