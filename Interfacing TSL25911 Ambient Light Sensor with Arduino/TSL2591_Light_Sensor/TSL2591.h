#ifndef _TSL2591_H_
#define _TSL2591_H_

#include "DEV_Config.h"

#define TSL2591_ADDRESS       (0x29)

#define COMMAND_BIT           (0xA0)
//Register (0x00)
#define ENABLE_REGISTER       (0x00)
#define ENABLE_POWERON        (0x01)
#define ENABLE_POWEROFF       (0x00)
#define ENABLE_AEN            (0x02)
#define ENABLE_AIEN           (0x10)
#define ENABLE_SAI            (0x40)
#define ENABLE_NPIEN          (0x80)

#define CONTROL_REGISTER      (0x01)
#define SRESET                (0x80)
//AGAIN
#define LOW_AGAIN             (0X00)//Low gain (1x)
#define MEDIUM_AGAIN          (0X10)//Medium gain (25x)
#define HIGH_AGAIN            (0X20)//High gain (428x)
#define MAX_AGAIN             (0x30)//Max gain (9876x)
//ATIME
#define ATIME_100MS           (0x00)//100 millis    MAX COUNT 36863 
#define ATIME_200MS           (0x01)//200 millis    MAX COUNT 65535 
#define ATIME_300MS           (0x02)//300 millis
#define ATIME_400MS           (0x03)//400 millis
#define ATIME_500MS           (0x04)//500 millis
#define ATIME_600MS           (0x05)//600 millis

#define AILTL_REGISTER        (0x04)
#define AILTH_REGISTER        (0x05)
#define AIHTL_REGISTER        (0x06)
#define AIHTH_REGISTER        (0x07)
#define NPAILTL_REGISTER      (0x08)
#define NPAILTH_REGISTER      (0x09)
#define NPAIHTL_REGISTER      (0x0A)
#define NPAIHTH_REGISTER      (0x0B)

#define PERSIST_REGISTER      (0x0C)
// Bits 3:0
// 0000          Every ALS cycle generates an interrupt
// 0001          Any value outside of threshold range
// 0010          2 consecutive values out of range
// 0011          3 consecutive values out of range
// 0100          5 consecutive values out of range
// 0101          10 consecutive values out of range
// 0110          15 consecutive values out of range
// 0111          20 consecutive values out of range
// 1000          25 consecutive values out of range
// 1001          30 consecutive values out of range
// 1010          35 consecutive values out of range
// 1011          40 consecutive values out of range
// 1100          45 consecutive values out of range
// 1101          50 consecutive values out of range
// 1110          55 consecutive values out of range
// 1111          60 consecutive values out of range

#define ID_REGISTER           (0x12)

#define STATUS_REGISTER       (0x13)#read only

#define CHAN0_LOW             (0x14)
#define CHAN0_HIGH            (0x15)
#define CHAN1_LOW             (0x16)
#define CHAN1_HIGH            (0x14)

//LUX_DF   GA * 53   GA is the Glass Attenuation factor 
#define LUX_DF                (762.0)
// LUX_DF                408.0
#define MAX_COUNT_100MS       (36863) // 0x8FFF
#define MAX_COUNT             (65535) // 0xFFFF
/***********************************************************************************/
UBYTE TSL2591_Init(void);
UWORD TSL2591_Read_Lux(void);
void TSL2591_SET_InterruptThreshold(UWORD SET_LOW, UWORD SET_HIGH);
void TSL2591_SET_LuxInterrupt(UWORD SET_LOW, UWORD SET_HIGH);
#endif
