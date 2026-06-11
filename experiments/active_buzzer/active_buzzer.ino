int buzzer = 6;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  analogWrite(buzzer, 10);
  delay(1000);

  analogWrite(buzzer, 50);
  delay(1000);

  analogWrite(buzzer, 100);
  delay(1000);

  analogWrite(buzzer, 150);
  delay(1000);

  analogWrite(buzzer, 200);
  delay(1000);

  analogWrite(buzzer, 255);
  delay(1000);
}