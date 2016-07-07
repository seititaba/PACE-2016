#define LED_VERDE 7
#define LED_AMARELO 8
int comando = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);

}

void loop() {
  if (Serial.available()) {
    comando = Serial.read();
    Serial.println(comando);
  }
  switch (comando) {
    case 5:
    digitalWrite(LED_VERDE, HIGH);
      break;
    case 6:
    digitalWrite(LED_VERDE, LOW);
      break;
    case 7:
    digitalWrite(LED_AMARELO, HIGH);
      break;
    case 8:
    digitalWrite(LED_AMARELO, LOW);
      break;
  }
}
