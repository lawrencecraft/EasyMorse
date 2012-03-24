///////////////////////////////////////////////////
//
// doMorse
//
// My morse code thingermadude
//
// Writes morse code
#ifndef MORSE_H
#define MORSE_H
// Basic packed structure containing a Morse byte
typedef struct {
  unsigned char number : 3;
  unsigned char code : 5;
} flashcode_t;

void dit();
void dash();
void flash_byte(byte pattern, byte toflash);
void flash_pin(int length);
void flash_packed_pattern(flashcode_t code);
void flash_char(char c);
#endif
