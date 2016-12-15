#include <string.h>
#include <SimpleTimer.h>
#include "servos.h"
#include "rgb_led.h"
#include "rfid.h"
#include "proximity.h"


//SimpleTimer timer;
//int timerID;
//MAIN SETUP
void setup() {
  Serial.begin(9600);
  RFID_setup();
  proximity_setup(7*60*1000);//checks for activity every 7 minutes
  rgb_led_setup();
  //timerID = timer.setTimer(500, RFID_read(), 100);
}

String val;
String servo_status;
int qa [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //right id index w.r.t questions!
int q_id;
//MAIN_LOOP
void loop() {
  //timer.run();
  int Tag = -1;
  if (true/*activity()*/) {
    if (Serial.available()) {
      val = Serial.readString();
      if (!(val.equals("y") || val.equals("n") || val.equals("z"))) {
        q_id = val.toInt();
        if (q_id >= 0) {
          //ready -> intialize RFID and read.
          //RFID_setup();
          while(Tag<0) {
            rgb_led(false, false, true, 2000);
            Tag = RFID_read();
            Serial.println(Tag);
            }
          //timer.run();
          if (if_correct(Tag, q_id)) {
            //correct tag shown
            //state = true;
            servo_status = servo_action('y');
            //state = false;
          }
          else {
            //incorrect tag shown
            //state = true;
            servo_status = servo_action('n');
            //state = false;
          }
          //Serial.flush();
          //timer.disable(timerID);
          Serial.println(servo_status);
        }
        else {
          //something is wrong - > Signal Error
          //Serial.flush();
          Serial.println("E");
        }
      }
      else if ( val.equals("z")) {
        //say Hello!
        //state = true;
        //Serial.flush();
        Serial.println(servo_action('z'));
        //state = false;
      }
      else if ( val.equals( "y")) {
        //say yes
        //state = true;
        //Serial.flush();
        Serial.println(servo_action('y'));
        //state = false;
      }
      else if ( val.equals("n")) {
        //say no
        //state = true;
        //Serial.flush();
        Serial.println(servo_action('n'));
        //state = false;
      }
      else {
        //Do Nothing
      }
    }
    else {
      //check for activity every 10 seconds
      //delay(10000);
    }
  }
}
