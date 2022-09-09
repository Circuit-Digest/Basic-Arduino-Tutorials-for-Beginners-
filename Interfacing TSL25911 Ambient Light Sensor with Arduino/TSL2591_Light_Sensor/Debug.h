/*****************************************************************************
* | File      	:	Debug.h
* | Author      :   Waveshare team
* | Function    :	debug with printf
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2018-01-11
* | Info        :   Basic version
*
******************************************************************************/
#ifndef __DEBUG_H
#define __DEBUG_H

#include <stdio.h>

#define USE_DEBUG 1
#if USE_DEBUG
	#define DEBUG(__info) Serial.print("Debug : " __info)
#else
	#define DEBUG(__info,...)  
#endif

#endif

