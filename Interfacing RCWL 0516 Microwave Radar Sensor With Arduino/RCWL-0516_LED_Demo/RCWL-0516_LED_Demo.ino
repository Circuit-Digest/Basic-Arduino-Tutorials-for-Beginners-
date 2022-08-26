/*  
  RCWL-0516 LED Demo
*/
 
int Sensor = 2;     // RCWL-0516 Input Pin
int LED = 3;       // LED Output Pin
 
void setup()
 {
  pinMode (Sensor, INPUT);  // RCWL-0516 as input
  pinMode (LED, OUTPUT);    // LED as OUTPUT
  digitalWrite(LED, LOW);   // Turn LED Off
  Serial.begin(9600);
}
 
void loop()
{
  bool SensValue = digitalRead(Sensor);  // Read Sensor value
  if (SensValue == HIGH) 
{        
    digitalWrite(LED, HIGH);  // Turn LED On
    Serial.println("Motion detected !!");
  }
  else 
{        
    digitalWrite(LED, LOW);  // Turn LED Off
    Serial.println("Clear");
  }
}
