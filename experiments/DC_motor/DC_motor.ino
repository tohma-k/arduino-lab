#define ENABLE 5
#define DIRA 3
#define DIRB 4

int i;

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("One way, then reverse");
  digitalWrite(ENABLE, HIGH);
  for (int i = 0; i < 5; i++) {
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, LOW);
    delay(500);
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, HIGH);
    delay(500);
  }
  digitalWrite(ENABLE, LOW);
  delay(2000);

  Serial.println("fast Slow example");
  digitalWrite(ENABLE, HIGH);
  digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, LOW);
  delay(3000);
  digitalWrite(ENABLE, LOW);
  delay(1000);
  digitalWrite(ENABLE, HIGH);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, HIGH);
  delay(3000);
  digitalWrite(DIRA, LOW);
  delay(2000);

  Serial.println("PWM full then slow");
  analogWrite(ENABLE, 255);
  digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, LOW);
  delay(2000);
  analogWrite(ENABLE, 180);
  delay(2000);
  analogWrite(ENABLE, 128);
  delay(2000);
  analogWrite(ENABLE, 50);
  delay(2000);
  analogWrite(ENABLE, 128);
  delay(2000);
  analogWrite(ENABLE, 180);
  delay(2000);
  analogWrite(ENABLE, 255);
  delay(2000);
  digitalWrite(ENABLE, LOW);
  delay(10000);
}