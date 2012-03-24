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
const flashcode_t codes[] = { // Packing code: 
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

void dit() {
  flash_pin(DIT_LENGTH);
}

void dash() {
  flash_pin(DASH_LENGTH);
}

// Flash a specific sequence of characters
void flash_morse_string(char *string){
  while(*(string)) {
    flash_char(*string);
    string++;
    delay(500);
  }
}

// Flash a pattern with a specific number of times to flash
void flash_byte(byte pattern, byte toflash) {
  byte mask = 1 << (toflash - 1);
  while(toflash-- != 0) {
    (pattern & mask) ? dit() : dash();
    pattern = pattern << 1;
    delay(200);
  }
  delay(700);
}

// Helper method to flash a specific packed pattern.
// No need to duplicate, so take a pointer
void flash_packed_pattern(const flashcode_t *code) {
  flash_byte(code->code, code->number);
}

void flash_char(char c) {
  if(c >= '0' && c <= '9')
    flash_packed_pattern(&codes[c - '0']);
  else if (c >= 'A' && c <= 'Z')
    flash_packed_pattern(&codes[c - 'A' + 10]);
  else if (c >= 'a' && c <= 'z')
    flash_packed_pattern(&codes[c - 'a' + 10]);
}

void flash_pin(int length) {
  digitalWrite(OUTPUT_PIN, HIGH);
  delay(length);
  digitalWrite(OUTPUT_PIN, LOW);
}
