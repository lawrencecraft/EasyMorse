///////////////////////////////////////////////////
//
// doMorse
//
// My morse code thingermadude
//
// Writes morse code
#include "morse.h"

#define OUTPUT_PIN 13
#define DIT_LENGTH 100
#define DASH_LENGTH 600

// Store codes in progmem  
flashcode_t codes[] PROGMEM = { // Packing code: 
  {5, B0000},  // 0
  {5, B10000}, // 1
  {5, B11000}, // 2
  {5, B11100}, // 3
  {5, B11110}, // 4
  {5, B11111}, // 5
  {5, B01111}, // 6
  {5, B00111}, // 7
  {5, B00011}, // 8
  {5, B00001}, // 9
  {2, B10},   // A -- NOTE: add ascii calculations
  {4, B0111}, // B
  {4, B0101}, // C
  {3, B011},  // D
  {1, B1},    // E
  {4, B1101}, // F
  {3, B001},  // G
  {4, B1111}, // H
  {2, B11},   // I
  {4, B1000}, // J
  {3, B010},  // K
  {4, B1011}, // L
  {2, B00},   // M
  {2, B10},   // N
  {3, B000},  // O
  {4, B1001}, // P
  {4, B0010}, // Q
  {3, B101},  // R
  {3, B111},  // S
  {1, B0},    // T
  {3, B110},  // U
  {4, B1110}, // V
  {3, B100},  // W
  {4, B0110}, // X
  {4, B0100}, // Y
  {4, B0011}, // Z
};

void dit();
void dash();
void flash_byte(byte pattern, byte toflash);
void flash_pin(int length);
void flash_packed_pattern(flashcode_t code);

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
  flashcode_t s = {3, B111};
  flashcode_t o = {3, B000};
  flash_packed_pattern(s);
  delay(300);
  flash_packed_pattern(o);
  delay(300);
  flash_packed_pattern(s);
  delay(300);
  delay(1000);
}


void dit() {
  flash_pin(DIT_LENGTH);
}

void dash() {
  flash_pin(DASH_LENGTH);
}

void flash_byte(byte pattern, byte toflash) {
  while(toflash-- != 0) {
    (pattern & 1) ? dit() : dash();
    delay(200);
  }
  delay(700);
}

void flash_packed_pattern(flashcode_t code) {
  flash_byte(code.code, code.number);
}

void flash_pin(int length) {
  digitalWrite(OUTPUT_PIN, HIGH);
  delay(length);
  digitalWrite(OUTPUT_PIN, LOW);
}
