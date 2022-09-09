#include "DEV_Config.h"
#include "TSL2591.h"

UWORD Lux = 0;
void setup() {
DEV_ModuleInit();
Serial.print("TSL2591_Init\r\n");
TSL2591_Init();
}

void loop() {
    Lux = TSL2591_Read_Lux();
    Serial.print("Lux = ");
    Serial.print(Lux);
    Serial.print("\r\n");
    TSL2591_SET_LuxInterrupt(50,200);
}
