////////////////////////////////////////////////
// Main loop and test driver for morse project
#include "morse.h"

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
  dit();
  delay(100);
  dit();
  delay(100);
  dit();
  delay(1000);
}

void loop() {
  char s = 's';
  char o = 'o';
  flash_char(s);
  delay(300);
  flash_char(o);
  delay(300);
  flash_char(s);
  delay(1000);
}
