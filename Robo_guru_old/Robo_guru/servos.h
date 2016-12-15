#ifndef SERVOS_H
#define SERVOS_H

//servos.h
#include <Servo.h>
#include "rgb_led.h"
#include "behaviors.h"
//#include "proximity.h"
//#include "rfid.h"
// It waits for a serial ready signal ('r') and then initializes the RFID reader.
//The RFID reader then starts printing the index of the tag from the database if it is valid.
//It sends invalid signal (-1) if a tag is not valid.
char servo_action(char val) {
  if( val == 'y') {
    rgb_led(false, true, false, 1000);
    yes();
    //state = false;
    //return "y";
  }
  else if( val == 'n') {
    rgb_led(false, false, true, 1000);
    no();
    //state = false;
    //return "n";
  }
  else if( val == 'z') {
    rgb_led_loop(1000);
    crazy_dance();
    //state = false;
    //return "z";
  }
  else {
    //Do Nothing
    //return "d";
  }
  //Nod or Turn action completed
  //send communication to say that I am done and ready for another action!.
  return 'd';
}

#endif
