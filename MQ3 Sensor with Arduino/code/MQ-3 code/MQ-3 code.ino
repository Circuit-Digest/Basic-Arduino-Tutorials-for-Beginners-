#define Sober 200   // Define max value that we consider sober
#define Drunk 400   // Define min value that we consider drunk
#define MQ3 0
#define ledPin 6
float sensorValue;  //variable to store sensor value
void setup() {
  Serial.begin(9600); // sets the serial port to 9600
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.println("MQ3 Heating Up!");
  delay(2000); // allow the MQ3 to warm up
}
void loop() {
  sensorValue = analogRead(MQ3); // read analog input pin 0
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  // Return analog moisture value
  // Determine the status
  if (sensorValue < Sober) {
    Serial.println("  |  Status: Sober");
  } else if (sensorValue >= Sober && sensorValue < Drunk) {
    Serial.println("  |  Status: Drinking but within legal limits");
  } else {
    Serial.println("  |  Status: DRUNK");
  }
  unsigned int outputValue = map(sensorValue, 0, 1023, 0, 255);
  if (sensorValue > 700) {
    analogWrite(ledPin, outputValue); // generate PWM signal
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  return outputValue;
  delay(2000); // wait 2s for next reading
}
