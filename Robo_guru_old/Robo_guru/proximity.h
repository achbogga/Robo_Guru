#ifndef PROXIMITY_H
#define PROXIMITY_H
#include <SimpleTimer.h>//yet to be used
//#include "rgb_led.h"
#include "servos.h"
#define PROXIMITY_SENSOR 0//Analog A0 in arduino
#define PROXIMITY_THRESHOLD 20 //Approximate distance threshold for proximity sensor
int proximity, timerID, timerID2;
bool state=false; // false -> passive, ture -> active
SimpleTimer timer;
bool activity(void);

void timerToggle() {
  timer.toggle(timerID);
}

//approximate proximity distance conversion
int sharp_IR_distance_conversion(int val) {
  return ((6762 / (val - 9)) - 4);
}

void proximity_setup(int interval_time) {
  pinMode(PROXIMITY_SENSOR, OUTPUT);
  timerID = timer.setTimer(10, activity, 20000000000); //check for activity every 10 milliseconds 
  timerID = timer.setTimer(interval_time, timerToggle, 20000);// toggle activity watchdog
}

bool activity() {
  proximity = analogRead(PROXIMITY_SENSOR);
  if ((sharp_IR_distance_conversion(proximity)) <= PROXIMITY_THRESHOLD) {
    //Serial.println((sharp_IR_distance_conversion(proximity)));
    //if (!state) {
    timer.toggle(timerID);
      servo_action('z'); //say hello if someone is nearby!
      //state = true;
      
      return true;
    //}
    //else {
      ////state = false;
      //return false;
    //}
  }
}
#endif
