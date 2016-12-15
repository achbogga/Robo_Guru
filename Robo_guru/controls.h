#ifndef CONTROLS_H
#define CONTROLS_H
#include <Arduino.h>
#include <Servo.h>

// still buggy. will figure out something.
// use the hack rotate_neck_no() in the mean time...
//Achyut B extended it to work with continuous servos. -> additional first and second function parameters and function name changes servo_location, servo_type.
//both head and neck can now be called using a single function rotate with additional servo_location parameter
int REST = 89;

// ACHYUT REVISION NOV 16
Servo my_servo;

/// DEFINE PINS FOR SERVOS
int lower_servo = 9;
int upper_servo = 10;

/// STARTING POSITIONS FOR EACH SERVO
int head_position = 90;
int neck_position = 0;

//servo_type : true = normal servo
//servo_type : false = continuous servo
//servo_location : 10 = upper
// servo_location : 9 = lower
void rotate(int servo_location, bool servo_type, int start_pos, int end_pos, int ms_delay) {
  int relevant_servo = (servo_location == 10) ? (upper_servo) : (lower_servo);
  if (servo_type) {
    int angle = 0;
    int i = 1; // increment size
    my_servo.attach(relevant_servo);
    if (start_pos < end_pos) {
      for ( angle = start_pos; angle <= end_pos; angle += 1) {
        my_servo.write(angle);
        delay(ms_delay);
      }
    } else {
      for ( angle = start_pos; angle >= end_pos; angle -= 1) {
        my_servo.write(angle);
        delay(ms_delay);
      }
    }
    head_position = angle;
    my_servo.detach();
  }
  else {
    //approximate delay is implemented -> exact can be calculated later.
    int angle = end_pos - start_pos;
    int dir;
    int i = 1; // increment size
    my_servo.attach(upper_servo);
    if (start_pos < end_pos) {
      dir = 180;
    }
    else {
      dir = 0;
    }
    // start clockwise turning at full pace
    my_servo.write(180);
    // turn for calculated amount of time
    delay(angle * 2);
    // stop rotating
    my_servo.write(REST);
    if (servo_location == 9) neck_position = end_pos;
    else head_position = end_pos;
    delay(ms_delay);
    my_servo.detach();
  }
}
void rotate(int servo_location, bool servo_type, int end_pos, int ms_delay) {
  int relevant_servo = (servo_location == 10) ? (upper_servo) : (lower_servo);
  if (servo_type) {
    int angle = 0;
    int i = 1; // increment size
    my_servo.attach(relevant_servo);
    if (head_position < end_pos) {
      for ( angle = head_position; angle <= end_pos; angle += 1) {
        my_servo.write(angle);
        delay(ms_delay);
      }
    } else {
      for ( angle = head_position; angle >= end_pos; angle -= 1) {
        my_servo.write(angle);
        delay(ms_delay);
      }
    }
    head_position = angle;
    my_servo.detach();
  }
  else {
    //approximate delay is implemented -> exact can be calculated later.
    int start_pos = head_position;
    int angle = end_pos - start_pos;
    int dir;
    my_servo.attach(relevant_servo);
    if (start_pos < end_pos) {
      dir = 180;
    }
    else {
      dir = 0;
    }
    // start clockwise turning at slower pace
    my_servo.write(180);
    // turn for calculated amount of time
    delay(angle * 2);
    // stop rotating
    my_servo.write(REST);
    if (servo_location == 9) neck_position = end_pos;
    else head_position = end_pos;
    delay(ms_delay);
    my_servo.detach();
  }
}

void rotate_neck_no (int angle, int ms_delay) {
  my_servo.attach(lower_servo);
  //start turning anti-clockwise
  my_servo.write(70);
  //go on turning at max speed for TURN_TIME seconds
  delay(angle * 3);
  //stop turning
  my_servo.write(89);//caliberated at rest
  delay(ms_delay);
  //start turning clockwise
  my_servo.write(105);
  //go on turning at max speed for TURN_TIME seconds
  delay(angle * 3);
  //stop turning
  my_servo.write(89);//caliberated at rest
  delay(ms_delay);

  my_servo.detach();
}

#endif
