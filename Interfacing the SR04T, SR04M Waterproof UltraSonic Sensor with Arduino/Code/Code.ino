#include <NewPing.h>

#define TRIGGER_PIN  3 
#define ECHO_PIN     2  
#define MAX_DISTANCE 400 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

float tempval1;
float tempval2;
int finalval;

void setup() {
  Serial.begin(57600); 
}

void loop() {
  delay(20);                     
  Serial.print("Ping: ");
  
  int iterations = 10;
  tempval1=((sonar.ping_median(iterations) / 2) * 0.0343);
  
  if(tempval1-tempval2>60 || tempval1-tempval2<-60)
  {
    tempval2=(tempval1*0.02 )+ (tempval2*0.98);
    }
  else
  {
  tempval2=(tempval1*0.4 )+ (tempval2*0.6);
  }
  
  finalval=tempval2;
  
  Serial.print(finalval);
  Serial.println("cm");
}
