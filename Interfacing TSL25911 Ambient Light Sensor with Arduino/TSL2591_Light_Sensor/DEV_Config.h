#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_
/***********************************************************************************************************************
			------------------------------------------------------------------------
			|\\\																///|
			|\\\					Hardware interface							///|
			------------------------------------------------------------------------
***********************************************************************************************************************/
#include "Arduino.h"
//#include <avr/pgmspace.h>
#include "Wire.h"

#include "Debug.h"


#define DEV_SPI 0
#define DEV_I2C 1

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

#define INT_PIN 8


/**
 * GPIO read and write
**/
#define DEV_Digital_Write(_pin, _value) digitalWrite(_pin, _value == 0? LOW:HIGH)
#define DEV_Digital_Read(_pin) digitalRead(_pin)

/*------------------------------------------------------------------------------------------------------*/
uint8_t DEV_ModuleInit(void);
void    DEV_ModuleExit(void);

void I2C_Write_Byte(uint8_t Cmd, uint8_t value);
int I2C_Read_Byte(uint8_t Cmd);
int I2C_Read_Word(uint8_t Cmd);

void DEV_GPIO_Mode(UWORD Pin, UWORD mode);
//void DEV_Digital_Write(UWORD Pin, UBYTE Value);
//UBYTE DEV_Digital_Read(UWORD Pin);

void DEV_Delay_ms(UDOUBLE xms);

// void DEV_SPI_WriteByte(UBYTE Value);
// void DEV_SPI_Write_nByte(uint8_t *pData, uint32_t Len);

#endif
