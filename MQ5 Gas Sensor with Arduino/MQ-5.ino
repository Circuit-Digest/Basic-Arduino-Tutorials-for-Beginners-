#define ledPin 7
#define sensor  A0
int gas_value;
void setup()
{
  pinMode(sensor, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("MQ5 Heating Up!");
  delay(20000); // allow the MQ5 to warm up
}
void loop()
{
  gas_value = analogRead(sensor);
   Serial.print("Sensor Value:");
 Serial.println(gas_value);
  if (gas_value > 250) {
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}
