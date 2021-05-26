#include <Servo.h>                             //include the servos library needed to run the program
Servo servo1;                                   //Declare presence of Servo

int servmax = 180;                              //Define maximum servo angle
int servmin = 0;                                //Define minimum servo angle
#define pin 0                                   //Define which pin we attached the servos to

void setup(){                                   //Setup runs 1 time to get things ready
  servo1.attach(pin);                             //Servo is initialized to pin 0 from the earlier line of cod
}

void loop(){                                   //Loop runs over and over again so program continues indefinitely
   
     servo1.write(servmax);                    //Move servo to maximum angle
      delay(10000);                             // wait 10 seconds
     
      servo1.write(servmin);                   //move servo to minimum angle 
       delay(10000);
       
    }
