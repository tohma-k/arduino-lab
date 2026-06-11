int ledPin = 5;
int buttonPin = 9;

bool ledState = false;
bool lastButtonState = HIGH;

byte leds = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);
  Serial.print("buttonState: ");
  Serial.println(buttonState);
  
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    Serial.print("ledState: ");
    Serial.println(ledState);
  }

  lastButtonState = buttonState;
  Serial.print("lastButtonState: ");
  Serial.println(lastButtonState);
}