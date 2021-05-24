#include <LiquidCrystal.h>   //lcd library 
#include <Servo.h>                             //include the servos library needed to run the program
Servo servo1;                                   //Declare presence of Servo
Servo servo2;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int servmax = 180;                              //Define maximum servo angle
int servmin = 0;                                //Define minimum servo angle
//#define pin 0                                   //Define which pin we attached the servos to

void setup(){                                   //Setup runs 1 time to get things ready
  servo1.attach(0);                             //Servo is initialized to pin 0 from the earlier line of code
 servo2.attach(2); // comment this out to get back to one servo
lcd.begin(16,2); //Start the LCD

}

void loop(){                                   //Loop runs over and over again so program continues indefinitely
   
     servo1.write(servmax);                    //Move servo to maximum angle
     delay(900);
     servo2.write(servmax);//comment this out to get back to one servo 
    delay(900);
    lcd.setCursor (0,0); 
     lcd.print("angle: 180");
     // delay(10000);                             // wait 10 seconds
      lcd.clear();
      
      servo1.write(servmin);                   //move servo to minimum angle 
    delay(900);
     servo2.write(servmin);  //comment this out to get back to one servo 
    delay (900);
     lcd.setCursor (0,1);
      lcd.print("angle 0");
      delay(10000);
      lcd.clear();
    }
