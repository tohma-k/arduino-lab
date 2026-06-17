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
  digitalWrite(ENABLE, HIGH);
  for (int i = 0; i < 5; i++) {
    Serial.println("spin");
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, LOW);
    delay(2000);
    Serial.println("stop");
    digitalWrite(DIRA, LOW);
    digitalWrite(DIRB, HIGH);
    delay(2000);
  }
}