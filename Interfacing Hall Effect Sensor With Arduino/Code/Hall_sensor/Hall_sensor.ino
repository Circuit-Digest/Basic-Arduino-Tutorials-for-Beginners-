int HallSensor = 2; // Hall sensor is connected to the D2 pin
int LED = 13; // built-in LED pin

void setup() {
  pinMode(HallSensor, INPUT); // Hall Effect Sensor pin INPUT
  pinMode(LED, OUTPUT); // LED Pin Output
}

void loop() {
  int sensorStatus = digitalRead(HallSensor); // Check the sensor status
  if (sensorStatus == 1) // Check if the pin high or not
  {
    // if the pin is high turn on the onboard Led
    digitalWrite(LED, HIGH); // LED on
  }
  else  {
    //else turn off the onboard LED
    digitalWrite(LED, LOW); // LED off
  }
}
