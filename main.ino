////////////////////////////////////////////////
// Main loop and test driver for morse project
#include "morse.h"

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
  flash_pin(1000);
  delay(500);
}

void loop() {
  flash_morse_string("Hello Laura Day");
  delay(1000);
}
