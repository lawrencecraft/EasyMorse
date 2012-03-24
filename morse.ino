///////////////////////////////////////////////////
//
// doMorse
//
// My morse code thingermadude
//
// Writes morse code

#define OUTPUT_PIN 13
#define DIT_LENGTH 100
#define DASH_LENGTH 600

struct flashcode {
  prog_uchar number : 3;
  prog_uchar code : 5;
};

// Store codes in progmem  
flashcode codes[] PROGMEM = { // Packing code: 
  {5, 0}, // 0 -----
  {5, B1000}, // 1
  {5, B11000}, // 2
  {5, B11100}, // 3
  {5, B11110}, // 4
  {5, B11111}, // 5
  {5, B01111}, // 6
  {5, B00111}, // 7
  {5, B00011}, // 8
  {5, B00001}, // 9
  
  
};

void dit();
void dash();
void flash_byte(byte pattern, byte toflash);
void flash_pin(int length);

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
  //flash_byte(B111, 3);
  //flash_byte(B000, 3);
  //flash_byte(B111, 3);
  int tst = sizeof(flashcode);
  while(tst-- > 0) {
    dit();
    delay(100);
  }
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

void flash_pin(int length) {
  digitalWrite(OUTPUT_PIN, HIGH);
  delay(length);
  digitalWrite(OUTPUT_PIN, LOW);
}
