
/*
    Sensor Pin S0 -> Arduino Pin D8
    Sensor Pin S1 -> Arduino Pin D7
    Sensor Pin S2 -> Arduino Pin D6
    Sensor Pin S3 -> Arduino Pin D5
    Sensor Pin OUT -> Arduino Pin D4
*/

#define S0_PIN 5
#define S1_PIN 4
#define S2_PIN 7
#define S3_PIN 6
#define OUT_PIN  8



void setup()
{
  // Set the S0, S1, S2, S3 Pins as Output
  pinMode(S0_PIN, OUTPUT);
  pinMode(S1_PIN, OUTPUT);
  pinMode(S2_PIN, OUTPUT);
  pinMode(S3_PIN, OUTPUT);

  //Set OUT_PIN as Input
  pinMode(OUT_PIN, INPUT);

  // Set Pulse Width scaling to 20%
  digitalWrite(S0_PIN, HIGH);
  digitalWrite(S1_PIN, LOW);

  // Enabl UART for Debugging
  Serial.begin(9600);
}

void loop()
{
  int r, g, b;

  r = process_red_value();
  delay(200);
  g = process_green_value();
  delay(200);
  b = process_blue_value();
  delay(200);

  Serial.print("r = ");
  Serial.print(r);
  Serial.print(" ");
  Serial.print("g = ");
  Serial.print(g);
  Serial.print(" ");
  Serial.print("b = ");
  Serial.print(b);
  Serial.print(" ");
  Serial.println();

  if (r < 42)
  {
    Serial.println("Colour Pink");
  }
  else if (g < 63)
  {
    Serial.println("Colour Green");
  }

  else if (r < 64)
  {
    Serial.println("Colour Red");
  }


}


int process_red_value()
{
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, LOW);

  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}

int process_green_value()
{
  digitalWrite(S2_PIN, HIGH);
  digitalWrite(S3_PIN, HIGH);

  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;

}

int process_blue_value()
{
  digitalWrite(S2_PIN, LOW);
  digitalWrite(S3_PIN, HIGH);

  int pulse_length = pulseIn(OUT_PIN, LOW);
  return pulse_length;
}
