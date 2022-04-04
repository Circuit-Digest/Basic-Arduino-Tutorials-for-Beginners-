#include "SevSeg.h"
SevSeg sevseg;
void setup()
{
  //Set to 1 for single-digit display
  byte numDigits = 1;

  //defines common pins while using multi-digit display. Left for single digit display
  byte digitPins[] = {};

  //Defines Arduino pin connections in order: A, B, C, D, E, F, G, DP
  byte segmentPins[] = {9,8, 7, 6, 5, 4, 3, 2};

  byte displayType = COMMON_CATHODE; //Use COMMON_ANODE for Common Anode display

  bool resistorsOnSegments = true; //‘false’ if resistors are connected to common pin

  //Initialize sevseg object. Use COMMON_ANODE instead of COMMON_CATHODE for CA display
  sevseg.begin(displayType, numDigits, digitPins, segmentPins, resistorsOnSegments);

  sevseg.setBrightness(90);
}

void loop()
{ 
   //Display numbers 0-9 with 1 seconds delay
   for(int i = 0; i <= 10; i++)
   {
     if (i == 10)
{
 i = 0;
}
     sevseg.setNumber(i);
     sevseg.refreshDisplay(); 
     delay(1000);
   }
}
