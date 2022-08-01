#include <Wire.h>


#include <LiquidCrystal.h>


#include <RTClib.h>


DateTime now;


RTC_DS3231 rtc;


LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // (rs, e, d4, d5, d6, d7)


void displayDate(void);


void displayTime(void); 


void setup ()


{


  Serial.begin(9600);


  lcd.begin(16,2);


  if (! rtc.begin()) 


  {


    Serial.println(" RTC Module not Present");


    while (1);


  }


  if (rtc.lostPower()) 


  {


    Serial.println("RTC power failure, reset the time!");


    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));


  }


}


void loop () 


{


  now = rtc.now();


  displayDate();


  displayTime();


}


 void displayDate()


 {


  lcd.setCursor(0,0);


  lcd.print("Date:");


  lcd.print(now.day());


  lcd.print('/');


  lcd.print(now.month());


  lcd.print('/');


  lcd.print(now.year());


 }


 void displayTime()


 {


  lcd.setCursor(0,1);


  lcd.print("Time:");


  lcd.print(now.hour());


  lcd.print(':');


  lcd.print(now.minute());


  lcd.print(':');


  lcd.print(now.second());


  lcd.print("    ");


 } 


 


To set the Time


#include <RTClib.h>


#include <Wire.h>


RTC_DS3231 rtc;


char t[32];


void setup() 


{


  Serial.begin(9600);


  Wire.begin();


  rtc.begin();


  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));


  //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0)); 


}


void loop()


{


  DateTime now = rtc.now();


  sprintf(t, "%02d:%02d:%02d %02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());   


  Serial.print(F("Date/Time: "));


  Serial.println(t);


  delay(1000);


}

