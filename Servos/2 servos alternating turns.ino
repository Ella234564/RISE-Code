
/**
Making the following code for 2 servos turn alternatingly
*/


#include <LiquidCrystal.h>   //lcd library 
#include <Servo.h>                             //include the servos library needed to run the program
Servo servo1;                                   //Declare presence of Servo
Servo servo2;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int servmax = 180;                              //Define maximum servo angle
int servmin = 0;                                //Define minimum servo angle
#define pin0 0                                  //attach one servo to pin0
#define pin2 2                                 //attach other servo to pin2

void setup(){                                   //Setup runs 1 time to get things ready
  servo1.attach(pin0);                             //Servo is initialized to pin 0 from the earlier line of code
 servo2.attach(pin2); 
lcd.begin(16,2); //Start the LCD

}

void loop(){                                   //Loop runs over and over again so program continues indefinitely
   
     servo1.write(servmax);                    //Move servo to maximum angle
     delay(100);
    servo2.write(servmax);
      delay(1000);
    lcd.setCursor (0,0); 
     lcd.print("angle: 180");
                            
      lcd.clear();
      
      servo1.write(servmin);                   //move servo to minimum angle 
     delay(100);
    servo2.write(servmin); 
    delay (1000);
      lcd.print("angle 0");
      lcd.clear();
    }
