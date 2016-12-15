#include <string.h>
#include "servos.h"
#include "rgb_led.h"
#include "rfid.h"
#include "proximity.h"


//MAIN SETUP
void setup() {
  Serial.begin(9600);
  RFID_setup();
  proximity_setup(5*60*1000);//checks for activity every 7 minutes
  rgb_led_setup();
}

String val;
String servo_status;
int qa [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //right id index w.r.t questions!
int q_id;
//MAIN_LOOP
void loop() {
  timer.run();
  int Tag;
  if (true/*activity()*/) {
    if (Serial.available()) {
      val = Serial.readString();
      if (!(val.equals("y") || val.equals("n") || val.equals("z"))) {
        q_id = val.toInt();
        if (q_id >= 0) {
          //ready -> intialize RFID and read.
          //RFID_setup();
          Tag = RFID_read();
          if (if_correct(Tag, q_id)) {
            //correct tag shown
            state = true;
            servo_status = servo_action('y');
            state = false;
          }
          else {
            //incorrect tag shown
            state = true;
            servo_status = servo_action('n');
            state = false;
          }
          Serial.println("d");
        }
        else {
          //something is wrong - > Signal Error
          Serial.println("E");
        }
      }
      else if ( val.equals("z")) {
        //say Hello!
        state = true;
        //Serial.println();
        servo_action('z');
        state = false;
      }
      else if ( val.equals( "y")) {
        //say yes
        state = true;
        servo_action('y');
        //Serial.println();
        state = false;
      }
      else if ( val.equals("n")) {
        //say no
        state = true;
        servo_action('n');
        state = false;
      }
      else {
        //Do Nothing
      }
      Serial.println("d");
    }
    else {
      //check for activity every 10 seconds
      //delay(10000);
    }
  }
}
