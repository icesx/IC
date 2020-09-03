//============================================================================
// Name        : GPIO-Mapping.cpp
// Author      : i
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include "RKIO.h"
static int physToWpi[64] = {
		-1,           // 0
		-1,
		-1,       // 1, 2
		8, -1, 9, -1, 7, 15, -1, 16, 0, 1, 2, -1, 3, 4, -1, 5, 12, -1, 13, 6,
		14, 10, -1,
		11,       // 25, 26
		30,
		31,        // Actually I2C, but not used
		21, -1, 22, 26, 23, -1, 24, 27, 25, 28, -1, 29, -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1, 17, 18, 19, 20, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
static int pinToGpio_AP[64] = { GPIO5_B4, GPIO6_A0,        //0, 1
		GPIO5_B6, GPIO5_B7,        //2, 3
		GPIO5_B2, GPIO5_B3,        //4, 5
		GPIO5_C3, GPIO0_C1,        //6, 7
		GPIO8_A4, GPIO8_A5,        //8, 9
		GPIO8_A7, GPIO8_A3,        //10, 11
		GPIO8_B1, GPIO8_B0,        //12, 13
		GPIO8_A6, GPIO5_B1,        //14, 15
		GPIO5_B0, -1,              //16, 17
		-1, -1,              //18, 19
		-1, GPIO5_B5,        //20, 21
		GPIO5_C0, GPIO7_C6,        //22, 23
		GPIO6_A1, GPIO7_B0,        //24, 25
		GPIO7_C7, GPIO7_A7,        //26, 27
		GPIO6_A3, GPIO6_A4,        //28. 29
		GPIO7_C1, GPIO7_C2,        //30, 31
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // ... 47
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, // ... 63
		};
static int physPinToGpio(int physPin) {
	return pinToGpio_AP[physPin & 63];
}
static int physPinToWpi(int wpiPin) {
	return physToWpi[wpiPin & 63];
}
int main(int argc, char *argv[]) {
	int srcPin = 3;
	int wpi = physPinToWpi(srcPin);
	int ausu = physPinToGpio(wpi);
	printf("src pin is %d:,map to %d,%d\n", srcPin, ausu, wpi);
	return 0;
}
