#define pirPin 2
#define ledPin 3
int statusPir = LOW;
int m;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  m = digitalRead(pirPin);
  if (m == HIGH){
    digitalWrite(ledPin, HIGH);

    Serial.println("Gerakan Terdeteksi");
    statusPir = HIGH;
  }
  else{
    delay(3000);
    digitalWrite(ledPin, LOW);
    Serial.println("Tidak ada gerakan");
  }
  delay(2000);
}
