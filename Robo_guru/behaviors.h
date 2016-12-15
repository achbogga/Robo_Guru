#ifndef BEHAVIORS_H
#define BEHAVIORS_H
#include "controls.h"

void no() {
  int s = 100;
  //rotate(10, true, 90,s);
  rotate_neck_no (60, s);
  rotate_neck_no (60, s);
}

void yes() {
  int s = 4;
  for (int i = 0 ; i < 2; i++) { // repeat the following two times
    rotate(10, true, 110, s);
    rotate(10, true, 80, s);
  }
  rotate(10, true, 90, s);
}

void crazy_dance() {
  int s = 4;
  rotate_neck_no (65, 100);
  for (int i = 0 ; i < 2; i++) { // repeat the following two times
    rotate(10, true, 110, s);
    rotate(10, true, 80, s);
  }
  rotate(10, true, 90, s);
  rotate_neck_no (65, 100);
  rotate_neck_no (65, 100);
  for (int i = 0 ; i < 2; i++) { // repeat the following two times
    rotate(10, true, 110, s);
    rotate(10, true, 80, s);
  }
  rotate(10, true, 90, s);
  rotate_neck_no (65, 100);
}
#endif
