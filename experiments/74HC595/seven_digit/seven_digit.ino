byte seven_seg_digits[10] = {
  B11111100,
  B01100000,
  B11011010,
  B11110010,
  B01100110,
  B10110110,
  B10111110,
  B11100000,
  B11111110,
  B11100110
};

int latchPin = 3;
int clockPin = 4;
int dataPin = 2;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void sevenSegWrite(byte digit) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);
  digitalWrite(latchPin, HIGH);
}

void loop() {
  for (byte digit = 10; digit > 0; --digit) {
    delay(500);
    sevenSegWrite(digit - 1);
  }

  delay(1000);
}