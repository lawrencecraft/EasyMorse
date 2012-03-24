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
  flash_morse_string("Hello Laura Day");
  delay(1000);
}
