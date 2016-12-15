#ifndef PROXIMITY_H
#define PROXIMITY_H
#include <SimpleTimer.h>//yet to be used
//#include "rgb_led.h"
#include "servos.h"
#define PROXIMITY_SENSOR 0//Analog A0 in arduino
#define PROXIMITY_THRESHOLD 20 //Approximate distance threshold for proximity sensor
int proximity;
//bool state=false; // false -> passive, ture -> active
//SimpleTimer timer;
bool activity(void);

//approximate proximity distance conversion
int sharp_IR_distance_conversion(int val) {
  return ((6762 / (val - 9)) - 4);
}

void proximity_setup(int interval_time) {
  pinMode(PROXIMITY_SENSOR, OUTPUT);
  //timer.setInterval(interval_time, activity);
}

bool activity() {
  proximity = analogRead(PROXIMITY_SENSOR);
  if ((sharp_IR_distance_conversion(proximity)) <= PROXIMITY_THRESHOLD) {
    //Serial.println((sharp_IR_distance_conversion(proximity)));
    /*if (!state) {
      servo_action('z'); //say hello if someone is nearby!
      state = true;
      return true;
    }
    else {
      //state = false;
      return false;
    }*/
  }
}
#endif
