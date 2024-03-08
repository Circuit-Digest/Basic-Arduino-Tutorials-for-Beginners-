const int trigPin = 4; // Trigger pin of the ultrasonic sensor (connected to Arduino digital pin 2)
const int echoPin = 5; // Echo pin of the ultrasonic sensor (connected to Arduino digital pin 3)
void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {
  // Trigger the ultrasonic sensor by sending a 10us pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Measure the time it takes for the echo to return
  long duration = pulseIn(echoPin, HIGH);
  // Calculate the distance in centimeters
  // Speed of sound in air at room temperature is approximately 343 meters/second or 0.0343 cm/microsecond
  // Divide the duration by 2 to account for the time it takes for the sound pulse to travel to the object and back
  int distance = duration * 0.0343 / 2;
  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000); // Delay for readability (adjust as needed)
}
