//RGB LED Header
#ifndef RGB_LED_H
#define RGB_LED_H
const int RED_PIN = 6;
const int GREEN_PIN = 2;
const int BLUE_PIN = 3;

// This variable controls how fast we loop through the colors.
// (Try changing this to make the fading faster or slower.)

int DISPLAY_TIME = 100;  // In milliseconds

void rgb_led_setup()
{
  // Here we'll configure the Arduino pins we're using to
  // drive the LED to be outputs:

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

}

void rgb_led(bool red, bool green, bool blue, int display_time) {

  // Off (all LEDs off):
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  (red) ? digitalWrite(RED_PIN, HIGH) : digitalWrite(RED_PIN, LOW);
  (green) ? digitalWrite(GREEN_PIN, HIGH) : digitalWrite(GREEN_PIN, LOW);
  (blue) ? digitalWrite(BLUE_PIN, HIGH) : digitalWrite(BLUE_PIN, LOW);

  delay(display_time); //display_time in milli seconds

  // Off (all LEDs off):
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  

}

// Here's the mainColors() function we've written.

// This function displays the eight "main" colors that the RGB LED
// can produce. If you'd like to use one of these colors in your
// own sketch, you cancopy and paste that section into your code.

void mainColors(int disp_time)
{
  // Off (all LEDs off):

  rgb_led(false, false, false, disp_time);

  // Red (turn just the red LED on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(disp_time);

  // Green (turn just the green LED on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(disp_time);

  // Blue (turn just the blue LED on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(disp_time);

  // Yellow (turn red and green on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(disp_time);

  // Cyan (turn green and blue on):

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);

  delay(disp_time);

  // Purple (turn red and blue on):

  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(disp_time);

  // White (turn all the LEDs on):

  rgb_led(false, false, false, 1000);

  delay(disp_time);
}

void rgb_led_loop(int disp_time)
{
  mainColors(disp_time);
}



#endif
