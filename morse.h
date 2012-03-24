///////////////////////////////////////////////////
//
// doMorse
//
// My morse code thingermadude
//
// Writes morse code

// Basic packed structure containing a Morse byte
typedef struct {
  unsigned char number : 3;
  unsigned char code : 5;
} flashcode_t;
