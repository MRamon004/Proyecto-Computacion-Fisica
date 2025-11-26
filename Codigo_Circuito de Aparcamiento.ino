int ledVerde = 10;
int ledAmarillo = 9;
int ledRojo = 8;

int buzzer = 6;
int pingPin = 7;

long readUltrasonicDistance() {
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  long duration = pulseIn(pingPin, HIGH);
  return duration;
}

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  long duration = readUltrasonicDistance();
  int cm = duration / 29 / 2;

  if (cm > 200) {
    apagarTodo();
  }
  else if (cm <= 200 && cm > 100) {
    parpadearLEDsinBeep(ledVerde, 550);
  }
  else if (cm <= 100 && cm > 50) {
    parpadearLEDyBeep(ledAmarillo, 300, 60);
  }
  else if (cm <= 50 && cm > 20) {
    parpadearLEDyBeep(ledRojo, 120, 40);
  }
  else if (cm <= 20) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, HIGH);
    tone(buzzer, 300);
  }
}

void apagarTodo() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo, LOW);
  noTone(buzzer);
}

void parpadearLEDsinBeep(int led, int velLED) {
  apagarTodo();
  digitalWrite(led, HIGH);
  delay(velLED);
  digitalWrite(led, LOW);
  delay(velLED);
}

void parpadearLEDyBeep(int led, int velLED, int velBeep) {
  apagarTodo();
  digitalWrite(led, HIGH);
  tone(buzzer, 300);
  delay(velBeep);
  noTone(buzzer);
  delay(velLED - velBeep);
  digitalWrite(led, LOW);
}
