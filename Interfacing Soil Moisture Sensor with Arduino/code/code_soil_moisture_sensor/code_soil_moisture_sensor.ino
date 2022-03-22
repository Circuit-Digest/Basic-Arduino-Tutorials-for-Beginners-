// Sensor pins pin D6 LED output, pin A0 analog Input
#define ledPin 6
#define sensorPin A0

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  Serial.print("Analog output: ");
  Serial.println(readSensor());
  delay(500);
}

//  This function returns the analog data to calling function
int readSensor() {
  int sensorValue = analogRead(sensorPin);  // Read the analog value from sensor
  int outputValue = map(sensorValue, 0, 1023, 255, 0); // map the 10-bit data to 8-bit data
  analogWrite(ledPin, outputValue); // generate PWM signal
  return outputValue;             // Return analog moisture value
}
