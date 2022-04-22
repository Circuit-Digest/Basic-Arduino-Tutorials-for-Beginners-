/* Arduino pins where the LED is attached*/
#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5
#define LED_5 6

#define sensorPin A0 // Analog input pin that the Sensor is attached to

/* boolean variables to hold the status of the pins*/

bool ledPin1Status;
bool ledPin2Status;
bool ledPin3Status;
bool ledPin4Status;
bool ledPin5Status;

void setup() {

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);

  pinMode(sensorPin, INPUT);

  Serial.begin(9600);// initialize serial communications at 9600 bps:

}

void loop() {

  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  if (sensorValue > 555  )
    ledPin1Status = 1;

   if (sensorValue > 558  )
    ledPin2Status = 1;


   if (sensorValue > 560  )
    ledPin3Status = 1;

   if (sensorValue > 562  )
    ledPin4Status = 1;


   if (sensorValue > 564 )
    ledPin5Status = 1;

  if (ledPin1Status == 1 || ledPin2Status == 1 || ledPin3Status == 1 || ledPin4Status == 1 || ledPin5Status == 1)
  {
    if (sensorValue > 555 || sensorValue < 537  )
      digitalWrite(LED_1, HIGH);

     if (sensorValue > 558 || sensorValue < 534  )
      digitalWrite(LED_2, HIGH);


     if (sensorValue > 560 || sensorValue < 534  )
      digitalWrite(LED_3, HIGH);

     if (sensorValue > 562 || sensorValue < 531 )
      digitalWrite(LED_3, HIGH);


     if (sensorValue > 564 || sensorValue < 528)
      digitalWrite(LED_4, HIGH);

     if (sensorValue > 568 || sensorValue < 525)
      digitalWrite(LED_5, HIGH);

    delay(200);

    ledPin5Status = 0;
    ledPin4Status = 0;
    ledPin3Status = 0;
    ledPin2Status = 0;
    ledPin1Status = 0;

  }
  
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_4, LOW);
  digitalWrite(LED_5, LOW);

}
