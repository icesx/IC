/*
 * serial.h
 *
 *  Created on: 2015年8月11日
 *      Author: i
 */

#ifndef IDREADER_H_
#define IDREADER_H_
#define CATINFO_LEN 1300
#include <Arduino.h>
#include <HardwareSerial.h>
struct Commands {
	byte heartbit[10] = { 0xAA, 0xAA, 0xAA, 0x96, 0x69, 0x00, 0x03, 0x11, 0xFF,
			0xED };
	byte heartbit2[10] = { 0xAA, 0xAA, 0xAA, 0x96, 0x69, 0x00, 0x03, 0x20, 0x01,
			0x22 };
	byte readCard[10] = { 0xAA, 0xAA, 0xAA, 0x96, 0x69, 0x00, 0x03, 0x20, 0x02,
			0x21 };
	byte readCard2[10] = { 0xAA, 0xAA, 0xAA, 0x96, 0x69, 0x00, 0x03, 0x30, 0x01,
			0x32 };
};
struct Result {
	int carTouchLength = 15;
	int carReadyLength = 19;
};
class IDReader {
private:
	HardwareSerial *mySerial;
	Commands commands;
	Result result;
	byte commandResponse[64];
	byte carInfo[CATINFO_LEN];
public:
	IDReader(HardwareSerial* mySerial, long band) {
		this->mySerial = mySerial;
		this->mySerial->begin(band);
	}
	~IDReader() {
		free(commandResponse);
		free(carInfo);
	}
	char* heartbit();
private:
	void runCommand(byte* command, int len);
	char* carRead();
	int readSerial();
	char* readPrepary();
	char* readHeartbit();
	void printId();
};

#endif /* IDREADER_H_ */
