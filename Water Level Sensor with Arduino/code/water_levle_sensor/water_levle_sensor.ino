
// Sensor pins pin D6 LED output, pin A0 analog Input
#define ledPin 6
#define sensorPin A0

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

}

void loop()
{
  unsigned int sensorValue = analogRead(sensorPin);

  if (sensorValue < 540)
    return;
    
  uint8_t outputValue = map(sensorValue, 540, 800, 0, 255);
  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.println(outputValue);
  analogWrite(ledPin, outputValue); // generate PWM signal
}
