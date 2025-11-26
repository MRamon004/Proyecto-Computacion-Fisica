
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

  Serial.println(cm);

  

  
  if (cm > 150) {
    apagarTodo();
  }

 
  else if (cm <= 150 && cm > 70) {
    parpadearLEDyBeep(ledVerde, 550, 120); 
  }


  else if (cm <= 70 && cm > 40) {
    parpadearLEDyBeep(ledAmarillo, 300, 80); 
  }

  
  else if (cm <= 40 && cm > 15) {
    parpadearLEDyBeep(ledRojo, 120, 40); 
  }

  
  else if (cm <= 15) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, HIGH);

    tone(buzzer, 1000); 
  }
}

void apagarTodo() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo, LOW);
  noTone(buzzer);
}


void parpadearLEDyBeep(int led, int velLED, int velBeep) {

  apagarTodo();
  
  digitalWrite(led, HIGH);

  tone(buzzer, 1200);
  delay(velBeep);
  noTone(buzzer);
 
  delay(velLED - velBeep);
  digitalWrite(led, LOW);
}
