#include "Stepper.h"
#include "IRremote.h"

#define STEPS 32
int Steps2Take;
int receiver = 12;

Stepper small_stepper(STEPS, 8, 10, 9, 11);
IRrecv irrecv(receiver);
uint32_t last_decodedRawData = 0;

void setup() {
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode()) {
    if (irrecv.decodedIRData.flags) {
      irrecv.decodedIRData.decodedRawData = last_decodedRawData;
    } switch (irrecv.decodedIRData.decodedRawData) {
      case 0xB946FF00:
        small_stepper.setSpeed(500);
        Steps2Take = -2048;
        small_stepper.step(Steps2Take);
        delay(2000);
        break;
      
      case 0xEA15FF00:
        small_stepper.setSpeed(500);
        Steps2Take = 2048;
        small_stepper.step(Steps2Take);
        delay(2000);
        break;
    }

    last_decodedRawData = irrecv.decodedIRData.decodedRawData;
    irrecv.resume();
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}