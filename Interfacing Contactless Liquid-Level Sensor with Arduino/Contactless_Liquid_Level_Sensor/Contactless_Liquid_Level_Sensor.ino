int SensePin = 2;  //Sensor input
void setup() {
  Serial.begin(9600);
  pinMode(SensePin, INPUT);
}

void loop() {
  if(digitalRead(SensePin)) {
    Serial.println("Liquid Detected");
  }
  else {
    Serial.println("No Liquid Available");
  }

  delay(1000);
}
